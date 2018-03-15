
void setup() {
 pinMode(A3,OUTPUT);
}

void loop() {
  for(int i=2000; i<6000; i+=2){
   tone(A3,i);
  }
}
