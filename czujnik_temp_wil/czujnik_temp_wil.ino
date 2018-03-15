#include <DHT.h>
#include <math.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(3,4,5,6,7,8,9);
DHT czujnik(10,DHT11);

float wil,temo,indeks;

byte znak_stopnia[8] = {
  0b00100,
  0b01010,
  0b10001,
  0b01010,
  0b00100,
  0b00000,
  0b00000,
  0b00000
};

void setup() {
  lcd.createChar(0,znak_stopnia);
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600);
  Serial.println("Pomiar temperatury i wilgotności");
  czujnik.begin();  

  lcd.setCursor(0,0);
  lcd.print("Czujnik temp");
  lcd.setCursor(0,1);
  lcd.print("i wilgotnosci");
  delay(2000);
}

void loop() {
 delay(2000);
 lcd.clear();
  
 wil = czujnik.readHumidity();
 temo = czujnik.readTemperature();
 indeks = czujnik.computeHeatIndex(temo,wil,false);
 if (isnan(wil) & isnan(temo) & isnan(indeks)){
    Serial.println("Błąd oczytu z czujnika. Sprawdź połączenie");
    return;  
 }
 /*
 Serial.println("==============================");
 Serial.print("Wiglotnosc: ");
 Serial.print(wil);
 Serial.println(" %");
 Serial.print("Temperatura: ");
 Serial.print(temo);
 Serial.println(" *C");
 Serial.print("Indeks temp: ");
 Serial.print(indeks);
 Serial.println(" *C");
 Serial.println("==============================");
 */ 

 lcd.setCursor(0,0);
 lcd.print("Temp: ");
 lcd.setCursor(7,0);
 lcd.print(temo);
 lcd.setCursor(10,0);
 lcd.print(char(0));
 lcd.print("C");

 lcd.setCursor(0,1);
 lcd.print("Wilg: ");
 lcd.setCursor(7,1);
 lcd.print(wil);
 lcd.setCursor(10,1);
 lcd.print(" %");
 
}
