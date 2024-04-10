
#include <Wire.h> 
#include<IRremote.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int IRPIN = 11;
IRrecv irrecv(IRPIN);
decode_results results;
#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED
int LEDPin1 = 10;
int LEDPin2 = 11;
int LEDPin3 = 12;
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
int buzzer = 9;
long duration, distance; 
void setup() {
 lcd.init();                      
 Serial.begin(9600);
 Serial.println("Enabling the IR Remote: ");
 irrecv.enableIRIn();

 lcd.backlight();
 lcd.setCursor(3,0);
 lcd.print("Distance is:  ");
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
 
 //Calculate the distance (in cm) based on the speed of sound.
digitalWrite(buzzer, LOW);
distance = duration/58.2;
if (distance >= maximumRange || distance <= minimumRange){
 
  lcd.setCursor(3,1);
  lcd.print("-1   ");
 digitalWrite(LEDPin, HIGH); 
 }
 else {
 
  lcd.setCursor(3,1);
  lcd.print(distance);
 digitalWrite(LEDPin, LOW); 
 }
 if(distance<10)
 {
  lcd.setCursor(4,1);
  lcd.print("    ");
}
 if(distance<100)
 {
  lcd.setCursor(5,1);
  lcd.print("    ");
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  digitalWrite(LEDPin1, HIGH);
  digitalWrite(LEDPin2, HIGH);
  digitalWrite(LEDPin3, HIGH);
  delay(100);
} else {
    digitalWrite(buzzer, LOW);
  digitalWrite(LEDPin1, HIGH);
  digitalWrite(LEDPin2, HIGH);
  digitalWrite(LEDPin3, HIGH);
}


  if (irrecv.decode(&results)) {
    
    Serial.println(results.value);
    if(results.value == 5316027) {
      Serial.println("You pressed up");
      
      
    } 
    
    if (results.value == 16754775) {
      Serial.println("You have pressed down");
      
    }
    
  }
  

irrecv.resume();

 delay(100);
} 
//////////////////////////////////////////////////////////////////
