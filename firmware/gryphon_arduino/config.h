// =============================================================================
// config.h — Gryphon Robot Arm Configuration
// =============================================================================
// All pin assignments, encoder parameters, and tuning constants in one place.
// =============================================================================

#ifndef GRYPHON_CONFIG_H
#define GRYPHON_CONFIG_H

// ─── General ─────────────────────────────────────────────────────────────────
#define NUM_MOTORS        5       // Physical motors (and encoders)
#define NUM_JOINTS        5       // Logical joints for ROS2
// Joints 1-3 map 1:1 to motors 1-3
// Joints 4-5 (differential wrist) map to motors 4-5 via:
//   motor4_target = joint4 + joint5
//   motor5_target = joint4 - joint5
//   joint4_actual = (enc4 + enc5) / 2
//   joint5_actual = (enc4 - enc5) / 2

#define SERIAL_BAUD       115200
#define REPORT_INTERVAL_MS 20     // Periodic encoder report (ms)

// ─── TB6600 Driver Pins ─────────────────────────────────────────────────────
//                        PUL  DIR
#define J1_PUL_PIN        27
#define J1_DIR_PIN        28
#define J2_PUL_PIN        29
#define J2_DIR_PIN        30
#define J3_PUL_PIN        31
#define J3_DIR_PIN        32
#define J4_PUL_PIN        33
#define J4_DIR_PIN        34
#define J5_PUL_PIN        35
#define J5_DIR_PIN        36

// ─── Encoder Pins (Channel A = hardware interrupt) ──────────────────────────
#define ENC1_A_PIN        2    // INT4
#define ENC1_B_PIN        22
#define ENC2_A_PIN        3    // INT5
#define ENC2_B_PIN        23
#define ENC3_A_PIN        18   // INT3
#define ENC3_B_PIN        24
#define ENC4_A_PIN        19   // INT2
#define ENC4_B_PIN        25
#define ENC5_A_PIN        20   // INT1
#define ENC5_B_PIN        26

// ─── Encoder Resolution ─────────────────────────────────────────────────────
// HEDS-9100 A00 = 500 PPR
// With x2 decoding (CHANGE on channel A) = 1000 counts/motor-rev
#define ENCODER_PPR       500
#define ENCODER_CPR       (ENCODER_PPR * 2)  // x2 decoding

// ─── Per-Encoder Multiplier (encoder_degrees = raw_degrees * multiplier) ────
// Use this to calibrate each encoder independently.
// If encoder reads 90° but link actually moved 45° → multiplier = 0.5
// If encoder reads 90° but link actually moved 180° → multiplier = 2.0
// Default 1.0 = no scaling. Tune each one on the real robot.
#define ENC1_MULTIPLIER   1.0f
#define ENC2_MULTIPLIER   1.0f
#define ENC3_MULTIPLIER   1.0f
#define ENC4_MULTIPLIER   1.0f  // Motor 4 (differential wrist)
#define ENC5_MULTIPLIER   1.0f  // Motor 5 (differential wrist)

// ─── TB6600 Microstepping ───────────────────────────────────────────────────
// TODO: Set to match your TB6600 DIP switch setting
// Common: 1, 2, 4, 8, 16, 32
#define MICROSTEPS            8
#define MOTOR_STEPS_PER_REV   200   // Standard 1.8° stepper
#define STEPS_PER_MOTOR_REV   (MOTOR_STEPS_PER_REV * MICROSTEPS)

// ─── Per-Motor Step Multiplier (for step→degree conversion) ─────────────────
// Same idea: how many motor degrees per link degree.
// steps_for_link_angle = (angle / 360) * STEPS_PER_MOTOR_REV * MOT_MULTIPLIER
// Default 1.0 = motor shaft angle == link angle
#define MOT1_MULTIPLIER   1.0f
#define MOT2_MULTIPLIER   1.0f
#define MOT3_MULTIPLIER   1.0f
#define MOT4_MULTIPLIER   1.0f  // Differential motor 4
#define MOT5_MULTIPLIER   1.0f  // Differential motor 5

// ─── Stepper Speed ──────────────────────────────────────────────────────────
#define DEFAULT_STEP_DELAY_US  400   // us between pulses
#define MIN_STEP_DELAY_US      100
#define MAX_STEP_DELAY_US      5000

// ─── Gripper (Relay — ON/OFF) ───────────────────────────────────────────────
// Relay module: HIGH = gripper closed, LOW = gripper open (or invert below)
#define GRIPPER_PIN           42
#define GRIPPER_ACTIVE_HIGH   true  // true = HIGH closes gripper, false = inverted

// ─── Emergency Stop ─────────────────────────────────────────────────────────
#define ESTOP_PIN         43
#define ESTOP_ACTIVE_LOW  true

// ─── Homing — Stall Detection ───────────────────────────────────────────────
#define HOMING_SPEED_DELAY_US  800   // Slow approach speed (us between steps)
#define HOMING_RETURN_DELAY_US 400   // Speed for return-to-zero move
#define STALL_CHECK_STEPS      50    // Check encoder every N steps
#define STALL_THRESHOLD        3     // Ticks below this = stalled
#define HOMING_TIMEOUT_MS      30000

// Per-motor homing direction: false = negative, true = positive
// This is the direction the motor moves to FIND the mechanical stop.
#define HOM1_DIR  true   // Motor 1 moves positive to find stop
#define HOM2_DIR  false
#define HOM3_DIR  false
#define HOM4_DIR  false
#define HOM5_DIR  false

// ─── Homing Stall Angle (degrees) ──────────────────────────────────────────
// The KNOWN angle of the joint when the motor hits its mechanical stop.
// After stall detection, the encoder is set to this angle, then the motor
// moves to 0°.
// Example: motor stalls at the -90° position → set to -90.0
//          motor stalls at the +45° position → set to  45.0
#define HOM1_STALL_ANGLE  -90.0f
#define HOM2_STALL_ANGLE  -90.0f
#define HOM3_STALL_ANGLE  -90.0f
#define HOM4_STALL_ANGLE  -90.0f  // Motor 4 (diff wrist)
#define HOM5_STALL_ANGLE  -90.0f  // Motor 5 (diff wrist)

// ─── Homing Sequence Order ──────────────────────────────────────────────────
// Motors are homed in this order. Motors 4 & 5 (differential wrist) are
// homed together as the last step.
// Sequence: Motor 1 → Motor 2 → Motor 3 → Motors 4+5 together

// ─── Joint Direction Inversion ──────────────────────────────────────────────
#define J1_DIR_INVERT     false
#define J2_DIR_INVERT     false
#define J3_DIR_INVERT     false
#define J4_DIR_INVERT     false
#define J5_DIR_INVERT     false

// ─── Pulse Timing ───────────────────────────────────────────────────────────
#define PULSE_WIDTH_US    5  // HIGH pulse duration for TB6600 (min ~2.5us)

#endif // GRYPHON_CONFIG_H
