#include <WiFiClientSecure.h> 

#include "RESTConnector.h"
#include "NTP.h"
#include "Credentials.h"
#include "WiFiCore.h"
#include "Global.h"

WiFiClientSecure httpsClient;

boolean postComposedData(const char* path, const char* data)
{
  bool ret = false;
  char httpPayload[LEN_HTTP_PAYLOAD_MAX] = {};

  httpsClient.setFingerprint(SHA1);
  httpsClient.setTimeout(TIMEOUT_SSL);

  if(httpsClient.connect(SERVER, PORT)) {
    memset(httpPayload, 0, LEN_HTTP_PAYLOAD_MAX);
    snprintf(httpPayload, LEN_HTTP_PAYLOAD_MAX,
      "POST %s HTTP/1.1\r\n"
      "Host: %s\r\n"
      "Accept: */*\r\n"
      "User-Agent: Mozilla/4.0 (compatible; nodemcu esp8266 Arduino;)\r\n"
      "Connection: close\r\n"
      "Content-Length: %d\r\n"
      "Content-Type: application/json\r\n\r\n"
      "%s",
      path, SERVER, strlen(data), data);

    httpsClient.print(httpPayload);

    while (httpsClient.connected()) {
      String line = httpsClient.readStringUntil('\n');
      if (line == "\r") {
        break;
      }
      yield();
    }

    while(httpsClient.available()) {
      String response = httpsClient.readStringUntil('\n');
      if (response == "Ok.") {
        Printf("Posted : %s\n", data);
        ret = true;
      } else {
        Printf("Data post failure!\n");
      }
      yield();
    }
  }
  else {
    Printf("Secure connection failed\n");
  }

  return ret;
}

boolean RESTPostMetrics(const char* temp, const char* hum)
{
  char mac[LEN_MAC_MAX] = {};
  char jsonBuf[LEN_HTTP_DATA_MAX] = {};

  WiFiGetMAC(mac);

  memset(jsonBuf, 0, LEN_HTTP_DATA_MAX);
  snprintf(jsonBuf, LEN_HTTP_DATA_MAX,
    "{"
      "\"mac\":\"%s\","
      "\"location\":{\"lat\":\"%s\",\"lon\":\"%s\"},"
      "\"timestamp\":\"%lu\","
      "\"metrics\":"
      "["
        "{\"value\":\"%s\",\"unit\":\"C\",\"type\":\"temperature\"},"
        "{\"value\":\"%s\",\"unit\":\"%%\",\"type\":\"humidity\"}"
      "],"
      "\"key\":\"%s\""
    "}",
    mac, LAT, LON, NTPGetEpoch(), temp, hum, KEY);

  return postComposedData(DATA, jsonBuf);
}