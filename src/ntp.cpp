#include <Arduino.h>
#include "ntp.h"

#define MY_NTP_SERVER "at.pool.ntp.org"           
#define MY_TZ "UTC"

time_t now;

uint32_t sntp_update_delay_MS_rfc_not_less_than_15000 () {
  return 60 * 1000UL;
}

void ntp_client_setup() {
    configTime(MY_TZ, MY_NTP_SERVER);
}

time_t ntp_now() {
    time(&now);
    return now;
}