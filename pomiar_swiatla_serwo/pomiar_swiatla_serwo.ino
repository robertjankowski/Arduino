#include <Servo.h>

Servo s;
byte pozycja = 0;
int back = 0;

void setup() {
  s.attach(11);
  Serial.begin(9600);

}

void loop() {
 int odczyt = analogRead(A5);
 pozycja = map(odczyt,90,400,0,180);

 if(abs(pozycja - back) > 3){
  s.write(pozycja);
  back = pozycja;
 }

 Serial.println(odczyt);
 delay(200);

}
