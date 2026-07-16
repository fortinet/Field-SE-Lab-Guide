+++
title = "Configs"
type = "default"
weight =20
+++
 
### **FGR Configs**

- Microsegmentation with Modbus Traffic
    - {{% button href="https://github.com/fortinet/Field-SE-Lab-Guide/raw/refs/heads/main/content/Extras/OT_Demo_Lab/Configs/OT_Demo_Kit-Digital_MODBUS.txt" style="tip" icon="angle-down" %}}FortiGate Rugged Config - Modbus{{% /button %}} 
    - Change FSW port mode to NAC
    ![Dynamic_VLAN](Dynamic_VLAN.png)

- Digital I/O
    -  {{% button href="https://github.com/fortinet/Field-SE-Lab-Guide/raw/refs/heads/main/content/Extras/OT_Demo_Lab/Configs/OT_Demo_Kit-Digital_IO.txt" style="tip" icon="angle-down" %}}FortiGate Rugged Config - Digital I/O{{% /button %}} 

- FAP
    - {{% button href="https://github.com/fortinet/Field-SE-Lab-Guide/raw/refs/heads/main/content/Extras/OT_Demo_Lab/Configs/OT_Demo_Kit-Digital_Wireless.txt" style="tip" icon="angle-down" %}}FortiGate Rugged Config - Wireless{{% /button %}} 

### **How-To Program Arduino Modbus Devices**

- Step-by-step guide to installing the Arduino IDE, loading OT sketches, and uploading Modbus TCP firmware to the Arduino Uno WiFi Rev2."

**Arduino Modbus Sketches:**

- Server (with LED)
    - {{% button href="https://github.com/fortinet/Field-SE-Lab-Guide/raw/refs/heads/main/content/Extras/OT_Demo_Lab/Configs/Ethernet_Modbus_TCP_Server_LED.ino" style="tip" icon="angle-down" %}}Ethernet_Modbus_TCP_Server_LED.ino{{% /button %}} 
 - Client (without LED)
    - {{% button href="https://github.com/fortinet/Field-SE-Lab-Guide/raw/refs/heads/main/content/Extras/OT_Demo_Lab/Configs/Ethernet_Modbus_TCP_Client_Toggle.ino" style="tip" icon="angle-down" %}}Ethernet_Modbus_TCP_Client_Toggle.ino{{% /button %}}  

---

### Prerequisites

Before starting, ensure you have the following:

- A computer running Windows 10/11 with internet access and local administrator privileges
- An Arduino Uno WiFi Rev2 board
- A USB Type-A to Type-B cable
- Access to the lab network (Ethernet switch with available port)

{{% notice warning %}}
Do not power the Arduino via both Power-over-Ethernet (PoE) and USB simultaneously. Use one power source at a time to avoid hardware damage.
{{% /notice %}}

---

### Install the Arduino IDE

Download the Arduino IDE from **<https://www.arduino.cc/en/software/>** and run the installer.

---

### Install Board Support Package

The Arduino Uno WiFi Rev2 requires a separate board package. After installing the IDE:

- Open the **Boards Manager** from the left sidebar
- Search for `megaAVR`
- Locate **Arduino megaAVR Boards** by Arduino and click **Install**

[![Boards Manager showing Arduino megaAVR Boards](boards-manager.png)](boards-manager.png)

{{% notice note %}}
After installation the package status will show `INSTALLED`. {{% /notice %}}

---

### Open the OT Sketch Files

Open the sketch files from this page. When prompted to move the file into a sketch folder, click **OK**.

[![Arduino IDE prompts you to move the .ino file into a correctly named sketch folder](moving-dialog.png)](moving-dialog.png)

{{% notice note %}}
There is a known bug in Arduino IDE 2.x where a sketch may not appear in the Sketchbook after opening. To fix this, click the three-dot menu (**⋯**) on the sketch tab and select **Rename**.
{{% /notice %}}

[![Click ⋯ on the sketch tab and select Rename](rename-menu.png)](rename-menu.png)

- Save the file (**Ctrl+S**) to the default Arduino documents directory
- Both sketches should now appear under **OT Files** in the Sketchbook

[![Both sketches visible in the Sketchbook under OT Files](sketchbook.png)](sketchbook.png)

