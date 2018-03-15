#include <LiquidCrystal.h>
LiquidCrystal lcd (2, 3, 4, 5, 6, 7);

#define startButton 8
#define stopButton 9

int mins = 0;
int sec = 0;
int ms = 0;
boolean startButtonState;
boolean stopButtonState;

void setup() {

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Simple stopwatch");
  lcd.setCursor(0, 1);
  lcd.print("00:00.00");
  pinMode(startButton, INPUT_PULLUP);
  pinMode(stopButton, INPUT_PULLUP);

}

void loop() {

startStopwatch(); //start stopwatch

}

void startStopwatch()

{

startButtonState = digitalRead(startButton); //read button's state

if (startButtonState == LOW)//if start button was pressed

{

while (1) //while loop to write time and increase it by 'miliseconds' function

{

miliseconds();

stopStopwatch();//check after every single milisecond if "stop button" was pressed and if yes stop increasing time

}

}

}

void stopStopwatch()

{

stopButtonState = digitalRead(stopButton); //read button's state

if (stopButtonState == LOW)//if button was pressed

{

while (1)

{

lcd.setCursor(10, 1);

lcd.print("Finish"); //display inscription

}

}

}

void miliseconds() //display miliseconds

{

if (ms < 10) //if number needs one position

{

lcd.setCursor(7, 1);

lcd.print(ms);

lcd.setCursor(6, 1);//before number print "0"

lcd.print(0);

}

else //if number needs two positions

{

lcd.setCursor(6, 1);

lcd.print(ms);

}

delay(9);//with 10 ms delay, program was a little bit delayed than the true stopwatch

ms++;//increase miliseconds

if (ms == 100) //after every 100 ms

{

sec++;//increase seconds by 1

ms = 0;//zero miliseconds

seconds();//trigger 'seconds' function

}

}

void seconds()//display seconds

{

if (sec < 10)//same as in 'miliseconds'

{

lcd.setCursor(4, 1);

lcd.print(sec);

lcd.setCursor(3, 1);

lcd.print(0);

}

else

{

lcd.setCursor(3, 1);

lcd.print(sec);

}

if (sec == 60)//like in 'miliseconds'

{

mins++;

minutes();

sec = 0;

lcd.setCursor(3, 1);

lcd.print("00"); //print "00" because after every 60 seconds ,there should be counting from the beginning

}

}

void minutes()

{

if (mins < 10)//same as in 'seconds'

{

lcd.setCursor(1, 1);

lcd.print(mins);

lcd.setCursor(0, 1);

lcd.print(0);

}

else

{

lcd.setCursor(0, 1);

lcd.print(mins);

}

}
