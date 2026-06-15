// =============================================================================
// steppers.h — TB6600 Stepper Motor Control (Open-Loop, 5 motors)
// =============================================================================

#ifndef GRYPHON_STEPPERS_H
#define GRYPHON_STEPPERS_H

#include "config.h"
#include <Arduino.h>

// ─── Runtime-adjustable angle multipliers (start from config.h defaults) ─────
// Adjust these live via the MUL command to calibrate real joint angles.
float rt_joint_angle_mult[NUM_JOINTS] = {
  JOINT1_ANGLE_MULT, JOINT2_ANGLE_MULT, JOINT3_ANGLE_MULT,
  JOINT4_ANGLE_MULT, JOINT5_ANGLE_MULT
};

float rt_mot_mult[NUM_MOTORS] = {
  MOT1_MULTIPLIER, MOT2_MULTIPLIER, MOT3_MULTIPLIER,
  MOT4_MULTIPLIER, MOT5_MULTIPLIER
};

// ─── Pin arrays ──────────────────────────────────────────────────────────────
static const uint8_t pul_pins[NUM_MOTORS] = {
  J1_PUL_PIN, J2_PUL_PIN, J3_PUL_PIN, J4_PUL_PIN, J5_PUL_PIN
};
static const uint8_t dir_pins[NUM_MOTORS] = {
  J1_DIR_PIN, J2_DIR_PIN, J3_DIR_PIN, J4_DIR_PIN, J5_DIR_PIN
};
static const bool dir_invert[NUM_MOTORS] = {
  J1_DIR_INVERT, J2_DIR_INVERT, J3_DIR_INVERT, J4_DIR_INVERT, J5_DIR_INVERT
};

// ─── Per-motor motion state ───────────────────────────────────────────────────
struct MotorMotion {
  long target_steps;
  long current_steps;
  unsigned long step_delay_us;
  unsigned long last_step_us;
  bool moving;
};

MotorMotion motors[NUM_MOTORS];

// ─── Init ─────────────────────────────────────────────────────────────────────
void steppers_init() {
  unsigned long now = micros();
  for (int i = 0; i < NUM_MOTORS; i++) {
    pinMode(pul_pins[i], OUTPUT);
    pinMode(dir_pins[i], OUTPUT);
    digitalWrite(pul_pins[i], LOW);
    digitalWrite(dir_pins[i], LOW);
    motors[i].target_steps  = 0;
    motors[i].current_steps = 0;
    motors[i].step_delay_us = DEFAULT_STEP_DELAY_US;
    // FIX: stamp current time so the first step waits a full step_delay.
    // Without this, (now - 0) is huge and ALL motors fire simultaneously
    // on the very first steppers_update() call after a MOV command.
    motors[i].last_step_us  = now;
    motors[i].moving        = false;
  }
}

// ─── Set motor target (in steps) ─────────────────────────────────────────────
void motor_set_target(uint8_t motor, long target) {
  motors[motor].target_steps = target;
  if (target != motors[motor].current_steps) {
    motors[motor].moving = true;
    // FIX: Reset timestamp to now so this motor waits its full step_delay
    // before the first step. Without this, all motors that get a new target
    // in the same MOV command share the old (stale) timestamp and fire
    // simultaneously on the next loop iteration.
    motors[motor].last_step_us = micros();
  }
}

void motor_set_speed(uint8_t motor, unsigned long delay_us) {
  if (delay_us < MIN_STEP_DELAY_US) delay_us = MIN_STEP_DELAY_US;
  if (delay_us > MAX_STEP_DELAY_US) delay_us = MAX_STEP_DELAY_US;
  motors[motor].step_delay_us = delay_us;
}

// ─── Single step pulse ────────────────────────────────────────────────────────
// TB6600 datasheet: DIR must be stable for ≥5µs before rising edge of PUL.
// We use 10µs to have safe margin across all operating conditions.
void do_step(uint8_t motor, bool dir_positive) {
  bool hw_dir = dir_positive ^ dir_invert[motor];
  digitalWrite(dir_pins[motor], hw_dir ? HIGH : LOW);
  delayMicroseconds(10); // DIR setup time (TB6600 min = 5µs, was 2µs — too short)
  digitalWrite(pul_pins[motor], HIGH);
  delayMicroseconds(PULSE_WIDTH_US);
  digitalWrite(pul_pins[motor], LOW);
}

