
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
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; /
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
 pinMode(LEDPin, OUTPUT); 
}
void loop() {

 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
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
