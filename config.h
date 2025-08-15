// config.h - RFID Asset Tracking Configuration

#ifndef CONFIG_H
#define CONFIG_H


// RFID Reader Pin Settings

#define SS_PIN   9    // SDA pin for MFRC522
#define RST_PIN  8    // RST pin for MFRC522


// System Settings

#define SERIAL_BAUDRATE 9600    // Serial communication speed

// Unique ID for the location of this reader
// Example: "Ward_A_Reader_01", "ICU_Reader_02"
#define LOCATION_ID "Ward_A_Reader_01"

// =========================
// Optional Features
// =========================
// Uncomment if you want to enable debug messages
// #define DEBUG_MODE

#endif
