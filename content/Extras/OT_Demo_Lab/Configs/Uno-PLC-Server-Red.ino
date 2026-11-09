#include <SPI.h>
#include <Ethernet.h>

#include <ArduinoRS485.h> // ArduinoModbus depends on the ArduinoRS485 library
#include <ArduinoModbus.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
// The IP address will be dependent on your local network:
byte mac[] = { 0xA8, 0x61, 0x0A, 0xAE, 0x84, 0xB0 };
IPAddress ip(192,168,1,10);
IPAddress myDNS(8,8,8,8);
IPAddress gateway(192,168,1,1);

EthernetServer ethServer(502);

ModbusTCPServer modbusTCPServer;

// GPIO Pin LED Configuration
#define TARGET_RED_LED_PIN   7
#define TARGET_GREEN_LED_PIN 6
#define TARGET_BLUE_LED_PIN  5

const uint16_t target_RED_Coil   = 0x00;
const uint16_t target_GREEN_Coil = 0x01;
const uint16_t target_BLUE_Coil  = 0x02;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  // You can use Ethernet.init(pin) to configure the CS pin
  Ethernet.init(10);  // Most Arduino shields
  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip, myDNS, gateway);
  delay(1000);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }

  // start the server
  ethServer.begin();
  
  // start the Modbus TCP server
  if (!modbusTCPServer.begin()) {
    Serial.println("Failed to start Modbus TCP Server!");
    while (1);
  }
  
    // Initialize GPIO outputs
  pinMode(TARGET_RED_LED_PIN, OUTPUT);
  pinMode(TARGET_GREEN_LED_PIN, OUTPUT);
  pinMode(TARGET_BLUE_LED_PIN, OUTPUT);
  
  // configure a single coil at address 0x00
  modbusTCPServer.configureCoils(0x00, 3);

  Serial.println("End of Setup");

}

void loop() {
  // listen for incoming clients
  EthernetClient client = ethServer.available();
  
  Serial.println("Looping");

  if (client) {
    // a new client connected
    Serial.println("new client");

    // let the Modbus TCP accept the connection 
    modbusTCPServer.accept(client);

    while (client.connected()) {
      // poll for Modbus TCP requests, while client connected
      modbusTCPServer.poll();
      
      Serial.println("Connected");

      // update the LEDs
      updateLED(TARGET_RED_LED_PIN,   target_RED_Coil);
      updateLED(TARGET_GREEN_LED_PIN, target_GREEN_Coil);
      updateLED(TARGET_BLUE_LED_PIN,  target_BLUE_Coil);
      
      Serial.print("R: ");
      Serial.print(modbusTCPServer.coilRead  (target_RED_Coil));
      Serial.print("G: ");
      Serial.print(modbusTCPServer.coilRead  (target_GREEN_Coil));
      Serial.print("B: ");
      Serial.println(modbusTCPServer.coilRead(target_BLUE_Coil));
      
    }

        // Explicitly close the connection and free up the hardware socket!
    client.stop(); 
    Serial.println("Client disconnected & socket freed");
  }
}

void updateLED(int gpio_pin, int coil) {
  // read the current value of the coil
  int coilValue = modbusTCPServer.coilRead(coil);
  if (coilValue) {
    // coil value set, turn LED on
    digitalWrite(gpio_pin, HIGH);
  } else {
    // coild value clear, turn LED off
    digitalWrite(gpio_pin, LOW);
  }
}
