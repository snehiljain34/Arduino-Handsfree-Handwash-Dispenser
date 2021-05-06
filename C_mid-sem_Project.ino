#include <Servo.h>
/*contains 
 * attach()
 * write()
 * writeMicroseconds()
 * read()
 * attached()
 detach()*/
#define trigPin 3
#define echoPin 2


Servo servo1;
Servo servo2;
int sound = 250;

void setup() 
    {
        Serial.begin (9600);
        pinMode(trigPin, OUTPUT);
        pinMode(echoPin, INPUT);
        servo1.attach(4);
        servo2.attach(5);
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
        if (distance < 5) 
            {
                Serial.println("the distance is less than 5, dettol liquid dispensed");
                servo1.write(100);
                /*will rotate servo1 to 100degress clockwise*/
                servo2.write(100);
                /*will rotate servo2 to 100degress clockwise*/
            }
        else  
            {  
                servo1.write(0);
                servo2.write(0);
                /*no effect on the two servos*/
            }
        if (distance > 60 || distance <= 0)
            {
              Serial.println("The distance is more than 60, move your hand closer");
            }
        else 
            {
              Serial.print(distance);
              Serial.println(" cm");
            }
      delay(500);
}
