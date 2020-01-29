#ifndef ARDUINO_CREDENTIALS_H
#define ARDUINO_CREDENTIALS_H

/* RESTFul TerasysHUB Credentials */
#define SERVER  "www.terasyshub.io"
#define PORT    443
#define DATA    "/api/v1/data"
/* To be able to post to a secure address, SHA1 fingerprint must be gathered from target certificate.
 * Get it from https://www.terasyshub.io.
 */
#define SHA1    "D9 D0 F2 1A C9 31 DC 44 11 DA FB 7B 2A 24 52 BD EC 16 F9 FF"

/* User credentails, change them before proceeding! */
/* WiFi Credentials*/
#define WIFI_SSID "YOUR-WIFI-SSID"
#define WIFI_PASS "YOUR-WIFI-PASS"
/* Location info*/
#define LAT     "YOUR-LOCATION-LATITUDE"
#define LON     "YOUR-LOCATION-LONGITUDE"
/* The credential key to access TerasysHUB with given device. */
#define KEY     "YOUR-TERASYSHUB-DEVICE-KEY"

#endif /* ARDUINO_CREDENTIALS_H */
