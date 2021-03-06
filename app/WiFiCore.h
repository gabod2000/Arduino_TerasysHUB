#ifndef ARDUINO_WIFICORE_H
#define ARDUINO_WIFICORE_H

#include <ESP8266WiFi.h>

#define LEN_SSID_MAX        32
#define LEN_PASSPHRASE_MAX  64

void WiFiBegin(const char* ssid, const char* pass);
void WiFiStop();
void WiFiGetIP(char *deviceIP);
void WiFiGetMAC(char *macBuffer);
void WiFiGetSSID(char* ssidBuffer);
void WiFiGetPassphrase(char* passBuffer);

#endif /* ARDUINO_WIFICORE_H */
