+++
title = "Demo Use Cases"
type = "default"
weight =60
+++

### **Intra-VLAN Blocking**

**Overview**

Demonstrate how a basic OT MODBUS environment unmodified, can be moved from an unmanaged switch to a FortiGate connected to a FortiSwitch via FortiLink and gain visibility, inspection, and microsegmentation.

**High Level Steps**
-	MODBUS devices (Client and Server) communicating on an unmanaged 4 port switch
-	Move the MODBUS devices to FortiSwitch with no changes made to the MODBUS devices
-	Configure Intra-VLAN Blocking and demonstrate the FortiGate’s visibility of the MODBUS traffic
-	Add/Configure micro-segmentation where MODBUS devices only speak to each other only using MODBUS protocol/application

**Required Lab Components**
-	FGR & FSR
-	MODBUS Server/Client devices
-	Unmanaged “cheap” 4 port switch 

**Playbook**

The steps/screenshots needs built out


### **Digital I/O and Safety State**

**Overview**

FGR-70F and FGR-70F-3G4g has support for the following Digital I/O:
-	Two digital inputs: contact state (open/closed) or voltage state (high/low) inputs
-	Single digital output: Both normal-closed (NC) and normal-open (NO) states
o	Support three states:
	Default – NC=closed, NO=open
	Opposite – NC=open, NO=closed
	Alternating – The NC and NO states will continuously alternate between default and open
-	Keeps output state between system reboots

Safety-State provides operators a visible notation that the FortiGate is operating in an environment that is experiencing an abnormal condition.  
-	Both a CLI-based and GUI-based message is provided
o	Messaging is independent and persistent
-	Entering/exiting the safety-state is performed by a CLI execute command:
o	Can be performed manually via CLI.
o	Can be included within an automation CLI script, and controlled as an action by an automation stitch responding to a trigger
-	Generates System Event Log
o	Safety-State event log can be used as a trigger for additional automation

**Required Lab Components**

-	FGR & FSR

**Playbook**

The steps/screenshots needs built out


### **Industrial Connectivity (RS-232 to TCP)**

**Overview**

https://docs.fortinet.com/document/fortigate/7.4.4/administration-guide/426842 
The industrial connectivity daemon (icond) and Industrial Connectivity service are available for FortiGate Rugged models equipped with a serial RS-232 (DB9/RJ45) interface to:

-	Receive data in IEC 60870-5-101 serial protocol and convert it to IEC 60870-5-104 TCP/IP. See Sample configuration to convert IEC 60870-5-101 serial to IEC 60870-5-104 TCP/IP transport .

-	Receive data in Modbus serial (RTU/ASCII) protocol and convert it to Modbus TCP. See Sample configuration to convert Modbus serial to Modbus TCP.

**Required Lab Components**
-	FGR & FSR
-	MODBUS Server/Client devices

**Playbook**
The steps/screenshots needs built out


### **OT Asset Visibility and Network Topology**

**Overview**

https://docs.fortinet.com/document/fortigate/7.6.0/administration-guide/880597/ot-asset-visibility-and-network-topology

When the Operational Technology (OT) feature is enabled, tabs are added in the Asset Identity Center page to view the OT asset list and OT network topology using Purdue Levels.  This feature is available regardless of whether a Security Fabric is enabled.

https://docs.fortinet.com/document/fortigate/7.4.0/new-features/588614/configure-purdue-levels-for-fabric-devices-7-4-2 
FortiOS supports configurable Purdue levels for Fortinet Fabric devices, specifically FortiGates, managed FortiSwitches, and FortiAPs. This means that users have the flexibility to adjust the Purdue levels of these devices according to their specific needs and preferences, enhancing the adaptability and functionality of their Fabric devices. The default Purdue Level for these devices is 3.

**Required Lab Components**
-	FGR & FSR
-	MODBUS Server/Client devices

**Playbook**
The steps/screenshots needs built out