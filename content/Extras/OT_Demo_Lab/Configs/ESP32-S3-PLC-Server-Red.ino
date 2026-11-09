#include <Arduino.h>
#include <WiFi.h>
#include <SPI.h>
#include <ETH.h>
#include <ModbusIP_ESP8266.h>

//#define USE_BUILTIN_LED

#if defined(USE_BUILTIN_LED)
  #include <Adafruit_NeoPixel.h>
  // Define the GPIO pin for the built-in RGB LED
  #define LED_PIN    21
  // Waveshare ESP32-S3-ETH has exactly 1 onboard RGB LED
  #define LED_COUNT   1
  // Initialize the NeoPixel object
  Adafruit_NeoPixel BuiltIn_LED(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
#endif

// Target LED Configuration
#define TARGET_RED_LED_PIN   1
#define TARGET_GREEN_LED_PIN 2
#define TARGET_BLUE_LED_PIN  3

// Verified Hardware Pinout for Waveshare ESP32-S3-ETH
#define W5500_MISO 12
#define W5500_MOSI 11
#define W5500_SCK 13
#define W5500_CS 14
#define W5500_RST 9
#define W5500_INT 10

// Define Server Static IP Network Parameters (Matches slave_IP in client sketch)
IPAddress local_IP(192, 168, 1, 110); 
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);

const uint16_t target_RED_Coil   = 0x00;
const uint16_t target_GREEN_Coil = 0x01;
const uint16_t target_BLUE_Coil  = 0x02;

ModbusIP mb;

unsigned long lastDebugTime = 0;
bool last_RED_CoilState   = false;
bool last_GREEN_CoilState = false;
bool last_BLUE_CoilState  = false;

void setup() {
  Serial.begin(115200);
  delay(500); 
  Serial.println("\n--- Booting Waveshare ESP32-S3-ETH (Server Mode) ---");

  // Step 1: Initialize RED GREEN BLUE GPIO's for the LED output
  #if defined(USE_BUILTIN_LED)
    BuiltIn_LED.begin();           // Initialize the LED pin
    BuiltIn_LED.show();            // Turn off the LED initially
    BuiltIn_LED.setBrightness(50); // Set brightness (0 to 255) to protect your eyes
  #else
    pinMode     (TARGET_RED_LED_PIN,   OUTPUT);
    digitalWrite(TARGET_RED_LED_PIN,   LOW);

    pinMode     (TARGET_GREEN_LED_PIN, OUTPUT);
    digitalWrite(TARGET_GREEN_LED_PIN, LOW);
  
    pinMode     (TARGET_BLUE_LED_PIN,  OUTPUT);
    digitalWrite(TARGET_BLUE_LED_PIN,  LOW);
  #endif

  // Step 2: Force manual physical reset of W5500 hardware transceiver
  pinMode(W5500_RST, OUTPUT);
  digitalWrite(W5500_RST, LOW);
  delay(50);
  digitalWrite(W5500_RST, HIGH);
  delay(200);

  // Step 3: Initialize SPI bus using the physical board layout pins
  SPI.begin(W5500_SCK, W5500_MISO, W5500_MOSI);

  // Step 4: Spin up the W5500 driver layer
  bool started = ETH.begin(ETH_PHY_W5500, 1, W5500_CS, W5500_INT, W5500_RST, SPI);
  if (!started) {
    Serial.println("Hardware SPI link to W5500 failed!");
  } else {
    Serial.println("W5500 controller detected successfully.");
  }

  // Step 5: Bind static IP addresses directly into the interface memory
  if (ETH.config(local_IP, gateway, subnet, primaryDNS)) {
    Serial.println("Static IP configuration stored in memory.");
  } else {
    Serial.println("Static IP configuration rejected!");
  }

  // Step 6: Start Modbus TCP Server engine and register the target coil
  mb.server();
  mb.addCoil(target_RED_Coil, false); 
  mb.addCoil(target_GREEN_Coil, false); 
  mb.addCoil(target_BLUE_Coil, false); 
  Serial.print("Modbus Server active. Listening on IP: ");
  Serial.println(local_IP);
}

