+++
title = "Steps To Build This Lab"
type = "default"
weight = 30

+++

Execute and complete the following 11 steps in order

**1) PVE server**
- PVE should be built with the steps found here: **[Proxmox Install](/Extras/Proxmox_Install)**
- {{% badge %}}Note{{% /badge %}} The scripts/steps in this guide tested against 9.x, but will likely work with 8.x too)
![Version](Version.png)

**2) Create VNETs on PVE server**
{{% tab title="from PVE Shell" %}}
````bash
cd /root
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
````bash
curl https://raw.githubusercontent.com/stevesweeneywisc/SE-Lab-OOB/refs/heads/main/automation/proxmox/Create_VNETs.sh > Create_VNETs.sh
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
````bash
chmod 777 Create_VNETs.sh
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
````bash
./Create_VNETs.sh
````
{{% /tab %}}

**3)Install proxmoxer on each PVE server**
- Starting with Proxmox 9.x, proxmoxer version 2.3 is required
    - Unforunately, "apt install -y python3-proxmoxer" will only install 2.2
- The following steps "force" installs proxmoxer version 2.3
{{% tab title="from PVE Shell" %}}
````bash
apt install pip
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
````bash
pip install requests --break-system-packages
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
````bash
pip install openssh-wrapper --break-system-packages
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
````bash
pip install ssh_paramiko --break-system-packages
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
````bash
pip install proxmoxer==2.3.0 --break-system-packages
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
- Verify proxmoxer version 2.3 is installed
````bash
python3 -c "import proxmoxer; print(proxmoxer.__version__)"
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