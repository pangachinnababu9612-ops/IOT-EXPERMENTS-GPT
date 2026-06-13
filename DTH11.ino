#define BLYNK_TEMPLATE_ID "TMPL3Jk42J"
#define BLYNK_TEMPLATE_NAME "DHT11"
#define BLYNK_AUTH_TOKEN "jv5PllyFsLTwN-jB9jfuFSSL5VS-"

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char ssid[] = "gpt";   // Your WiFi name
char pass[] = "gpt@208";   // Your WiFi password

#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//BlynkTimer timer;

void sendSensorData() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print(" | Humidity: ");
  Serial.println(h);
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
    
    
    
    
    
    
  //timer.setInterval(2000L, sendSensorData);
}

void loop() {
  Blynk.run();
    
    unsigned long lastTime = 0;
    unsigned long interval = 1000;
    unsigned long currentTime = millis();

if (currentTime - lastTime >= interval) {
lastTime = currentTime;
   sendSensorData();

}
    
  //timer.run();
}
