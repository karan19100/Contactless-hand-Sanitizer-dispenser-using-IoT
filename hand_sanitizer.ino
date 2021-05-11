const int trigPin = 3;
const int echoPin = 2;
#define DCwater_pump 8
    // defines pins
    long duration;
    int distance;
    void setup()
{
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    pinMode(DCwater_pump, OUTPUT);
    Serial.begin(9600); // For serial communication
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
}
else
{
 digitalWrite(DCwater_pump,LOW);
 Serial.println("DC Pump is OFF Now!!");
 delay(500);

}
}
