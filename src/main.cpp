#include <Arduino.h>
#include "M5Unified.h"
#include "M5GFX.h"
#include "MultipleSatellite.h"

// put function declarations here:

static const int RXPin = 5,TXPin = 6;
static const uint32_t GPSBaud = 115200;
MultipleSatellite gps(Serial1, GPSBaud, SERIAL_8N1, RXPin, TXPin);

void setup() {
    M5.begin();
    M5.Power.begin();
    M5.Display.setRotation(3);
    M5.Display.fillScreen(BLACK);
    
    Serial1.begin(GPSBaud, SERIAL_8N1, RXPin, TXPin);
    gps.begin();

    // Set the GPS to a specific mode if needed
    gps.setSatelliteMode(SATELLITE_MODE_GPS);
    
    // Optionally set the system boot mode
    gps.setSystemBootMode(BOOT_HOST_START);

    // Print GPS version
    String version = gps.getGNSSVersion();
    M5.Display.println("GPS Version: " + version);
}

void loop() {

}

// put function definitions here:
