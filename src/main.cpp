#include <Arduino.h>
#include <ESP8266WiFi.h>    
#include <time.h>               

#define MY_NTP_SERVER "at.pool.ntp.org"           
#define MY_TZ "UTC"

#define STASSID "****"   
#define STAPSK  "******"     

time_t now;

uint32_t sntp_update_delay_MS_rfc_not_less_than_15000 () {
  return 60 * 1000UL;
}

void setupWifi() {
  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFi.begin(STASSID, STAPSK);
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print ( "." );
  }
  Serial.println("\nWiFi connected");
}


void setup() {
  Serial.begin(9600);
  configTime(MY_TZ, MY_NTP_SERVER);
  setupWifi();
}

void loop() {
  time(&now);  
  int value = analogRead(A0);
  Serial.print(now);
  Serial.print(": ");
  Serial.println(value);
  delay(2000);
}
