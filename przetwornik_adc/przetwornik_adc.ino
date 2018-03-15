int odczytanaWartosc = 0;
float napiecie = 0;

void setup() {
 Serial.begin(9600);
 for(int i=3; i<8; i++){
  pinMode(i,OUTPUT);
 }
 
}

void loop() {
  odczytanaWartosc = analogRead(A5);
  odczytanaWartosc = map(odczytanaWartosc,0,1023,1,6);
  Serial.println(odczytanaWartosc);
  switch(odczytanaWartosc){
    case 1:
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      break;
    case 2:
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
     break;
    case 3:
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      break;
     case 4:
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(7,LOW);
      break;
     case 5:
     case 6:
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
      break; 
  }
  delay(75);
  
}
