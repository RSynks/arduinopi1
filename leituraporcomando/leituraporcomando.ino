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
    if((pulseR < pulseB) && (pulseR < pulseG) && (pulseW < 100)){
      Serial.println("vermelho");
      //aqui eu poderia botar uma funcao do que deve acontecer se vermelho
    }

    else if((pulseB<pulseR) && (pulseB<pulseG) && (pulseW<100)){
      Serial.println("azul");
      //aqui poderia inserir funcao do que acontecer se azul
    }

    else if((pulseG<pulseR) && (pulseG < pulseB) && (pulseW <100)){
      Serial.println("verde");
      //aqui poderia inserir funcao do que deve acontecer se verde
    }
    
    
  else{
    Serial.println("retornando....");
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