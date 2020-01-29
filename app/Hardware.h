#ifndef ARDUINO_HARDWARE_H
#define ARDUINO_HARDWARE_H

#include <Arduino.h>

/* DHT Temperature Sensor Configurations */
#define ENABLE_DHT              true
#define DHT_PIN                 5
#define DHT_TYPE                DHT11
#define DHT_FAHRENHEIT          false

/* MQ3 Air-Quality and Gas Sensor Configurations */
#define ENABLE_MQ3              true
#define MQ3_PIN                 A0

/* Generic Sensor Definitions */
#define INCORRECT_MEASUREMENT   ""

void  HWInit();
void  HWRestart();
String Temperature();
String Humidity();
String AirQuality();

/* GPIO Definitions */
static const uint8_t pinMap[11] = {16, 5, 4, 0, 2, 14, 12, 13, 15, 3, 1};

#endif /* ARDUINO_HARDWARE_H */
