#include "Servo.h"

Servo servo1; //laranja portas digitais


void setup() {
  Serial.begin(9600);
  servo1.attach(13);
}

void loop() {
  int angulo = Serial.parseInt();
  Serial.available();
  Serial.print("digite valor do angulo: ");
  Serial.println(angulo);
  servo1.write(angulo);
  delay(1500);

  angulo = 0;
}
