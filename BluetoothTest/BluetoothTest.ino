void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop()
{
    if (Serial.available() > 0) //If remote control is true execute the next line of code
    {
        char ch = Serial.read();  //reads the string value from the Bluestick Controll application
        Serial.print("Received: "); //Displays the string value of the button that was pressed
        Serial.println(ch);
    
        }
    }
}
