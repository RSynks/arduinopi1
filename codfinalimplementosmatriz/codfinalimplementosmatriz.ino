#include <VarSpeedServo.h>

#define pinLED 3 //OE=preto SUL;VCC=verde NORTE;GND=roxo SUL;
#define pinS0 5 //S0;branco SUL
#define pinS1 6 //S1; verde SUL
#define pinOUT 9 //OUT; cinza NORTE
#define pinS3 10 //S3; azul claro NORTE
#define pinS2 11 //S2; amarelo NORTE

//PARTE NORTE:
//azul=s3=10
//amarelo=s2=11
//cinza=OUT=9
//verde=VCC=positivo

//PARTE SUL:
//branco=s0=5
//verde=s1=6
//preto=OE=3
//roxo=GND=negativo

//SERVOS:
//servo1=fila=2
//servo2=leitura=4
//servo3=escorregador=7

int red[3][2] = {{54,90},
                {115,135},
                {120,135}};

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
    entrega = 0,
    cr=0,//checa vermelho
    cy=0,//checa amarelo
    cb=0,//checa azul
    cg=0,//checa verde
    cw=0,//checa branco
    co=0,//checa outros
    vse=30,//velocidade giro servo3 após id cor
    ar=0,//angulo compart vermelho
    ay=30,//angulo compart amarelo
    ab=60,//angulo compart azul
    ag=90,//angulo compart verde
    aw=120,//angulo compart branco
    ao=180;//angulo compart geral

