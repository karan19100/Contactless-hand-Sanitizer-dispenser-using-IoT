//Karan Shah
//Blynk Alert system
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;

int count=0;
boolean state = true;
char auth[] = "_______________________________"; //Auth code sent via Email
char ssid[] = "______________"; //Wifi name
char pass[] = "*********";  //Wifi Password
int flag=0;
int distance;

void notifyOnThings()
{
  int isButtonPressed = digitalRead(D1);
  if (isButtonPressed==0) {
    count++;
    Serial.print("count >> ");
    Serial.println(count);
      Blynk.virtualWrite(V1,count);
    delay(4000);

      if(count<10 && count==0)
      {
        Serial.println("FULL");
        Blynk.virtualWrite(V0,100);
      }
        else if(count<10 && count==3)
      {
        Serial.println("THREE QUATER");
        Blynk.virtualWrite(V0,75);
      }
        else if(count<10 && count==5)
      {
        Serial.println("HALF");
        Blynk.virtualWrite(V0,50);
      }
          else if(count<10 && count==7)
      {
        Serial.println("QUATER");
        Blynk.virtualWrite(V0,25);
      }
    else if(count>10)
    {
      count=0;
        Serial.println("Reminder of refilling the santizer bottle");
        Blynk.email("karanshah2019@gmail.com", "Reminder!!!", "Refill your sanitizer Bottle");
        Blynk.notify("Reminder!!! - Refill your Sanitizer Bottle");      
       flag=1;  
    }
  }
  else if(isButtonPressed==0)
  {
    flag=0;
  }
}
void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
pinMode(D1,INPUT_PULLUP);
timer.setInterval(1000L,notifyOnThings);
}
void loop()
{
  Blynk.run();
  timer.run();
}
