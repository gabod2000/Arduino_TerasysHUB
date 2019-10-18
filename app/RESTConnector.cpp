#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h> 
#include <ESP8266WebServer.h>

#include "RESTConnector.h"
#include "Credentials.h"
#include "WiFiCore.h"
#include "Global.h"

HTTPClient http;
WiFiClient client;

unsigned short postComposedData(const char* path, const char* data)
{
  unsigned short httpCode = 0;
  char httpPayload[1024] = {};
  WiFiClientSecure httpsClient;

  httpsClient.setFingerprint(SHA1);
  httpsClient.setTimeout(15000); // 15 Seconds

  if(!httpsClient.connect(SERVER, PORT))
  {
    Serial.println("Connection failed");
  }

  snprintf(httpPayload, 1024, "POST %s HTTP/1.1\r\n"
                              "Host: %s\r\n"
                              "Accept: */*\r\n"
                              "User-Agent: Mozilla/4.0 (compatible; nodemcu esp8266 Arduino;)\r\n"
                              "Connection: close\r\n"
                              "Content-Length: %d\r\n"
                              "Content-Type: application/json\r\n\r\n"
                              "%s", 
                              path, SERVER, strlen(data), data);
  printf("%s\n", httpPayload);
  httpsClient.print(httpPayload);
 
  Serial.println("request sent");

  while (httpsClient.connected()) {
    String line = httpsClient.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
 
  Serial.println("reply was:");
  Serial.println("==========");
  String line;
  while(httpsClient.available()){        
    line = httpsClient.readStringUntil('\n');  //Read Line by Line
    Serial.println(line); //Print response
  }
  Serial.println("==========");
  Serial.println("closing connection");
  
  return httpCode;
}

void RESTInit()
{
  RESTPostTemperature();

  // char mac[LEN_MAC_MAX] = {};
  // char jsonBuf[128] = {};
  // WiFiGetMAC(mac);
  // Printf("Gathered mac : %s\n", mac);
  // snprintf(jsonBuf, 128, "{\"mac\":\"%s\"}", mac);
  // postComposedData(KEYS, jsonBuf);
}

boolean RESTPostTemperature()
{
  char mac[LEN_MAC_MAX] = {};
  char jsonBuf[256] = {};
  WiFiGetMAC(mac);
  Printf("Gathered mac : %s\n", mac);
    // data.mac = wifi.sta.getmac()
    // data.location = {lat=lat, lon=lon}
    // data.timestamp = time
    // data.metrics = {
    //     { value = value,  unit = unit, type = type }
    //     }
    // data.key = mykey
  snprintf(jsonBuf, 256, "{\"mac\":\"%s\", \"location\":{\"lat\":\"%s\", \"lon\":\"%s\"}, \"timestamp\": \"1571148898\",\"metrics\":{\"value\": \"26\", \"unit\":\"C\", \"type\":\"C\"}, \"key\": \"1a918f8f4226504f4b39\"}", mac, LAT, LON);
  printf("%s\n", jsonBuf);
  postComposedData(TEMPERATURE, jsonBuf);

  return true;
}

boolean RESTPostTeraSys(const char* data)
{
  boolean retval = false;
  if (postComposedData(TEMPERATURE, data) == HTTP_OK)
  {
    retval = true;
  }
  
  return retval;
}