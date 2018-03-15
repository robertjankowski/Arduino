void setup() {
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  pinMode(A3,OUTPUT);
  
}

void loop() {
  tone(A3,1212,2000);
  
}

