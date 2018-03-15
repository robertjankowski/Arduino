#define zielona 8
#define zolta 9

String dane = "";
boolean dioda1 = true,dioda2 = true;

void setup() {
  pinMode(zielona,OUTPUT);
  pinMode(zolta,OUTPUT);
  digitalWrite(zolta,LOW);
  digitalWrite(zielona,LOW); 
  Serial.begin(9600); 
}

void loop() {
  if(Serial.available() > 0){
   dane = Serial.readStringUntil('\n');

    if(dane == "zielona"){
      if(dioda1){
        digitalWrite(zielona,HIGH);
        dioda1 = false;
      }
      else{
        digitalWrite(zielona,LOW);
        dioda1 = true;
      }
    }
    else if(dane == "zolta"){
     if(dioda2){
        digitalWrite(zolta,HIGH);
        dioda2 = false;
      }
      else{
        digitalWrite(zolta,LOW);
        dioda2 = true;
      }
    }
    else{
      Serial.println("Nie ma takiej diody");
    }
    
  }

  /*
  if(digitalRead(10) == LOW){
    digitalWrite(9,LOW);
    digitalWrite(8,HIGH);
  }
  else{
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    Serial.println("Uwaga okno otwarte !");
  
    while(digitalRead(10) == HIGH){
     delay(25);
  }
  }
  */
}
