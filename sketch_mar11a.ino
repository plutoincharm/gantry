int enB = 11;
int in3 = 12;
int in4 = 13;
 
 

void setup()
 
{
 
  // Set all the motor control pins to outputs
 
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
}


void loop()
 
{
 
  // This function will run the motors in both directions at a fixed speed
 
  // Turn on motor A
 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 
  // Set speed to 200 out of possible range 0~255
 
  analogWrite(enB, 255);
 delay(500); 
  // Now change motor directions
 digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
 delay(3000);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);  
   
 analogWrite(enB, 255);
   delay(500);
 
  // Now turn off motors
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);  
 delay(5000);
}
