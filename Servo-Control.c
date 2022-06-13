#include <Servo.h>
//#include "SR04.h"
#define ENABLE 5
#define DIRA 3
#define DIRB 4
int i;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

#define TRIG_PIN 12
#define ECHO_PIN 11
//SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
    pinMode(2,INPUT);
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object

 Serial.begin(9600);
   delay(1000);


  pinMode(ENABLE,OUTPUT);
    pinMode(DIRA,OUTPUT);
    pinMode(DIRB,OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int digitalVal = digitalRead(2);
    if(LOW == digitalVal)
    {
        for (pos = 0; pos <= 180; pos += 1) {   // goes from 0 degrees to 180 degrees
                                                // in steps of 1 degree
            myservo.write(pos);                 // tell servo to go to position in variable 'pos'
            delay(15);                          // waits 15ms for the servo to reach the position
        }
        for (pos = 180; pos >= 0; pos -= 1) {   // goes from 180 degrees to 0 degrees
            myservo.write(pos);                 // tell servo to go to position in variable 'pos'
            delay(15);                          // waits 15ms for the servo to reach the position
        }
    }
  
     //a=sr04.Distance();
   //Serial.print(a);
   //Serial.println("cm");
   delay(1000);

  
  Serial.println("One way, then reverse");
    digitalWrite(ENABLE,HIGH);      // enable on
    for (i=0;i<5;i++) {
        digitalWrite(DIRA,HIGH);    //one way
        digitalWrite(DIRB,LOW);
        delay(500);
        digitalWrite(DIRA,LOW);     //reverse
        digitalWrite(DIRB,HIGH);
        delay(500);
    }
  


      digitalWrite(ENABLE,LOW);       // disable
    delay(2000);

    Serial.println("fast Slow example");
    //---fast/slow stop example
    digitalWrite(ENABLE,HIGH);      //enable on
    digitalWrite(DIRA,HIGH);        //one way
    digitalWrite(DIRB,LOW);
    delay(3000);
    digitalWrite(ENABLE,LOW);       //slow stop
    delay(1000);
    digitalWrite(ENABLE,HIGH);      //enable on
    digitalWrite(DIRA,LOW);         //one way
    digitalWrite(DIRB,HIGH);
    delay(3000);
    digitalWrite(DIRA,LOW);         //fast stop
    delay(2000);

    Serial.println("PWM full then slow");
    //---PWM example, full speed then slow
    analogWrite(ENABLE,255);        //enable on
    digitalWrite(DIRA,HIGH);        //one way
    digitalWrite(DIRB,LOW);
    delay(2000);
    analogWrite(ENABLE,180);        // 70% speed
    delay(2000);
    analogWrite(ENABLE,128);        // 50% speed
    delay(2000);
    analogWrite(ENABLE,50);         // 20% speed
    delay(2000);
    analogWrite(ENABLE,128);        // 50% speed
    delay(2000);
    analogWrite(ENABLE,180);        // 70% speed
    delay(2000);
    analogWrite(ENABLE,255);        // 100% speed
    delay(2000);
    digitalWrite(ENABLE,LOW);       // all done
    delay(10000);
}
