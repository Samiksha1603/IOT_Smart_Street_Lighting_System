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
//Serial.print("Distance of vehicle from Street Light 1: ");
//Serial.print(distance);
//Serial.println("  cm");
delay(10);

 if(distance < 10)
    {
      digitalWrite(led_1, HIGH);
      digitalWrite(led_2, HIGH);
     // Serial.println("Street Light 1 is turned on");
      //Serial.println("Street Light 2 is turned on");
      delay(1000);
     
    }
    else
    {
      digitalWrite(led_1,LOW);
      //digitalWrite(led_2,LOW);
    }  


}

void US2(){
  digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);

duration1=pulseIn(echoPin2,HIGH);
distance1=duration1*0.034/2;
//Serial.println("Distance of vehicle from Street Light 2: ");
//Serial.print(distance1);
//Serial.println("  cm");
delay(10);

 if(distance1 < 10)
    {
      digitalWrite(led_2, HIGH);
      digitalWrite(led_3, HIGH);
     // Serial.println("Street Light 2 is turned on");
      //Serial.println("Street Light 3 is turned on");
      delay(1000);
    }
    else
    {
      digitalWrite(led_2,LOW);
      digitalWrite(led_3,LOW);
    }  


}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A0, INPUT);
pinMode(led_1,OUTPUT);
pinMode(led_2,OUTPUT);
pinMode(led_3,OUTPUT);
pinMode(trigPin1,OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2,OUTPUT);
pinMode(echoPin2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  LDR = analogRead(A0);
  Serial.println(LDR);
 if(LDR<165)
     {
      US1();
      US2();
      delay(100);
     }
  else{
   
    digitalWrite(led_1,LOW);
    digitalWrite(led_2,LOW);
    digitalWrite(led_3,LOW);
   //Serial.println("ITS DAYTIME");
    delay(100);
  }
}
