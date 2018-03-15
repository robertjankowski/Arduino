#define red 5
#define green 6
#define blue 7


void setup() {
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  Serial.begin(9600);
  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  digitalWrite(blue,LOW);
}

void loop() {
  int x = analogRead(A4);
  int y = analogRead(A5);
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");


  if(x == 1023){
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
  } else if(x == 0){
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
  }
  if(y == 1023){
    digitalWrite(blue,LOW);
    digitalWrite(red,HIGH);
  } else if(y == 0){
    digitalWrite(green,LOW);
    digitalWrite(blue,HIGH);
  }


}

void LED(int n){
  digitalWrite(n,HIGH);
  delay(1000);
  digitalWrite(n,LOW);
}

