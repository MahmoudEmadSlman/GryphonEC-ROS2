// =============================================================================
// config.h — Gryphon Robot Arm Configuration (Open-Loop)
// =============================================================================
// All pin assignments and tuning constants in one place.
// No encoders — pure open-loop stepper control.
// =============================================================================

#ifndef GRYPHON_CONFIG_H
#define GRYPHON_CONFIG_H

// ─── General ─────────────────────────────────────────────────────────────────
#define NUM_MOTORS 5 // Physical motors
#define NUM_JOINTS 5 // Logical joints for ROS2
// Joints 1-3 map 1:1 to motors 1-3
// Joints 4-5 (differential wrist):
//   J4 = angle where BOTH motors 4 & 5 move in the SAME direction
//   J5 = angle where motors 4 & 5 move in OPPOSITE directions
//
//   Motor targets from joint commands:
//     motor4 = J4 + J5
//     motor5 = J4 - J5
//
//   Joint positions from motor positions:
//     J4 = (motor4 + motor5) / 2
//     J5 = (motor4 - motor5) / 2

#define SERIAL_BAUD 115200
#define REPORT_INTERVAL_MS 20 // Periodic position report (ms)

// ─── TB6600 Driver Pins ─────────────────────────────────────────────────────
//                        PUL  DIR
#define J1_PUL_PIN 31
#define J1_DIR_PIN 32
#define J2_PUL_PIN 35
#define J2_DIR_PIN 40
#define J3_PUL_PIN 33
#define J3_DIR_PIN 34
#define J4_PUL_PIN 27
#define J4_DIR_PIN 28
#define J5_PUL_PIN 29
#define J5_DIR_PIN 30

// ─── TB6600 Microstepping ───────────────────────────────────────────────────
// Set to match your TB6600 DIP switch setting (1,2,4,8,16,32)
#define MICROSTEPS 8
#define MOTOR_STEPS_PER_REV 200 // Standard 1.8° stepper
#define STEPS_PER_MOTOR_REV (MOTOR_STEPS_PER_REV * MICROSTEPS) // 1600

// ─── Per-Motor Step Multiplier ───────────────────────────────────────────────
// Accounts for gearbox ratio between motor shaft and joint link.
// steps_for_angle = (angle / 360) * STEPS_PER_MOTOR_REV * MOT_MULTIPLIER
// Example: 50:1 gearbox → MOT_MULTIPLIER = 50.0
// Default 1.0 = motor shaft angle == link angle (no gearbox)
#define MOT1_MULTIPLIER 40.0f
#define MOT2_MULTIPLIER 50.0f
#define MOT3_MULTIPLIER 30.0f
#define MOT4_MULTIPLIER 12.0f // Differential wrist motor 4
#define MOT5_MULTIPLIER 24.0f // Differential wrist motor 5

// ─── Joint Angle Multiplier (Step Position → Real Joint Degrees) ─────────────
// After moving N steps, the firmware computes a "motor angle" from steps.
// This multiplier converts that motor angle to the REAL joint angle reported
// to ROS2, compensating for any mechanical ratio or calibration offset.
//
//   reported_joint_deg = motor_deg_from_steps * JOINT_ANGLE_MULTIPLIER
//
// Example: motor turns 360° but link only moves 180° → multiplier = 0.5
// Example: motor turns 360° but link moves 720°     → multiplier = 2.0
// Default 1.0 = no correction needed
#define JOINT1_ANGLE_MULT 1.0f
#define JOINT2_ANGLE_MULT 1.0f
#define JOINT3_ANGLE_MULT 1.0f
#define JOINT4_ANGLE_MULT 1.0f // Applied AFTER differential wrist transform
#define JOINT5_ANGLE_MULT 1.0f // Applied AFTER differential wrist transform

// ─── Stepper Speed ──────────────────────────────────────────────────────────
#define DEFAULT_STEP_DELAY_US 400 // µs between pulses (lower = faster)
#define MIN_STEP_DELAY_US 100
#define MAX_STEP_DELAY_US 5000

