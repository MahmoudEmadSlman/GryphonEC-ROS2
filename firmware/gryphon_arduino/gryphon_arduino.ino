// =============================================================================
// gryphon_arduino.ino — Gryphon Robot Arm Firmware
// =============================================================================
// Plain Arduino firmware replacing GRBL.
// Features: 5 TB6600 steppers, 5 HEDS-9100 encoders, differential wrist,
//           stall-detect homing, pneumatic gripper.
//
// Serial Protocol (115200 baud):
//   ROS2 → Arduino:
//     MOV:<j1>,<j2>,<j3>,<j4>,<j5>   Joint targets (degrees)
//     HOM:<motor_id>                  Home single motor (0-4)
//     HOM:ALL                         Home all motors
//     STP                             Emergency stop
//     RST                             Reset all counters
//     GRP:<0|1>                       Gripper OFF/ON
//     SPD:<motor_id>,<delay_us>       Set speed for a motor
//     GET                             Request position report
//     MUL:E<id>,<val>                 Set encoder multiplier at runtime
//     MUL:M<id>,<val>                 Set motor multiplier at runtime
//
//   Arduino → ROS2:
//     POS:<j1>,<j2>,<j3>,<j4>,<j5>   Joint positions (degrees)
//     OK                              Command acknowledged
//     HMD:<motor_id> / HMD:ALL       Homing complete
//     ERR:<msg>                       Error
//     RDY                             Boot complete
// =============================================================================

#include "config.h"
#include "encoders.h"
#include "steppers.h"
#include "homing.h"

// ─── Runtime-adjustable multipliers (start from config.h defaults) ──────────
float rt_enc_mult[NUM_MOTORS] = {
  ENC1_MULTIPLIER, ENC2_MULTIPLIER, ENC3_MULTIPLIER,
  ENC4_MULTIPLIER, ENC5_MULTIPLIER
};
float rt_mot_mult[NUM_MOTORS] = {
  MOT1_MULTIPLIER, MOT2_MULTIPLIER, MOT3_MULTIPLIER,
  MOT4_MULTIPLIER, MOT5_MULTIPLIER
};

// ─── State ──────────────────────────────────────────────────────────────────
static unsigned long last_report_ms = 0;
static String serial_buf = "";

// ─── Forward declarations ───────────────────────────────────────────────────
void process_command(String &cmd);
void send_position_report();

// ─── Setup ──────────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(SERIAL_BAUD);
  while (!Serial) { ; }

  encoders_init();
  steppers_init();

  // Gripper
  pinMode(GRIPPER_PIN, OUTPUT);
  digitalWrite(GRIPPER_PIN, GRIPPER_ACTIVE_HIGH ? LOW : HIGH);

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

  // Update stepper motion
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

  // Periodic position report
  unsigned long now = millis();
  if (now - last_report_ms >= REPORT_INTERVAL_MS) {
    send_position_report();
    last_report_ms = now;
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
  // ── HOM ──
  else if (cmd.startsWith("HOM:")) {
    String arg = cmd.substring(4);
    if (arg == "ALL") {
      Serial.println("OK");
      uint8_t fail = home_all();
      if (fail == 0) Serial.println("HMD:ALL");
      else { Serial.print("ERR:HOM_FAIL:"); Serial.println(fail, BIN); }
    } else {
      int mid = arg.toInt();
      if (mid < 0 || mid >= NUM_MOTORS) { Serial.println("ERR:BAD_ID"); return; }
      Serial.println("OK");
      if (home_motor(mid)) { Serial.print("HMD:"); Serial.println(mid); }
      else { Serial.print("ERR:HOM_FAIL:"); Serial.println(mid); }
    }
  }
  // ── STP ──
  else if (cmd == "STP") {
    steppers_stop_all();
    Serial.println("OK");
  }
  // ── RST ──
  else if (cmd == "RST") {
    encoder_reset_all();
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
    digitalWrite(GRIPPER_PIN, (val != 0) == GRIPPER_ACTIVE_HIGH ? HIGH : LOW);
    Serial.println("OK");
  }
  // ── SPD ──
  else if (cmd.startsWith("SPD:")) {
    int comma = cmd.indexOf(',', 4);
    if (comma < 0) { Serial.println("ERR:BAD_ARGS"); return; }
    int mid = cmd.substring(4, comma).toInt();
    unsigned long d = cmd.substring(comma + 1).toInt();
    if (mid < 0 || mid >= NUM_MOTORS) { Serial.println("ERR:BAD_ID"); return; }
    motor_set_speed(mid, d);
    Serial.println("OK");
  }
  // ── MUL:E<id>,<val> or MUL:M<id>,<val> — runtime multiplier adjustment ──
  else if (cmd.startsWith("MUL:")) {
    char type = cmd[4]; // 'E' or 'M'
    int id = cmd.substring(5, 6).toInt();
    int comma = cmd.indexOf(',', 5);
    if (comma < 0 || id < 0 || id >= NUM_MOTORS) { Serial.println("ERR:BAD_ARGS"); return; }
    float val = cmd.substring(comma + 1).toFloat();
    if (type == 'E') rt_enc_mult[id] = val;
    else if (type == 'M') rt_mot_mult[id] = val;
    else { Serial.println("ERR:BAD_TYPE"); return; }
    Serial.println("OK");
  }
  // ── GET ──
  else if (cmd == "GET") {
    send_position_report();
  }
  else {
    Serial.println("ERR:UNKNOWN");
  }
}

// ─── Position Report (joint-space degrees) ──────────────────────────────────
void send_position_report() {
  float joint_deg[NUM_JOINTS];

  // Joints 1-3: direct
  for (int i = 0; i < 3; i++) {
    long ticks = encoder_read(i);
    float motor_deg = (ticks * 360.0f) / (float)ENCODER_CPR;
    joint_deg[i] = motor_deg * rt_enc_mult[i];
  }

  // Joints 4-5: differential wrist
  long t4 = encoder_read(3);
  long t5 = encoder_read(4);
  float m4 = ((t4 * 360.0f) / (float)ENCODER_CPR) * rt_enc_mult[3];
  float m5 = ((t5 * 360.0f) / (float)ENCODER_CPR) * rt_enc_mult[4];
  joint_deg[3] = (m4 + m5) / 2.0f;  // pitch
  joint_deg[4] = (m4 - m5) / 2.0f;  // roll

  Serial.print("POS:");
  for (int i = 0; i < NUM_JOINTS; i++) {
    Serial.print(joint_deg[i], 2);
    if (i < NUM_JOINTS - 1) Serial.print(",");
  }
  Serial.println();
}
