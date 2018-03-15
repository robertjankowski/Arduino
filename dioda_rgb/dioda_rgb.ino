#define red 3
#define green 5
#define blue 6

void setup() {
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
}

void loop() {
  int zmiana = 0;
  for(zmiana = 0; zmiana<255; zmiana++){
    analogWrite(red,zmiana);
    analogWrite(green,zmiana);
    analogWrite(blue,255-zmiana);
    delay(10);
  }
}
