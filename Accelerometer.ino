#include <Wire.h>

int ADXL345 = 0x53; 

float X_out, Y_out, Z_out;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin(); 

  Wire.beginTransmission(ADXL345);
  Wire.write(0x2D);
  Wire.write(8);
  Wire.endTransmission();
  delay(10);

  //Off-set Cali
  //x 
  Wire.beginTransmission(ADXL345);
  Wire.write(0x1E);
  Wire.write(1);
  Wire.endTransmission();
  delay(10);

  //y
  Wire.beginTransmission(ADXL345);
  Wire.write(0x1F);
  Wire.write(-2);
  Wire.endTransmission();
  delay(10);

  Wire.beginTransmission(ADXL345);
  Wire.write(0x20);
  Wire.write(-7);
  Wire.endTransmission();
  delay(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32);
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true);
  X_out = (Wire.read() | Wire.read() << 8);
  X_out = X_out/256;
  Y_out = (Wire.read() | Wire.read() << 8);
  Y_out = Y_out/256;
  Z_out = (Wire.read() | Wire.read() << 8);
  Z_out = Z_out/256;

  float roll = atan(Y_out / sqrt(pow(X_out, 2) + pow(Z_out, 2))) * 180 / PI;
  float pitch = atan(-1 * X_out / sqrt(pow(Y_out, 2) + pow(Z_out, 2))) * 180 / PI;
  Serial.println("Roll: ");
  Serial.print(roll);
  Serial.println("Pitch: ");
  Serial.print(pitch);
  delay(1000);
}