// ─── Joint Direction Inversion ──────────────────────────────────────────────
#define J1_DIR_INVERT false
#define J2_DIR_INVERT true
#define J3_DIR_INVERT true
#define J4_DIR_INVERT true
#define J5_DIR_INVERT                                                          \
  false // Motor 5 is physically reversed — invert to match motor 4

// ─── Pulse Timing ───────────────────────────────────────────────────────────
#define PULSE_WIDTH_US 5 // HIGH pulse duration for TB6600 (min ~2.5µs)

// ─── Gripper (Relay — ON/OFF) ───────────────────────────────────────────────
#define GRIPPER_PIN 42
#define GRIPPER_ACTIVE_HIGH true // true = HIGH closes gripper

// ─── Gripper Relay (pin 36) ──────────────────────────────────────────────────
// HIGH when gripper is closed (≥ 50%), LOW when open (< 50%).
// For a binary ON/OFF gripper: closed = 100%, open = 0%.
#define RELAY_PIN 36
#define RELAY_CLOSED_THRESHOLD 50 // percent (0-100)

// ─── Emergency Stop ─────────────────────────────────────────────────────────
#define ESTOP_PIN 43
#define ESTOP_ACTIVE_LOW true

// ─── Current Sensor ─────────────────────────────────────────────────────────
#define CURRENT_SENSOR_PIN A0
// Stall detection thresholds — one per motor (ADC counts, 0-1023).
// Tune each independently based on observed SEN AVG values during stall.
// idle~563, moving~572, stall~577+ (typical). Raise if false triggers.
#define STALL_THRESHOLD1  575  // Motor 1 — BASE
#define STALL_THRESHOLD2  577  // Motor 2 — SHOULDER
#define STALL_THRESHOLD3  577  // Motor 3 — ELBOW
#define STALL_THRESHOLD4  577  // Motor 4 — WRIST A
#define STALL_THRESHOLD5  577  // Motor 5 — WRIST B
#define STALL_THRESHOLD   577  // General threshold — used by runtime WRN:STALL in loop()
#define STALL_COUNT 5          // consecutive samples needed (~100ms at 20ms/sample)

// ─── Stall-Based Auto Homing ─────────────────────────────────────────────────
// After each motor hits its mechanical stop (stall detected via current
// sensor), it backs off by HOME_OFFSETx_DEG to reach the defined zero (home)
// position. Negative = back away from stop (most common). 0.0 = stop itself is
// home.
#define HOME_OFFSET1_DEG 0.0f // Motor 1 (waist)   — tune per robot
#define HOME_OFFSET2_DEG 0.0f // Motor 2 (shoulder)
#define HOME_OFFSET3_DEG -145.0f // Motor 3 (elbow)
#define HOME_OFFSET4_DEG 0.0f // Motor 4 (wrist A)
#define HOME_OFFSET5_DEG 0.0f // Motor 5 (wrist B)

// Safety timeout per motor (ms). If stall not detected, stop anyway.
#define HOMING_TIMEOUT_MS 15000

// ─── Homing ─────────────────────────────────────────────────────────────────
// Direction each motor moves to reach its mechanical stop.
// true = positive direction, false = negative direction.
#define HOM1_DIR true
#define HOM2_DIR false
#define HOM3_DIR true
#define HOM4_DIR false
#define HOM5_DIR false

// Number of steps to drive toward the stop (open-loop — no encoder feedback).
// Set high enough that the motor definitely reaches the stop even in the worst
// case. Motor will lightly grind at the stop for the remaining steps — keep
// HOMING_SPEED_DELAY_US slow to avoid damage.
#define HOM1_STEPS 10000
#define HOM2_STEPS 10000
#define HOM3_STEPS 10000
#define HOM4_STEPS 10000
#define HOM5_STEPS 10000

// Step delay during homing (µs) — slow to reduce grind force at stop.
#define HOMING_SPEED_DELAY_US 800

#endif // GRYPHON_CONFIG_H
