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

void setup() {
 pinMode(pinS0, OUTPUT);
 pinMode(pinS1, OUTPUT);
 pinMode(pinS2, OUTPUT);
 pinMode(pinS3, OUTPUT);
 pinMode(pinLED, OUTPUT);
 pinMode(pinOUT, INPUT);

 Serial.begin(9600);
 digitalWrite(pinS0, HIGH);
 digitalWrite(pinS1, LOW);

 delay(2000);

 digitalWrite(pinLED, HIGH); //liga LED

}

void loop() {
 
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
  if((pulseR > 30) && (pulseR < 100) &&
    (pulseG > 60 ) && (pulseG < 140 ) &&
    (pulseB > 60) && (pulseB < 140 ) &&
    (pulseW < 100)){
    Serial.println("VERMELHO");
    //aqui eu poderia botar uma funcao do que deve acontecer se vermelho
  }

  else if((pulseR > 140) && (pulseR < 170) &&
    (pulseG > 70 ) && (pulseG < 100 ) &&
    (pulseB > 70) && (pulseB < 100 ) &&
    (pulseW < 100)){
    Serial.println("AZUL ESCURO");
     //aqui poderia inserir funcao do que acontecer se azul
  }

  else if((pulseR > 100) && (pulseR < 120) &&
    (pulseG > 110 ) && (pulseG < 135 ) &&
    (pulseB > 110) && (pulseB < 135 ) &&
    (pulseW < 100)){
    Serial.println("VERDE CLARO");
    //aqui poderia inserir funcao do que deve acontecer se verde
  }

  else if((pulseR > 120) && (pulseR < 150) &&
    (pulseG > 90 ) && (pulseG < 120 ) &&
    (pulseB > 90) && (pulseB < 120 ) &&
    (pulseW < 100)){
    Serial.println("VERDE ESCURO");
    //aqui poderia inserir funcao do que deve acontecer se verde
  }

  else if((pulseR > 10) && (pulseR < 40) &&
    (pulseG > 10 ) && (pulseG < 40 ) &&
    (pulseB > 10) && (pulseB < 40 ) &&
    (pulseW < 100)){
    Serial.println("BRANCO");
    //aqui poderia inserir funcao do que deve acontecer se verde
  }  

  else if((pulseR > 145) && (pulseR < 160) &&
    (pulseG > 120 ) && (pulseG < 140 ) &&
    (pulseB > 120) && (pulseB < 140 ) &&
    (pulseW < 100)){
    Serial.println("PRETO");
    //aqui poderia inserir funcao do que deve acontecer se verde
  }
    
  else{
    Serial.println("Leitura vazia....");
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