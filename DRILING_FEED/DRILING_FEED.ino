int enA = 11;
int in1 = 12;
int in2 = 13;
 
 

void setup()
 
{
 
  // Set all the motor control pins to outputs
 
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
 
}


void loop()
 
{
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);
 //************************************
  analogWrite(enA, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(500); 
 //************************************  
 digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  delay(1000);
 //************************************
  analogWrite(enA, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(500);  
 //************************************ 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);

  
}
