#ifndef ARDUINO_HARDWARE_H
#define ARDUINO_HARDWARE_H

#include <Arduino.h>

#define DHT_PIN                 5
#define DHT_TYPE                DHT11
#define DHT_FAHRENHEIT          false
#define INCORRECT_MEASUREMENT   ""

void  HWInit();
void  HWRestart();
String Temperature();
String Humidity();

/* GPIO Definitions */
static const uint8_t pinMap[11] = {16, 5, 4, 0, 2, 14, 12, 13, 15, 3, 1};

#endif /* ARDUINO_HARDWARE_H */
