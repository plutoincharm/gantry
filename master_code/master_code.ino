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

//VarSpeedServo myservo;

void setup() {
  
  Wire.begin();
  Serial.begin(9600);
  
  //myservo.attach(servoPin);  
  //myservo.write(0,255,true);
  
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
  delay(1000); 
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
  delay(1000);

  
}

void slave(int x)
{

  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting  
  
}


void loop() 
{

  //--------------------
  //1
  
   //myservo.write(30,150,true); //open  
  //delay(1000);
  gantrypick();
  gantrypick();
  gantrypick();
  gantrypick();





  
/*
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
  //delay(1000);

  slave(0);
  delay(1000);

    
  //---------------------------

  //2
  xaxis(2400,HIGH);// x LH thread pick
  //delay(1000);

  //myservo.write(30,150,true); //open  
  //delay(1000);

  zaxis(1400,HIGH);//z
  delay(1000);

  //myservo.write(0,30,true); 
  //delay(1000);

  zaxis(1400,LOW);//z
  //delay(1000);

  //*************************
  
  xaxis(2400,LOW);// x fixture

  zaxis(800,HIGH);//z downn
  delay(1000);

  //myservo.write(30,150,true); //drop  
 // delay(1000);
  
  
  zaxis(800,LOW);//z up
 // delay(1000);

  slave(0);
  delay(3000);
  //feedback(1);

    
  //---------------------------

  //slave(1);
   //feedback(1);//tap
  //delay(12000);
  */
  
 directionControl();// D1
  delay(1000);
 

  slave(0);//index
  delay(6000);
  slave(1);//tap1
  directionControl();// D2
  delay(5000);
  
  slave(0);//index
  delay(6000);
  slave(1);//tap 2
  directionControl();// D3
  delay(5000);

  slave(0);//index
  delay(6000);
 slave(1);//tap 3
 directionControl();// D4
 delay(5000);

  slave(1);//tap 3

  

 /* 
  slave(0);//index
  delay(3000);
  slave(1);//tap
  delay(3000);
  slave(0);//index
  delay(3000);
  slave(1);//tap
  delay(3000);
  

/*


for(int x = 0; x < 3; x++)
{
  slave(0);//index
  delay(2000);
  //slave(5);

  delay(1000);
  slave(1);//tap
  //
  slave(5);
  
  //directionControl();//drill
  //delay(2000);
  y=6;

} 
Serial.print(y);

/*
  slave(0);//index
  delay(6000);

  slave(1);//tap
  delay(12000);*/
  

 // slave(0);
//  delay(5000);
 //  slave(1);
 // delay(5000);


   //directionControl();
 //
 delay(200000);
} 
   
