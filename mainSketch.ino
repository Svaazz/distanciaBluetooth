#include <SoftwareSerial.h>
#define trigPin 13
#define echoPin 12
SoftwareSerial BT(10, 11); //10 RX, 11 TX.

int Dist;


void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  BT.begin(9600); 
  Serial.begin(9600); 
}
 
void loop()
{
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  
  BT.print("Distancia: ");
  BT.print(distance);
  BT.println(" cm");  
  delay(750);
}
