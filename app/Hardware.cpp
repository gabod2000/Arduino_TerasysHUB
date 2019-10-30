#include "Hardware.h"
#include "Global.h"
#include <DHT.h>

DHT dht(DHT_PIN, DHT_TYPE);
const uint8_t hw_delay = 10;

String Temperature()
{
  float t = dht.readTemperature(DHT_FAHRENHEIT);
  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return INCORRECT_MEASUREMENT;
  }
  else {
    Serial.println(t);
    return String(t);
  }
}

String Humidity()
{
  float h = dht.readHumidity();
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return INCORRECT_MEASUREMENT;
  }
  else {
    Serial.println(h);
    return String(h);
  }
}

void SerialInit()
{
  Serial.begin(SERIAL_BAUD_RATE);
  Serial.setDebugOutput(true);
  delay(hw_delay);
}

void GPIOInit()
{
  dht.begin();
}

void HWInit()
{
  SerialInit();
  GPIOInit();
}

void HWRestart()
{
  ESP.restart();
}

