#define trig 12
#define echo 11
#define red 5
#define green 6
#define blue 7

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {

  Serial.print(zmierz());
  delay(500);
  RGB();

}
int zmierz() {
  long czas, dystans;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  czas = pulseIn(echo, HIGH);
  dystans = czas / 58;
  return dystans;
}
void zakres(int a, int b) {
  int x = zmierz();
  if ( x > a && x < b) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }
}
void RGB()
{
  int zmiana = 0;
  int zmianaLosowa = map(zmierz(),200,0,0,255);
  analogWrite(red, zmianaLosowa);
  analogWrite(green, zmianaLosowa/2);
  analogWrite(blue, 255 - zmianaLosowa);
  delay(10);
}


