#include "Timer.h"
#include "Hardware.h"
#include "RESTConnector.h"
#include "Global.h"

/* Catastrophically using symbols from ESP OpenSDK directly. */
extern "C" {
#include "user_interface.h"
}

String measurement = "";
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
  if(publishTimerTick)
  {
    measurement = Temperature();
    if (measurement != INCORRECT_MEASUREMENT)
    {
      //RESTPostTeraSys(measurement.c_str());
      Printf("%s\n", measurement.c_str());
    }
    measurement = Humidity();
    if (measurement != INCORRECT_MEASUREMENT)
    {
      //RESTPostTeraSys(measurement.c_str());
      Printf("%s\n", measurement.c_str());
    }
    publishTimerTick = false;
  }
}
