/*
  Ethernet Modbus TCP Client Toggle

  This sketch toggles three coils of a Modbus TCP server connected
  in sequence on and off every second.

  Circuit:
   - Any Arduino MKR Board
   - MKR ETH Shield

*/

#include <SPI.h>
#include <Ethernet.h>

#include <ArduinoRS485.h> // ArduinoModbus depends on the ArduinoRS485 library
#include <ArduinoModbus.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFF, 0xED
};
IPAddress ip(192,168,1,20);
IPAddress myDNS(8,8,8,8);
IPAddress gateway(192,168,1,1);

EthernetClient ethClient;
ModbusTCPClient modbusTCPClient(ethClient);

IPAddress server(192,168,1,10); // update with the IP Address of your Modbus server

#define Modbus_1 0x01
#define Modbus_0 0x00

const uint16_t target_RED_Coil   = 0x00;
const uint16_t target_GREEN_Coil = 0x01;
const uint16_t target_BLUE_Coil  = 0x02;

// State management variables
unsigned long lastActionTime = 0;
unsigned long lastDebugTime = 0;

// States == 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 0
int nextState = 0; 

void setup() {
  // Use Ethernet.init(pin) to configure the CS pin
  Ethernet.init(10);  // Most Arduino shields
  
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // start the Ethernet connection and the client:
  Ethernet.begin(mac, ip);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield not found");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  else {
    Serial.println("Ethernet shield found");
  }

  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("No RJ45 cable");
  }
}

void loop() {

  // Guard condition: Only interact with network if physical cable link is active
  if (Ethernet.linkStatus() != LinkOFF) {
    
    unsigned long currentMillis = millis();

    // Data Pacing Timer: Executes every 1000ms
    if (currentMillis - lastActionTime >= 1000) {
      lastActionTime = currentMillis;

      // Handle standard TCP handshake connection status
      if (!modbusTCPClient.connected()) {
        Serial.print("Attempting connection to Modbus Slave [");
        Serial.print(server);
        Serial.println("]...");
        
        if (!modbusTCPClient.begin(server, 502)) {
          Serial.println("Modbus Client fail connect");
        } else {
          Serial.println("Modbus Client connected");
        }
      }
    } else {
        // client connected

        // Sequentially progress through states just like the ESP32 firmware
        
        switch (nextState) {
          case 0:
            debug_print_Modbus_TX(target_RED_Coil, true);
            if (!modbusTCPClient.coilWrite(target_RED_Coil, Modbus_1)) {
              debug_print_Fail_Writing_Coil (target_RED_Coil);
            }
            nextState = 1;
            break;

          case 1:
            debug_print_Modbus_TX(target_RED_Coil, false);
            if (!modbusTCPClient.coilWrite(target_RED_Coil, Modbus_0)) {
              debug_print_Fail_Writing_Coil (target_RED_Coil);
            }
            nextState = 2;
            break;

          case 2:
            debug_print_Modbus_TX(target_GREEN_Coil, true);
            if (!modbusTCPClient.coilWrite(target_GREEN_Coil, Modbus_1)) {
              debug_print_Fail_Writing_Coil (target_GREEN_Coil);
            }
            nextState = 3;
            break;

          case 3:
            debug_print_Modbus_TX(target_GREEN_Coil, false);
            if (!modbusTCPClient.coilWrite(target_GREEN_Coil, Modbus_0)) {
              debug_print_Fail_Writing_Coil (target_GREEN_Coil);
            }
            nextState = 4;
            break;

          case 4:
            debug_print_Modbus_TX(target_BLUE_Coil, true);
            if (!modbusTCPClient.coilWrite(target_BLUE_Coil, Modbus_1)) {
              debug_print_Fail_Writing_Coil (target_BLUE_Coil);
            }
            nextState = 5;
            break;

          case 5:
            debug_print_Modbus_TX(target_BLUE_Coil, false);
            if (!modbusTCPClient.coilWrite(target_BLUE_Coil, Modbus_0)) {
              debug_print_Fail_Writing_Coil (target_BLUE_Coil);
            }
            nextState = 0;
            break;

          default:
            break;
        }
        
        delay(1000);
        
        // Disconnect Session
        modbusTCPClient.stop();
    }
  }
  // Safe Fallback: Executed when no physical ethernet link is established
  else {
    unsigned long currentMillis = millis();
    if (currentMillis - lastDebugTime >= 3000) {
      lastDebugTime = currentMillis;
      Serial.println("Awaiting physical link connection (Check RJ45 cable/LEDs)...");
    }
  }

}

// Replicated debug printer to output identical Serial logs to your ESP32 setup
void debug_print_Modbus_TX (int coil, bool state) {
  String string_hex_coil;
  
  if (coil < 0x10)
    string_hex_coil = '0' + String(coil, HEX);
  else
    string_hex_coil = String(coil, HEX);
  
  if (state)
    Serial.println("Modbus TX -> Writing Coil 0x" + string_hex_coil + " sent 0x01");
  else
    Serial.println("Modbus TX -> Writing Coil 0x" + string_hex_coil + " sent 0x00");
}

// Replicated debug printer to output identical Serial logs
void debug_print_Fail_Writing_Coil (int coil) {

  Serial.println("Fail writing coil: " + coil);
  Serial.println(modbusTCPClient.lastError());
}