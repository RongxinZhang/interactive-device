#include <Servo.h> 

#define servoPin  9
#define switchPin 2

#define closePos  00
#define openPos   180

Servo servo;
int switchState;
int previousSwitchState;

void ToggleSwitch(int switchState)
{    
  if (switchState == HIGH)
  {
    servo.write(openPos);
  }
  else
  {
    servo.write(closePos);
  }
  previousSwitchState = switchState;  // remember that the switch state has changed 
}

void setup()
{
 
  switchState = LOW;
  previousSwitchState = LOW;

  servo.attach(servoPin);
  servo.write(closePos);

  // we should probably pay attention to the switch
  pinMode(switchPin, INPUT); 
}

void loop()
{ 
  int switchState = digitalRead(switchPin);
  if (switchState != previousSwitchState)
    ToggleSwitch(switchState);

  delay(20);
}
