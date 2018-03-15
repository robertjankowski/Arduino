#define dioda 3

byte wypelnienie = 0;
int zmiana = 5;

void setup() {
  pinMode(dioda,OUTPUT);

}

void loop() {
   analogWrite(dioda,wypelnienie);
   wypelnienie += zmiana;
    if( wypelnienie==255)
    {
      while(wypelnienie!=0)
          {
          wypelnienie-=zmiana;
          analogWrite(dioda,wypelnienie);
          delay(50);
          }
    }

  
   delay(50);
}
