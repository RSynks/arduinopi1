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
  if((pulseR > 63) && (pulseR < 90) &&
    (pulseG > 114 ) && (pulseG < 141) &&
    (pulseB > 114) && (pulseB < 141) &&
    (pulseW < 100)){
    Serial.println("VERMELHO");
    
  }

  else if((pulseR > 54) && (pulseR < 68) &&
    (pulseG > 111 ) && (pulseG < 123 ) &&
    (pulseB > 111) && (pulseB < 123 ) &&
    (pulseW < 100)){
    Serial.println("LARANJA");
    
  }

  else if((pulseR > 60) && (pulseR < 70) &&
    (pulseG > 84 ) && (pulseG < 95 ) &&
    (pulseB > 84) && (pulseB < 95 ) &&
    (pulseW < 100)){
    Serial.println("ROSA");
    
  }

  else if((pulseR > 49) && (pulseR < 65) &&
    (pulseG > 98) && (pulseG < 115 ) &&
    (pulseB > 98) && (pulseB < 115 ) &&
    (pulseW < 100)){
    Serial.println("AMARELO");
    
  }

  else if((pulseR > 140) && (pulseR < 170) &&
    (pulseG > 70) && (pulseG < 115) &&
    (pulseB > 70) && (pulseB < 115) &&
    (pulseW < 100)){
    Serial.println("AZUL ESCURO");
    
  }

  else if((pulseR > 112) && (pulseR < 131) &&
    (pulseG > 49) && (pulseG < 63) &&
    (pulseB > 49) && (pulseB < 63) &&
    (pulseW < 100)){
    Serial.println("AZUL MARINHO");
    
  }

  else if((pulseR > 111) && (pulseR < 130) &&
    (pulseG > 61) && (pulseG < 80) &&
    (pulseB > 61) && (pulseB < 80) &&
    (pulseW < 100)){
    Serial.println("TURQUESA");
    
  }

  else if((pulseR > 100) && (pulseR < 120) &&
    (pulseG > 110 ) && (pulseG < 135 ) &&
    (pulseB > 110) && (pulseB < 135 ) &&
    (pulseW < 100)){
    Serial.println("VERDE CLARO");
    
  }

  else if((pulseR > 130) && (pulseR < 158) &&
    (pulseG > 110 ) && (pulseG < 135 ) &&
    (pulseB > 110) && (pulseB < 135 ) &&
    (pulseW < 100)){
    Serial.println("VERDE ESCURO");
    
  }

  else if((pulseR > 10) && (pulseR < 50) &&
    (pulseG > 10 ) && (pulseG < 45) &&
    (pulseB > 10) && (pulseB < 45) &&
    (pulseW < 100)){
    Serial.println("BRANCO");
    
  } 

  else if((pulseR > 39) && (pulseR < 55) &&
    (pulseG > 62 ) && (pulseG < 75 ) &&
    (pulseB > 62) && (pulseB < 75 ) &&
    (pulseW < 100)){
    Serial.println("AMARELO CLARO");
    
  }

  else if((pulseR > 115) && (pulseR < 126) &&
    (pulseG > 102) && (pulseG < 118) &&
    (pulseB > 102) && (pulseB < 118) &&
    (pulseW < 100)){
    Serial.println("ROXO");
    
  }

  else if((pulseR > 164) && (pulseR < 175) &&
    (pulseG > 140 ) && (pulseG < 154 ) &&
    (pulseB > 140) && (pulseB < 154 ) &&
    (pulseW < 100)){
    Serial.println("PRETO");
    
  }

  else if((pulseR > 140) &&
    (pulseG > 130) &&
    (pulseB > 130) &&
    (pulseW < 100)){
    Serial.println("Fila de leitura vazia...");
    
  }
    
  else{
    Serial.println("Desculpe, nao conseguimos identificar a cor....");
  }
  Serial.println();
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