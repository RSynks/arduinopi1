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
Serial.begin(9600);

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

detectaCor(); //puxa/inicia a funcao da leitura de cor
delay(2000);
Serial.print("vermelho: ");
Serial.println(pulseR);

Serial.print(" verde : ");
Serial.println(pulseG);

Serial.print(" azul: ");
Serial.println(pulseB);

Serial.print(" branco: ");
Serial.print(pulseW);
Serial.println();

//inicia-se a leitura de cor


if((100<pulseR<120)and(90<pulseG<120)and(100<pulseB<130)and(pulseW<100)){
  Serial.println("VERDE");
  
}

else if((140<pulseR<170)and(130<pulseG<160)and(60<pulseB<100)and(pulseW<100)){
  Serial.println("AZUL");
  
}

else if ((60<pulseR<100)and(150<pulseG<180)and(110<pulseB<140)and(pulseW<100)){
  Serial.println("VERMELHO");
  
}

else if((pulseR>150)and(pulseG>190)and(pulseB>140)and(pulseW<100)){
  Serial.println("leitura vazia");
  
}


else{
  Serial.println("OUTRA COR");
  
}
delay(1000);

}

void detectaCor(){
  //detectando vermelho
  digitalWrite(pinS2,LOW);
  digitalWrite(pinS3,LOW);
  pulseR = pulseIn(pinOUT, digitalRead(pinOUT) == HIGH ? LOW : HIGH);

  //sem filtro
  digitalWrite(pinS2, HIGH);
  digitalWrite(pinS3, LOW);
  pulseW = pulseIn(pinOUT, digitalRead(pinOUT) == HIGH ? LOW : HIGH);

  //detectando azul
  digitalWrite(pinS2, LOW);
  digitalWrite(pinS3, HIGH);
  pulseB = pulseIn(pinOUT, digitalRead(pinOUT) == HIGH ? LOW : HIGH);

  //detectando verde
  digitalWrite(pinS2, HIGH);
  digitalWrite(pinS3, HIGH);
  pulseG = pulseIn(pinOUT, digitalRead(pinOUT) == HIGH ? LOW : HIGH);

  

}
