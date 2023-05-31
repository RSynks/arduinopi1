
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
if((xxx<pulseR<xxx)&&(xxx<pulseG<xxx)&&(xxx<pulseB<xxx)&&(pulseW<100)){
  Serial.println("VERMELHO");
  
}

else if((xxx<pulseR<xxx)&&(xxx<pulseG<xxx)&&(xxx<pulseB<xxx)&&(pulseW<100)){
  Serial.println("VERDE");
  
}

else if((xxx<pulseR<xxx)&&(xxx<pulseG<xxx)&&(xxx<pulseB<xxx)&&(pulseW<100)){
  Serial.println("AZUL");
  
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
  digitalWrite(pinS2,HIGH);
  pulseW = pulseIn(pinOUT, digitalRead(pinOUT) == HIGH ? LOW : HIGH);

  //detectando azul
  digitalWrite(pinS2, LOW);
  digitalWrite(pinS3, HIGH);
  pulseB = pulseIn(pinOUT, digitalRead(pinOUT) == HIGH ? LOW : HIGH);

  //detectando verde
  pulseG = pulseIn(pinOUT, digitalRead(pinOUT) == HIGH ? LOW : HIGH);

}
