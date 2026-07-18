+++
title = "IP Scheme"
type = "default"
weight = 10
+++

Download following as {{% button href="https://github.com/fortinet/Field-SE-Lab-Guide/raw/refs/heads/main/content/Introduction/IP%20Scheme.xlsx" style="tip" icon="angle-down" %}}IP Scheme.xlsx{{% /button %}}

### **Branch FortiGates**
| VNET| FTNTMGT | BRCHWAN1 BRCHWAN2| BRCHWAN3 BRCHWAN4| BRCHWAN5 BRCHWAN6|  BRCHLAN1 | BRCHLAN2 | BRCHLAN3 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Device** |  | |  | |  |  |  |
| **Branch01** | *port4* **10.100.55.55** /24 | *port1* **10.198.1.2** *port2* **10.198.2.2** /29  | | | *port3* **10.1.1.1** /24 | | |
| **Branch02** | *port4* **10.100.55.56** /24 | |*port1* **10.198.3.2** *port2* **10.198.4.2** /29 | | | *port3* **10.1.2.1** /24 | |
| **Branch03** | *port4* **10.100.55.57** /24 | | | *port1* **10.198.5.2** *port2* **10.198.6.2** /29 | | | *port3* **10.1.3.1** /24 |

### **Hub FortiGates**
| VNET| FTNTMGT | COREWAN1 COREWAN2| COREWAN3 COREWAN4| ISFW01 | ISFW02 | DMZ01 | HAHUB01 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Device** | |  |  |  |  |  |  |
| **Hub01a** | *port4* **10.100.55.51** /24 | *port1* **10.198.7.2** *port2* **10.198.8.2** /29 | | *port3* **10.100.88.1** /24 | | *port5* **10.100.77.1** /24 | *port6* **No_IP**|
| **Hub01b** | *port4* **10.100.55.52** /24 | *port1* **10.198.7.3** *port2* **10.198.8.3** /29 | | *port3* **10.100.88.2** /24 | | *port5* **10.100.77.2** /24 | *port6* **No_IP**|
| **Hub02a** | *port4* **10.100.55.53** /24 | | *port1* **10.198.9.2** *port2* **10.198.10.2** /29 | | *port3* **10.100.99.1** /24 | | |

### **FMG and FAZ**
| VNET| ISFW01 | FTNTMGT | vmbr0 | FTNTMGT |
| :---: | :---: | :---: | :---: | :---: |
| **Device** |  |  |  |  |
| **FMG** | *port1* &nbsp;&nbsp;**10.100.55.12** /24 | *port2* &nbsp;&nbsp;**10.100.88.12** /24 | *port3* &nbsp;&nbsp;**172.16.3.12** /24 | *port4* &nbsp;&nbsp; down |
| **FAZ** | *port1* &nbsp;&nbsp;**10.100.55.2** /24 | *port2* &nbsp;&nbsp;**10.100.88.2** /24 | *port3* &nbsp;&nbsp;**172.16.3.2** /24 | *port4* &nbsp;&nbsp; down |

### **Ubuntu Endpoints**
| VNET| FTNTMGT | OFFNET | BRCHLAN1 | BRCHLAN2 | BRCHLAN3 | ISFW01 | ISFW02 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Device** |  |  | |  |  |  |   |
| **Ubuntu-00** | *eth1* **10.100.55.70** /24 | *eth0* &nbsp;&nbsp; **10.100.66.10** /24 | | | | | |
| **Ubuntu-01** | *eth1* **10.100.55.71** /24 | | *eth0* &nbsp;&nbsp; **10.1.1.10** &nbsp;/24 | | | | |
| **Ubuntu-02** | *eth1* **10.100.55.72** /24 | | | *eth0* &nbsp;&nbsp; **10.1.2.10** &nbsp;/24 | | | |
| **Ubuntu-03** | *eth1* **10.100.55.73** /24 | | | | *eth0* &nbsp;&nbsp; **10.1.3.10** &nbsp;/24 | | |
| **Ubuntu-11** | *eth1* **10.100.55.81** /24 | | | | | *eth0* &nbsp;&nbsp; **10.100.88.10** /24 | |
| **Ubuntu-21** | *eth1* **10.100.55.91** /24 | | | | | | *eth0* &nbsp;&nbsp; **10.100.99.10** /24 |

### **OOB & TCGUI**
| VNET| vmbr0 | FTNTMGT | BRCHWAN1 BRCHWAN2| BRCHWAN3 BRCHWAN4| BRCHWAN5 BRCHWAN6| COREWAN1 COREWAN2| COREWAN3 COREWAN4| OFFNET |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Device** |  |   |  |  |  |  |   |  |
| **_Ubuntu-OOB_** | *_eth0_* &nbsp;**172.16.3.80** /24  | *eth1* **10.100.55.80** /24| | | | | | |
| **_Ubuntu-TCGUI_** | *_eth0_* &nbsp; **172.16.3.90** /24 |  | *eth1* **10.198.1.1** *eth2* **10.198.2.1** /29 | *eth3* **10.198.3.1** *eth4* **10.198.4.1** /29 | *eth5* **10.198.5.1** *eth6* **10.198.6.1** /29 | *eth7* **10.198.7.1** *eth8* **10.198.8.1** /29 | *eth9* **10.198.9.1** *eth10* **10.198.10.1** /29 | *eth11* **10.100.66.1** /24 |


### **Other Demo "Tools"**
| VNET| vmbr0 | FTNTMGT |
| :---: | :---: | :---: |
| **Device** |  |  |
| **_Ubuntu-GNS3_** | *_eth0_* &nbsp; **172.16.3.86** /24 | *eth1* &nbsp; **10.100.55.86** /24 |