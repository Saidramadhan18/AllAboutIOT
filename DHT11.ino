#include <DHT.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 2 // D4 DHTPIN
#define DHTTYPE DHT11
#define BLYNK_PRINT Serial

char auth[] = "9CihoaH0U5z0IaTLVmqge00vaoY5depa";
char ssid[] = "hiii";
char pass[] = "miskinlu";

#define DHTPIN 2          // What digital pin we're connected to
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  
  Serial.println (F("DHT11 test!")); // f()= nyimpen di memory
  dht.begin();
  
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  float h = dht.readHumidity(); // kelembapan ganteng bngt parah uwais jelek
  float t = dht.readTemperature(); //suhu

  if(isnan(h)|| isnan(t)){
    Serial.println(F("Failed to read from dht11"));
    return;
  }
  Serial.print(F("Humidity: "));
  Serial.println(h);
  Serial.print("\n");
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println(F("°C"));
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);
}
