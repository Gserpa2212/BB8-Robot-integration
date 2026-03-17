#include <SoftwareSerial.h>

// For Bluetooth (HC-05/06)
SoftwareSerial BTSerial(10, 11); // RX, TX

int motorSpeedPin = 3;
int motorDirection1 = 4;
int motorDirection2 = 5;

int motor2SpeedPin = 6;
int motor2Direction1 = 7;
int motor2Direction2 = 8;

char command;

void setup() 
{   
  pinMode(motorSpeedPin, OUTPUT);
  pinMode(motorDirection1, OUTPUT);
  pinMode(motorDirection2, OUTPUT);

  pinMode(motor2SpeedPin, OUTPUT);
  pinMode(motor2Direction1, OUTPUT);
  pinMode(motor2Direction2, OUTPUT);    

  Serial.begin(9600);      // Serial Monitor
  BTSerial.begin(9600);    // Bluetooth module

  Stop();  // Start off stopped
  Serial.println("Ready for Serial or Bluetooth commands (U/D/L/R/S)");
}

void loop() {

  // -------------------------------
  //   SERIAL MONITOR CONTROL
  // -------------------------------
  if (Serial.available() > 0) { 
    command = Serial.read(); 
    Serial.print("Serial Command: ");
    Serial.println(command);
    handleCommand(command);
  }

  // -------------------------------
  //   BLUETOOTH CONTROL
  // -------------------------------
  if (BTSerial.available() > 0) { 
    command = BTSerial.read(); 
    Serial.print("BT Command: ");
    Serial.println(command);
    handleCommand(command);
  }
}

// Centralized command handler
void handleCommand(char cmd) {
  switch (cmd) {
    case 'U':  
      forward();
      break;
    case 'D':  
      back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    case 'S':
      Stop();
      break;
    default:
      Stop();
      break;
  }
}

void forward()
{
  analogWrite(motorSpeedPin, 60);
  digitalWrite(motorDirection1, HIGH);
  digitalWrite(motorDirection2, LOW);

  analogWrite(motor2SpeedPin, 60);
  digitalWrite(motor2Direction1, HIGH);
  digitalWrite(motor2Direction2, LOW);
}

void back()
{
  analogWrite(motorSpeedPin, 60);
  digitalWrite(motorDirection1, LOW);
  digitalWrite(motorDirection2, HIGH);

  analogWrite(motor2SpeedPin, 60);
  digitalWrite(motor2Direction1, LOW);
  digitalWrite(motor2Direction2, HIGH);
}

void left()
{
  analogWrite(motorSpeedPin, 60);
  digitalWrite(motorDirection1, HIGH);
  digitalWrite(motorDirection2, LOW);

  analogWrite(motor2SpeedPin, 60);
  digitalWrite(motor2Direction1, LOW);
  digitalWrite(motor2Direction2, HIGH);
}

void right()
{
  analogWrite(motorSpeedPin, 60);
  digitalWrite(motorDirection1, LOW);
  digitalWrite(motorDirection2, HIGH);

  analogWrite(motor2SpeedPin, 60);
  digitalWrite(motor2Direction1, HIGH);
  digitalWrite(motor2Direction2, LOW);
}

void Stop()
{
  analogWrite(motorSpeedPin, 0);
  digitalWrite(motorDirection1, LOW);
  digitalWrite(motorDirection2, LOW);

  analogWrite(motor2SpeedPin, 0);
  digitalWrite(motor2Direction1, LOW);
  digitalWrite(motor2Direction2, LOW);
}
