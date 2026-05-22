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

//const int ledPin = LED_BUILTIN;
const int ledPin = 7;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Ethernet Modbus TCP Example");

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
  /*
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }
  */
  // start the server
  ethServer.begin();
  
  // start the Modbus TCP server
  if (!modbusTCPServer.begin()) {
    Serial.println("Failed to start Modbus TCP Server!");
    while (1);
  }
  pinMode(ledPin, OUTPUT);
  
  // configure a single coil at address 0x00
  modbusTCPServer.configureCoils(0x00, 10);
  modbusTCPServer.configureDiscreteInputs(0x00, 10);
  modbusTCPServer.configureHoldingRegisters(0x00, 10);
  modbusTCPServer.configureInputRegisters(0x00, 10);
}

void loop() {
  // listen for incoming clients
  EthernetClient client = ethServer.available();
  
  if (client) {
    // a new client connected
    Serial.println("new client");

    // let the Modbus TCP accept the connection 
    modbusTCPServer.accept(client);

    while (client.connected()) {
      // poll for Modbus TCP requests, while client connected
      modbusTCPServer.poll();

      // update the LED
      updateLED();
      //delay(1000);
      Serial.print("LED: ");
      Serial.print(modbusTCPServer.coilRead(0));
      Serial.print(" Chan: ");
      Serial.println(modbusTCPServer.holdingRegisterRead(0));
      
    }

    Serial.println("client disconnected");
  }
}

void updateLED() {
  // read the current value of the coil
  int coilValue = modbusTCPServer.coilRead(0);
  if (coilValue) {
    // coil value set, turn LED on
    digitalWrite(ledPin, HIGH);
  } else {
    // coild value clear, turn LED off
    digitalWrite(ledPin, LOW);
  }
}

