#include <Arduino.h>

#include "Hardware.h"
#include "WiFiCore.h"
#include "RESTConnector.h"
#include "Timer.h"
#include "Global.h"
#include "Credentials.h"

#define TIMER_PERIOD 5000

void setup()
{
  HWInit();
  WiFiBegin(WIFI_SSID, WIFI_PASS);
  RESTInit();
  TIMERInit(TIMER_PERIOD);
}

void loop()
{
  TIMERLoop();
}
