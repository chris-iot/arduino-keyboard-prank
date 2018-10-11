#include "Keyboard.h"
#include <avr/pgmspace.h>  
//This sketch is intended for an Arduino Due...
//
//It is loosely inspired by
//https://learn.adafruit.com/trinket-usb-keyboard/prank-example
//https://github.com/EngineerTony/Arduino_USBKeyboard_Hacker/blob/master/keyboard_hacker.ino

const int buttonPin = 6;          // input pin for pushbutton
const int normalPin = 7;
const int guttenbergPin = 8;
int pinmode = 0;

const char string1[] = {"xyzxyzxyzxyzxyzxyz"};
const char string2[] = {"Der kleine Jens möchte aus dem Bällchenparadies abgeholt werden..."};
const char string3[] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
const char string4[] = {"Wir braucen Eier, Eier brauchen wir!!"};
const char string5[] = {"aaaaAAAAaaaa"};
const char string6[] = {"qwertyuiop"};
const char string7[] = {"Nachricht an den Typen, der mir meine Daunenjacke gestohlen hat: Du kannst dich warm anziehen!"};
const char string8[] = {"Zweite Kasse bitte!"};
const char string9[] = {"Ich weiß, was du im letzen TAZ verbrochen hast...!"};
const char* const stringTable[] =
{
 string1, string2, string3, string4, string5, string6, string7,
 string8, string9 };

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT);
  pinMode(normalPin, OUTPUT);
  digitalWrite(normalPin, LOW);
  pinMode(guttenbergPin, OUTPUT);
  digitalWrite(guttenbergPin, LOW);
  // initialize control over the keyboard:
  Keyboard.begin();
  randomSeed(analogRead(0));
  delay(200);
  digitalWrite(normalPin, HIGH);
  if(digitalRead(buttonPin)){
    pinmode = 1; //normal (non Guttenberg) mode
    digitalWrite(normalPin, LOW);
  }else{
    digitalWrite(normalPin, LOW);
    digitalWrite(guttenbergPin, HIGH);
    if(digitalRead(buttonPin)){
      pinmode = 2; //Guttenberg mode
    }
    digitalWrite(guttenbergPin, LOW);
  }
}

void loop() {
  // read the pushbutton:
  if (pinmode != 0) {
    unsigned long secs_to_wait = random(1000, 15000); // generate a random amount of time (1..15sec.)
    int randomString = random(1, 9); //choose a random message between 1 and 9
    delay(secs_to_wait);
    Keyboard.print(stringTable[randomString]);
    Keyboard.print("\r\n");
  }
}
