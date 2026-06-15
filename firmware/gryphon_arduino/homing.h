// =============================================================================
// homing.h — Current-Sensor Stall-Based Auto Homing
// =============================================================================
#ifndef GRYPHON_HOMING_H
#define GRYPHON_HOMING_H

#include "config.h"
#include "steppers.h"
#include <Arduino.h>

// ─── Per-motor config arrays ──────────────────────────────────────────────────
static const bool  homing_dirs[NUM_MOTORS]     = { HOM1_DIR, HOM2_DIR, HOM3_DIR, HOM4_DIR, HOM5_DIR };
static const int   stall_thresholds[NUM_MOTORS] = { STALL_THRESHOLD1, STALL_THRESHOLD2,
                                                     STALL_THRESHOLD3, STALL_THRESHOLD4,
                                                     STALL_THRESHOLD5 };
static const float home_offsets_deg[NUM_MOTORS] = { HOME_OFFSET1_DEG, HOME_OFFSET2_DEG,
                                                     HOME_OFFSET3_DEG, HOME_OFFSET4_DEG,
                                                     HOME_OFFSET5_DEG };

// ─── Drive one motor to mechanical stop via current-sensor stall detection ───
// Returns true  = stall detected (normal).
// Returns false = timeout (HOMING_TIMEOUT_MS elapsed without stall).
// hit_current   = EMA value at the moment stall was triggered (0 if timeout).
bool drive_to_stall(uint8_t motor, int &hit_current) {
  bool dir       = homing_dirs[motor];
  int  threshold = stall_thresholds[motor];
  hit_current    = 0;

  // ── Wait for current to settle before seeding the EMA ──
  // After the previous motor stalled, current stays elevated.
  // Keep sampling until average drops at least 15 below threshold, or 3s.
  float ema = 0;
  unsigned long settle_deadline = millis() + 3000;
  do {
    ema = 0;
    for (int i = 0; i < 20; i++) {
      ema += analogRead(CURRENT_SENSOR_PIN);
      delay(10);
    }
    ema /= 20.0f;
  } while ((int)ema > (threshold - 15) && millis() < settle_deadline);

  // ── Blocking step loop: step → read → EMA → check ──
  unsigned long deadline = millis() + HOMING_TIMEOUT_MS;
  bool stalled = false;

  while (millis() < deadline) {
    do_step(motor, dir);
    motors[motor].current_steps += dir ? 1 : -1;
    delayMicroseconds(HOMING_SPEED_DELAY_US);

    int raw = analogRead(CURRENT_SENSOR_PIN);
    ema = 0.2f * raw + 0.8f * ema;

    if ((int)ema > threshold) {
      hit_current = (int)ema;
      stalled     = true;
      break;
    }
  }

  // Stop motor
  motors[motor].target_steps = motors[motor].current_steps;
  motors[motor].moving       = false;

  return stalled;
}

// ─── Move motor by a fixed number of degrees (blocking, homing speed) ────────
void move_degrees_blocking(uint8_t motor, float deg) {
  if (deg == 0.0f) return;

  long steps     = degrees_to_steps(motor, deg);
  bool dir       = (steps > 0);
  long abs_steps = steps < 0 ? -steps : steps;

  for (long s = 0; s < abs_steps; s++) {
    do_step(motor, dir);
    delayMicroseconds(HOMING_SPEED_DELAY_US);
  }
  motors[motor].current_steps += steps;
  motors[motor].target_steps   = motors[motor].current_steps;
}

// ─── Home a single motor (for manual HOM:<id> command) ───────────────────────
bool home_motor(uint8_t motor) {
  Serial.print("HOM_START:");
  Serial.println(motor);

  int  hit_current = 0;
  bool ok          = drive_to_stall(motor, hit_current);

  motors[motor].current_steps = 0;
  motors[motor].target_steps  = 0;

  if (home_offsets_deg[motor] != 0.0f) {
    move_degrees_blocking(motor, home_offsets_deg[motor]);
    motors[motor].current_steps = 0;
    motors[motor].target_steps  = 0;
  }

  Serial.print(ok ? "HOM_HIT:" : "HOM_TIMEOUT:");
  Serial.print(motor);
  Serial.print(" ( With Current : ");
  Serial.print(hit_current);
  Serial.println(" )");
  return ok;
}

// ─── Home all motors — Elbow(2)→Shoulder(1)→Base(0)→WristA(3)→WristB(4) ─────
uint8_t home_all() {
  Serial.println("HOM_START:ALL");

  // Homing order: ELBOW(2) → SHOULDER(1) → BASE(0) → WRIST_A(3) → WRIST_B(4)
  const uint8_t order[NUM_MOTORS] = { 2, 1, 0, 3, 4 };

  // Phase 1: each motor drives to its mechanical stop
  for (int i = 0; i < NUM_MOTORS; i++) {
    uint8_t mid = order[i];

    Serial.print("HOM_START:");
    Serial.println(mid);

    int  hit_current = 0;
    bool ok          = drive_to_stall(mid, hit_current);

    motors[mid].current_steps = 0;
    motors[mid].target_steps  = 0;

    Serial.print(ok ? "HOM_HIT:" : "HOM_TIMEOUT:");
    Serial.print(mid);
    Serial.print(" ( With Current : ");
    Serial.print(hit_current);
    Serial.println(" )");

    delay(300);
  }

  // Phase 2: back off to home positions (same order)
  Serial.println("HOM_OFFSET:START");
  for (int i = 0; i < NUM_MOTORS; i++) {
    uint8_t mid = order[i];
    if (home_offsets_deg[mid] != 0.0f) {
      move_degrees_blocking(mid, home_offsets_deg[mid]);
    }
    motors[mid].current_steps = 0;
    motors[mid].target_steps  = 0;
    motors[mid].moving        = false;
  }

  Serial.println("HMD:ALL");
  return 0;
}

#endif // GRYPHON_HOMING_H
