// pomiar napiecia na fotorezystorze

#include <LiquidCrystal.h> 
LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
 lcd.begin(16,2);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Nap. odczytane");
 lcd.setCursor(0,1);
 lcd.print("0.00 V");

}
double odczyt = 0;

void loop() {
  odczyt = analogRead(A0)*5.0/1023.0; // fotorezystor
  lcd.setCursor(0,1);
  lcd.print(odczyt);
  lcd.print(" V");
  delay(100);

}
