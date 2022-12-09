#include <Servo.h>
//#include <VarSpeedServo.h> 
#include <Wire.h>
const int x_stepPin = 9; 
const int x_dirPin = 8; 
const int x_enPin = 7;
const int z_stepPin = 3; 
const int z_dirPin = 4; 
const int z_enPin = 2;
const int servoPin = 6;
int enA = 11;
int in1 = 12;
int in2 = 13;
int c = 1;
int e = 1;
int obstaclePin = 5;  
int hasObstacle = HIGH;

Servo Servo1;

void setup() {
  
  Wire.begin();
  Serial.begin(9600);
  
  Servo1.attach(servoPin); 
  Servo1.write(180);
  delay(1000); 
  Servo1.write(120); 
  delay(1000); 
  
  pinMode(x_stepPin,OUTPUT); 
  pinMode(x_dirPin,OUTPUT);
  pinMode(x_enPin,OUTPUT);
  digitalWrite(x_enPin,LOW);


  pinMode(z_stepPin,OUTPUT); 
  pinMode(z_dirPin,OUTPUT);
  pinMode(z_enPin,OUTPUT);
  digitalWrite(z_enPin,LOW);
//DC
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(obstaclePin, INPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
}

void xaxis (int step,char dir[] )
{
 
    digitalWrite(x_dirPin,dir);
     
for(int x = 0; x < step; x++) 
{
    
    digitalWrite(x_stepPin,HIGH); 
    delay(1); 
    digitalWrite(x_stepPin,LOW); 
    delay(1); 
  } 

  
}


void zaxis (int step,char dir[])
{

    digitalWrite(z_dirPin,dir); 
    
 for(int x = 0; x < step; x++)
 {
    digitalWrite(z_stepPin,HIGH);
    delay(1);
    digitalWrite(z_stepPin,LOW);
    delay(1);
  } 

  
}

void directionControl()
{


  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(500);
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
  delay(1500);
 //************************************
  analogWrite(enA, 200);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  delay(1000);  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
 // delay(1000);
 i=0;
     
  }

}
}

void gantrypick()
{


 xaxis(2400,LOW);// x FIXTURE 
 
 zaxis(1400,HIGH);//z 42mm
 delay(500);//CUSHION

 Servo1.write(180); 
 delay(2000); 

  zaxis(1400,LOW);//z

 if((c==4)||(c==3))
  directionControl();// D12

 //*************************
  
  xaxis(2400,HIGH);// x fixture

  zaxis(800,HIGH);//z 24mm downn
  delay(500);//CUSHION

  Servo1.write(120); //drop  
  delay(2000);
 // delay(3500);
  
  
  zaxis(800,LOW);//z up
  
 if((c==1)||(c==3)||(c==2))
     slave(0);

  Servo1.write(120);
  
      
  //---------------------------

  
}


void gantrydrop()
{

   
  zaxis(800,HIGH);//z 24mm downn
  delay(500);//CUSHION

  Servo1.write(180);  //pick 
  delay(2000);
  
  
  zaxis(800,LOW);//z up

 /*if(e==1) 
  slave(0);
  //delay(1000);
*/
  xaxis(2400,HIGH);// x drop

  zaxis(1400,HIGH);//z 42mm
  delay(500);//CUSHION

  Servo1.write(120);//drop
  //delay(1000);

  zaxis(1400,LOW);//z

  xaxis(2400,LOW);// x drop 


  


}

void slave(int x)
{

  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting  
  
}


void loop() 
{

  e=c=1;
  //--------------------
  //1
 
 for(int x = 0; x < 4; x++)
     {
      gantrypick();
      c++;
     }
  
  c--;
  c--;
  //Serial.print(c);
    
 /* directionControl();// D1
  delay(1000);
 

  slave(0);//index
  delay(6000);
  slave(1);//t1
  directionControl();// D2
  delay(5000);

  delay(1000);
  slave(1);//t1
    ///doubt-------------------------------------
  //gantrydrop();  
  slave(0);//index
  delay(6000);
  slave(1);//t2
  directionControl();// D3
  delay(5000);
  
  //gantrydrop();

  slave(0);//index
  delay(6000);
 slave(1);//t3
 directionControl();// D4
 delay(5000);

 //gantrydrop();
 
  slave(1);//t4
  delay(3000);

*/
  //------------------------------------

  e=5;
 // delay(1000);
  slave(1);//t1
  delay(5000);//time needeeeeeeeeeeeeeeeeeeeeeeed
  slave(0);//index
  delay(5000);
      //doubt-------------------------------------

    
  slave(1);//t2  
  gantrydrop();  
   //directionControl();// D3
  gantrypick(); 
  //slave(0);//index 
  delay(5000);////time needeeeeeeeeeeeeeeeeeeeeeeed

  slave(1);//t3
  gantrydrop();  
   //directionControl();// D3
  gantrypick(); 
  //slave(0);//index 
  delay(5000);////time needeeeeeeeeeeeeeeeeeeeeeeed


  /*
  gantrydrop();
  slave(1);//t3
  directionControl();// D4
  gantrypick(); 
  slave(0);//index
  delay(5000);
  */
 
  slave(1);//t4
  gantrydrop();
  gantrypick(); 
  gantrydrop();

  //------------------------------------

  

} 
   
