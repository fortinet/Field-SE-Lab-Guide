+++
title = "Kali"
type = "default"
weight = 55
+++

- {{% badge style="important" title="IMPORTANT:" style="red"%}}This page is a work in progress{{% /badge %}}

### **Download Kali ISO**
- Kali Pre-Built VMs - [QEMU](https://www.kali.org/get-kali/#kali-virtual-machines)
- Download and unzip
- Import the Kali qcow2 file
![pic-import_qcow2](pic-import_qcow2.png)

### **Create Kali VM**
- If you get the error {{% badge %}}No route to host{{% /badge %}} with any of the following steps, use the **[Troubleshoot Ansible](/Extras/Troubleshoot_Ansible)** steps

{{% tab title="RDP to OOB" %}}
- from Terminal in OOB
````bash
cd /home/fortinet/automation/ansible/ubuntu
````
````bash
./create_kali.sh      ../vars/all-hosts.yml  <PVE server name>  kali  <qcow2 file name>
````
````bash
./start_stop_remove_vm.sh  ../vars/all-hosts.yml  <PVE server name>  kali started
````
{{% /tab %}}

### **Configure Kali NICs**
{{% tab title="via console tab in Proxmox" %}}
Login
    - Default Username/Password : kali/kali
- In upper right corner of desktop, right-click on Network Settings and Edit Connections
    ![Edit_Network01](Edit_Network01.png)
- Double Click into each Wired connection
    ![Edit_Network02](Edit_Network02.png)
- Configure Wired connection 1
    - IPv4/Manual/Address/Netmask/Gateway/DNS/Domain
    ![Edit_Network03](Edit_Network03.png)
- Configure Wired connection 2
    - IPv4/Manual/Address/Netmask
    ![Edit_Network04](Edit_Network04.png)
{{% /tab %}}

### **Configure Kali RDP**
{{% tab title="RDP to OOB" %}}
- Update package list: 
````bash
sudo apt update && sudo apt upgrade -y
````
- Install Xfce and XRDP: 
````bash
sudo apt install -y xfce4 xfce4-goodies xrdp
````
- Set Xfce as your default session: 
````bash
echo xfce4-session > ~/.xsession
````

Service configuration
- Enable and start the XRDP service: 
````bash
sudo systemctl enable --now xrdp
````
- Restart the service to apply changes: 
````bash
sudo systemctl restart xrdp
````
- Check the service status to verify it is running: 
````bash
sudo systemctl status
````
{{% /tab %}}