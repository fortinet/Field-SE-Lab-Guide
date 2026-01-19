+++
title = "IP Scheme"
type = "default"
weight = 10
+++

Download following as {{% button href="/introduction/IP%20Scheme.xlsx?download" style="tip" icon="angle-down" %}}IP Scheme.xlsx{{% /button %}}

### **Branch FortiGates**
| VNET| FTNTMGT | BRCHWAN1 BRCHWAN2| BRCHWAN3 BRCHWAN4| BRCHWAN5 BRCHWAN6|  BRCHLAN1 | BRCHLAN2 | BRCHLAN3 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Device** | *port4* **10.100.55.x** /24 | *port1* **10.198.1.x** *port2* **10.198.2.x** /29 | *port1* **10.198.3.x** *port2* **10.198.4.x** /29 | *port1* **10.198.5.x** *port2* **10.198.6.x** /29 | *port3* **10.1.1.x** /24 | *port3* **10.1.2.x** /24 | *port3* **10.1.3.x** /24 |
| **Branch01** | .55 | .2 | | | .1 | | |
| **Branch02** | .56 | |.2 | | | .1 | |
| **Branch03** | .57 | | | .2 | | | .1 |

### **Hub FortiGates**
| VNET| FTNTMGT | COREWAN1 COREWAN2| COREWAN3 COREWAN4| ISFW01 | ISFW02 | DMZ01 | HAHUB01 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Device** | *port4* **10.100.55.x** /24 | *port1* **10.198.7.x** *port2* **10.198.8.x** /29 | *port1* **10.198.9.x** *port2* **10.198.10.x** /29 | *port3* **10.100.88.x** /24 | *port3* **10.100.99.x** /24 | *port5* **10.100.77.** /24 | *port6* **No_IP** |
| **Hub01a** | .51 | .2 | | .1 | | .1 | |
| **Hub01b** | .52 | .3 | | .2 | | .2 | |
| **Hub02a** | .53 | | .2 | | .1 | | |

### **FMG and FAZ**
| VNET| ISFW01 | FTNTMGT | vmbr0 | FTNTMGT |
| :---: | :---: | :---: | :---: | :---: |
| **Device** | *port1* &nbsp;&nbsp;**10.100.55.x** /24 | *port2* &nbsp;&nbsp;**10.100.88.x** /24 | *port3* &nbsp;&nbsp;**172.16.3.x** /24 | *port4* |
| **FMG** | .12 | .12 | .12 | down |
| **FAZ** | .2 | .2 | .2 | down |

### **Ubuntu Endpoints**
| VNET| FTNTMGT | OFFNET | BRCHLAN1 | BRCHLAN2 | BRCHLAN3 | ISFW01 | ISFW02 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Device** | *eth1* **10.100.55.x** /24 | *eth0* **10.100.66.x** /24 |*eth0* **10.1.1.x** &nbsp;/24 | *eth0* **10.1.2.x** &nbsp;/24 | *eth0* **10.1.3.x** &nbsp;/24 | *eth0* **10.100.88.x** /24 |  *eth0* **10.100.99.x** /24 |
| **Ubuntu-00** | .70 | .10 | | | | | |
| **Ubuntu-01** | .71 | | .10 | | | | |
| **Ubuntu-02** | .72 | | | .10 | | | |
| **Ubuntu-03** | .73 | | | | .10 | | |
| **Ubuntu-11** | .81 | | | | | .10 | |
| **Ubuntu-21** | .91 | | | | | | .10 |

### **OOB & TCGUI**
| VNET| FTNTMGT | vmbr0 | BRCHWAN1 BRCHWAN2| BRCHWAN3 BRCHWAN4| BRCHWAN5 BRCHWAN6| COREWAN1 COREWAN2| COREWAN3 COREWAN4| OFFNET |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Device** | *eth0* **10.100.55.x** /24 | (below) **172.16.3.x** /24 | *eth1* **10.198.1.x** *eth2* **10.198.2.x** /29 | *eth3* **10.198.3.x** *eth4* **10.198.4.x** /29 | *eth5* **10.198.5.x** *eth6* **10.198.6.x** /29 | *eth7* **10.198.7.x** *eth8* **10.198.8.x** /29 | *eth9* **10.198.9.x** *eth10* **10.198.10.x** /29 | *eth11* **10.100.66.x** /24 |
| **_Ubuntu-OOB_** | .80 | **_eth1_** &nbsp;.80 | | | | | | |
| **_Ubuntu-TCGUI_** | | **_eth0_** &nbsp;.90 |  | .1 | .1 | .1 | .1 | .1 |