#include "Hardware.h"
#include "Global.h"
#include <DHT.h>

DHT dht(DHT_PIN, DHT_TYPE);
const uint8_t hw_delay = 10;

String Temperature()
{
  float t = dht.readTemperature(DHT_FAHRENHEIT);
  if (!ENABLE_DHT || isnan(t)) {
    Serial.println("Failed to read from DHT sensor or not enabled!");
    return String(INCORRECT_MEASUREMENT);
  } else {
    Serial.println(t);
    return String(t);
  }
}

String Humidity()
{
  float h = dht.readHumidity();
  if (!ENABLE_DHT || isnan(h)) {
    Serial.println("Failed to read from DHT sensor or not enabled!");
    return String(INCORRECT_MEASUREMENT);
  } else {
    Serial.println(h);
    return String(h);
  }
}

String AirQuality()
{
  int sensor_read = 0;
  sensor_read = analogRead(MQ3_PIN);
  if (ENABLE_MQ3 && sensor_read > 0 && sensor_read < 1024) {
    return String(sensor_read * 100 / 1024);
  } else {
    return String(INCORRECT_MEASUREMENT);
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

