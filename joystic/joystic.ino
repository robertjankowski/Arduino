#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);
Servo s;

int X = 0;
int val;

void setup() {
 s.attach(11);
 pinMode(A5,INPUT);
 digitalWrite(A5,HIGH);
 lcd.begin(16,2);
}

void loop() {
  val = analogRead(X);
  val = map(val,0,1023,0,180);
  s.write(val);
  lcd.setCursor(0,0);
  lcd.print("Kat w stopniach: ");
  lcd.setCursor(0,1);
  lcd.print(val);
  
  if(!digitalRead(A5)){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Przycisk");
    lcd.setCursor(0,1);
    lcd.print("wcisniety");
  }
  
  delay(250);
  lcd.clear();

 
}
