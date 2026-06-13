// =============================================================================
// encoders.h — Quadrature Encoder Reading (x2 decoding, HEDS-9100)
// =============================================================================

#ifndef GRYPHON_ENCODERS_H
#define GRYPHON_ENCODERS_H

#include "config.h"
#include <Arduino.h>

// ─── Volatile tick counters (modified in ISR) ───────────────────────────────
volatile long enc_ticks[NUM_MOTORS] = {0};

// ─── Pin arrays ─────────────────────────────────────────────────────────────
static const uint8_t enc_a_pins[NUM_MOTORS] = {
  ENC1_A_PIN, ENC2_A_PIN, ENC3_A_PIN, ENC4_A_PIN, ENC5_A_PIN
};
static const uint8_t enc_b_pins[NUM_MOTORS] = {
  ENC1_B_PIN, ENC2_B_PIN, ENC3_B_PIN, ENC4_B_PIN, ENC5_B_PIN
};
static const float enc_multipliers[NUM_MOTORS] = {
  ENC1_MULTIPLIER, ENC2_MULTIPLIER, ENC3_MULTIPLIER,
  ENC4_MULTIPLIER, ENC5_MULTIPLIER
};

// ─── ISRs (x2 decoding: trigger on CHANGE of channel A) ────────────────────
void enc1_isr() {
  (digitalRead(ENC1_A_PIN) == digitalRead(ENC1_B_PIN)) ? enc_ticks[0]++ : enc_ticks[0]--;
}
void enc2_isr() {
  (digitalRead(ENC2_A_PIN) == digitalRead(ENC2_B_PIN)) ? enc_ticks[1]++ : enc_ticks[1]--;
}
void enc3_isr() {
  (digitalRead(ENC3_A_PIN) == digitalRead(ENC3_B_PIN)) ? enc_ticks[2]++ : enc_ticks[2]--;
}
void enc4_isr() {
  (digitalRead(ENC4_A_PIN) == digitalRead(ENC4_B_PIN)) ? enc_ticks[3]++ : enc_ticks[3]--;
}
void enc5_isr() {
  (digitalRead(ENC5_A_PIN) == digitalRead(ENC5_B_PIN)) ? enc_ticks[4]++ : enc_ticks[4]--;
}

typedef void (*isr_func_t)();
static const isr_func_t enc_isrs[NUM_MOTORS] = {
  enc1_isr, enc2_isr, enc3_isr, enc4_isr, enc5_isr
};

// ─── Init ───────────────────────────────────────────────────────────────────
void encoders_init() {
  for (int i = 0; i < NUM_MOTORS; i++) {
    pinMode(enc_a_pins[i], INPUT_PULLUP);
    pinMode(enc_b_pins[i], INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(enc_a_pins[i]), enc_isrs[i], CHANGE);
  }
}

// ─── Safe read/reset ────────────────────────────────────────────────────────
long encoder_read(uint8_t motor) {
  noInterrupts();
  long val = enc_ticks[motor];
  interrupts();
  return val;
}

void encoder_reset(uint8_t motor) {
  noInterrupts();
  enc_ticks[motor] = 0;
  interrupts();
}

void encoder_reset_all() {
  noInterrupts();
  for (int i = 0; i < NUM_MOTORS; i++) enc_ticks[i] = 0;
  interrupts();
}

// ─── Convert motor encoder ticks → motor shaft degrees ──────────────────────
// x2 decoding: CPR = PPR * 2 = 1000 counts/rev
float motor_ticks_to_degrees(uint8_t motor, long ticks) {
  return (ticks * 360.0f) / (float)ENCODER_CPR;
}

// ─── Convert motor encoder ticks → link degrees (with multiplier) ───────────
float encoder_to_link_degrees(uint8_t motor, long ticks) {
  float motor_deg = motor_ticks_to_degrees(motor, ticks);
  return motor_deg * enc_multipliers[motor];
}

// ─── Differential wrist: motor encoders → joint angles ──────────────────────
// Joint 4 (pitch) = (motor4_deg + motor5_deg) / 2
// Joint 5 (roll)  = (motor4_deg - motor5_deg) / 2
void diff_wrist_motor_to_joint(float motor4_deg, float motor5_deg,
                                float &joint4_deg, float &joint5_deg) {
  joint4_deg = (motor4_deg + motor5_deg) / 2.0f;
  joint5_deg = (motor4_deg - motor5_deg) / 2.0f;
}

// ─── Get all 5 JOINT positions (degrees) ────────────────────────────────────
// Joints 1-3: direct from encoders with multiplier
// Joints 4-5: differential wrist transform
void get_joint_positions(float joint_deg[NUM_JOINTS]) {
  // Joints 1-3: direct
  for (int i = 0; i < 3; i++) {
    long ticks = encoder_read(i);
    joint_deg[i] = encoder_to_link_degrees(i, ticks);
  }
  // Joints 4-5: differential wrist
  long ticks4 = encoder_read(3);
  long ticks5 = encoder_read(4);
  float mot4_deg = encoder_to_link_degrees(3, ticks4);
  float mot5_deg = encoder_to_link_degrees(4, ticks5);
  diff_wrist_motor_to_joint(mot4_deg, mot5_deg, joint_deg[3], joint_deg[4]);
}

#endif // GRYPHON_ENCODERS_H
