#include "WiFiCore.h"
#include "Global.h"

const uint16_t delayMilis = 1000;
  
void WiFiBegin(const char* ssid, const char* pass)
{
  WiFi.begin(ssid, pass);
  Printf("Waiting for AP connection ...\n");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(delayMilis);
    Printf(".");
  }
  char deviceIP[LEN_IP_MAX] = {};
  char macBuffer[LEN_MAC_MAX] = {};
  WiFiGetIP(deviceIP);
  WiFiGetMAC(macBuffer);
  Printf("\nConnected to AP. IP : %s. MAC : %s\n", deviceIP, macBuffer);
}

void WiFiGetIP(char *deviceIP)
{
  IPAddress ip = WiFi.localIP();
  snprintf(deviceIP, LEN_IP_MAX, "%d.%d.%d.%d",ip[0],ip[1],ip[2],ip[3]);
}

void WiFiGetMAC(char *macBuffer)
{
  byte mac[6];
  WiFi.macAddress(mac);
  snprintf(macBuffer, LEN_MAC_MAX, "%02x:%02x:%02x:%02x:%02x:%02x",
    mac[0],mac[1],mac[2],mac[3], mac[4], mac[5]);
}

void WiFiGetSSID(char* ssidBuffer)
{
  memset(ssidBuffer, 0, LEN_SSID_MAX);
  strncpy(ssidBuffer, WiFi.SSID().c_str(), LEN_SSID_MAX);
}

void WiFiGetPassphrase(char* passBuffer)
{
  memset(passBuffer, 0, LEN_PASSPHRASE_MAX);
  strncpy(passBuffer, WiFi.psk().c_str(), LEN_PASSPHRASE_MAX);
}

