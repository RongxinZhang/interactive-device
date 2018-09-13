int redPin = 0;
int greenPin = 1;
int bluePin = 2;
 
//uncomment this line if using a Common Anode LED
#define COMMON_ANODE
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  Serial.begin(9600);
}
 
void loop()
{
  int val = analogRead(A0);
  Serial.println(val);
  if (val > 850) {
    setColor(0, 255, 0);  // aqua
  }
  
  if (val > 50 && val < 850) {
    setColor(0, 0, 255);  // aqua
  }
  
  if (val < 50) {
    setColor(255, 0, 0);  // red 
  }
}
 
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
