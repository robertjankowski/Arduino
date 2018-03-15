int odczytanaWartosc = 0;
int prog = 0;
float pomiar = 0;
int napiecie = 0;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A2, OUTPUT); //buzer1
  pinMode(A3, OUTPUT); //buzer2
  Serial.begin(9600);
}

void loop() {
  odczytanaWartosc = analogRead(A5);
  prog = analogRead(A4);
  napiecie = map(prog, 0, 1021, 0, 500);
  Serial.println(napiecie);

  if (odczytanaWartosc < napiecie) {
    digitalWrite(8, HIGH);
    tone(A3, 4000);
    digitalWrite(7, HIGH);
    tone(A2, 3000);

  } else {
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    noTone(A3);
    noTone(A2);
  }
  if (digitalRead(8) == HIGH) {
    pomiar = prog * (5.0 / 1021.0);
    //Serial.print(pomiar);
    //Serial.println(" V");
  }
  delay(50);

}



