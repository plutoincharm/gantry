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
int y=5;

Servo Servo1;

void setup() {
  
  Wire.begin();
  Serial.begin(9600);
  
  Servo1.attach(servoPin); 
  //Servo1.write(180);
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

void gantrypick()
{


 zaxis(1000,HIGH);//z 42mm
 delay(1000);


   Servo1.write(170); 
   delay(2000); 

  zaxis(1000,LOW);//z
  

 //*************************
  
  xaxis(2400,HIGH);// x fixture

  zaxis(1000,HIGH);//z 24mm downn
  delay(1000);

   Servo1.write(120); //drop  
  delay(5000);
  
  
  zaxis(1000,LOW);//z up
  delay(1500);

 // slave(0);
  //delay(1000);

 // xaxis(2400,HIGH);// x LH thread pick
  //delay(1000);

    
  //---------------------------

  
}


void gantrydrop()
{
    
  zaxis(1000,HIGH);//z 24mm downn
  delay(1000);

   Servo1.write(180);  //pick 
   delay(1000);
  
  
  zaxis(1000,LOW);//z up
  delay(1500);

 // slave(0);
  delay(1000);

  xaxis(2400,LOW);// x drop

  zaxis(1000,HIGH);//z 42mm
  delay(1000);

   Servo1.write(120);//drop
  delay(1000);

  zaxis(1000,LOW);//z

 // xaxis(2400,LOW);// x FIXTURE


 /*


 
 //-----------------------
 zaxis(1400,HIGH);//z 42mm
 delay(1000);


  //myservo.write(0,30,true); 
  //delay(1000);

  zaxis(1400,LOW);//z
  

 //*************************
  
  xaxis(2400,LOW);// x fixture

  zaxis(800,HIGH);//z 24mm downn
  delay(1000);

  //myservo.write(30,150,true); //drop  
  //delay(1000);
  
  
  zaxis(800,LOW);//z up
  delay(1500);

  slave(0);
  delay(1000);

  xaxis(2400,HIGH);// x LH thread pick
  //delay(1000);

    
  //---------------------------

  */
}

void directionControl()
{
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
  delay(2500);

  
}

void slave(int x)
{

  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting  
  
}


void loop() 
{


for(int x = 0; x <4 ; x++) 
{
  // delay(1000);
   //Servo1.write(120);
   delay(1000);
   Servo1.write(180);
   delay(2500); 
   zaxis(1400,LOW);//z up 7rot(42mm)
  xaxis(2400,HIGH);// x fixture(72mm)
  zaxis(800,HIGH);//z 24mm downn
  delay(2000);//CUSHION
  Servo1.write(120); //drop  
  delay(3000);
 // delay(3500);
   zaxis(800,LOW);//z up
   slave(0);
   delay(2500);
   Servo1.write(120);
   xaxis(2400,LOW);// conv
   zaxis(1400,HIGH);//z
   delay(1000);

}   

  directionControl();
  delay(6000);
  slave(0);
  delay(6000);
  
for(int x = 0; x <3 ; x++) 
{
  delay(1000);
  slave(1);//t1
  directionControl();
  delay(8000);//time needeeeeeeeeeeeeeeeeeeeeeeed
  slave(0);//index
  delay(6000);
  
}

  delay(1000); 
  slave(1);//t1
  delay(8000);

for(int x = 0; x <4 ; x++) 
{
  // delay(1000);
   //Servo1.write(120);
   zaxis(1400,LOW);//z
   xaxis(2400,HIGH);// fix
   Servo1.write(120);
   delay(2000); 
   zaxis(800,HIGH);//z 24mm downn
   delay(1000);//CUSHION
   Servo1.write(180); //pick
   delay(1000);
 // delay(3500);
   zaxis(800,LOW);//z up
   slave(0);
   delay(2500);
   xaxis(2400,HIGH);// DROP
   zaxis(1400,HIGH);//z
   Servo1.write(120);

}   


} 
   
