#include <Servo.h>
Servo servo1, servo2, servo3, servo4, servo5, servo6, servo7, servo8; 

#define S2 6
#define S3 7
#define OUT 8

void detectaCor();
int pulseR = 0,
    pulseG = 0,
    pulseB = 0; //pulso de cada cor


void setup() {

pinMode(S2,OUTPUT);
pinMode(S3,OUTPUT);
pinMode(OUT,INPUT);

servo1.attach(9);
Serial.println("digite o grau de movimento do servo");
Serial.begin(9600);

}

void loop() {

if(Serial.available()){
  int angulo = Serial.parseInt();
  if (angulo<0){
    Serial.print(">");
    Serial.println(angulo);
    Serial.println("nao pode executar, muito baixo numero");
  }

  if(angulo>0 && angulo < 180){
    Serial.print(" l ");
    Serial.println(angulo);
    Serial.print("Servo posicionado em ");
    Serial.print(angulo);
    Serial.println(" graus");
    servo1.write(angulo);
  }


}  

}


void detectaCor(){
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  //count OUT, pRed, red
  pulseR = pulseIn(OUT,digitalRead(OUT) == HIGH ? LOW : HIGH);
  digitalWrite(S3,HIGH);
  //count OUT, pBlue, BLUE
  PulseB = pulseIn(OUT,digitalRead(OUT) == HIGH ? LOW : HIGH);
  digitalWrite(S2,HIGH);
  //count OUT, pGreen, Green
  pulseG = pulseIn(OUT,digitalRead(OUT) == HIGH ? LOW : HIGH);

  if (pulseR<pulseB && pulseR < pulseG && pulseR < 500){
    Serial.println("vermelho");

  }

  else if (pulseG < pulseR && pulseG < pulseB){
    Serial.println("verde")
  }

  else if (pulseR < pulseG && pulseG < pulseB){
    Serial.println("azul")
  }
}


//vcc liga ao 5V do arduino; S0,S1,S2,S3 precisam estar ligados