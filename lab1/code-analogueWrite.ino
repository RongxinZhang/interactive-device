/*
  Custom Blink
*/
const int PIN= 3;

const int MIN_WAIT= 15;
const int MAX_WAIT= 1000;

void setup() {
  pinMode(PIN, OUTPUT);

  // Create a random seed based on some value
  randomSeed(analogRead(0));
}

void loop() {
  // Create a random wait value
  int waitTime= random(MIN_WAIT, MAX_WAIT);

  analogWrite(PIN, random(1, 255));
  delay(waitTime);
  analogWrite(PIN, 0);
  delay(waitTime);
}