/*
  RFID-Based Asset Tracking - Simple Version
  For Arduino Uno + MFRC522 RFID Reader
  Reads tag UID and sends it to Serial Monitor (or computer logging software)
  
  Asset Tracking
*/

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 9    // SDA pin on MFRC522
#define RST_PIN 8   // RST pin on MFRC522

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  
  Serial.println("RFID Asset Tracking System");
  Serial.println("Scan a device tag...");
}

void loop() {
  // Look for a new card
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  
  // Select the card
  if (!mfrc522.PICC_ReadCardSerial()) return;
  
  // Print UID
  Serial.print("UID:");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }

  // Optional: Print location ID (set per RFID reader in hospital)
  Serial.print(" | Location: Ward_A_Reader_01");

  // Optional: Print timestamp (PC will add this if logging via Serial)
  Serial.println();

  // Halt PICC
  mfrc522.PICC_HaltA();
}