void setup() {
 servo1.attach(2);//entrada,controla fila
 servo2.attach(4);//saida torre, controla entrega
 servo3.attach(7);//escorregador, direciona compartimento

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

void define_cor(cor){
  Serial.print(cor);
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

 while((i1<=5)||(i2<=5)||(cr<=5)||(cy<=5)||(cb<=5)||(cg<=5)||(cw<=5)||(co<=5)){ 
  
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

  if((pulseR > 54) && (pulseR < 90) &&
    (pulseG > 120) && (pulseG < 135) &&
    (pulseB > 120) && (pulseB < 135) &&
    (pulseW < 100)){
    cr=cr+1;
    if(cr>=5){
      Serial.println("VERMELHO");
      servo3.slowmove(ar,vse);
      break;
    }
  
  }

  else if((pulseR > 40) && (pulseR < 68) &&
    (pulseG > 100 ) && (pulseG < 128) &&
    (pulseB > 100) && (pulseB < 128) &&
    (pulseW < 100)){
    cr=cr+1;
    if(cr>=5){
      Serial.println("LARANJA/VERMELHO CLARO");
      servo3.slowmove(ar,vse);
      break;
    }
  }

  else if((pulseR > 60) && (pulseR < 75) &&
    (pulseG > 84 ) && (pulseG < 99) &&
    (pulseB > 84) && (pulseB < 99) &&
    (pulseW < 100)){
    co=co+1;
    if(co>=5){
      Serial.println("ROSA");
      servo3.slowmove(ao,vse);
      break;
    }
  }

  else if((pulseR < 50) &&
    (pulseG > 98) && (pulseG < 110) &&
    (pulseB > 98) && (pulseB < 110) &&
    (pulseW < 100)){
    cy=cy+1;
    if(cy>=5){
      Serial.println("AMARELO");
      servo3.slowmove(ay,vse);
      break;
    }
  }

  else if((pulseR > 39) && (pulseR < 55) &&
    (pulseG > 62 ) && (pulseG < 100) &&
    (pulseB > 62) && (pulseB < 100) &&
    (pulseW < 100)){
    cy=cy+1;
    if(cy>=5){
      Serial.println("AMARELO CLARO");
      servo3.slowmove(ay,vse);
      break;
    }
  }

  else if((pulseR > 125) && (pulseR < 150) &&
    (pulseG > 52) && (pulseG < 65) &&
    (pulseB > 52) && (pulseB < 65) &&
    (pulseW < 100)){
    cb=cb+1;
    if(cb>=5){
      Serial.println("AZUL ESCURO");
      servo3.slowmove(ab,vse);
      break;
    }
  }

  else if((pulseR > 140) && (pulseR < 170) &&
    (pulseG > 95) && (pulseG < 108) &&
    (pulseB > 95) && (pulseB < 108) &&
    (pulseW < 45)){
    cb=cb+1;
    if(cb>=5){
      Serial.println("AZUL MUITO ESCURO");//TALVEZ PRECISO COLOCAR RANGE no w
      servo3.slowmove(ab,vse);//para nao confundir com verde escuro
      break;
    }
  }

  else if((pulseR > 112) && (pulseR < 131) &&
    (pulseG > 55) && (pulseG < 70) &&
    (pulseB > 55) && (pulseB < 70) &&
    (pulseW < 100)){
    cb=cb+1;
    if(cb>=5){
      Serial.println("AZUL MARINHO");
      servo3.slowmove(ab,vse);
      break;
    }
  }

  else if((pulseR > 90) && (pulseR < 105) &&
    (pulseG > 50) && (pulseG < 65) &&
    (pulseB > 50) && (pulseB < 65) &&
    (pulseW < 100)){
    cb=cb+1;
    if(cb>=5){
      Serial.println("TURQUESA");
      servo3.slowmove(ab,vse);
      break;
    }
  }

  else if((pulseR > 100) && (pulseR < 120) &&
    (pulseG > 110 ) && (pulseG < 135 ) &&
    (pulseB > 110) && (pulseB < 135 ) &&
    (pulseW < 100)){
    cg=cg+1;
    if(cg>=5){
      Serial.println("VERDE CLARO");
      servo3.slowmove(ag,vse);
      break;
    }
  }

  else if((pulseR > 130) && (pulseR < 170) &&
    (pulseG > 110 ) && (pulseG < 142) &&
    (pulseB > 110) && (pulseB < 142) &&
    (pulseW < 100)){
    cg=cg+1;
    if(cg>=5){
      Serial.println("VERDE ESCURO");
      servo3.slowmove(ag,vse);
      break;
    }
  }

  else if((pulseR < 50) &&
    (pulseG < 50) &&
    (pulseB < 50) &&
    (pulseW < 100)){
    cw=cw+1;
    if(cw>=5){
      Serial.println("BRANCO");
      servo3.slowmove(aw,vse);
      break;
    }
  } 

  //leitura de cor roxa
  else if((pulseR > 115) && (pulseR < 130) &&
    (pulseG > 102) && (pulseG < 120) &&
    (pulseB > 102) && (pulseB < 120) &&
    (pulseW < 100)){
    co=co+1;
    if(co>=5){
      Serial.println("ROXO");
      servo3.slowmove(ao,vse);
      break;
    }
  }

  //leitura de cor preta
  else if((pulseR > 140) &&
    (pulseG > 135 ) &&
    (pulseB > 135) &&
    (pulseW < 100)){
    co=co+1;
    if(co>=5){
      Serial.println("PRETO");
      servo3.slowmove(ao,vse);
      break;
    }
  }

  //leitura se a fila está vazia
  //else if((pulseR > 80) && (pulseR<90) &&
  //  (pulseG > 99) && (pulseG<105) &&
  //  (pulseB > 99) && (pulseB<105) &&
  //  (pulseW < 50)){
  //  Serial.println("Fila de leitura vazia...");
  //  i1=i1+1;
  //  Serial.println("valor de i1:");
  //  Serial.println(i1);
  //  if(i1>=5){
  //    break;
  //  }
  //  delay(1000);
  //}
    
  //verificação se a cor está ou nao cadastrada  
  else{
    Serial.println("Desculpe, nao conseguimos identificar a cor....");
    if(i2>=5){
      Serial.println("checamos e realmente a cor e diferente, moveu escorregador");
      Serial.println("valor de i2: ");
      Serial.println(i2);
      servo3.slowmove(ao,vse);
      break;
    }
    else{
      i2=i2+1;
      Serial.println("nao identificamos, vamos checar novamente");
      Serial.println("valor de i2: ");
      Serial.println(i2);
      delay(300);
    }
  }
  delay(300);
 }
  delay(6000);
  cr=0,
  cy=0,
  cb=0,
  cg=0,
  cw=0,
  co=0;

  Serial.println();
  delay(1000);
  Serial.println("encerrou checagem");
  Serial.println("vamos dar sequencia");
  Serial.println("");


  servo2.slowmove(open,50);
  Serial.println("abriu entrega");
  delay(3000);
  
  Serial.println("fechou entrega");
  Serial.println("vamos recomecar!!");
  Serial.println("");
  servo3.slowmove(90,50);

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