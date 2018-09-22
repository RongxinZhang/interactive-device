# Paper Puppets

*A lab report by Rongxin Zhang rz345*

## In this Report

## Part A. Actuating DC motors

[![](http://img.youtube.com/vi/5wUcJ2sIu-U/0.jpg)](https://youtu.be/5wUcJ2sIu-U)

```java
/*
  Vibration Code
*/

int led = 9;
int vibration = 0;
int vibrateAmount = 5;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  analogWrite(led, vibration);

  vibration = vibration + vibrateAmount;

  if (vibration <= 0 || vibration >= 255) {
    vibrateAmount = -vibrateAmount;
  }
  delay(30);
}
```

## Part B. Actuating Servo motors

### Part 1. Connect the Servo to your breadboard

Signal = Orange
Power = Red
Ground = Brown

reference: https://www.arduino.cc/en/Tutorial/Sweep

### Part 2. Connect the Servo to your Arduino

**a. Which Arduino pin should the signal line of the servo be attached to?**

`Pin 9` provides the signals to change the motor's rotation

The below code updates the speed of sweeping and angle of rotation.

[![](http://img.youtube.com/vi/Zds3OSF1iPg/0.jpg)](https://youtu.be/Zds3OSF1iPg)


**b. What aspects of the Servo code control angle or speed?**

The speed is controlled by the `delay()` function and the max value in the `for` loop determines the rotation angle

```java
/*
  Sweep
*/
#include <Servo.h>
Servo myservo;

int pos = 0;

void setup() {
  myservo.attach(9);
}

void loop() {
  int sweepAngle = 90; // Update sweep angle
  int wait = 5;// Update sweep speed

  for (pos = 0; pos <= sweepAngle; pos += 1) {
    myservo.write(pos);
    delay(wait);
  }
  for (pos = sweepAngle; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(wait);
  }
}
```

## Part C. Integrating input and output

I attached a rotary encoder to the servo such that the rotation of the rotar changes the rotation of the servo. [Full code](./servo-protentiometer/servo-protentiometer.ino) attached.

[![](http://img.youtube.com/vi/hUcMVFdc2nE/0.jpg)](https://youtu.be/hUcMVFdc2nE)

## Part D. Paper puppet

**a. Make a video of your proto puppet.**

## Part E. Make it your own

**a. Make a video of your final design.**