// ─── Non-blocking update (call every loop iteration) ─────────────────────────
bool steppers_update() {
  unsigned long now = micros();
  bool any_moving = false;

  for (int i = 0; i < NUM_MOTORS; i++) {
    if (!motors[i].moving) continue;

    long diff = motors[i].target_steps - motors[i].current_steps;
    if (diff == 0) { motors[i].moving = false; continue; }

    if ((now - motors[i].last_step_us) >= motors[i].step_delay_us) {
      bool dir = (diff > 0);
      do_step(i, dir);
      motors[i].current_steps += dir ? 1 : -1;
      motors[i].last_step_us = now;
      motors[i].moving = (motors[i].current_steps != motors[i].target_steps);
    }
    if (motors[i].moving) any_moving = true;
  }
  return any_moving;
}

// ─── Emergency stop ───────────────────────────────────────────────────────────
void steppers_stop_all() {
  for (int i = 0; i < NUM_MOTORS; i++) {
    motors[i].target_steps = motors[i].current_steps;
    motors[i].moving = false;
  }
}

// ─── Degree → steps conversion ────────────────────────────────────────────────
// Uses the per-motor mechanical multiplier (gearbox ratio etc.)
long degrees_to_steps(uint8_t motor, float degrees) {
  float steps_per_rev = (float)STEPS_PER_MOTOR_REV * rt_mot_mult[motor];
  return (long)((degrees / 360.0f) * steps_per_rev);
}

// ─── Steps → motor degrees (inverse of above, no angle multiplier) ────────────
float steps_to_motor_deg(uint8_t motor, long steps) {
  float steps_per_rev = (float)STEPS_PER_MOTOR_REV * rt_mot_mult[motor];
  return (steps * 360.0f) / steps_per_rev;
}

// ─── Get current joint positions from step counters ───────────────────────────
// Joints 1-3: direct from motor steps × joint angle multiplier
// Joints 4-5: differential wrist transform, then × joint angle multiplier
void get_joint_positions_from_steps(float joint_deg[NUM_JOINTS]) {
  // Joints 1-3: direct
  for (int i = 0; i < 3; i++) {
    float motor_deg = steps_to_motor_deg(i, motors[i].current_steps);
    joint_deg[i] = motor_deg * rt_joint_angle_mult[i];
  }

  // Joints 4-5: differential wrist
  // J4 = (motor4 + motor5) / 2  → combined same-direction angle
  // J5 = (motor4 - motor5) / 2  → opposite-direction angle
  float m4 = steps_to_motor_deg(3, motors[3].current_steps);
  float m5 = steps_to_motor_deg(4, motors[4].current_steps);
  float j4 = (m4 + m5) / 2.0f;
  float j5 = (m4 - m5) / 2.0f;
  joint_deg[3] = j4 * rt_joint_angle_mult[3];
  joint_deg[4] = j5 * rt_joint_angle_mult[4];
}

// ─── Set all 5 joint targets (handles differential wrist) ────────────────────
// Input: desired joint angles in degrees (joint-space)
// Converts to motor-space targets considering differential wrist kinematics.
void set_joint_targets(float joint_deg[NUM_JOINTS]) {
  // Joints 1-3: direct motor mapping
  for (int i = 0; i < 3; i++) {
    // Inverse of angle multiplier to get required motor degrees
    float motor_deg = joint_deg[i] / rt_joint_angle_mult[i];
    motor_set_target(i, degrees_to_steps(i, motor_deg));
  }

  // Joints 4-5: differential wrist
  // J4 → both motors same direction:     motor4 = J4 + J5,  motor5 = J4 - J5
  // J5 → motors in opposite directions:  motor4 = +J5,      motor5 = -J5
  float j4 = joint_deg[3] / rt_joint_angle_mult[3];
  float j5 = joint_deg[4] / rt_joint_angle_mult[4];
  motor_set_target(3, degrees_to_steps(3, j4 + j5));  // motor4 = J4 + J5
  motor_set_target(4, degrees_to_steps(4, j4 - j5));  // motor5 = J4 - J5
}

#endif // GRYPHON_STEPPERS_H
