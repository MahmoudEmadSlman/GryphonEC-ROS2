// =============================================================================
// steppers.h — TB6600 Stepper Motor Control (non-blocking, 5 motors)
// =============================================================================

#ifndef GRYPHON_STEPPERS_H
#define GRYPHON_STEPPERS_H

#include "config.h"
#include <Arduino.h>

// ─── Pin arrays ─────────────────────────────────────────────────────────────
static const uint8_t pul_pins[NUM_MOTORS] = {
  J1_PUL_PIN, J2_PUL_PIN, J3_PUL_PIN, J4_PUL_PIN, J5_PUL_PIN
};
static const uint8_t dir_pins[NUM_MOTORS] = {
  J1_DIR_PIN, J2_DIR_PIN, J3_DIR_PIN, J4_DIR_PIN, J5_DIR_PIN
};
static const bool dir_invert[NUM_MOTORS] = {
  J1_DIR_INVERT, J2_DIR_INVERT, J3_DIR_INVERT, J4_DIR_INVERT, J5_DIR_INVERT
};
static const float mot_multipliers[NUM_MOTORS] = {
  MOT1_MULTIPLIER, MOT2_MULTIPLIER, MOT3_MULTIPLIER,
  MOT4_MULTIPLIER, MOT5_MULTIPLIER
};

// ─── Per-motor motion state ─────────────────────────────────────────────────
struct MotorMotion {
  long target_steps;
  long current_steps;
  unsigned long step_delay_us;
  unsigned long last_step_us;
  bool moving;
};

MotorMotion motors[NUM_MOTORS];

// ─── Init ───────────────────────────────────────────────────────────────────
void steppers_init() {
  for (int i = 0; i < NUM_MOTORS; i++) {
    pinMode(pul_pins[i], OUTPUT);
    pinMode(dir_pins[i], OUTPUT);
    digitalWrite(pul_pins[i], LOW);
    digitalWrite(dir_pins[i], LOW);
    motors[i].target_steps = 0;
    motors[i].current_steps = 0;
    motors[i].step_delay_us = DEFAULT_STEP_DELAY_US;
    motors[i].last_step_us = 0;
    motors[i].moving = false;
  }
}

// ─── Set motor target (in steps) ────────────────────────────────────────────
void motor_set_target(uint8_t motor, long target) {
  motors[motor].target_steps = target;
  motors[motor].moving = (target != motors[motor].current_steps);
}

void motor_set_speed(uint8_t motor, unsigned long delay_us) {
  if (delay_us < MIN_STEP_DELAY_US) delay_us = MIN_STEP_DELAY_US;
  if (delay_us > MAX_STEP_DELAY_US) delay_us = MAX_STEP_DELAY_US;
  motors[motor].step_delay_us = delay_us;
}

// ─── Single step pulse ──────────────────────────────────────────────────────
void do_step(uint8_t motor, bool dir_positive) {
  bool hw_dir = dir_positive ^ dir_invert[motor];
  digitalWrite(dir_pins[motor], hw_dir ? HIGH : LOW);
  delayMicroseconds(2); // DIR setup time
  digitalWrite(pul_pins[motor], HIGH);
  delayMicroseconds(PULSE_WIDTH_US);
  digitalWrite(pul_pins[motor], LOW);
}

// ─── Non-blocking update (call in loop) ─────────────────────────────────────
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

// ─── Emergency stop ─────────────────────────────────────────────────────────
void steppers_stop_all() {
  for (int i = 0; i < NUM_MOTORS; i++) {
    motors[i].target_steps = motors[i].current_steps;
    motors[i].moving = false;
  }
}

// ─── Degree → steps conversion (per motor, with multiplier) ─────────────────
long degrees_to_steps(uint8_t motor, float degrees) {
  float steps_per_rev = (float)STEPS_PER_MOTOR_REV * mot_multipliers[motor];
  return (long)((degrees / 360.0f) * steps_per_rev);
}

// ─── Differential wrist: joint angles → motor targets (in degrees) ──────────
// motor4_deg = joint4_deg + joint5_deg
// motor5_deg = joint4_deg - joint5_deg
void diff_wrist_joint_to_motor(float joint4_deg, float joint5_deg,
                                float &motor4_deg, float &motor5_deg) {
  motor4_deg = joint4_deg + joint5_deg;
  motor5_deg = joint4_deg - joint5_deg;
}

// ─── Set all 5 JOINT targets (handles differential wrist) ───────────────────
void set_joint_targets(float joint_deg[NUM_JOINTS]) {
  // Joints 1-3: direct motor mapping
  for (int i = 0; i < 3; i++) {
    motor_set_target(i, degrees_to_steps(i, joint_deg[i]));
  }
  // Joints 4-5: differential wrist → motors 4 & 5
  float mot4_deg, mot5_deg;
  diff_wrist_joint_to_motor(joint_deg[3], joint_deg[4], mot4_deg, mot5_deg);
  motor_set_target(3, degrees_to_steps(3, mot4_deg));
  motor_set_target(4, degrees_to_steps(4, mot5_deg));
}

#endif // GRYPHON_STEPPERS_H