void loop() {
  // Keep the Modbus task register engine running smoothly
  mb.task();

  if (ETH.linkUp()) {
    // Read the current state of the coil registered in memory
    bool current_RED_CoilState   = mb.Coil(target_RED_Coil);
    bool current_GREEN_CoilState = mb.Coil(target_GREEN_Coil);
    bool current_BLUE_CoilState  = mb.Coil(target_BLUE_Coil);

    // If the client has changed the coil state, update the physical pin
    if (current_RED_CoilState != last_RED_CoilState) {
      last_RED_CoilState = current_RED_CoilState;
      
      if (current_RED_CoilState) {
 
        #if defined(USE_BUILTIN_LED)
          BuiltIn_LED.setPixelColor(0, BuiltIn_LED.Color(255, 0, 0));
          BuiltIn_LED.show();        
        #else
          digitalWrite(TARGET_RED_LED_PIN, HIGH);
        #endif
        debug_print_Modbus_RX (target_RED_Coil, TARGET_RED_LED_PIN, HIGH);
 
      } else {
 
        #if defined(USE_BUILTIN_LED)
          BuiltIn_LED.setPixelColor(0, BuiltIn_LED.Color(0, 0, 0));
          BuiltIn_LED.show();        
        #else
          digitalWrite(TARGET_RED_LED_PIN, LOW);
        #endif
 
        debug_print_Modbus_RX (target_RED_Coil, TARGET_RED_LED_PIN, LOW);
 
      }
    }
    
    if (current_GREEN_CoilState != last_GREEN_CoilState) {
      last_GREEN_CoilState = current_GREEN_CoilState;
    
      if (current_GREEN_CoilState) {
 
        #if defined(USE_BUILTIN_LED)
          BuiltIn_LED.setPixelColor(0, BuiltIn_LED.Color(0, 255, 0));
          BuiltIn_LED.show();        
        #else
          digitalWrite(TARGET_GREEN_LED_PIN, HIGH);
        #endif
        debug_print_Modbus_RX (target_GREEN_Coil, TARGET_GREEN_LED_PIN, HIGH);
 
      } else {
 
        #if defined(USE_BUILTIN_LED)
          BuiltIn_LED.setPixelColor(0, BuiltIn_LED.Color(0, 0, 0));
          BuiltIn_LED.show();        
        #else
          digitalWrite(TARGET_GREEN_LED_PIN, LOW);
        #endif
 
        debug_print_Modbus_RX (target_GREEN_Coil, TARGET_GREEN_LED_PIN, LOW);
 
      }  
    }

    if (current_BLUE_CoilState != last_BLUE_CoilState) {
      last_BLUE_CoilState = current_BLUE_CoilState;
    
      if (current_BLUE_CoilState) {
 
        #if defined(USE_BUILTIN_LED)
          BuiltIn_LED.setPixelColor(0, BuiltIn_LED.Color(0, 0, 255));
          BuiltIn_LED.show();        
        #else
          digitalWrite(TARGET_BLUE_LED_PIN, HIGH);
        #endif
 
        debug_print_Modbus_RX (target_BLUE_Coil, TARGET_BLUE_LED_PIN, HIGH);
 
      } else {
 
        #if defined(USE_BUILTIN_LED)
          BuiltIn_LED.setPixelColor(0, BuiltIn_LED.Color(0, 0, 0));
          BuiltIn_LED.show();        
        #else
          digitalWrite(TARGET_BLUE_LED_PIN, LOW);
        #endif
 
        debug_print_Modbus_RX (target_BLUE_Coil, TARGET_BLUE_LED_PIN, LOW);
 
      }

    }
  } 
  else {
    unsigned long currentMillis = millis();
    if (currentMillis - lastDebugTime >= 3000) {
      lastDebugTime = currentMillis;
      Serial.println("Awaiting physical link connection (Check RJ45 cable/LEDs)...");
    }
  }
}

void debug_print_Modbus_RX (int coil, int pin, bool state) {
  
  String string_hex_coil;
  
  if (coil < 0x10)
    string_hex_coil = '0' + String(coil, HEX);
  else
    string_hex_coil = String(coil, HEX);
  
  if (state)
    Serial.println("Modbus RX -> Coil 0x" + string_hex_coil + " changed to ON.  GPIO " + pin + " set to 1");
  else
    Serial.println("Modbus RX -> Coil 0x" + string_hex_coil + " changed to OFF. GPIO " + pin + " set to 0");

}