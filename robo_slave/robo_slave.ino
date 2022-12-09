#include <Wire.h>
const int i_stepPin = 9; 
const int i_dirPin = 8; 
const int i_enPin = 7;
const int t_stepPin = 3; 
const int t_dirPin = 4; 
const int t_enPin = 2;
int enA = 11;
int in1 = 12;
int in2 = 13;

//char x ='11';
int x=6;
int n=1 ;
int y=5;

void setup() {
  
  
  Wire.begin(9); 
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);

  pinMode(i_stepPin,OUTPUT); 
  pinMode(i_dirPin,OUTPUT);
  pinMode(i_enPin,OUTPUT);
  digitalWrite(i_enPin,LOW);


  pinMode(t_stepPin,OUTPUT); 
  pinMode(t_dirPin,OUTPUT);
  pinMode(t_enPin,OUTPUT);
  digitalWrite(t_enPin,LOW);
//DC
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
}


void receiveEvent(int bytes) {
  
  x = Wire.read(); 

}


void loop() 
{

  //x = Wire.read(); 
//if(n==1)

  Serial.print(x);
if (x == 0) 
{
 x=5;
   digitalWrite(i_dirPin,LOW);
     
  for(int x = 0; x < 1000; x++) 
{
    
    digitalWrite(i_stepPin,HIGH); 
    delay(1); 
    digitalWrite(i_stepPin,LOW); 
    delay(1); 
 } 


//x=5;
  /*delay(10000);
  x = Wire.read(); 
  Serial.print(x);*/
}


  if (x == 1)    
{

  x=5;
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);
 //************************************
  analogWrite(enA, 80);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  
   digitalWrite(t_dirPin,HIGH);
     
  for(int x = 0; x < 2400; x++) 
{
    
    digitalWrite(t_stepPin,HIGH); 
    delay(1); 
    digitalWrite(t_stepPin,LOW); 
    delay(1); 
 } 

     delay(1000); 

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  delay(1000);
 //************************************
  analogWrite(enA, 80);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
    
  
  digitalWrite(t_dirPin,LOW);
     
  for(int x = 0; x < 2400; x++) 
{
    
    digitalWrite(t_stepPin,HIGH); 
    delay(1); 
    digitalWrite(t_stepPin,LOW); 
    delay(1); 
 } 

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);
x=5;  
}



}
