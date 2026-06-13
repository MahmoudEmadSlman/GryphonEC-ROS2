# Gryphon Firmware

Custom Arduino Mega firmware for the **Gryphon 5-DOF robotic arm** with **closed-loop encoder feedback**.

Replaces the old GRBL-based firmware with a simpler, purpose-built solution featuring:
- 5× TB6600 stepper motor drivers (PUL/DIR control)
- 5× HEDS-9100 incremental encoders (500 PPR, x2 quadrature decoding)
- Differential wrist (Motors 4 & 5)
- Stall-detection homing with configurable stall angles
- Relay-based gripper (ON/OFF)
- Per-encoder and per-motor multipliers for calibration

## Files

| File | Description |
|------|-------------|
| `gryphon_arduino.ino` | Main sketch — serial protocol, command parser, position reporting |
| `config.h` | All pin assignments, encoder PPR, multipliers, homing params |
| `encoders.h` | Quadrature encoder reading via hardware interrupts |
| `steppers.h` | Non-blocking TB6600 stepper control |
| `homing.h` | Stall-detection homing with return-to-zero sequence |

## Pin Mapping

### TB6600 Drivers

| Joint | PUL | DIR |
|-------|-----|-----|
| 1 (Waist) | 27 | 28 |
| 2 (Shoulder) | 29 | 30 |
| 3 (Elbow) | 31 | 32 |
| 4 (Diff Wrist) | 33 | 34 |
| 5 (Diff Wrist) | 35 | 36 |

### Encoders (HEDS-9100 A00, 500 PPR)

| Encoder | Ch A (interrupt) | Ch B |
|---------|-----------------|------|
| 1 | 2 (INT4) | 22 |
| 2 | 3 (INT5) | 23 |
| 3 | 18 (INT3) | 24 |
| 4 | 19 (INT2) | 25 |
| 5 | 20 (INT1) | 26 |

### Other

| Function | Pin |
|----------|-----|
| Gripper Relay | 42 |
| Emergency Stop | 43 |

## Serial Protocol (115200 baud)

### Commands (ROS2 → Arduino)

| Command | Description |
|---------|-------------|
| `MOV:<d1>,<d2>,<d3>,<d4>,<d5>` | Move joints to target (degrees) |
| `HOM:ALL` | Home all motors (sequence: 1→2→3→4+5) |
| `HOM:<id>` | Home single motor (0–4) |
| `STP` | Emergency stop |
| `RST` | Reset all encoder/step counters |
| `GRP:<0\|1>` | Gripper relay OFF/ON |
| `SPD:<id>,<delay_us>` | Set step speed for a motor |
| `MUL:E<id>,<val>` | Set encoder multiplier at runtime |
| `MUL:M<id>,<val>` | Set motor multiplier at runtime |
| `GET` | Request position report |

### Responses (Arduino → ROS2)

| Response | Description |
|----------|-------------|
| `POS:<d1>,<d2>,<d3>,<d4>,<d5>` | Joint positions in degrees (sent every 20ms) |
| `OK` | Command acknowledged |
| `HMD:<id>` / `HMD:ALL` | Homing complete |
| `ERR:<msg>` | Error message |
| `RDY` | Arduino boot complete |

## Uploading to Arduino Mega

1. Open **Arduino IDE**
2. Open `firmware/gryphon_arduino/gryphon_arduino.ino`
3. Select `Tools > Board > Arduino Mega or Mega 2560`
4. Select correct port under `Tools > Port`
5. Press **Upload**

## Calibration

1. Upload the firmware
2. Open Serial Monitor at **115200 baud**
3. Manually rotate each joint exactly **90°**
4. Read the `POS:` value for that joint
5. Calculate multiplier: `multiplier = 90.0 / reported_value`
6. Set via serial: `MUL:E0,<multiplier>` (for encoder 0)
7. Once confirmed, update the values in `config.h` and re-upload

## Homing Sequence

Each motor homes individually (Motor 1 → 2 → 3 → 4+5 together):

1. **Find stall**: Motor moves slowly until encoder stops changing (mechanical stop)
2. **Set angle**: Encoder counter is set to the configured stall angle (e.g., −90°)
3. **Return to zero**: Motor moves to 0° using encoder feedback
