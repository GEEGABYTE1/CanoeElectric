# Canoeing Synchronicity Enhancement System

## Overview
This project aims to enhance canoeing synchronicity by providing a system that alerts paddlers when their paddle approaches the water surface. The system utilizes an ultrasonic sensor to detect the water level and emits an audible signal through a buzzer. Additionally, an IR remote control allows users to adjust the frequency of the buzzer based on their preferences.

Project will be presented at Showcase for Praxis II.

## Components Used
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- IR Receiver Module
- IR Remote Control
- Buzzer
- 16x2 LCD Display with I2C Backpack
- Resistors
- Breadboard and Jumper Wires

## Functionality
- The ultrasonic sensor measures the distance to the water surface.
- When the paddle approaches the water, the sensor detects the reduced distance and triggers the buzzer to emit an audible signal.
- An IR remote control allows users to adjust the frequency of the buzzer sound based on their hearing preferences.
- The 16x2 LCD display provides visual feedback by displaying the current water level distance and system status.

## Wiring
- Connect the HC-SR04 ultrasonic sensor to the Arduino as follows:
  - VCC to 5V
  - Trig to pin 8
  - Echo to pin 7
  - GND to GND
- Connect the IR receiver module to the Arduino:
  - Signal pin to pin 11
  - VCC to 5V
  - GND to GND
- Connect the buzzer to pin 13.
- Connect the 16x2 LCD display via I2C:
  - SDA to A4
  - SCL to A5
  - VCC to 5V
  - GND to GND

## Operation
1. Upload the provided Arduino sketch to the Arduino board.
2. Ensure all components are connected correctly.
3. Power on the Arduino.
4. Use the IR remote control to adjust the frequency of the buzzer sound based on your hearing preferences.
5. As the paddle approaches the water, the buzzer will emit an audible signal.
6. The LCD display provides visual feedback by showing the current water level distance and system status.

## Important Notes
- Calibrate the ultrasonic sensor for accurate distance measurements based on sound though not the best choice.
- Circuit images coming soon.
- Wiring and casing need to be done. 
- Customize the IR remote control codes and actions as needed.
- Ensure the system is securely attached to the paddle and does not interfere with paddling movements.

