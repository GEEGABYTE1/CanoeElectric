
#include <Wire.h> 
#include<IRremote.h>
#include <LiquidCrystal_I2C.h>

int ADXL345 = 0x53; 

float X_out, Y_out, Z_out;
#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED
int LEDPin1 = 13;
int LEDPin2 = 11;
int LEDPin3 = 12;
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
int buzzer = 10;
long duration, distance; 
void setup() {
                    
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


 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(buzzer,OUTPUT);// set digital IO pin pattern, OUTPUT to be output
 pinMode(LEDPin, OUTPUT); 
 pinMode(LEDPin2, OUTPUT);// define pin with LED connected as output.
 pinMode(LEDPin3, OUTPUT);// define pin with LED connected as output.
 pinMode(LEDPin1, OUTPUT);// define pin with LED connected as output.
}
void loop() {

 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);



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

 
 
 //Calculate the distance (in cm) based on the speed of sound.
digitalWrite(buzzer, LOW);
if (pitch > 30) { 
  digitalWrite(LEDPin1, HIGH);
  digitalWrite(LEDPin2, HIGH);
  digitalWrite(LEDPin3, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(500);


} 
  digitalWrite(buzzer, LOW);
  digitalWrite(LEDPin1, LOW);
  digitalWrite(LEDPin2, LOW);
  digitalWrite(LEDPin3, LOW);
  




  



} 
//////////////////////////////////////////////////////////////////
