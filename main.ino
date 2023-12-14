// Created by: Jaden Plugowsky
// Created on: Oct 2023
//
// This is a circuit with an ultrasonic distance sensor
//   that moves a servo under a certain distance.

#include <Servo.h>

Servo servoNumber1;

int pin5 = 5;
int trigPin = 10;
int echoPin = 9;
float duration, distance; 

void setup() {
    // Setup distance sensor
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);

    // Setup servo
    servoNumber1.attach(pin5);
    servoNumber1.write(0); // Default servo position
}

void loop() {
    // Send pulse of sound out.
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Calculate distance between object.
    duration = pulseIn(echoPin, HIGH);
    distance = (duration*.0343)/2;

    // Print to serial monitor.
    Serial.print("Distance: ");
    Serial.println(distance);

    if (distance < 50) {
        servoNumber1.write(180); // 180 degrees
        delay(1000); // Wait for 1000 millisecond(s)
        servoNumber1.write(0); // 0 degrees
        delay(1000); // Wait for 1000 millisecond(s)
    }

    delay(100);
}