- Repeat for both the Client and Server sketch files

---

### Connect the Arduino

Plug the Arduino into your workstation via USB. The IDE should auto-detect the board and assign a COM port.

- If not detected automatically, click **Select Board** in the toolbar and choose **Arduino Uno WiFi Rev2**

[![Board selection dropdown showing Arduino Uno WiFi Rev2 auto-detected](board-select.png)](board-select.png)

{{% notice warning %}}
Do not connect PoE and USB power simultaneously — use only one power source at a time.
{{% /notice %}}

---

### Install Required Libraries

The OT sketches depend on two libraries. Install them via the Library Manager:

- Click the **Library Manager** icon in the left sidebar (or go to **Tools → Manage Libraries**)
- Search for `ArduinoModbus` and click **Install**
- When the dependency dialog appears, click **Install All**

[![Dependency dialog — click Install All to install ArduinoModbus and ArduinoRS485](install-all.png)](install-all.png)

[![ArduinoRS485 library in the Library Manager](library-rs485.png)](library-rs485.png)

{{% notice note %}}
Always choose **Install All**. Installing ArduinoModbus without ArduinoRS485 will cause compilation errors.
{{% /notice %}}

---

### Upload the Sketches

Each sketch must be uploaded to a separate Arduino board — one for the Server (with LED), one for the Client (without LED).

- Open the **Server** sketch (`Ethernet_Modbus_TCP_Server_LED`) from the Sketchbook
- Confirm the correct board and port are selected in the toolbar
- Click the **Upload** button (→ arrow icon)

[![Click the Upload button in the toolbar to compile and flash the sketch](upload-button.png)](upload-button.png)

- Wait for the output console to display `Done uploading`
- Disconnect the first Arduino, connect the second, and repeat for the **Client** sketch (`Ethernet_Modbus_TCP_Client_Toggle`)

{{% notice warning %}}
If compilation errors appear, verify that **ArduinoModbus** and **ArduinoRS485** are both installed and the correct board is selected.
{{% /notice %}}

---

### Checklist

Verify all steps are complete before beginning the lab exercise:

- [ ] Arduino IDE installed
- [ ] Arduino megaAVR Boards package installed via Boards Manager
- [ ] Server sketch (`Ethernet_Modbus_TCP_Server_LED`) opened and saved
- [ ] Client sketch (`Ethernet_Modbus_TCP_Client_Toggle`) opened and saved
- [ ] Sketchbook visibility bug resolved (Rename → Save) for both sketches
- [ ] Arduino connected via USB; board and port confirmed in toolbar
- [ ] ArduinoModbus and ArduinoRS485 libraries installed (Install All)
- [ ] Server sketch uploaded to first Arduino board
- [ ] Client sketch uploaded to second Arduino board

---

### **Arduino Troubleshooting Using the Serial Monitor**

The Serial Monitor provides real-time terminal output from the connected Arduino, making it the primary tool for diagnosing connection and communication issues at runtime.
{{% notice warning %}}
Do not power the Arduino via both Power-over-Ethernet (PoE) and USB simultaneously. Use one power source at a time to avoid hardware damage.
{{% /notice %}}

### Opening the Serial Monitor

1. Ensure the Arduino is connected via USB **and the POE Power is NOT connected** and the correct board and port are selected 
2. Click the **Serial Monitor icon** (magnifying glass) in the top-right corner of the IDE toolbar.

[![Serial Monitor icon in the Arduino IDE toolbar](serial-monitor-icon.png)](serial-monitor-icon.png)

3. The Serial Monitor panel will open at the bottom of the IDE window.
4. Confirm the baud rate is set to **9600 baud** (bottom-right of the Serial Monitor panel).

### Reading Serial Output

The Serial Monitor displays live text output from the Arduino sketch. Use this to verify connectivity and diagnose Modbus communication errors.

[![Serial Monitor output showing Modbus client connection failures](serial-monitor-output.png)](serial-monitor-output.png)

*Serial Monitor output showing repeated Modbus client connection failures. This indicates the client cannot reach the server — check Ethernet cabling and IP configuration.*

{{% notice note %}}
The Serial Monitor is only active while the Arduino is connected via USB. Once you disconnect USB and power the device via PoE, serial output is no longer available.
{{% /notice %}}
