#define BLYNK_PRINT Serial 
//Definisi Serial pada Blink 

//Setting Library 
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h> 
#include <Servo.h> 

//Definisi variabel token, SSID, password 
char auth[] = "9CihoaH0U5z0IaTLVmqge00vaoY5depa"; 
char ssid[] = "hiii"; 
char pass[] = "miskinlu"; 

//Definisi fungsi servo menjadi gerak_servo 
Servo gerak_servo; 

//Fungsi Blynk untuk mengatur nilai servo dengan pin virtual V1 
BLYNK_WRITE(V2){ 
  gerak_servo.write(param.asInt()); 
}

//Settingan awal default 
void setup(){ 
 Serial.begin(9600);
 //memulai serial monitor dengan baudrate 9600 
  
 gerak_servo.attach(2); 
 //setting pin gpio 2 ke servo 
  
 Blynk.begin(auth, ssid, pass); 
 //setting blynk 
} 
void loop(){ 
  Blynk.run(); 
  //memulai blynk 
}
