#include <Servo.h>

#define pinLED 3 //OE, GND no GND, VCC no positivo; old 8
#define pinS0 5 //S0; old 9
#define pinS1 6 //S1; old 10
#define pinOUT 9 //OUT; old 11
#define pinS3 10 //S3; old 12
#define pinS2 11 //S2; old 13

void detectaCor();

int pulseR = 0,
    pulseG = 0,
    pulseB = 0,
    pulseW = 0;

Servo servo1,
      servo2,
      servo3;

int open = 90,
    close = 0,
    entrega = 0;


void setup() {
 servo1.attach(1);
 servo2.attach(2);
 servo3.attach(4);

 pinMode(pinS0, OUTPUT);
 pinMode(pinS1, OUTPUT);
 pinMode(pinS2, OUTPUT);
 pinMode(pinS3, OUTPUT);
 pinMode(pinLED, OUTPUT);
 pinMode(pinOUT, INPUT);

 Serial.begin(9600);
 digitalWrite(pinS0, HIGH);
 digitalWrite(pinS1, LOW);
 digitalWrite(pinLED, HIGH); //liga LED

}

void loop() {
  
  servo1.write(close);
  servo2.write(close);
  delay(1000);

  servo1.write(open);
  delay(1000);
  servo1.write(close);
  delay(1000);

  detectaCor(); //inicia a funcao la em baixo fora do loop

  //mostra os valores dos pulso das cores no serial monitor
  Serial.print("vermelho: ");
  Serial.print(pulseR);

  Serial.print(" verde: ");
  Serial.print(pulseG);

  Serial.print(" azul: ");
  Serial.print(pulseB);

  Serial.print(" branco: ");
  Serial.print("pulseW");
  Serial.println();

  //verifica se a cor vermelha foi detectada
  if((pulseR > 62) && (pulseR < 90) &&
    (pulseG > 118) && (pulseG < 141) &&
    (pulseB > 118) && (pulseB < 141) &&
    (pulseW < 100)){
    Serial.println("VERMELHO");
    servo3.write(0);
  }

  else if((pulseR > 58) && (pulseR < 68) &&
    (pulseG > 111 ) && (pulseG < 128) &&
    (pulseB > 111) && (pulseB < 128) &&
    (pulseW < 100)){
    Serial.println("LARANJA");
    servo3.write(0);
  }

  else if((pulseR > 60) && (pulseR < 75) &&
    (pulseG > 84 ) && (pulseG < 99) &&
    (pulseB > 84) && (pulseB < 99) &&
    (pulseW < 100)){
    Serial.println("ROSA");
    servo3.write(180);
  }

  else if((pulseR > 51) && (pulseR < 70) &&
    (pulseG > 98) && (pulseG < 120) &&
    (pulseB > 98) && (pulseB < 120) &&
    (pulseW < 100)){
    Serial.println("AMARELO");
    servo3.write(30);
  }

  else if((pulseR > 39) && (pulseR < 55) &&
    (pulseG > 62 ) && (pulseG < 100) &&
    (pulseB > 62) && (pulseB < 100) &&
    (pulseW < 100)){
    Serial.println("AMARELO CLARO");
    servo3.write(30);
  }

  else if((pulseR > 140) && (pulseR < 170) &&
    (pulseG > 70) && (pulseG < 115) &&
    (pulseB > 70) && (pulseB < 115) &&
    (pulseW < 100)){
    Serial.println("AZUL ESCURO");
    servo3.write(60);
  }

  else if((pulseR > 112) && (pulseR < 131) &&
    (pulseG > 49) && (pulseG < 63) &&
    (pulseB > 49) && (pulseB < 63) &&
    (pulseW < 100)){
    Serial.println("AZUL MARINHO");
    servo3.write(60);
  }

  else if((pulseR > 111) && (pulseR < 130) &&
    (pulseG > 61) && (pulseG < 80) &&
    (pulseB > 61) && (pulseB < 80) &&
    (pulseW < 100)){
    Serial.println("TURQUESA");
    servo3.write(60);
  }

  else if((pulseR > 100) && (pulseR < 120) &&
    (pulseG > 110 ) && (pulseG < 135 ) &&
    (pulseB > 110) && (pulseB < 135 ) &&
    (pulseW < 100)){
    Serial.println("VERDE CLARO");
    servo3.write(90);
  }

  else if((pulseR > 130) && (pulseR < 170) &&
    (pulseG > 110 ) && (pulseG < 142) &&
    (pulseB > 110) && (pulseB < 142) &&
    (pulseW < 100)){
    Serial.println("VERDE ESCURO");
    servo3.write(90);
  }

  else if(pulseR < 50) &&
    (pulseG < 50) &&
    (pulseB < 50) &&
    (pulseW < 100)){
    Serial.println("BRANCO");
    servo3.write(180);
  } 

  else if((pulseR > 115) && (pulseR < 130) &&
    (pulseG > 102) && (pulseG < 120) &&
    (pulseB > 102) && (pulseB < 120) &&
    (pulseW < 100)){
    Serial.println("ROXO");
    servo3.write(180);
  }

  else if((pulseR > 129) && (pulseR < 155) &&
    (pulseG > 129 ) && (pulseG < 155) &&
    (pulseB > 129) && (pulseB < 155) &&
    (pulseW < 100)){
    Serial.println("PRETO");
    servo3.write(180);
  }

  else if((pulseR > 80) && (pulseR<90)&&
    (pulseG > 99) && (pulseG<105) &&
    (pulseB > 99) && (pulseB<105) &&
    (pulseW < 50)){
    Serial.println("Fila de leitura vazia...");
    i=i+1
  }
    
  else{
    Serial.println("Desculpe, nao conseguimos identificar a cor....");
    servo3.write(180);
  }
  Serial.println();
  delay(1000);
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