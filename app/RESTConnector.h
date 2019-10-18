#ifndef ARDUINO_RESTCONNECTOR_H
#define ARDUINO_RESTCONNECTOR_H

#include <Arduino.h>

#define LEN_HTTP_PATH_MAX 256
#define HTTP_OK           200

void RESTInit();
boolean RESTPostTemperature();
boolean RESTPostTeraSys(const char* data);

#endif /* ARDUINO_RESTCONNECTOR_H */