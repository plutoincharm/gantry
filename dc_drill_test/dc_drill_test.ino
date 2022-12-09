
int enA = 11;
int in1 = 12;
int in2 = 13;
int obstaclePin = 5;  
int hasObstacle = HIGH;

void setup() {


  pinMode(obstaclePin, INPUT);
  Serial.begin(9600); 
 
//DC
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
   
}



void directionControl()
{


  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);
 //************************************
  analogWrite(enA, 100);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  for(int i=1; i!=0; i++)
  {

  hasObstacle = digitalRead(obstaclePin);
  if (hasObstacle == LOW)
  {
   
   digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  delay(3000);
 //************************************
  analogWrite(enA, 200);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(1000);  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  delay(1000);
 i=0;
     
  }
  }

/*
   
   if(digitalRead(IRSensor)==HIGH)      //Check the sensor output
  {

    digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);
 //************************************
  analogWrite(enA, 150);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
   
  }
  else //if(digitalRead(IRSensor)==HIGH)
  {
    digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  delay(2000);
 //************************************
  analogWrite(enA, 150);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(1000);  
  }
  delay(100);             

  
  
  /*
  
  
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);
 //************************************
  analogWrite(enA, 150);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(500); 
 //************************************  
 digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  delay(2000);
 //************************************
  analogWrite(enA, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(1000);  
 //************************************ 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(500);
*/
  
}



void loop() 
{

directionControl();
delay(200000);



  
} 
   
