// =============================================================================
// homing.h — Homing via Stall Detection with Return-to-Zero
// =============================================================================
// Sequence for each motor:
//   1. Move slowly in homing direction until stall detected
//   2. Set encoder to the known stall angle (e.g., -90°)
//   3. Move motor to 0° position
//
// Full homing order:
//   Motor 1 → Motor 2 → Motor 3 → Motors 4+5 (together)
// =============================================================================

#ifndef GRYPHON_HOMING_H
#define GRYPHON_HOMING_H

#include "config.h"
#include "encoders.h"
#include "steppers.h"
#include <Arduino.h>

// ─── Per-motor config arrays ────────────────────────────────────────────────
static const bool homing_dirs[NUM_MOTORS] = {
  HOM1_DIR, HOM2_DIR, HOM3_DIR, HOM4_DIR, HOM5_DIR
};

static const float stall_angles[NUM_MOTORS] = {
  HOM1_STALL_ANGLE, HOM2_STALL_ANGLE, HOM3_STALL_ANGLE,
  HOM4_STALL_ANGLE, HOM5_STALL_ANGLE
};

// ─── Phase 1: Find mechanical stop via stall detection ──────────────────────
// Returns true if stall found, false on timeout.
bool find_stall(uint8_t motor) {
  unsigned long start = millis();
  bool dir = homing_dirs[motor];

  while (true) {
    if (millis() - start > HOMING_TIMEOUT_MS) return false;

    long enc_before = encoder_read(motor);

    for (int s = 0; s < STALL_CHECK_STEPS; s++) {
      do_step(motor, dir);
      delayMicroseconds(HOMING_SPEED_DELAY_US);
    }

    long enc_after = encoder_read(motor);
    if (abs(enc_after - enc_before) < STALL_THRESHOLD) {
      return true; // Stalled
    }
  }
}

// ─── Phase 2: Set encoder to stall angle ────────────────────────────────────
// Convert the known stall angle to encoder ticks and set the counter.
void set_encoder_to_angle(uint8_t motor, float angle_deg) {
  // ticks = (angle / 360) * CPR / multiplier
  // We need the raw ticks that correspond to this angle
  extern float rt_enc_mult[];
  float raw_deg = angle_deg / rt_enc_mult[motor];
  long ticks = (long)((raw_deg / 360.0f) * (float)ENCODER_CPR);

  noInterrupts();
  enc_ticks[motor] = ticks;
  interrupts();
}

// ─── Phase 3: Move motor to 0° (blocking) ───────────────────────────────────
// Uses stepping with encoder feedback to reach zero position.
bool move_to_zero(uint8_t motor) {
  unsigned long start = millis();
  extern float rt_enc_mult[];

  while (true) {
    if (millis() - start > HOMING_TIMEOUT_MS) return false;

    // Read current angle
    long ticks = encoder_read(motor);
    float motor_deg = (ticks * 360.0f) / (float)ENCODER_CPR;
    float link_deg = motor_deg * rt_enc_mult[motor];

    // Close enough to zero? (within ~0.5°)
    if (abs(link_deg) < 0.5f) {
      break;
    }

    // Step toward zero
    bool dir = (link_deg < 0);  // If negative angle, move positive
    do_step(motor, dir);
    delayMicroseconds(HOMING_RETURN_DELAY_US);
  }

  // Set step counter to match current encoder position
  motors[motor].current_steps = 0;
  motors[motor].target_steps = 0;
  motors[motor].moving = false;

  return true;
}

// ─── Home a single motor (full sequence) ────────────────────────────────────
// Phase 1: Find stall → Phase 2: Set angle → Phase 3: Go to 0°
// Returns true on success.
bool home_motor(uint8_t motor) {
  Serial.print("HOM_START:");
  Serial.println(motor);

  // Phase 1: Find mechanical stop
  if (!find_stall(motor)) {
    Serial.print("ERR:STALL_TIMEOUT:");
    Serial.println(motor);
    return false;
  }
  Serial.print("HOM_STALL:");
  Serial.println(motor);

  // Phase 2: Set encoder to known stall angle
  set_encoder_to_angle(motor, stall_angles[motor]);

  // Phase 3: Move to 0°
  if (!move_to_zero(motor)) {
    Serial.print("ERR:RETURN_TIMEOUT:");
    Serial.println(motor);
    return false;
  }

  return true;
}

// ─── Home all motors in sequence ────────────────────────────────────────────
// Order: Motor 0 → 1 → 2 → then 3 & 4 together (differential wrist)
// Returns bitmask of failed motors (0 = all OK).
uint8_t home_all() {
  uint8_t fail_mask = 0;

  // ── Step 1: Home motors 0, 1, 2 sequentially ──
  for (int i = 0; i < 3; i++) {
    if (!home_motor(i)) {
      fail_mask |= (1 << i);
    }
    delay(200); // Brief pause between joints
  }

  // ── Step 2: Home motors 3 & 4 (differential wrist) together ──
  // First, find stall on both
  Serial.println("HOM_START:WRIST");

  bool stall3 = find_stall(3);
  bool stall4 = find_stall(4);

  if (!stall3) { fail_mask |= (1 << 3); Serial.println("ERR:STALL_TIMEOUT:3"); }
  if (!stall4) { fail_mask |= (1 << 4); Serial.println("ERR:STALL_TIMEOUT:4"); }

  if (stall3 && stall4) {
    // Set both encoders to their stall angles
    set_encoder_to_angle(3, stall_angles[3]);
    set_encoder_to_angle(4, stall_angles[4]);

    Serial.println("HOM_STALL:WRIST");

    // Move both to 0° (alternating steps for smoother motion)
    unsigned long start = millis();
    extern float rt_enc_mult[];
    bool done3 = false, done4 = false;

    while (!done3 || !done4) {
      if (millis() - start > HOMING_TIMEOUT_MS) {
        if (!done3) fail_mask |= (1 << 3);
        if (!done4) fail_mask |= (1 << 4);
        break;
      }

      // Motor 3
      if (!done3) {
        long t3 = encoder_read(3);
        float deg3 = (t3 * 360.0f / (float)ENCODER_CPR) * rt_enc_mult[3];
        if (abs(deg3) < 0.5f) {
          done3 = true;
        } else {
          do_step(3, deg3 < 0);
          delayMicroseconds(HOMING_RETURN_DELAY_US / 2);
        }
      }

      // Motor 4
      if (!done4) {
        long t4 = encoder_read(4);
        float deg4 = (t4 * 360.0f / (float)ENCODER_CPR) * rt_enc_mult[4];
        if (abs(deg4) < 0.5f) {
          done4 = true;
        } else {
          do_step(4, deg4 < 0);
          delayMicroseconds(HOMING_RETURN_DELAY_US / 2);
        }
      }
    }

    // Reset step counters
    motors[3].current_steps = 0;
    motors[3].target_steps = 0;
    motors[3].moving = false;
    motors[4].current_steps = 0;
    motors[4].target_steps = 0;
    motors[4].moving = false;
  }

  return fail_mask;
}

#endif // GRYPHON_HOMING_H
