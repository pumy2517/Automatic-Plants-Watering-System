#include <ESP8266WiFi.h>
#include <Wire.h>
#include <TridentTD_LineNotify.h>
#include <Adafruit_ADS1015.h>
#include <BlynkSimpleEsp8266.h>
#include <time.h>

#define Relay D2            //Variable Relay is D2
#define BLYNK_PRINT Serial
#define ssid "Chalermwong"  //SSID WIFI
#define pass "10010110"     //PASSWORD WIFI
#define LINE_TOKEN   "OK7wIuUyLwFI7XMzyLpAHP9bGaX4yk96g2cZroJlXhp" //LINE TOKEN
Adafruit_ADS1015 ads;
TridentTD_LineNotify myLINE(LINE_TOKEN);

//Variable
  int Moisture, check = 0, sensorPin = A0 , time_min, time_hour;
  int16_t Light;
  int Check_mode = 0;

//blynk code
  char auth[] = "6cac4a5950f24bbdbbcb4cde09136e02";

//Time zone
int timezone = 7 * 3600;
int dst = 0;

//function
  int Blynk_print(int Moisture, int Light);
  void Watering(void);
  void StopMotor(void);


void Watering(void)
{
    if(check==0)
    {
        myLINE.notify("กำลังทำการรดน้ำต้นไม้");
        Blynk.virtualWrite(V4, "Pump On");
        delay(1000);
        Blynk.virtualWrite(V4, "Watering");
        delay(500);
        check++;
    }
    digitalWrite(Relay, LOW);
    delay(5000);
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
  delay(500);
}

//Blynk teminal
  WidgetTerminal terminal(V0);

void setup() {

  //Serial begin at 115200
    Serial.begin(115200);
  
  //  Connect to Wi-Fi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to WIFI... : ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED) 
    {
     delay(500);
     Serial.print(".");
    }
    Serial.println("");
    Serial.println("Wi-Fi connected successfully");

  //Connect to Blynk
    Blynk.begin(auth, ssid, pass); 
  
  //Connect to Line
    myLINE.wificonnect(ssid,pass); 

  //Start I2C
    ads.begin();

  //for time
  Serial.setDebugOutput(true);
  configTime(timezone, dst, "pool.ntp.org", "time.nist.gov");

  //Turn off Motor
    pinMode(Relay, OUTPUT);
    digitalWrite(Relay, HIGH);
}

//Blynk input control water
BLYNK_WRITE(V5)
{ 
    int y = param.asInt();
    if(y==1)
    {
      Blynk.virtualWrite(V3, "Mode: Time");
      Check_mode = 1;
    }
    else
    {
      Blynk.virtualWrite(V3, "Mode:Moisture");
      Check_mode = 0;
    }
}

//Blynk select mode
BLYNK_WRITE(V6)
{ 
    int y = param.asInt();
    if(y==1)
    {
      Watering();
    }
    else
    {
      StopMotor();
    }
}

//Blynk Time set
BLYNK_WRITE(V7)
{ 
    time_min = param.asInt();
    
}
BLYNK_WRITE(V8)
{ 
    time_hour = param.asInt();
    
}



void loop() 
{
  //Start Blynk
  Blynk.run();

  
  //รับค่าความเข้มแสงจากI2C
  Light = ads.readADC_SingleEnded(0)/16; 
  
  //รับค่าความชื้นของดินจากช่องDigital 2
  Moisture = analogRead(sensorPin)/4;   

  //Show data in blynk dashboard
  Blynk_print(Moisture, Light);
  check = 0;

  //Time mode
  if(Check_mode == 1)
  {
    time_t now = time(nullptr);
    struct tm* p_tm = localtime(&now);
    Serial.print(p_tm->tm_sec);
    if((p_tm->tm_sec == 0)&&(p_tm->tm_min == time_min)&&(p_tm->tm_hour == time_hour))
    {
      Watering();
      check++;
    }
    if(check != 0)
    {
    StopMotor();
    }
  }
  
  //Check moisture
  else{
  while(Moisture<=30)
  {
    if(check==0)
    {
      Blynk.virtualWrite(V4, "Watering"); 
    }
    Watering();
    Moisture = analogRead(sensorPin);
    check++; 
  }
  if(check!=0)
  {
    StopMotor();  
  }
  }
} 
