#define pot A0
#include "Servo.h"

Servo servo1;

void setup() {
  Serial.begin(9600);
  servo1.attach(7);
}

void loop() {

  int potvalor = analogRead(pot);
  Serial.print("valor do potenciometro = ");
  Serial.println(potvalor);
  potvalor = map(potvalor, 0, 1023, 0, 180);
  servo1.write(potvalor);
  delay(250);
}
