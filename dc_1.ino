#include <Servo.h>


#include <Wire.h>
const int z_stepPin = 3; 
const int z_dirPin = 4; 
const int z_enPin = 2;
const int x_stepPin = 9; 
const int x_dirPin = 8; 
const int x_enPin = 7;
const int servoPin = 6;
Servo Servo1;  // create servo object to control a servo
// twelve servo objects can be created on most boards
 

void setup()

 {
  Servo1.attach(servoPin);
  // Sets the two pins as Outputs
  pinMode(z_stepPin,OUTPUT); 
  pinMode(z_dirPin,OUTPUT);

  pinMode(z_enPin,OUTPUT);
  digitalWrite(z_enPin,LOW);

    pinMode(x_stepPin,OUTPUT); 
  pinMode(x_dirPin,OUTPUT);

  pinMode(x_enPin,OUTPUT);
  digitalWrite(x_enPin,LOW);
   Servo1.write(120); 
   delay(1000);

   
}

void loop() {


  
 
 /*
     Servo1.write(180); 
   delay(1000);*/
   
     digitalWrite(z_dirPin,LOW ); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation

   
  for(int x = 0; x < 20*200; x++) 
{
    digitalWrite(x_stepPin,HIGH); 
    delay(.5); 
    digitalWrite(x_stepPin,LOW); 
    delay(.5); 
  } 

  delay(1000);
  digitalWrite(x_dirPin,HIGH );

     
  for(int x = 0; x < 20*200; x++) 
{
    digitalWrite(x_stepPin,HIGH); 
    delay(7); 
    digitalWrite(x_stepPin,LOW); 
    delay(7); 
  } 
   
/*
    digitalWrite(x_dirPin,LOW ); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
   
  for(int x = 0; x < 2000; x++) 
{
    digitalWrite(x_stepPin,HIGH); 
    delay( 1); 
    digitalWrite(x_stepPin,LOW); 
    delay(1); 
  } 

  delay(1000);

 
 

      
   
  
  
    digitalWrite(x_dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
   
  for(int x = 0; x < 2000; x++) 
{
    digitalWrite(x_stepPin,HIGH); 
    delay( 1); 
    digitalWrite(x_stepPin,LOW); 
    delay(1); 
  } 

  delay(1000);
 
   
    digitalWrite(z_dirPin,HIGH ); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
   
  for(int x = 0; x < 1200; x++) 
{
    digitalWrite(z_stepPin,HIGH); 
    delay(1); 
    digitalWrite(z_stepPin,LOW); 
    delay(1); 
  } 

  delay(1000);
  
    Servo1.write(130); 
   delay(5000);

    */

  
}
