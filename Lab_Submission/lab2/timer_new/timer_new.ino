#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define ENC_A 8 //these need to be digital input pins
#define ENC_B 7

// constants won't change. They're used here to set pin numbers:
#define BTN 10     // the number of the pushbutton pin     // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int prevState = 0;
bool clicked = false;

int timersToCount = 0;
 
void setup()
{
  /* Setup encoder pins as inputs */
 
  lcd.begin(16, 2);

  pinMode(BTN, INPUT);
  
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
 
  Serial.begin (9600);
  Serial.println("Start");
   
  lcd.clear();
}
 
void loop() {
  lcd.setCursor(0, 0);
  static unsigned int counter4x = 0;      //the SparkFun encoders jump by 4 states from detent to detent
  static unsigned int counter = 0;
  static unsigned int prevCounter = 0;
  int tmpdata;
  tmpdata = read_encoder();
  if(tmpdata && clicked == false) {
    counter4x += tmpdata;
    counter = counter4x/4;
    if (prevCounter != counter){
      Serial.print("Counter value: ");
      Serial.println(counter);
      lcd.print(counter);
    }
    prevCounter = counter;
  }
  
  buttonState = digitalRead(BTN);
  
  if (buttonState != prevState && clicked == false){
    if (buttonState == HIGH) {
      Serial.print("Click: ");
      Serial.println(buttonState);
      prevState = buttonState;
      clicked = true;
      timersToCount = counter;
      lcd.print("Time set: ");
      lcd.print(timersToCount);
    }
  }
}

void startCountDown(){
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  int secondsRemaining = timersToCount - millis() / 1000;

  if (secondsRemaining > 0){
    lcd.print(secondsRemaining);
  } else {
    lcd.print("Are you Ready!");
  }

  if (secondsRemaining % 10 == 0){
    lcd.clear();
  }
}
 
/* returns change in encoder state (-1,0,1) */
int read_encoder()
{
  static int enc_states[] = {
    0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0  };
  static byte ABab = 0;
  ABab *= 4;                   //shift the old values over 2 bits
  ABab = ABab%16;      //keeps only bits 0-3
  ABab += 2*digitalRead(ENC_A)+digitalRead(ENC_B); //adds enc_a and enc_b values to bits 1 and 0
  return ( enc_states[ABab]);
}
