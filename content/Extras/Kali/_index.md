+++
title = "Kali"
type = "default"
weight = 55
+++

### **Assumptions**
- [TCGUI](steps/tcgui) is built and running
- Kali Lab Topology Location
    - The installation steps below, creates a Kali VM in the following location in the lab

| NIC | VNET | IP Address |
| :---: | :---: | :---: |
| eth0 | OFFNET | 10.100.66.88 |
| eth1 | FTNTMGMT | 10.100.55.88 |

![Lab_Topology_Kali](Lab_Topology_Kali.png)

### **Download and Import ISO**
- Kali Installer Image - [ISO](https://www.kali.org/get-kali/#kali-installer-images)
- Import the Kali ISO file
![pic-import_ISO](pic-import_ISO.png)

### **Create Kali VM**
- If you get the error {{% badge %}}No route to host{{% /badge %}} with any of the following steps, use the **[Troubleshoot Ansible](/Extras/Troubleshoot_Ansible)** steps

{{% tab title="RDP to OOB" %}}
- from Terminal in OOB
````bash
cd /home/fortinet/automation/ansible/ubuntu
````
````bash
./create_kali.sh      ../vars/all-hosts.yml  <PVE server name>  kali  <ISO file name (no extension..just file name)>
````
````bash
./start_stop_remove_vm.sh  ../vars/all-hosts.yml  <PVE server name>  kali started
````
{{% /tab %}}

### **Kali Installer**
{{% tab title="via Kali VM console in Proxmox" %}}
- Kali Linux installer menu
    - Choose **Graphical install**
    - Select **Language, Location, Keyboard**
    - Primary NIC used for installation **eth0**
    - Not using DHCP **Continue**
    - **Do not configure** the network at this time
    - Hostname **kali**
    - Username **kali**
    - Password **kali** (not recommended for production, this is for non-internet facing lab)
    - Choose **Time zone**
    - Partition disks 
        - **Guided - use entire disk**
        - **sda**
        - **All files in one partition**
        - **Finish partitioning and write changes to disk**
        - Write the changes to disks? **Yes**
    - Software selection
        - Desktop environment: **Xfce**
        - Collection of tools: **top10** and **default**
    - Install the GRUB boot loader: **Yes**
    - Device for boot loader location: **/dev/sda**
    - Installation complete **Continue**
    - VM reboots
{{% /tab %}}

### **NIC Configuration**
{{% tab title="via Kali VM console in Proxmox" %}}
- Login
    - Username/Password : **kali/kali**
- In upper right corner of desktop, right-click on Network Settings and Edit Connections
    ![Edit_Network01](Edit_Network01.png)
- Double Click on **Wired connection 1**
![Edit_Network02](Edit_Network02.png)
- Configure **Wired connection 1**
    - Ethernet / eth0 
    ![Edit_Network03](Edit_Network03.png)
    - IPv4 Settings/Manual/Address/Netmask/Gateway/DNS/Search domains
    - Click **Save**
    ![Edit_Network04](Edit_Network04.png)
- Click on **+**
    ![Edit_Network05](Edit_Network05.png)
- Choose a Connection Type **Ethernet** and Click on **Create**
    ![Edit_Network06](Edit_Network06.png)
- Configure **Wired connection 2**
    - Ethernet / eth1 
    ![Edit_Network07](Edit_Network07.png)
    - IPv4 Settings/Manual/Address/Netmask (Leave Gateway Blank)
    - Click **Save**
    ![Edit_Network08](Edit_Network08.png)
- In upper right corner of desktop, right-click on Network Settings and see the following
    ![Edit_Network09](Edit_Network09.png)

{{% /tab %}}

### **Configure RDP**
{{% tab title="RDP to OOB" %}}
- Update package list: 
````bash
sudo apt update && sudo apt upgrade -y
````
- Install XRDP: 
````bash
sudo apt install -y xrdp
````
- Enable XRDP service: 
````bash
sudo systemctl enable xrdp
````
- Start the service 
````bash
sudo systemctl start xrdp
````
- Check the service status to verify it is running: 
````bash
sudo systemctl status xrdp
````
- Logout and RDP to Kali VM (10.100.55.88)
    - {{% badge style="important" title="IMPORTANT:" style="red"%}}You must be logged out of the xfce desktop to successfully RDP to Kali{{% /badge %}}

{{% /tab %}}

### **Complete**

