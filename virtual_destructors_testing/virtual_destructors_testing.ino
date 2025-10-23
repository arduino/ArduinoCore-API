
#if defined(ARDUINO_SAMD_MKR1000)
  #include <WiFi101.h>
  #include <WiFiUdp.h>
#elif defined(ARDUINO_SAMD_MKRWIFI1010) || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_AVR_UNO_WIFI_REV2) || defined (ARDUINO_NANO_RP2040_CONNECT)
  #include <WiFiNINA.h>
  #include <WiFiUdp.h>
#elif defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_PORTENTA_H7_M7) || \
  defined(ARDUINO_NICLA_VISION) || defined(ARDUINO_OPTA) || defined(ARDUINO_GIGA)
  #include <WiFi.h>
  #include <WiFiUdp.h>
#elif defined(ARDUINO_PORTENTA_C33)
  #include <WiFiC3.h>
  #include <WiFiUdp.h>
#elif defined(ARDUINO_ARCH_ESP8266)
  #include <ESP8266WiFi.h>
  #include <WiFiUdp.h>
#elif defined(ARDUINO_ARCH_ESP32)
  #include <WiFi.h>
  #include <WiFiUdp.h>
#elif defined(ARDUINO_UNOR4_WIFI)
  #include <WiFiS3.h>
#elif defined(ARDUINO_RASPBERRY_PI_PICO_W)
  #include <WiFi.h>
  #include <WiFiUdp.h>
#endif
void setup() {
    Serial.begin(115200);

    while(!Serial);

    Serial.println("Hello world");

#if defined(ARDUINO_SAMD_MKR1000)           || \
    defined(ARDUINO_SAMD_MKRWIFI1010)       || \
    defined(ARDUINO_SAMD_NANO_33_IOT)       || \
    defined(ARDUINO_AVR_UNO_WIFI_REV2)      || \
    defined(ARDUINO_NANO_RP2040_CONNECT)    || \
    defined(ARDUINO_PORTENTA_H7_M7)         || \
    defined(ARDUINO_PORTENTA_H7_M7)         || \
    defined(ARDUINO_NICLA_VISION)           || \
    defined(ARDUINO_OPTA)                   || \
    defined(ARDUINO_GIGA)                   || \
    defined(ARDUINO_PORTENTA_C33)           || \
    defined(ARDUINO_ARCH_ESP8266)           || \
    defined(ARDUINO_ARCH_ESP32)             || \
    defined(ARDUINO_UNOR4_WIFI)             || \
    defined(ARDUINO_RASPBERRY_PI_PICO_W)
    Client *c = new WiFiClient(); // sizeof // as global variable
    delete c;
#endif
}

void loop() {
}
