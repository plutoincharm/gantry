#include <Servo.h>
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
int rot = ((100/6)*200);
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
  analogWrite(enA, 225);
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


 //xaxis(rot,LOW);// x FIXTURE 
 
 zaxis(1000,HIGH);//z 42mm
 delay(500);//CUSHION

 Servo1.write(180); 
 delay(2000); 

  zaxis(1000,LOW);//z
/*
 if(c==3)
   {
    directionControl();
    Serial.print(c);// D12
  }
 else if(c==4)
 {  
  slave(1);
  directionControl();
  //delay(1500);
 }
  
*/
  Serial.print(c);
  xaxis(rot,HIGH);// x fixture

  zaxis(1000,HIGH);//z 24mm downn
  delay(500);//CUSHION

  Servo1.write(120); //drop  
  delay(2000);
 // delay(3500);
  
  
  zaxis(1000,LOW);//z up
  Serial.print(c);
 /* 
 if((c!=1)&&(c!=3)&&(c!=2)&&(c==4))
     delay(1000);
 if((c==1)||(c==3)||(c==2)||(c==4))
     slave(0);
 if((c!=1)&&(c!=3)&&(c!=2)&&(c==4))
     delay(5000);*/
     
slave(0);
  Servo1.write(120);
  xaxis(rot,LOW);
  
      
  //---------------------------




 zaxis(1000,HIGH);//z 42mm
 delay(500);//CUSHION

 Servo1.write(180); 
 delay(2000); 

  zaxis(1000,LOW);//z

  xaxis(rot,HIGH);// x fixture

  zaxis(1000,HIGH);//z 24mm downn
  delay(500);//CUSHION

  Servo1.write(120); //drop  
  delay(2000);
  
  zaxis(1000,LOW);//z up
  Serial.print(c);
    
  slave(0);
  Servo1.write(120);
  xaxis(rot,LOW);

//-------------------------


 
 zaxis(1000,HIGH);//z 42mm
 delay(500);//CUSHION

 Servo1.write(180); 
 delay(2000); 

  zaxis(1000,LOW);//z

  directionControl();
 
   Serial.print(c);
  xaxis(rot,HIGH);// x fixture
  

  zaxis(1000,HIGH);//z 24mm downn
  delay(500);//CUSHION

  Servo1.write(120); //drop  
  //delay(2000);

  
  zaxis(1000,LOW);//z up
  Serial.print(c);
  delay(3000);
     
slave(0);
 delay(500);
  Servo1.write(120);
  xaxis(rot,LOW);

//-------------------------

 
 zaxis(1000,HIGH);//z 42mm
 delay(500);//CUSHION

 Servo1.write(180); 
 delay(1000);  
 slave(1);
 delay(1000);

  zaxis(1000,LOW);//z

 directionControl();
  //delay(1500);

  Serial.print(c);
  xaxis(rot,HIGH);// x fixture

  zaxis(1000,HIGH);//z 24mm downn
  delay(500);//CUSHION

  Servo1.write(120); //drop  
  //delay(2000);
 delay(3500);
  
  
  zaxis(1000,LOW);//z up
  Serial.print(c);

slave(0);
  Servo1.write(120);
   
}


void gantrydrop()
{

   
  zaxis(1000,HIGH);//z 24mm downn
  delay(500);//CUSHION

  Servo1.write(180);  //pick 
  delay(2000);
  
  
  zaxis(1000,LOW);//z up
  
  xaxis(rot,HIGH);// x drop

  zaxis(1000,HIGH);//z 42mm
  delay(500);//CUSHION

  Servo1.write(120);//drop
  delay(500);
   slave(0);
  zaxis(1000,LOW);//z

  xaxis(rot,LOW);// x drop 


  


}

void slave(int x)
{

  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting  
  
}


void loop() 
{

  e=0;
  c=1;
 
  gantrypick();
  
  /*
  
  
  //--------------------
  //1
 
 for(int x = 0; x < 4; x++)
     {
      Serial.print(c);
      gantrypick();
      c++;
     }
  */
  c--;
  c--;
  Serial.print(c);
 

   do
   {
    e++;
  slave(1);
  directionControl();  
  gantrydrop();  
  //directionControl();// D3
  //gantrypick(); 
  //slave(0);//index 
  delay(5000);////time needeeeeeeeeeeeeeeeeeeeeeeed
   
  }while(e<3);
   

 
  slave(1);
  delay(5000);
  slave(0);  
  gantrydrop();
 
/*gantrypick(); 
  gantrydrop();*/

  

} 
   
