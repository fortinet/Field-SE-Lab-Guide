+++
title = "Steps To Build This Lab"
type = "default"
weight = 30
+++

Execute and complete the following 11 steps in order

**1) PVE server**
- If creating a new PVE, use the following section **[Proxmox Install](/Tips_and_Tricks/Proxmox_Install)**
- If using an existing PVE, verify version (i.e. scripts/steps tested against 9.x, but will likely work with 8.x too)
![Version](Version.png)

**2) Create VNETs on PVE server**
{{% tab title="from PVE Shell" %}}
````bash
cd /root
curl https://raw.githubusercontent.com/stevesweeneywisc/SE-Lab-Build/refs/heads/main/Create_VNETs.sh > Create_VNETs.sh
chmod 777 Create_VNETs.sh
./Create_VNETs.sh
````
{{% /tab %}}

**3)Install proxmoxer on each PVE server**
{{% tab title="from PVE Shell" %}}
````bash
apt install -y python3-proxmoxer
````
{{% /tab %}}

**4) Create Ubuntu VM Template**
- Follow steps in this section **[Create Ubuntu VM Template](Ubuntu_Template)**

**5) Create OOB Management VM**
- Follow steps in this section **[Create OOB Management VM](OOB)**

**6) Ansible Prerequisites**
- Follow steps in this section **[Ansible Prerequisites](Ansible)**

**7) Create TCGUI VM**
- Follow steps in this section **[Create TCGUI VM](TCGUI)**

**8) Create FortiGate VMs**
- Follow steps in this section **[Create FortiGate VMs](FortiGate)**

**9) Create FortiManager VM**
- Follow steps in this section **[Create FortiManager VM](FortiManager)**

**10) Create FortiAnalyzer VM**
- Follow steps in this section **[Create FortiAnalyzer VM](FortiAnalyzer)**

**11) Create Ubuntu VMs**
- Follow steps in this section **[Create Ubuntu VMs](Ubuntu)**