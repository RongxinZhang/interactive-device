# IDD-Fa18-Lab1: Blink!

A lab report by **Rongxin Zhang (rz345)**

## Part A. Set Up a Breadboard

![a relative link](./assets/lab1.JPG)

## Part B. Manually Blink a LED

**a. What color stripes are on a 220 Ohm resistor?**

Red(2), Red(2), Black(0), Black(x1Ohm), Brown(+- 1%)

**b. What do you have to do to light your LED?**

I needed to push down the the button that connects the board and the LED.

[reference](https://github.com/FAR-Lab/Developing-and-Designing-Interactive-Devices/blob/docs/button_led_resistor_diagram.png)

## Part C. Blink a LED using Arduino

### 1. Blink the on-board LED

**a. What line(s) of code do you need to change to make the LED blink (like, at all)?**

Simply change the output pin to a port instead of the default `LED_BUILTIN`.

```
pinMode(3, OUTPUT);
```

**b. What line(s) of code do you need to change to change the rate of blinking?**

Change the delay function `delay();` which lowers or increases the time in between the voltage updates.

**c. What circuit element would you want to add to protect the board and external LED?**

You can add resistors to protect the LED or board as it limits the amount of current that can go through a particular point.

**d. At what delay can you no longer *perceive* the LED blinking? How can you prove to yourself that it is, in fact, still blinking?**

When the delay is `15 milliseconds`, it is difficult to figure out whether the light is still blinking. However, I know for sure the light is blinking based on my code, which specifies adjustments to the voltage.

**e. Modify the code to make your LED blink your way. Save your new blink code to your lab 1 repository, with a link on the README.md.**

My custom blink function uses a random number generator to create the wait time between the HIGH and LOW voltages.

[Custom Blink Code](./code.ino)

```java

/*
  Random Blink
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
  waitTime= random(MIN_WAIT, MAX_WAIT)

  digitalWrite(PIN, HIGH);
  delay(waitTime);
  digitalWrite(PIN, LOW);
  delay(waitTime);
}
```

[Reference](https://www.arduino.cc/reference/en/language/functions/random-numbers/random/)

### 2. Blink your LED

**Make a video of your LED blinking, and add it to your lab submission.**

NOTE: Click on image for video

[![](http://img.youtube.com/vi/2HoYjsD-I6s/0.jpg)](https://youtu.be/2HoYjsD-I6s)


Original video file located in: `lab1/assets/partc_blink.MOV`


## Part D. Manually fade an LED

**a. Are you able to get the LED to glow the whole turning range of the potentiometer? Why or why not?**

Yes, I was able to get the potentiometer to work. The potentiometer is essence a 3 pin resistor. There is a resistive material inside such that when I turn the knob, it increases the distance between the connective strip and the wire. The further away the knob (second pin) is from the power input, the lesser voltage can go across. By connecting the first pin to power and the second pin to the input of the LED. I am able to adjust the voltage that moves across the LED.

![bright](assets/partd_bright.JPG)
Bright

![dim](assets/partd_dim.JPG)
Dim

[reference](https://en.wikipedia.org/wiki/Potentiometer)

## Part E. Fade an LED using Arduino

**a. What do you have to modify to make the code control the circuit you've built on your breadboard?**

We need to replace `DigitalWrite` with the below code.

```java
// output is a value between 0 and 255
analogWrite(32, output);
```

[AnalogueWrite Code](./code-analogueWrite.ino)

**b. What is analogWrite()? How is that different than digitalWrite()?**

AnalogueWrite sends an analog voltage using PWN (pulse-width modulation) to specific pins with a value between 0 and 255. As a result, it gives one fine grained control over how much voltage can go across. DigitalWrite on the other hand only provides 2 values, HIGH and LOW where `HIGH=5V` and `LOW=0V`.

[reference](https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/)

[reference](https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM)

## Part F. FRANKENLIGHT!!!

### 1. Take apart your electronic device, and draw a schematic of what is inside.

I took apart an ergonomic mouse.

![dim](assets/partf_mouse_whole.JPG)
Mouse disassembled

![dim](assets/partf_board1.png)
Main board, front and back

![dim](assets/partf_board2.png)
Secondary boards, front and back

![dim](assets/partf_schematic_copy.png)
Secondary boards, front and back

I was not able to make all the connections, especially for the resistors as the circuit appears to be multi-layers where some connections are not visible. As a result, I simply showed the connections and all the components that I can physically see .

**a. Is there computation in your device? Where is it? What do you think is happening inside the "computer?"**

There is a small micro-controller in the mouse. It's main goal should be to convert analogue signals into digital and send it through bluetooth signals. The key analogue signals come from 3 sources:

1. button clicks from left and right mouse.
2. scrollers in the middle of the mouse
3. location tracking received from the laser tracker at the bottom of the mouse.

**b. Are there sensors on your device? How do they work? How is the sensed information conveyed to other portions of the device?**

Information is transferred in the following parts:

1. button clicks is a simple one and off switch. Information are transferred to a central Chip-on-board processor that then is able transcodes the information into digital data.

**c. How is the device powered? Is there any transformation or regulation of the power? How is that done? What voltages are used throughout the system?**

The device is powered by two 1.5V batteries.

**d. Is information stored in your device? Where? How?**

The device does not appear to store state. Furthermore, it is a uni-directional interaction. The device only sends information to the computer.

### 2. Using your schematic, figure out where a good point would be to hijack your device and implant an LED.

The section closest to the power switch is a great place for an LED. Currently, there is no LED there and it is directly connected to ground. ![dim](assets/partf_schematic_LED_new.png)Â

### 3. Build your light!

NOTE: Click on image for video

[![](http://img.youtube.com/vi/T2mMk329U0o/0.jpg)](https://youtu.be/T2mMk329U0o)

Original video file located in: `lab1/assets/partf_light.MOV`

