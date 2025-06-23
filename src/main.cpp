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
    Serial1.begin(115200);
    while (!Serial1) {
        delay(10); // Wait for Serial to be ready
    }
    M5.Display.fillScreen(BLACK);
    
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
    // Update GPS data
    gps.updateGPS();
    //Serial.println("%d",);
    
    delay(10);
}

// put function definitions here:
