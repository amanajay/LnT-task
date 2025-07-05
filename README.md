# Arduino MPU6050 + SH1106 OLED Project

This project reads real-time **accelerometer** and **gyroscope** data from the MPU6050 sensor and displays the readings on a **1.3" SH1106 128x64 OLED** screen using the **U8g2** graphics library.

---

## Components Required

- Arduino UNO
- MPU6050 (Accelerometer + Gyroscope)
- SH1106 128x64 I2C OLED Display
- Jumper wires
- Breadboard (optional)

---

## Circuit Connections

| **MPU6050** | Arduino UNO |
|-------------|-------------|
| VCC         | 3.3V or 5V  |
| GND         | GND         |
| SDA         | A4          |
| SCL         | A5          |

| **SH1106 OLED** | Arduino UNO |
|------------------|-------------|
| VCC              | 3.3V or 5V  |
| GND              | GND         |
| SDA              | A4          |
| SCL              | A5          |
---

## Arduino Libraries Used

Install these libraries via the **Arduino Library Manager**:

- [`U8g2`](https://github.com/olikraus/u8g2) by olikraus
- `Wire.h` (built-in)
- No external MPU6050 library required (we use low-level I2C)

---

## Project Features

- Initializes MPU6050 manually over I2C
- Displays real-time values of:
  - Accelerometer X, Y, Z (in Gs)
  - Gyroscope X, Y (in degrees/second)
- Uses `U8g2` to display clean, readable text on OLED
- Serial Monitor also shows the same output

---

## 🧪 Example Output

### OLED Display:
