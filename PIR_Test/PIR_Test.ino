/*
    Treemo PIR Sensor Test
*/

int movement = 13;  // D7


void setup() {

  pinMode(movement, INPUT);
  Serial.begin(9600);
}


void loop() {

  long state = digitalRead(movement);
  if (state == HIGH) {
    Serial.println("Interaction Detected");
    delay(1000);
  }

  else {
    Serial.println("No Interaction Detected");
    delay(2000);
  }
}
