/* The following two libraries are included with the Arduino IDE  */
#include <SPI.h>       // supports SPI serial communication and defines analog pins
#include <EEPROM.h>
#include <Wire.h>      // I2C support (currently not implemented)
//#include <L3G4200D.h>  // 3-axis Gyro (currently not implemented)

#include "pitches.h"

#define FALSE 0        // LOW
#define TRUE  1        // HIGH

/**************** Robot Configuration **************
 * Set Rover, Pinouts, Connection Type, and Pinger *
 ***************************************************/
#include "pinouts_robot.h"    // replace with your pinout



#define Rosco FALSE
#define PaperBot TRUE
#define bluetooth FALSE       // Leonardo class rovers - Serial used for USB, Serial1 for bluetooth (i.e., USART)
#define pinger FALSE          // FALSE if no ultrasonic sensor is used.
#define debug  FALSE
#define blinkled TRUE

unsigned long ping_interval = 5000;  // 5 seconds
unsigned long current = millis();
unsigned long endState = current + ping_interval;
// note: #define is a text substitution pre-processor directive
 
/**************** Global Variables ****************
 * source: Found in CommunicationRobotPilot Folder  *
 ***************************************************/
const int16_t FLAG = -128;  // value returned by readFuelGauge when called
                            // by sendDataon undervoltage condition
// Timer Variable
unsigned long timer; 
// unsigned 32-bit

//Sets the disable of the robot to FALSE


//Enables the anthem song to play at the beginning
int mus = 0;

unsigned int count = 0;
int16_t temp_value = 0x005;

//Sets the stall variable to 0 (starting point)

//Sets the umber of hits to 0



int speaker = 4;
int sum = 0;
int stall1 = 0;
int stall2 = 0;
boolean tag_delay = FALSE;
boolean disable = FALSE;




 int length = 70;   //Sets the length of the array to determine the index of each note on the array.
  String notes[] = {"G4","G4", "G4", "D#4/Eb4", "A#4/Bb4", "G4", "D#4/Eb4","A#4/Bb4", "G4", "D5", "D5", "D5", "D#5/Eb5", "A#4/Bb4", "F#4/Gb4", "D#4/Eb4","A#4/Bb4", "G4", "G5","G4","G4","G5","F#5/Gb5", "F5","E5","D#5/Eb5","E5", "rest", "G4", "rest","C#5/Db5","C5","B4","A#4/Bb4","A4","A#4/Bb4", "rest", "D#4/Eb4", "rest", "F#4/Gb4", "D#4/Eb4","A#4/Bb4", "G4" ,"D#4/Eb4","A#4/Bb4", "G4"}; 
  int beats[] = { 8, 8, 8, 6, 2, 8, 6 , 2 ,16 , 8, 8, 8, 6, 2, 8, 6, 2, 16,8,6,2,8,6,2,2, 2, 2,6,2,2,8,6,2,2,2,2,6,2,2,9,6,2,8,6,2,16  };
  int tempo = 50;   //Sets the tempo (speed) that the notes are played.
  

boolean collisionDetection = FALSE;
 
void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);      // legacy rovers operated at 57600
  #if bluetooth
  Serial.begin(9600);
  #endif

  asm("in r24, 0x35");
  asm("ori r24, 0x80");
  asm("out 0x35, r24");
  asm("out 0x35, r24");
  //LEDinit();
  /*
  while (!Serial) {
    ; // wait for USB serial port to connect. Needed for Leonardo only
  }
  */
  
  timer = millis();        // telemetry  
  // init_servos();        // Rosco uses servos
  
  pinMode(led, OUTPUT);    // initialize LED indicator as an output.
  pinMode(speakerPin, OUTPUT);  //Sets the speaker as an output
 
  // Configure motorshield and insure motors are off. 
  // If included in design, turn off collisionDetection
  setup_TB6612FNG();    // sparkfun_TB6612FNG
}



