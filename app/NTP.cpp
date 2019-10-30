#include <NTPClient.h>
#include <WiFiUdp.h>

#include "NTP.h"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_TIME_OFFSET, NTP_CHECK_INTERVAL);

void NTPBegin()
{
  timeClient.begin();
}

void NTPLoop()
{
  timeClient.update();
}

unsigned long NTPGetEpoch()
{
  return timeClient.getEpochTime();
}
