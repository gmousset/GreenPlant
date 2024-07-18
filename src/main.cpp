#include <Arduino.h>
#include <CSV_Parser.h>
#include "wifi.h"
#include "ntp.h"
#include "file.h"
      

void setup() {
  Serial.begin(9600);
  file_init();
  ntp_client_setup();
  wifi_setup();

  while (ntp_now() < 60 * 1000) {
    Serial.println("wait NTP sync...");
    delay(1000);
  }

  String content = file_read();
  // char buffer[content.length()];
  // content.getBytes(buffer, content.length());
  Serial.println(content);
  // CSV_Parser cp(buffer, "uLud");

  // time_t *ts = (time_t*) cp[0];
  // uint16 *values = (uint16*) cp[1];

  // for (int row=0; row<cp.getRowsCount(); row++) {
  //   char str[256];
  //   sprintf(str, "(%lld:%d)\n", ts[row], values[row]);
  // }

  file_delete();
}

void loop() { 
  time_t now = ntp_now();
  int value = analogRead(A0);
  char str[256];
  sprintf(str, "%lld:%d\n", now, value);
  file_append(str);
  delay(5000);
}