void loop()
{

digitalWrite(LAS,HIGH);
  //Plays the anthem of the song before we start the laser tag game.
 while(mus == 0)
  {
     mus = 1;
      for (int i = 0; i < length; i++) 
      {
      if (notes[i] == "rest") {
        delay(beats[i] * tempo);
      } else {
        playNote(notes[i], beats[i] * tempo);      
      }
      delay(tempo / 2);
      }
 
    
  }
  
  #if bluetooth
  if(Serial.available() ) 
  commandDecoder();  // note: Leonardo does not support serialEvent() handler
 // digitalWrite(LAS,HIGH);
  #else
  if(Serial1.available() ) 
  commandDecoder();
  digitalWrite(LAS,HIGH);
  #endif
  digitalWrite(LAS,LOW);

  int sensorValue = digitalRead(3);
float voltage = sensorValue;
delay(1000);
Serial.println(voltage);

if(voltage == 1)
{
  if(sum < 2)
  {
  tag_delay = TRUE;
  if(tag_delay == TRUE)
  {
  tone(2,NOTE_A5);
  delay(1000);
  noTone(2);
  sum = sum +1;
  Serial.println(sum);
  while(stall1 <= 4)
  { 
    auto_turn();
    delay(500);
    
    stall1 = stall1 + 1;
    Serial.println(stall1);
  }
  enable_Bot();
  tag_delay = FALSE;
  stall1 = 0;
  }
  }

  else if(sum == 2)
  {
  
          tone(2,NOTE_A5);
          delay(200);
          tone(2,NOTE_B5);
          delay(200);
          tone(2,NOTE_C5);
          delay(200);
          tone(2,NOTE_B5);
          delay(200);
          tone(2,NOTE_C5);
          delay(200);
          tone(2,NOTE_D5);
          delay(200);
          tone(2,NOTE_C5);
          delay(200);
          tone(2,NOTE_D5);
          delay(200);
          tone(2,NOTE_E5);
          delay(200);
          tone(2,NOTE_D5);
          delay(200);
          tone(2,NOTE_E5);
          delay(200);
          tone(2,NOTE_E5);
          delay(200);
          noTone(2);

          disable = TRUE;
          if(disable == TRUE)
            {
              disable_Bot();
            while(stall2 <=10)
              {
              delay(1000);
              stall2 = stall2 + 1;
              Serial.println(stall2);
              }
              disable = FALSE;
              stall2 = 0;
            }
            enable_Bot();
          sum = 0;
  }
}
  
  
 
                
  
  

/*
  if (tagged == FALSE)
  {
    //Recieve value from emitter
    tagged = TRUE;
   // tone(3,NOTE_C5);
    count = count + 1;
  }

  if (current == endState)&&(tagged == TRUE)&&(count == 3)
  {
    count = 0;
    tagged = FALSE;
    sendData();     // Call to send Data for Control Panel Feedback

    if(temp_value == 85)
    {
    temp_value = 0x0005;
    }
  }
  */
  
  // future: replace with watchdog timer interrupt  ****

  /*
  if (millis() > getNextPing()){   
    sendWordPacket(EMERGENCY_ID,WATCHDOG_TIMEOUT);
    
    #if bluetooth                                // if packet sent over USART=>bluetooth,  
      Serial.print("Emergency exception 0x0");   // send duplicate data as text to
      Serial.println(WATCHDOG_TIMEOUT,HEX);      // USB=>Arduino IDE Serial Monitor.
    #endif 
    */
    // ****** SLEEP PAPERBOT *******
    
    // ##### JEFF CHANGED
    // Until the above-mentioned "SLEEP PAPERBOT" is implemented,
    // let's reset to allow another ping interval to avoid the
    // constant barrage of an exception message on every loop.
  //  updateNextPing();
    // #####
  

  
 

  // If using a Pinger detect a collision
  /*
  #if pinger == TRUE
      if (collisionDetection)
      {
        if (checkSonar()) 
        {
          // insure motors are off and turn off collisionDetection
          stopMotors();
          collisionDetection = FALSE;   // rover is not moving
          // send Emergency Stop message
        }
      }
  #endif
  */

  
  
}  // end of loop
