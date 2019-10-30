#include "Timer.h"
#include "Hardware.h"
#include "NTP.h"
#include "RESTConnector.h"
#include "Global.h"

/* Catastrophically using symbols from ESP OpenSDK directly. */
extern "C" {
#include "user_interface.h"
}

os_timer_t publishTimer;
boolean publishTimerTick = false;

void publishCallback(void *pArg)
{
  /* Keep our ISR light! */
  publishTimerTick = true;
}

void TIMERInit(unsigned int timerDelay)
{
  os_timer_setfn(&publishTimer, publishCallback, NULL);
  os_timer_arm(&publishTimer, timerDelay, true);
  publishTimerTick = false;
}

void TIMERLoop()
{
  if (publishTimerTick) {
    /* Periodic timer function to POST data to TeraSYS IoT HUB */
    RESTPostMetrics(Temperature().c_str(), Humidity().c_str());
    publishTimerTick = false;
  }
}
