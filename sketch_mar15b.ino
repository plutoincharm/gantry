int obstaclePin = 5;  //NBSL COMMERCIAL
int hasObstacle = HIGH;


void setup() {
  pinMode(obstaclePin, INPUT);
  Serial.begin(9600); 
}
void loop() {
  hasObstacle = digitalRead(obstaclePin);
  if (hasObstacle == HIGH)
  {
    Serial.println("Nothing Ahead!!");//If obstacle detected
    delay(200);
  }
  else
  {
    Serial.println("Obstacle"); //No obstacle
  }
  delay(200);
}
