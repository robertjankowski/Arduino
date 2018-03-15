#include <IRremote.h>
int input_pin = 2; // wpisujemy nazwę pinu, po którym nastepuje komunikacja
IRrecv irrecv(input_pin);
decode_results signals;
 
void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn(); // włączenie odbierania danych
    pinMode(9,OUTPUT);
}
 
void loop() {
if (irrecv.decode(&signals)) {
        Serial.println(signals.decode_type); // typ nadajnika
        Serial.print(F("wynik = 0x"));
        Serial.println(signals.value, HEX); // wynik w systemie szesnatkowym
        Serial.println(signals.bits); // ilość przesłanych danych
        irrecv.blink13(true); // mrugamy diodami w arduino
        
        
        if (signals.value == 0x9716BE3F)
        {
          Serial.println("Wcisnieto klawisz 1");
          digitalWrite(9,HIGH);
          delay(2000);
          digitalWrite(9,LOW);
          
        }
        
        // ... i tak dalej
        
        irrecv.resume(); // nasłuchujemy na następne nadanie     
    }
}
