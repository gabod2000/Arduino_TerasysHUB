#ifndef ARDUINO_RESTCONNECTOR_H
#define ARDUINO_RESTCONNECTOR_H

#include <Arduino.h>

#define LEN_HTTP_PAYLOAD_MAX    1024
#define LEN_HTTP_DATA_MAX       384
#define HTTP_OK                 200
#define TIMEOUT_SSL             10000

boolean RESTPostMetrics(const char* temp, const char* hum);

#endif /* ARDUINO_RESTCONNECTOR_H */