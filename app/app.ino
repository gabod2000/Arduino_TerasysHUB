#include <Arduino.h>

#include "Hardware.h"
#include "WiFiCore.h"
#include "NTP.h"
#include "RESTConnector.h"
#include "Timer.h"
#include "Global.h"
#include "Credentials.h"

void setup()
{
  HWInit();
  WiFiBegin(WIFI_SSID, WIFI_PASS);
  NTPBegin();
  TIMERInit(TIMER_PERIOD);
}

void loop()
{
  NTPLoop();
  TIMERLoop();
}
