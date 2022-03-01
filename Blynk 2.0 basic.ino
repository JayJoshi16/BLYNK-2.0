/*******************************************
 * 
 * BLYNK 2.0 Example Code 
 * This code can Control Digital Pin(Connected on ESP32) as well 
 *                  as Viryual pin(Connected on BLYNK DASHBOARD)
 * 
 * github.com/JayJoshi16
 * 
 *****************************************/
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "YOUR Template ID"
#define BLYNK_DEVICE_NAME "YOUR DEVICE NAME"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial

#include "BlynkEdgent.h"
#include<SimpleTimer.h>
SimpleTimer timer;

bool flag = false;      //flag for toggle LED 

void toggle() {
  if (flag) {
    Blynk.virtualWrite(V2, 1);      //LED on Virtual Pin V2
    Serial.print("on");
    flag = false;

  }
  else if (flag == false) {
    Blynk.virtualWrite(V2, 0);
    Serial.print("off");
    flag = true;
  }

}
BLYNK_WRITE(V0)
{
  int s0 = param.asInt();           // parameter as int
  if (s0 == HIGH)
  {
    digitalWrite(2, HIGH);          //LED on Digital Pin V2
    delay(10);
  }
  if (s0 == LOW)
  {
    digitalWrite(2, LOW);
    delay(10);
  }
}
void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);       //On Board LED of ESP32
  digitalWrite(2, LOW);
  timer.setInterval(1000L, toggle);   // toggle() will call every 2 seconds
  BlynkEdgent.begin();
}

void loop() {

  BlynkEdgent.run();
  timer.run();
}
