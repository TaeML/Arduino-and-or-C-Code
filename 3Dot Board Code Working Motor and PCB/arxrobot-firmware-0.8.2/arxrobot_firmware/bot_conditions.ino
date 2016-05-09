
//Disables the robot motor functions.
void disable_Bot()
{
  digitalWrite(STBY, LOW);  // TB6612FNG enabled 
  digitalWrite(AIN1, LOW);  // motor 1 short brake
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);  // motor 2 short brake
  digitalWrite(BIN2, LOW);
 
}

//Enables the robot motor functions.
void enable_Bot()
{
  digitalWrite(STBY, HIGH);  // TB6612FNG enabled 
  digitalWrite(AIN1, LOW);  // motor 1 short brake
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);  // motor 2 short brake
  digitalWrite(BIN2, LOW);
}

void auto_turn()
{
  digitalWrite(STBY, HIGH);  // TB6612FNG enabled 
  digitalWrite(AIN1, HIGH);  // motor 1 short brake
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);  // motor 2 short brake
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMA,255);
  analogWrite(PWMB,255);
  
}

void auto_forward()
{
  digitalWrite(STBY, HIGH);  // TB6612FNG enabled 
  digitalWrite(AIN1, HIGH);  // motor 1 short brake
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);  // motor 2 short brake
  digitalWrite(BIN2, LOW);
  analogWrite(PWMA,255);
  analogWrite(PWMB,255);
}

