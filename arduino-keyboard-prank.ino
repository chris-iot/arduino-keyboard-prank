#include "Keyboard.h"
#include <avr/pgmspace.h>  
//This sketch is intended for an Arduino Due...
//
//It is loosely inspired by
//https://learn.adafruit.com/trinket-usb-keyboard/prank-example
//https://github.com/EngineerTony/Arduino_USBKeyboard_Hacker/blob/master/keyboard_hacker.ino

const int buttonPin = 4;          // input pin for pushbutton
int previousButtonState = HIGH;   // for checking the state of a pushButton

const char string1[] = {"  LOOK OUT BEHIND YOU!!!  "};
const char string2[] = {"Der kleine Jens möchte aus dem Bällchenparadies abgeholt werden..."};
const char string3[] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
const char string4[] = {" *insert toilet joke here* "};
const char string5[] = {"aaaaAAAAaaaa"};
const char string6[] = {"qwertyuiop"};
const char string7[] = {"Nachricht an den Typen, der mir meine Daunenjacke gestohlen hat: Du kannst dich warm anziehen!"};
const char string8[] = {" :D "};
const char string9[] = {" :P Happy April Fools ;P "};
const char* const stringTable[] =
{
 string1, string2, string3, string4, string5, string6, string7,
 string8, string9 };

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT);
  // initialize control over the keyboard:
  Keyboard.begin();
  randomSeed(analogRead(0));
  delay(200);
}

void loop() {
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin);
  // if the button state has changed and it's currently pressed:
  if ((buttonState != previousButtonState) && (buttonState == HIGH)) {
    unsigned long secs_to_wait = random(10000, 60000); // generate a random amount of time (10..60sec.)
    int randomString = random(1, 9); //choose a random message between 1 and 9
    delay(secs_to_wait);
    Keyboard.print(stringTable[randomString]);
  }
  // save the current button state for comparison next time:
  previousButtonState = buttonState;
}
