#ifndef ARDUINO_NTP_H
#define ARDUINO_NTP_H

/* Use UTC time without GMT settings by defining offset as 0. */
#define NTP_TIME_OFFSET     0
#define NTP_CHECK_INTERVAL  60 * 1000
#define NTP_ADDRESS         "europe.pool.ntp.org"

void NTPBegin();
void NTPLoop();
unsigned long NTPGetEpoch();

#endif /* ARDUINO_NTP_H */