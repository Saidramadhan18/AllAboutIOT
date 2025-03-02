#include <DHT.h>
#include <UbidotsMicroESP8266.h>

#define DHTPIN 4
#define DHTTYPE DHT11

char auth[] = "BBFF-y0vHIKvXRBOS0MZ74L1kUgDRq3OAqD";
char ssid[] = "baja";
char pass[] = "miskinlu";

DHT dht(DHTPIN,DHTTYPE);
Ubidots client(auth);
unsigned long last = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  delay(20);
  client.wifiConnection(ssid,pass);
}

void loop() {
  if(millis()-last>10000){
    float hum = dht.readHumidity();
    float temp = dht.readTemperature();

    last = millis();
    client.add("kelembapan",hum);
    client.add("Temperatur",temp);
    client.sendAll(true);
  }

}
