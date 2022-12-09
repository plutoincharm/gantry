// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 6; 
// Create a servo object 
Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
      Servo1.write(120); 
   delay(1000); 
}
void loop(){ 
  
}
  
