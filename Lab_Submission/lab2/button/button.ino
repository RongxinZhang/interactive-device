

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 10;     // the number of the pushbutton pin     // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int prevState = 0;
bool clicked = false;

void setup() {
  // initialize the LED pin as an output:
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin (9600);
  Serial.println("Start");
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  if (buttonState != prevState && clicked == false){
    if (buttonState == HIGH) {
      Serial.print("Click: ");
      Serial.println(buttonState);
      prevState = buttonState;
      clicked = true;
    }
  }
}
