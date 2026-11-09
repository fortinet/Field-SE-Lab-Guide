#include <Arduino.h>
#include <WiFi.h>   
#include <SPI.h>
#include <ETH.h>
#include <ModbusIP_ESP8266.h> 

// Verified Hardware Pinout for Waveshare ESP32-S3-ETH
#define W5500_MISO 12
#define W5500_MOSI 11
#define W5500_SCK  13
#define W5500_CS   14
#define W5500_RST  9
#define W5500_INT  10  

// Define your Static IP Network Parameters
IPAddress local_IP(192, 168, 1, 120);   
IPAddress gateway(192, 168, 1, 1);     
IPAddress subnet(255, 255, 255, 0);    
IPAddress primaryDNS(8, 8, 8, 8);      

// Target Modbus Server (Slave) Settings
IPAddress slave_IP(192, 168, 1, 110); 

const uint16_t target_RED_Coil   = 0x00;
const uint16_t target_GREEN_Coil = 0x01;
const uint16_t target_BLUE_Coil  = 0x02;

ModbusIP mb;

// State management variables
unsigned long lastActionTime = 0;
unsigned long lastDebugTime = 0;

// States == 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 0
int nextState = 0; 

void setup() {
  Serial.begin(115200);
  delay(500); // Give the serial line a brief moment to settle
  Serial.println("\n--- Booting Waveshare ESP32-S3-ETH ---");

  // Step 1: Force manual physical reset of W5500 hardware transceiver
  pinMode(W5500_RST, OUTPUT);
  digitalWrite(W5500_RST, LOW);
  delay(50);
  digitalWrite(W5500_RST, HIGH);
  delay(200); 

  // Step 2: Initialize SPI bus using the physical board layout pins
  SPI.begin(W5500_SCK, W5500_MISO, W5500_MOSI);

  // Step 3: Spin up the W5500 driver layer
  bool started = ETH.begin(ETH_PHY_W5500, 1, W5500_CS, W5500_INT, W5500_RST, SPI);
  if (!started) {
    Serial.println("Hardware SPI link to W5500 failed!");
  } else {
    Serial.println("W5500 controller detected successfully.");
  }

  // Step 4: Immediately bind static IP addresses directly into the interface memory
  if (ETH.config(local_IP, gateway, subnet, primaryDNS)) {
    Serial.println("Static IP configuration stored in memory.");
  } else {
    Serial.println("Static IP configuration rejected!");
  }
}

void loop() {
  // Keep the Modbus task register engine running smoothly
  mb.task();

  // Guard condition: Only interact with network if physical cable link is active
  if (ETH.linkUp()) {
    unsigned long currentMillis = millis();

    // Data Pacing Timer: Executes every 1000ms
    if (currentMillis - lastActionTime >= 1000) {
      lastActionTime = currentMillis;

      // Handle standard TCP handshake connection status
      if (!mb.isConnected(slave_IP)) {
        Serial.print("Attempting connection to Modbus Slave [");
        Serial.print(slave_IP);
        Serial.println("]...");
        mb.connect(slave_IP);
      } else {
        switch (nextState) {
            case 0:
              debug_print_Modbus_TX (target_RED_Coil, true);
              mb.writeCoil(slave_IP, target_RED_Coil, true);
              nextState = 1; // Moves to case 1 next
              break;

            case 1:
              debug_print_Modbus_TX (target_RED_Coil, false);
              mb.writeCoil(slave_IP, target_RED_Coil, false);
              nextState = 2; // Alternates back to case 0, change this to route to case 2 if needed
              break;
            case 2:
              debug_print_Modbus_TX (target_GREEN_Coil, true);
              mb.writeCoil(slave_IP, target_GREEN_Coil, true);
              nextState = 3; // Moves to case 1 next
              break;

            case 3:
              debug_print_Modbus_TX (target_GREEN_Coil, false);
              mb.writeCoil(slave_IP, target_GREEN_Coil, false);
              nextState = 4; // Alternates back to case 0, change this to route to case 2 if needed
              break;
              // Add your code for case 2 here
              break;
            case 4:
              debug_print_Modbus_TX (target_BLUE_Coil, true);
              mb.writeCoil(slave_IP, target_BLUE_Coil, true);
              nextState = 5; // Moves to case 1 next
              break;

            case 5:
              debug_print_Modbus_TX (target_BLUE_Coil, false);
              mb.writeCoil(slave_IP, target_BLUE_Coil, false);
              nextState = 0; // Alternates back to case 0, change this to route to case 2 if needed
              break;
              // Add your code for case 2 here
              break;

            default:
              // Optional: runs if nextState doesn't match any case
              break;
          }
          mb.dropTransactions();
          mb.disconnect(slave_IP);
      }
    }
  } 
  // Safe Fallback: Executed when no physical ethernet link is established
  else {
    unsigned long currentMillis = millis();
    // FIXED: Prints only once every 3000ms to completely prevent serial buffer crashes
    if (currentMillis - lastDebugTime >= 3000) {
      lastDebugTime = currentMillis;
      Serial.println("Awaiting physical link connection (Check RJ45 cable/LEDs)...");
    }
  }
}

void debug_print_Modbus_TX (int coil, bool state) {
  
  String string_hex_coil;
  
  if (coil < 0x10)
    string_hex_coil = '0' + String(coil, HEX);
  else
    string_hex_coil = String(coil, HEX);
  
  if (state)
    Serial.println("Modbus TX -> Writing Coil 0x" + string_hex_coil + " sent change to 1");
  else
    Serial.println("Modbus TX -> Writing Coil 0x" + string_hex_coil + " sent change to 0");

}
