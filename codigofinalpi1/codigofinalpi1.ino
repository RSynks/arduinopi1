#include "Servo.h"

#define pinLED 8 //OE, GND no GND, VCC no positivo
#define pinS0 9 //S0
#define pinS1 10 //S1
#define pinOUT 11 //OUT
#define pinS3 12 //S3
#define pinS2 13 //S2

void detectaCor();
int pulseR = 0,
    pulseG = 0,
    pulseB = 0,
    pulseW = 0;

Servo servo1,
      servo2,
      servo3;

int abre = 90;
int fecha = 0;
int entrega = 0; //R=0,B=30,G=60,Y=90,W=120,O=150,BK+=180;

void setup() {
Serial.begin(9600);
servo1.attach(5);
servo2.attach(6);
servo3.attach(7);

pinMode(pinS0, OUTPUT);
pinMode(pinS1, OUTPUT);
pinMode(pinS2, OUTPUT);
pinMode(pinS3, OUTPUT);
pinMode(pinLED, OUTPUT);
pinMode(pinOUT, INPUT);

digitalWrite(pinS0, HIGH);
digitalWrite(pinS1, LOW);

delay(2000);

digitalWrite(pinLED, HIGH); //liga LED


}

void loop() {

servo1.write(fecha);
servo2.write(fecha);
delay(1000);

servo1.write(abre);
delay(1000);
servo1.write(fecha);
delay(1000);

detectaCor(); //puxa/inicia a funcao da leitura de cor
Serial.print("vermelho: ");
Serial.println(pulseR);

Serial.print(" verde : ");
Serial.println(pulseG);

Serial.print(" azul: ");
Serial.println(pulseB);

Serial.print(" branco: ");
Serial.print(pulseW);
Serial.println();

//inicia-se a leitura de cor e a movimentacao do escorregador
if((pulseR<pulseB)&&(pulseR<pulseG)&&(pulseW<100)){
  Serial.println("VERMELHO");
  servo3.write(0);
}

else if((pulseG<pulseR)&&(pulseG<pulseB)&&(pulseW<100)){
  Serial.println("VERDE");
  servo3.write(30);
}

else if ((pulseB<pulseR)&&(pulseB<pulseG)&&(pulseW<100)){
  Serial.println("AZUL");
  servo3.write(60);
}

else{
  Serial.println("OUTRA COR");
  servo3.write(90);
}
delay(1000);

servo2.write(abre);
delay(1000);

servo2.write(fecha);
delay(3000);

}

void detectaCor(){
  //detectando vermelho
  digitalWrite(pinS2,LOW);
  digitalWrite(pinS3,LOW);
  pulseR = pulseIn(pinOUT, digitalRead(pinOUT) == HIGH ? LOW : HIGH);

  //sem filtro
  digitalWrite(pinS2,HIGH);
  pulseW = pulseIn(pinOUT, digitalRead(pinOUT) == HIGH ? LOW : HIGH);

  //detectando azul
  digitalWrite(pinS2, LOW);
  digitalWrite(pinS3, HIGH);
  pulseB = pulseIn(pinOUT, digitalRead(pinOUT) == HIGH ? LOW : HIGH);

  //detectando verde
  pulseG = pulseIn(pinOUT, digitalRead(pinOUT) == HIGH ? LOW : HIGH);

}
