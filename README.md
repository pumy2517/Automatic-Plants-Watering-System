# ![](/images/internet.png) Welcome
สวัสดีครับ พวกเราได้ทำเครื่องรดน้ำต้นไม้อัตโนมัติขึ้นเพื่อตอบสนองความต้องการให้กับผู้ที่ต้องการความสะดวกสบายในการรดน้ำต้นไม้

โดยสามารถสั่งการได้เองผ่าน Smartphone และสามารถตั้งเวลาให้รดน้ำต้นไม้เองได้อีกด้วย

---

# ![](images/help.png) How to use
วิธีใช้นั้นง่าย ๆ ครับ ต่อถ่านไฟฉายขนาด 9V ก้อนแรกกับบอร์ด Wemos D1R1 อีกก้อนต่อกับ Water Pump

เท่านี้เครื่องรดน้ำต้นไม้อัตโนมัติก็จะทำงานตามโปรแกรมที่สั่งไว้แล้วครับ ก็คือความชื้นต่ำกว่า 40% เครื่องจะทำการรดน้ำ

แต่ถ้าอยากปรับค่าตามสภาพแวดล้อมต่าง ๆ ก็สามารถแก้ไขได้ผ่านไฟล์ Motor_control.ino

หรือถ้าอยากควบคุมระยะไกล ก็สามารถใช้ application ที่ชื่อว่า Blynk (สามารถใช้ได้ทั้งระบบปฏิบัติการ Android และ IOS ครับ)

*แต่จำเป็นต้องต่ออินเทอร์เน็ตกับบอร์ดผ่าน Wifi ด้วยครับ

[Full Documentation](https://github.com/compro-itkmitl/Automatic-Plants-Watering-System/wiki)

---

# ![](images/apps.png) Application Blynk
ในส่วนของ application ที่ใช้ ชื่อว่า Blynk นั้น สามารถควบคุมการเปิด - ปิดของ water pump ได้

มีหน้าจอ Monitor ไว้บอกค่าของแสง ณ บริเวณนั้น และความชื้นในดิน บอกเป็นเปอร์เซ็นต์

สามารถตั้งเวลาที่เราจะรดน้ำต้นไม้ได้ผ่านแอป Blynk โดยใช้ Mode Time

ตั้งให้ water pump ทำงานไว้ เช่น ตั้งให้ทุก ๆ 8 นาฬิกาจะรดน้ำต้นไม้ของเรา

## ![](images/moisture.png) Mode Normal (Moisture Mode)
![](images/blynk_interface_moisture.png)

## ![](images/time.png) Mode Time
![](images/blynk_interface_time.png)

---

# ![](images/line.png) Line Notification

เมื่อ Water Pump มีการเปิด - ปิด สามารถตั้งค่าให้แจ้งเตือนว่า

"กำลังทำการรดน้ำต้นไม้" เมื่อกำลังรดน้ำต้นไม้ และ "หยุดการรดน้ำต้นไม้" เมื่อ Water Pump หยุดทำงาน

## ![](images/line_16.png) Screenshot Line Notify
![](images/line_notify.png)

---

# ![](images/notebook.png) Library Requirements
* [Blynk Library](https://github.com/blynkkk/blynk-library)
* [LineNotify Library](https://github.com/TridentTD/TridentTD_LineNotify)
* [ADS1X15 Library](https://github.com/adafruit/Adafruit_ADS1X15)
* [Time Library](https://github.com/PaulStoffregen/Time)

---

# ![](images/tools.png) Tools
* WeMos D1R1 WiFi UNO Development Board ESP8266
* I2C ADS1015 12-Bit ADC - 4 Channel
* 1 Channel Relay
* Soil Moisture Sensor
* Light Sensor
* Water Pump 6V
* Battery 9V (2 ea)
* Breadboard
* Water Source
* Plant

---

# ![](images/picture.png) More Pictures

แสดงถึงด้านหน้าและด้านข้างของอุปกรณ์

## Front View
![](images/front.png)

## Side View
![](images/side.png)

---

# ![](images/member.png) Members
|  |ชื่อ|นามสกุล|GitHub Username|รหัสนักศึกษา|
|:-:|--|------|---------------|---------|
|![](images/peerapol.png)|Peerapol|Onhan|[@pumy2517](https://github.com/pumy2517)|60070067|
|![](images/pattarapong.png)|Pattarapong|Intubtim|[@mezz3](https://github.com/mezz3)|60070070|

# ![](images/teacher.png) Assistant Teacher
|ผศ.ดร. กิติ์สุชาต พสุภา|ผศ.ดร. ปานวิทย์ ธุวะนุติ|
|:-:|:-:|
|![](images/aj_kitsuchart.png)|![](images/aj_panwit.png)|

รายงานนี้เป็นส่วนหนึ่งของวิชา Computer Programming (รหัส 06016206)

คณะเทคโนโลยีสารสนเทศ สถาบันเทคโนโลยีพระจอมเกล้าเจ้าคุณทหารลาดกระบัง

---

Faculty of Information Technology

King Mongkut's Institute of Technology Ladkrabang

---
