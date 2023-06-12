#define pinLED 3 //OE, GND no GND, VCC no positivo; old 8
#define pinS0 5 //S0; old 9
#define pinS1 6 //S1; old 10
#define pinOUT 9 //OUT; old 11
#define pinS3 10 //S3; old 12
#define pinS2 11 //S2; old 13
 
int pulseR = 0; // declara uma variavel int de nome red_frequency
int pulseG = 0; // declara uma variavel int de nome green_frequency
int pulseB = 0;// declara uma variavel int de nome blue_frequency

  
void setup(){
  pinMode(pinS0, OUTPUT); // define o pino denominado SO como saída 
  pinMode(pinS1, OUTPUT); // define o pino denominado S1 como saída 
  pinMode(pinS2, OUTPUT); // define o pino denominado S2 como saída 
  pinMode(pinS3, OUTPUT); // define o pino denominado S3 como saída 
  pinMode(pinOUT, INPUT); // define o pino denominado OutSensor como saída 
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600); // Inicia a comunicação serial
  digitalWrite(pinS0, HIGH); // configura a escala de frequência do sensor para 20%
  digitalWrite(pinS1, LOW); // configura a escala de frequência do sensor para 20%
 
}
  
void loop(){
 
// leitura da cor vermelha
digitalWrite(pinS2,LOW); // configuração para os Fotodiodos red serem lidos
digitalWrite(pinS3,LOW); // configuração para os Fotodiodos red serem lidos
pulseR = pulseIn (pinOUT, LOW); // armazena na variável red a frequência lida em OutSensor
Serial.print ("R= "); // escreve a letra R no monitor serial
Serial.print (pulseR); // apresenta os valores armazenados na variável red no monitor serial
Serial.print ("   "); // espaço de texto no monitor serial
 
// leitura da cor verde
digitalWrite(pinS2,HIGH); // configuração para os Fotodiodos green serem lidos
digitalWrite(pinS3,HIGH); // configuração para os Fotodiodos green serem lidos
pulseG = pulseIn (pinOUT, LOW); // armazena na variável green a frequência lida em OutSensor
Serial.print ("G= "); // escreve a letra G no monitor serial
Serial.print (pulseG); // apresenta os valores armazenados na variável green no monitor serial
Serial.print ("   "); // espaço de texto no monitor serial
 
// leitura da cor azul
digitalWrite(pinS2,LOW); // configuração para os Fotodiodos blue serem lidos
digitalWrite(pinS3,HIGH); // configuração para os Fotodiodos blue serem lidos
pulseB = pulseIn (pinOUT, LOW); // armazena na variável blue a frequência lida em OutSensor
Serial.print ("B= "); // escreve a letra B no monitor serial
Serial.print (pulseB); // apresenta os valores armazenados na variável blue no monitor serial
Serial.print ("   "); // espaço de texto no monitor serial
   
  // condiçoes para detecção das cores e atuação do servo motor
  if ((47 < pulseR) && (pulseR < 70) &&  
    (140 < pulseG) && (pulseG < 180) && 
    (110 < pulseB) && (pulseB < 130)){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Vermelho"); 
   }
  else if ((140 < pulseR) && (pulseR < 160) && 
    (85 < pulseG) && (pulseG < 115) && 
    (45< pulseB) && (pulseB < 65)){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Azul");
    }
  else if ((150 < pulseR) && (pulseR < 175) &&  
    (130< pulseG) && (pulseG < 155) && 
    (120< pulseB) && (pulseB < 140)){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Verde");
    }
  else if ((30 < pulseR) && (pulseR < 55) &&  
    (110 < pulseG) && (pulseG < 135) && 
    (105 < pulseB) && (pulseB < 125)){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Laranja");
    }
  else if ((25 < pulseR) && (pulseR < 45) &&  
    (35 < pulseG) && (pulseG < 55) && 
    (55 < pulseB) && (pulseB < 76)){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Amarelo");
    }
  else if ((65 < pulseR) && (pulseR < 90) &&  
    (100 < pulseG) && (pulseG < 120) && 
    (50 < pulseB) && (pulseB < 77)){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Roxo");
    }
  else if ((115 < pulseR) && (pulseR < 135) &&  
    (155 < pulseG) && (pulseG < 170) && 
    (110 < pulseB) && (pulseB < 140)){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Marron");
    }
  else if ((80 < pulseR) && (pulseR < 95) &&  
    (55 < pulseG) && (pulseG < 70) && 
    (35 < pulseB) && (pulseB < 50)){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Azul Claro");
    }
  else if ((74 < pulseR) && (pulseR < 90) &&  
    (45 < pulseG) && (pulseG < 75) && 
    (60 < pulseB) && (pulseB < 90)){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo Serial.println("| Verde Claro"); servo.write(130);} else if (red > 240 && green > 270 && blue > 200){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Preto");}
  else if ((pulseR < 50) && 
    (pulseG < 50) && 
    (pulseB < 50)){ // se os valores de RGB estiverem dentro dos parâmetros determinados, executa o codigo abaixo
    Serial.println("| Branco");}
    Serial.println(); // quebra um linha no texto do serial monitor
    delay(1000); // atraso de 300 milisegundos
}