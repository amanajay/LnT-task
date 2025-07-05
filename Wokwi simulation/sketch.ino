
#include <Wire.h>
#include <U8g2lib.h>

const int MPU = 0x68;
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  // Wake up MPU6050
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  // OLED
  u8g2.begin();
  u8g2.setFont(u8g2_font_6x10_tr);
}

void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 14, true);

  ax = Wire.read() << 8 | Wire.read();
  ay = Wire.read() << 8 | Wire.read();
  az = Wire.read() << 8 | Wire.read();
  Wire.read(); Wire.read();
  gx = Wire.read() << 8 | Wire.read();
  gy = Wire.read() << 8 | Wire.read();
  gz = Wire.read() << 8 | Wire.read();

  float accX = ax / 16384.0;
  float accY = ay / 16384.0;
  float accZ = az / 16384.0;
  float gyroX = gx / 131.0;
  float gyroY = gy / 131.0;

  // Display on OLED with offset
  u8g2.clearBuffer();
  int x = 2;  // Offset to prevent left-edge clipping
  u8g2.setCursor(x, 12); u8g2.print("Ax: "); u8g2.print(accX, 2);
  u8g2.setCursor(x, 22); u8g2.print("Ay: "); u8g2.print(accY, 2);
  u8g2.setCursor(x, 32); u8g2.print("Az: "); u8g2.print(accZ, 2);
  u8g2.setCursor(x, 42); u8g2.print("Gx: "); u8g2.print(gyroX, 2);
  u8g2.setCursor(x, 52); u8g2.print("Gy: "); u8g2.print(gyroY, 2);
  u8g2.setCursor(x, 62); u8g2.print("Gz: "); u8g2.print(gz / 131.0, 2);
  u8g2.sendBuffer();

  delay(200);
}
