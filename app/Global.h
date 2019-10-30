#ifndef ARDUINO_GLOBAL_H
#define ARDUINO_GLOBAL_H

/* Serial configs */
#define Printf            Serial.printf
#define SERIAL_BAUD_RATE  9600

/* Timer period for periodic events */
#define TIMER_PERIOD 20 * 1000

/* Buffer sizes */
#define LEN_IP_MAX  17
#define LEN_MAC_MAX 2 * 6 + 5 + 1

#endif /* ARDUINO_GLOBAL_H */
