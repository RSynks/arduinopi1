int LED1 = 13; //PORTA 13 DIGITAL
int LED2 = 12; //PORTA 12 DIGITAL


void setup() {
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);

}

void loop() {
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,LOW);
  delay(2000);

  digitalWrite(LED1,LOW);
  digitalWrite(LED2,HIGH);
  delay(2000);

  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  delay(5000);

  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  delay(1000);

}
