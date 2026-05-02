# Gryphon Firmware

This folder contains the **GRBL v1.0** firmware modified by Angel LM for the Gryphon robotic arm,
adapted here for use with the **Gryphon 5-DOF robotic arm**.

## Source
- Original: [AngelLM/grbl @ v1.0](https://github.com/AngelLM/grbl/releases/tag/v1.0)
- Documentation: [gryphon.angel-lm.com/documentation/firmware](http://gryphon.angel-lm.com/documentation/firmware/)

## Uploading to Arduino Mega

1. Open **Arduino IDE**
2. Go to `Sketch > Include Library > Add .ZIP Library`
   - Navigate to the file: `firmware/grbl_library.zip` and press **Open** 
3. Open the upload sketch:
   - Go to `File > Examples > grbl > grblUpload`
4. Select `Tools > Board > Arduino Mega or Mega 2560`
5. Select correct port under `Tools > Port`
6. Press **Upload**

> **Note:** If you get a "Library already exists" error, you can skip step 2. If you see "NoSuchFileException", make sure you are selecting the `.zip` file itself, not the folder.

## GRBL Axis → Gryphon Joint Mapping

| GRBL Axis | `defaults_gryphon.h` | Gryphon Joint | Motor |
|-----------|-------------------|---------------|-------|
| `A`       | `A_STEPS = 44.5`  | Joint 1 (Waist) | Motor 1 |
| `B`       | `B_STEPS = 270.0` | Joint 2 (Shoulder) | Motor 2 |
| `C`       | `C_STEPS = 270.0` | Joint 2 (Shoulder mirror) | Motor 3 — **must equal B** |
| `D`       | `D_STEPS = 265.0` | Joint 3 (Elbow) | Motor 4 |
| `X`       | `E_STEPS = 20.0`  | Joint 4 (Wrist pitch) | Motor 5 |
| `Y`       | `F_STEPS = 250.0` | Joint 5 (Wrist roll +) | Motor 6 — differential |
| `Z`       | `G_STEPS = 250.0` | Joint 5 (Wrist roll −) | Motor 7 — differential |

> **Note:** B and C must always be sent the same value (dual-motor shoulder joint).
> Y and Z implement a differential wrist where:
> - `Y = art5 + 2*art6`
> - `Z = -art5 + 2*art6`

## Move Command Format

```
G0 A<deg> B<deg> C<deg> D<deg> X<deg> Y<deg> Z<deg>\r\n
```

## Tool (Pneumatic Gripper) Command

```
M3 S255   ← Valve ON (gripper closes)
M5        ← Valve OFF (gripper opens)
```

## Configuration

After flashing, open Serial Monitor at **115200 baud** and send `$$` to verify settings.
To reset to defaults: `$RST=$`

Key settings for Gryphon:
- `$22=1` — Homing enabled
- `$100=44.5` — A steps/mm
- `$101=270.0` — B steps/mm
- `$102=270.0` — C steps/mm
- `$103=265.0` — D steps/mm
- `$104=20.0` — X (E) steps/mm
- `$105=250.0` — Y (F) steps/mm
- `$106=250.0` — Z (G) steps/mm
