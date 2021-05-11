const int trigPin = 3;
const int echoPin = 2;
#define DCwater_pump 8
  // defines pins
    long duration;
    int distance;
// voice libraries and defining pins 
#include "Talkie.h"
#include "PCM.h"
#define Voice 4
Talkie voice;
const unsigned char sample[ ] PROGMEM = {
126, 127, 128, 128, 128, 128, 128, 127, 128, 128, 128, 129, 129, 128, 127, 128, 128, 127, 126, 127, 128, 129, 128, 127, 126, 127, 128, 128, 126, 126, 127, 127, 127, 127, 127, 127, 126, 127, 126, 127, 128, 128, 128, 128, 128, 127, 128, 128, 128, 129, 129, 128, 127, 128, 128, 127, 126, 127, 128, 129, 128, 127, 126, 127, 128, 128, 126, 126, 127, 127, 127, 127, 127, 127, 126, 127,
};
 const unsigned char sample_1[ ] PROGMEM = {      
 126, 127, 128, 128, 128, 128, 128, 127, 128, 128, 128, 129, 129, 128, 127, 128, 128, 127, 126, 127, 128, 129, 128, 127, 126, 127, 128, 128, 126, 126, 127, 127, 127, 127, 127, 127, 126, 127, 126, 127, 128, 128, 128, 128, 128, 127, 128, 128, 128, 129, 129, 128, 127, 128, 128, 127, 126, 127, 128, 129, 128, 127, 126, 127, 128, 128, 126, 126, 127, 127, 127, 127, 127, 127, 126, 127,
}; 

    void setup()
{
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    pinMode(DCwater_pump, OUTPUT);
    Serial.begin(9600); // For serial communication
    
// arduino in voice setup 
    pinMode(Voice, OUTPUT);
  startPlayback(sample, sizeof(sample));
  startPlayback(sample_1, sizeof(sample_1));  
}
    void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    //Distance calculation
    distance= duration*0.034/2;
    // Printinng the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
   
 if (distance < 10)
{
 digitalWrite(DCwater_pump,HIGH);
 Serial.println("DC Pump is ON Now!!");
 delay(1500);
 digitalWrite(DCwater_pump, LOW);
 Serial.print("Pump OFF");
 delay(1000);
// voice setup it will say thankyou for sanitizing your hands and have a nice day!
 startPlayback(sample, sizeof(sample));
 delay(3500);
}
else
{
 digitalWrite(DCwater_pump,LOW);
 Serial.println("DC Pump is OFF Now!!");
 delay(500);
 // voice setup it will say plz santize your hands before entering the premises!
  startPlayback(sample_1, sizeof(sample_1));
   delay(3500);
}
}
