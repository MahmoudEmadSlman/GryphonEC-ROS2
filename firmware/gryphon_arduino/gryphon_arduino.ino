// =============================================================================
// gryphon_arduino.ino — Gryphon Robot Arm Firmware (Open-Loop)
// =============================================================================
// Serial Protocol (115200 baud):
//   ROS2 → Arduino:
//     MOV:<j1>,<j2>,<j3>,<j4>,<j5>   Joint targets (degrees)
//     STP                             Emergency stop
//     RST                             Reset all step counters to zero
//     GRP:<0|1>                       Gripper OFF/ON
//     SPD:<motor_id>,<delay_us>       Set step delay for a motor (µs)
//     MUL:J<id>,<val>                 Set joint angle multiplier at runtime
//     MUL:M<id>,<val>                 Set motor (gearbox) multiplier at runtime
//     DBG:<motor_id>                  Diagnostic: print step state
//
//   Arduino → ROS2:
//     OK                              Command acknowledged
//     ERR:<msg>                       Error
//     RDY                             Boot complete
// =============================================================================

#include "config.h"
#include "steppers.h"

// ─── State ──────────────────────────────────────────────────────────────────
static String serial_buf = "";

// ─── Forward declarations ───────────────────────────────────────────────────
void process_command(String &cmd);

// ─── Setup ──────────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(SERIAL_BAUD);
  while (!Serial) {
    ;
  }

  steppers_init();

  // Gripper
  pinMode(GRIPPER_PIN, OUTPUT);
  digitalWrite(GRIPPER_PIN, GRIPPER_ACTIVE_HIGH ? LOW : HIGH);

  // Gripper relay
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  // E-stop
  pinMode(ESTOP_PIN, INPUT_PULLUP);

  serial_buf.reserve(128);
  delay(500);
  Serial.println("RDY");
}

// ─── Loop ───────────────────────────────────────────────────────────────────
void loop() {
  // E-stop check
  bool estop = ESTOP_ACTIVE_LOW ? (digitalRead(ESTOP_PIN) == LOW)
                                : (digitalRead(ESTOP_PIN) == HIGH);
  if (estop) {
    steppers_stop_all();
    return;
  }

  // Motor stepping (non-blocking)
  steppers_update();

  // Serial commands
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n' || c == '\r') {
      if (serial_buf.length() > 0) {
        process_command(serial_buf);
        serial_buf = "";
      }
    } else {
      serial_buf += c;
    }
  }
}

// ─── Parse comma-separated floats ───────────────────────────────────────────
int parse_floats(const String &s, float *out, int max_count) {
  int idx = 0, start = 0;
  for (int i = 0; i <= (int)s.length() && idx < max_count; i++) {
    if (i == (int)s.length() || s[i] == ',') {
      out[idx++] = s.substring(start, i).toFloat();
      start = i + 1;
    }
  }
  return idx;
}

// ─── Command Handler ────────────────────────────────────────────────────────
void process_command(String &cmd) {
  cmd.trim();

  // ── MOV ──
  if (cmd.startsWith("MOV:")) {
    float targets[NUM_JOINTS];
    if (parse_floats(cmd.substring(4), targets, NUM_JOINTS) != NUM_JOINTS) {
      Serial.println("ERR:BAD_ARGS");
      return;
    }
    set_joint_targets(targets);
    Serial.println("OK");
  }

  // ── STP ──
  else if (cmd == "STP") {
    steppers_stop_all();
    Serial.println("OK");
  }

  // ── RST ──
  else if (cmd == "RST") {
    for (int i = 0; i < NUM_MOTORS; i++) {
      motors[i].current_steps = 0;
      motors[i].target_steps = 0;
      motors[i].moving = false;
    }
    Serial.println("OK");
  }

  // ── GRP ──
  else if (cmd.startsWith("GRP:")) {
    int val = cmd.substring(4).toInt();
    bool closed = (val != 0);
    digitalWrite(GRIPPER_PIN, closed == GRIPPER_ACTIVE_HIGH ? HIGH : LOW);
    digitalWrite(RELAY_PIN, (val >= RELAY_CLOSED_THRESHOLD) ? HIGH : LOW);
    Serial.println("OK");
  }

  // ── SPD ──
  else if (cmd.startsWith("SPD:")) {
    int comma = cmd.indexOf(',', 4);
    if (comma < 0) {
      Serial.println("ERR:BAD_ARGS");
      return;
    }
    int mid = cmd.substring(4, comma).toInt();
    unsigned long d = cmd.substring(comma + 1).toInt();
    if (mid < 0 || mid >= NUM_MOTORS) {
      Serial.println("ERR:BAD_ID");
      return;
    }
    motor_set_speed(mid, d);
    Serial.println("OK");
  }

  // ── MUL:J<id>,<val>  — runtime joint angle multiplier ──
  // ── MUL:M<id>,<val>  — runtime motor (gearbox) multiplier ──
  else if (cmd.startsWith("MUL:")) {
    char type = cmd[4];
    int id = cmd.substring(5, 6).toInt();
    int comma = cmd.indexOf(',', 5);
    if (comma < 0 || id < 0 || id >= NUM_MOTORS) {
      Serial.println("ERR:BAD_ARGS");
      return;
    }
    float val = cmd.substring(comma + 1).toFloat();
    if (type == 'J')
      rt_joint_angle_mult[id] = val;
    else if (type == 'M')
      rt_mot_mult[id] = val;
    else {
      Serial.println("ERR:BAD_TYPE");
      return;
    }
    Serial.println("OK");
  }

  // ── DBG:<motor_id> ──
  else if (cmd.startsWith("DBG:")) {
    int mid = cmd.substring(4).toInt();
    if (mid < 0 || mid >= NUM_MOTORS) {
      Serial.println("ERR:BAD_ID");
      return;
    }
    long diff = motors[mid].target_steps - motors[mid].current_steps;
    bool sw_dir = (diff > 0);
    int hw_pin = digitalRead(dir_pins[mid]);
    Serial.print("DBG:");
    Serial.print(mid);
    Serial.print(" tgt=");
    Serial.print(motors[mid].target_steps);
    Serial.print(" cur=");
    Serial.print(motors[mid].current_steps);
    Serial.print(" diff=");
    Serial.print(diff);
    Serial.print(" sw_dir=");
    Serial.print(sw_dir ? "+" : "-");
    Serial.print(" dir_pin=");
    Serial.println(hw_pin);
  }

  else {
    Serial.println("ERR:UNKNOWN");
  }
}
