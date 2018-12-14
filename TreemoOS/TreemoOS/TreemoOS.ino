/*
    TreemoOS for NodeMCU

    DISPLAY:
    Pin D0 is connected to DataIn
    Pin D1 is connected to LOAD/CS
    Pin D2 is connected to CLK

    MOISTURE SENSOR (Currently using YL-69):
    Pin D7 is connected to SignalIn

*/


#include <LedControl.h>

int DIN = 16; // D0

int CS =  5;  // D1

int CLK = 4;  // D2

int sens = 13; // D7

int moisture = 0;



LedControl lc = LedControl(DIN, CLK, CS);

void setup() {

  lc.shutdown(0, false);    //The MAX72XX is in power-saving mode on startup

  lc.setIntensity(0, 10);    // Set the brightness value (1-15)

  lc.clearDisplay(0);

  Serial.begin(9600);

}

void loop() {

  moisture = analogRead(sens); // rewrite using digital output?

  if (moisture >= 1000) { // these values will need tweaking depending on the type of plant and the sensor you use.

    byte h[8] = {B00000000, B00001010, B01000100, B00100000, B00100000, B01000100, B00001010, B00000000}; // sad

    lc.setRow(0, 0, h[0]);
    lc.setRow(0, 1, h[1]);
    lc.setRow(0, 2, h[2]);
    lc.setRow(0, 3, h[3]);
    lc.setRow(0, 4, h[4]);
    lc.setRow(0, 5, h[5]);
    lc.setRow(0, 6, h[6]);
    lc.setRow(0, 7, h[7]);

    delay(1400);

  }
  if (moisture >= 500 && moisture <= 700 ) { // these values will need tweaking depending on the type of plant and the sensor you use.

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
  if (moisture <= 200) { // these values will need tweaking depending on the type of plant and the sensor you use.

    byte h1[8] = {B00000010, B00000001, B00110010, B01010000, B01010000, B00110010, B00000001, B00000010}; // happy

    lc.setRow(0, 0, h1[0]);
    lc.setRow(0, 1, h1[1]);
    lc.setRow(0, 2, h1[2]);
    lc.setRow(0, 3, h1[3]);
    lc.setRow(0, 4, h1[4]);
    lc.setRow(0, 5, h1[5]);
    lc.setRow(0, 6, h1[6]);
    lc.setRow(0, 7, h1[7]);

    delay(1400);

    byte h2[8] = {B00000100, B00100010, B01000100, B01000000, B01000000, B01000100, B00100010, B00000100}; // happy

    lc.setRow(0, 0, h2[0]);
    lc.setRow(0, 1, h2[1]);
    lc.setRow(0, 2, h2[2]);
    lc.setRow(0, 3, h2[3]);
    lc.setRow(0, 4, h2[4]);
    lc.setRow(0, 5, h2[5]);
    lc.setRow(0, 6, h2[6]);
    lc.setRow(0, 7, h2[7]);

    delay(600);


  }
  Serial.println(moisture);
  delay(1000);
}


