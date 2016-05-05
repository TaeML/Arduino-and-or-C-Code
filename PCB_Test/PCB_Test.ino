#include "pitches.h"

int sum = 0;
int sample_count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  /*
  while (sample_count < 10) 
  {
    sum += analogRead(A5);
    sample_count++;
    delay(500);
  }*/
  int sensorValue = digitalRead(7);
  // put your main code here, to run repeatedly:
  float voltage = sensorValue;
  if(voltage == 1)
  {
    if(sum <= 2)
    {
      tone(5,NOTE_A5);
      delay(1000);
      noTone(5);
      sum = sum + 1;
    }
  else if(sum == 3)
  {
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
          noTone(5);
          sum = 0;
  }
  }
  Serial.println(voltage);
  //Serial.println(sensorValue);
  delay(1000);
}
