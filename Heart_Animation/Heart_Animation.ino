/*
    Treemo Animation Test

    Pin 12 is connected to DataIn
    Pin 11 is connected to CLK
    Pin 10 is connected to LOAD
*/

#include "LedControl.h"

LedControl lc = LedControl(7, 5, 6, 1);


void setup() {
  lc.shutdown(0, false); // Wake up MAX7219
  lc.setIntensity(0, 4); // Set brightness
  lc.clearDisplay(0);
}

void loop() {

  if (true) {

    byte heartBig[8] = {B00000000, B00100100, B01111110, B01111110, B00111100, B00011000, B00000000, B00000000};
    
    lc.setRow(0, 0, heartBig[0]);
    lc.setRow(0, 1, heartBig[1]);
    lc.setRow(0, 2, heartBig[2]);
    lc.setRow(0, 3, heartBig[3]);
    lc.setRow(0, 4, heartBig[4]);
    lc.setRow(0, 5, heartBig[5]);
    lc.setRow(0, 6, heartBig[6]);
    lc.setRow(0, 7, heartBig[7]);

    delay(600);

    byte heartSmall[8] = {B01100110, B11111111, B11111111, B11111111, B01111110, B00111100, B00011000, B00000000};

    lc.setRow(0, 0, heartSmall[0]);
    lc.setRow(0, 1, heartSmall[1]);
    lc.setRow(0, 2, heartSmall[2]);
    lc.setRow(0, 3, heartSmall[3]);
    lc.setRow(0, 4, heartSmall[4]);
    lc.setRow(0, 5, heartSmall[5]);
    lc.setRow(0, 6, heartSmall[6]);
    lc.setRow(0, 7, heartSmall[7]);

    delay(400);

  }

}
