#include <VarSpeedServo.h>

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

VarSpeedServo servo1,
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
  
  int i1=0,
      i2=0;

  servo1.slowmove(close,50);
  servo2.slowmove(close,50);
  Serial.println("fechou fila e entrega");
  Serial.println("valor de i1 e i2:");
  Serial.println(i1);
  Serial.println(i2);
  delay(1000);

  servo1.slowmove(open,50);
  Serial.println("abriu fila");
  delay(1000);
  servo1.slowmove(close,50);
  Serial.println("fechou fila");
  delay(1000);

 while((i1<=5) or (i2<=5)){ 
  
  detectaCor(); //inicia a funcao la em baixo fora do loop

  //mostra os valores dos pulso das cores no serial monitor
  Serial.print("vermelho: ");
  Serial.print(pulseR);

  Serial.print(" verde: ");
  Serial.print(pulseG);

  Serial.print(" azul: ");
  Serial.print(pulseB);

  Serial.print(" branco: ");
  Serial.print(pulseW);
  Serial.println();

  if((pulseR > 62) && (pulseR < 90) &&
    (pulseG > 118) && (pulseG < 141) &&
    (pulseB > 118) && (pulseB < 141) &&
    (pulseW < 100)){
    Serial.println("VERMELHO");
    servo3.slowmove(0,30);
    break;
  }

  else if((pulseR > 58) && (pulseR < 68) &&
    (pulseG > 111 ) && (pulseG < 128) &&
    (pulseB > 111) && (pulseB < 128) &&
    (pulseW < 100)){
    Serial.println("LARANJA");
    servo3.slowmove(0,30);
    break;
  }

  else if((pulseR > 60) && (pulseR < 75) &&
    (pulseG > 84 ) && (pulseG < 99) &&
    (pulseB > 84) && (pulseB < 99) &&
    (pulseW < 100)){
    Serial.println("ROSA");
    servo3.slowmove(180,30);
    break;
  }

  else if((pulseR > 51) && (pulseR < 70) &&
    (pulseG > 98) && (pulseG < 120) &&
    (pulseB > 98) && (pulseB < 120) &&
    (pulseW < 100)){
    Serial.println("AMARELO");
    servo3.slowmove(30,30);
    break;
  }

  else if((pulseR > 39) && (pulseR < 55) &&
    (pulseG > 62 ) && (pulseG < 75 ) &&
    (pulseB > 62) && (pulseB < 75 ) &&
    (pulseW < 100)){
    Serial.println("AMARELO CLARO");
    servo3.slowmove(30,30);
    break;
  }

  else if((pulseR > 140) && (pulseR < 170) &&
    (pulseG > 70) && (pulseG < 115) &&
    (pulseB > 70) && (pulseB < 115) &&
    (pulseW < 100)){
    Serial.println("AZUL ESCURO");
    servo3.slowmove(60,30);
    break;
  }

  else if((pulseR > 112) && (pulseR < 131) &&
    (pulseG > 49) && (pulseG < 63) &&
    (pulseB > 49) && (pulseB < 63) &&
    (pulseW < 100)){
    Serial.println("AZUL MARINHO");
    servo3.slowmove(60,30);
    break;
  }

  else if((pulseR > 111) && (pulseR < 130) &&
    (pulseG > 61) && (pulseG < 80) &&
    (pulseB > 61) && (pulseB < 80) &&
    (pulseW < 100)){
    Serial.println("TURQUESA");
    servo3.slowmove(60,30);
    break;
  }

  else if((pulseR > 100) && (pulseR < 120) &&
    (pulseG > 110 ) && (pulseG < 135 ) &&
    (pulseB > 110) && (pulseB < 135 ) &&
    (pulseW < 100)){
    Serial.println("VERDE CLARO");
    servo3.slowmove(90,30);
    break;
  }

  else if((pulseR > 130) && (pulseR < 170) &&
    (pulseG > 110 ) && (pulseG < 142) &&
    (pulseB > 110) && (pulseB < 142) &&
    (pulseW < 100)){
    Serial.println("VERDE ESCURO");
    servo3.slowmove(90,30);
    break;
  }

  else if((pulseR < 50) &&
    (pulseG < 50) &&
    (pulseB < 50) &&
    (pulseW < 100)){
    Serial.println("BRANCO");
    servo3.slowmove(180,30);
    break;
    
  } 

  //leitura de cor roxa
  else if((pulseR > 115) && (pulseR < 130) &&
    (pulseG > 102) && (pulseG < 120) &&
    (pulseB > 102) && (pulseB < 120) &&
    (pulseW < 100)){
    Serial.println("ROXO");
    servo3.slowmove(180,30);
    break;
  }

  //leitura de cor preta
  else if((pulseR > 150) && (pulseR < 183) &&
    (pulseG > 130 ) && (pulseG < 160) &&
    (pulseB > 130) && (pulseB < 160) &&
    (pulseW < 100)){
    Serial.println("PRETO");
    servo3.slowmove(180,30);
    break;
  }

  //leitura se a fila está vazia
  else if((pulseR > 170) &&
    (pulseG > 150) &&
    (pulseB > 150) &&
    (pulseW < 100)){
    Serial.println("Fila de leitura vazia...");
    i1=i1+1;
    Serial.println("valor de i1:");
    Serial.println(i1);
    if(i1>=5){
      break;
    }
  }
    
  //verificação se a cor está ou nao cadastrada  
  else{
    Serial.println("Desculpe, nao conseguimos identificar a cor....");
    if(i2>=5){
      Serial.println("checamos e realmente a cor e diferente, moveu escorregador");
      Serial.println("valor de i2: ");
      Serial.println(i2);
      servo3.slowmove(180,30);
      break;
    }
    else{
      i2=i2+1;
      Serial.println("nao identificamos, vamos checar novamente");
      Serial.println("valor de i2: ");
      Serial.println(i2);
      
    }
  }
  delay(5000);
 }
  Serial.println();
  delay(1000);
  Serial.println("encerrou checagem");
  Serial.println("vamos dar sequencia");
  Serial.println("");


  servo2.slowmove(open,50);
  Serial.println("abriu entrega");
  delay(1000);
  
  Serial.println("fechou entrega");
  Serial.println("vamos recomecar!!");
  Serial.println("");
  delay(5000);


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