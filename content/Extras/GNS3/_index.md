+++
title = "GNS3"
type = "default"
weight = 60
+++

### **Verify Nested Virtualization is Enabled** 
- https://pve.proxmox.com/wiki/Nested_Virtualization
- https://devopstales.github.io/virtualization/install-vmware-in-proxmox/
    - At CLI:	cat /sys/module/kvm_intel/parameters/nested
        - If it returns “Y”, proceed to Creation Step
        - If it returns “N”, follow steps in URL above to enable

### **GNS3 VM Creation**
- {{% tab title="from Proxmox CLI (use shell in GUI)" %}}
- Download [GNS3 VMware ESXi VM OVA](https://gns3.com/software/download-vm)

````bash
sudo apt install unzip -y

mkdir GNS3          <= (make directory to unzip OVA)

cd GNS3

curl -O https://github.com/GNS3/gns3-gui/releases/download/v2.2.57/GNS3.VM.VMware.ESXI.2.2.57.zip

unzip *.zip

tar -xvf *.ova
````
{{% /tab %}}
- In PVE GUI  > Click "Create VM"
    - __General__
        -	Choose Node
        -	Choose VM_id (or use the default)
        -	Type VM Name
    - __OS__
        -	Do not use any media
        ![No Media](no_media.png)
    - __System__
        -	Accept Defaults
        -   **Graphic card:** Default
        -	**Machine:** Default
        -	**BIOS:** Default
        -	**SCSI Controller:** VirtIO SCSI                
    - __Disks__
        -	Click on Trashcan Icon and delete disk
        ![No Disks](no_disks.png)
    - __CPU__
        -	**Cores:** 4
        -	**Type:** host
    -  __Memory__
        -	16GB is minimum
    - __Network__
        -	**Bridge** vmbr0
        -   Untick Firewall
        ![NIC](NIC.png)
    - __Confirm__
        -	Click **Finish**

Wait for the VM Create process to complete (i.e. Status OK)
- {{% tab title="from Proxmox CLI (use shell in GUI)" %}}
- Import the VMDK disks into VM just created
    - Make sure machine ID (511 is my GNS3 VM) and VMDK file name matches VM name before running the commands below.
    - **Note** - These commands take time to run as they are converting from VMDK formate to qcow2
````bash
qm importdisk <VMid you choose> <VM name you choose>_VM-disk1.vmdk <your Proxmox image storage> -format qcow2

qm importdisk <VMid you choose> <VM name you choose>_VM-disk2.vmdk <your Proxmox image storage> -format qcow2
````
{{% /tab %}}
