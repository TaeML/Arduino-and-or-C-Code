#include "pitches.h"

const int buzzerPin = 5;
//const int photoresistorPin = 0;
float val;
int x = 2;



void setup() 
{
  Serial.begin(9600);
  pinMode(buzzerPin,OUTPUT);
 
}

void loop() 
{
  // put your main code here, to run repeatedly:
val = analogRead(0)*10/1024;
//if((x <= 4))
//{
  Serial.println(val);
  //tone(5,NOTE_A5);
  x = x + 1;
  delay(1000);
//}
/*else if(x == 5)
{
  Serial.println("music");  

          tone(5,NOTE_A5);
          delay(200);
          tone(5,NOTE_B5);
          delay(200);
          tone(5,NOTE_C5);
          delay(200);
          tone(5,NOTE_B5);
          delay(200);
          tone(5,NOTE_C5);
          delay(200);
          tone(5,NOTE_D5);
          delay(200);
          tone(5,NOTE_C5);
          delay(200);
          tone(5,NOTE_D5);
          delay(200);
          tone(5,NOTE_E5);
          delay(200);
          tone(5,NOTE_D5);
          delay(200);
          tone(5,NOTE_E5);
          delay(200);
          tone(5,NOTE_E5);
          delay(200);
          x = x + 1;
}
else
{
//digitalWrite(buzzerPin, HIGH);
noTone(5);

}
*/

}
