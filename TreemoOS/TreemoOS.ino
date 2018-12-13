/*
    TreemoOS

    DISPLAY:
    Pin 12 is connected to DataIn
    Pin 11 is connected to CLK
    Pin 10 is connected to LOAD/CS

    MOISTURE SENSOR:
    Pin A1 is connected to SignalIn

*/

#include "LedControl.h"

LedControl lc = LedControl(7, 5, 6, 1);

int sens = A1;
int moisture = 0;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);

  pinMode(sens, INPUT);
  Serial.begin(9600);

}

void loop() {

  moisture = analogRead(sens);

  if (moisture <= 50) { // these values will need tweaking depending on the type of plant and the sensor you use.

    byte h[8] = {B00000000, B00001010, B01000100, B00100000, B00100000, B01000100, B00001010, B00000000}; // sad

    lc.setRow(0, 0, h[0]);
    lc.setRow(0, 1, h[1]);
    lc.setRow(0, 2, h[2]);
    lc.setRow(0, 3, h[3]);
    lc.setRow(0, 4, h[4]);
    lc.setRow(0, 5, h[5]);
    lc.setRow(0, 6, h[6]);
    lc.setRow(0, 7, h[7]);

  }
  if (moisture >= 50 && moisture <= 300 ) { // these values will need tweaking depending on the type of plant and the sensor you use.

    byte l[8] = {B00000100, B00000010, B01000100, B10000000, B10000000, B01000100, B00000010, B00000100}; // happy

    lc.setRow(0, 0, l[0]);
    lc.setRow(0, 1, l[1]);
    lc.setRow(0, 2, l[2]);
    lc.setRow(0, 3, l[3]);
    lc.setRow(0, 4, l[4]);
    lc.setRow(0, 5, l[5]);
    lc.setRow(0, 6, l[6]);
    lc.setRow(0, 7, l[7]);

  }
  if (moisture >= 300) { // these values will need tweaking depending on the type of plant and the sensor you use.

    byte s[8] = {B00000100, B00000010, B01100100, B10100000, B10100000, B01100100, B00000010, B00000100}; // very happy

    lc.setRow(0, 0, s[0]);
    lc.setRow(0, 1, s[1]);
    lc.setRow(0, 2, s[2]);
    lc.setRow(0, 3, s[3]);
    lc.setRow(0, 4, s[4]);
    lc.setRow(0, 5, s[5]);
    lc.setRow(0, 6, s[6]);
    lc.setRow(0, 7, s[7]);

  }
  Serial.println(moisture);
  delay(1000);
}
