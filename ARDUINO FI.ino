
#include <SoftwareSerial.h>
SoftwareSerial espSerial(5, 6);

const int trigPin1=3;
const int echoPin1=4;
const int trigPin2=8;
const int echoPin2=9;
long duration;
long duration1;
int distance;
int distance1;
int LDR = 0;
#define led_1 13
#define led_2 12
#define led_3 10



void US1(){
  digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);

duration=pulseIn(echoPin1,HIGH);
distance=duration*0.034/2;
Serial.print("Distance of vehicle from Street Light 1: ");
Serial.println(String(distance));
espSerial.print(String(distance));
espSerial.print(",");




 if(distance < 140)
    {
      digitalWrite(led_1, HIGH);
      digitalWrite(led_2, HIGH);
     Serial.println("Street Light 1 is turned on");
      Serial.println("Street Light 2 is turned on");
      delay(100);
     
    }
    else
    {
      digitalWrite(led_1,LOW);
      //digitalWrite(led_2,LOW);
    }   
;


}

void US2(){
  digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);

duration1=pulseIn(echoPin2,HIGH);
distance1=duration1*0.034/2;
Serial.print("Distance of vehicle from Street Light 2: ");
Serial.println(String(distance1));
espSerial.println(String(distance1));
delay(1000);


 if(distance1 < 10)
    {
      digitalWrite(led_2, HIGH);
      digitalWrite(led_3, HIGH);
     Serial.println("Street Light 2 is turned on");
      Serial.println("Street Light 3 is turned on");
      delay(10);
    }
    else
    {
      digitalWrite(led_2,LOW);
      digitalWrite(led_3,LOW);
    }   


}

void setup() {
 
Serial.begin(115200);
espSerial.begin(115200);

pinMode(A5, INPUT);
pinMode(led_1,OUTPUT);
pinMode(led_2,OUTPUT);
pinMode(led_3,OUTPUT);
pinMode(trigPin1,OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2,OUTPUT);
pinMode(echoPin2, INPUT);

delay(200);
}

void loop() {
 
LDR = analogRead(A5);
Serial.println(LDR);
 if(LDR<300)
     {
      US1();
      delay(1000);
      US2();
     }
  else{
    
    digitalWrite(led_1,LOW);
    digitalWrite(led_2,LOW);
    digitalWrite(led_3,LOW);
   Serial.println("ITS DAYTIME");
    delay(600);
  }
}