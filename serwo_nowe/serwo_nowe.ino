#include <Servo.h>

Servo s;
int pozycja = 0;
int zmiana = 5;
String dane = "";


void setup() {
  s.attach(9);
  Serial.begin(9600);

}

void loop() {
  if(Serial.available() > 0){
    dane = Serial.readStringUntil('\n');
  }
  if(dane.toInt() < 180 && dane.toInt() > 0){
    s.write(dane.toInt());
  }
  
  
  /* //obraca sie co 250ms o zmiane
  if(pozycja < 180){
    s.write(pozycja);
  } else{
    pozycja = 0;
  }

  pozycja += zmiana;
  delay(250);
  */
}
