#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  for(int i=10; i>0; i--){
    lcd.println(i);
    delay(500);
    lcd.clear();
  }
  lcd.print(" Wszystkiego");
  lcd.setCursor(0,1);
  lcd.print(" Najlepszego !");
  lcd.blink();  

}

void loop() {

}
