

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL3x4OayN"
#define BLYNK_TEMPLATE_NAME "LED ROL"
#define BLYNK_AUTH_TOKEN "8SX4vYTY5WnS49X6oSeGRDylz3Xh"


#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "gptamdv";
char pass[] = "gpt@1234";

BLYNK_WRITE(V0){
  int turn = param.asInt();
  digitalWrite(12,turn); //gpio
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}

