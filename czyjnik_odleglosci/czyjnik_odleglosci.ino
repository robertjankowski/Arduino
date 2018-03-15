#define trig 12
#define echo 11
void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(3,OUTPUT);
}

void loop() {
  
  Serial.print(zmierz());
  Serial.println(" cm");
  zakres(3,150);
  delay(500);

}
int zmierz(){
  long czas,dystans;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  czas = pulseIn(echo,HIGH);
  dystans = czas / 58;
  return dystans;
}
void zakres(int a,int b){
  int x = zmierz();
  if( x > a && x < b){
      digitalWrite(3,HIGH);
  } else {
      digitalWrite(3,LOW);
  }
}

