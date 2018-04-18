#include <ESP8266WiFi.h>
#include <Wire.h>
#include <TridentTD_LineNotify.h>
#include <Adafruit_ADS1015.h>
#include <BlynkSimpleEsp8266.h>
#define Relay D2            //Variable Relay is D2
#define BLYNK_PRINT Serial
#define ssid "BNK48"  //SSID WIFI
#define pass "0922530944"     //PASSWORD WIFI
#define LINE_TOKEN   "OK7wIuUyLwFI7XMzyLpAHP9bGaX4yk96g2cZroJlXhp" //LINE TOKEN

Adafruit_ADS1015 ads;
TridentTD_LineNotify myLINE(LINE_TOKEN);

int Moisture, check = 0, sensorPin = A0;
int16_t Light;
char auth[] = "6cac4a5950f24bbdbbcb4cde09136e02";
int Blynk_print(int Moisture, int Light);
void Watering(void);
void StopMotor(void);

void setup() {

  Serial.begin(115200);          //Serial begin at 115200
  Blynk.begin(auth, ssid, pass); //Connect to Blynk
  myLINE.wificonnect(ssid,pass); //Connect to Line
  ads.begin();                   //Start I2C
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, HIGH);     //Turn off Motor

}

WidgetTerminal terminal(V3);

BLYNK_WRITE(V5)
{ 
    int y = param.asInt();
    if(y==1)
    {
      myLINE.notify("กำลังทำการรดน้ำต้นไม้");
      Watering();
    }
    else
    {
      StopMotor();
    }
}

void loop() 
{
  Blynk.run();                        //Start Blynk
  Light = ads.readADC_SingleEnded(0); //รับค่าความเข้มแสงจากI2C
  Moisture = analogRead(sensorPin);   //รับค่าความชื้นของดินจากช่องDigital 2
  Blynk_print(Moisture, Light);
  check = 0;
  while(Moisture>=100)
  {
    if(check==0)
    {
      myLINE.notify("ความชื้นในดินต่ำ!!!");
      myLINE.notify("กำลังทำการรดน้ำต้นไม้");
      check++;  
    }
    Watering();
    Moisture = analogRead(sensorPin);
  }
  if(check!=0)
  {
    StopMotor();  
  }
} 

void Watering(void)
{
    if(check==0)
    {
        Blynk.virtualWrite(V4, "Pump On");
        delay(1000);
        Blynk.virtualWrite(V4, "Watering");
        delay(500);
        check++;
    }
    digitalWrite(Relay, LOW);
    delay(1000);
}

void StopMotor(void)
{
    myLINE.notify("หยุดการรดน้ำต้นไม้");
    Blynk.virtualWrite(V4, "Pump off");
    digitalWrite(Relay, HIGH);
    delay(1000);
}

int Blynk_print(int Moisture, int Light)
{
  Blynk.virtualWrite(V1, Moisture);
  Blynk.virtualWrite(V2, Light);
  Blynk.virtualWrite(V3, "Device Online");
  delay(500);
}
