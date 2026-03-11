+++
title = "Nesting ESXi"
type = "default"
weight = 70
+++

Why would do this?  FortiLink trunks do not work in Proxmox due to Proxmox developers have reserved the use of VLANs 0 and 4095 (need to find link defintively describin this).

There are "how-to" posts that I could not make FortiLink work in Proxmox: (examples below)
- [global channels](https://teams.microsoft.com/l/message/19:104c76bd09954d5794f64ac25e5b6e86@thread.skype/1720003124774?tenantId=2c36c478-3d00-452f-8535-48396f5f01f0&groupId=62fd9f66-e24c-403e-81bc-d8dfd7bf0ea8&parentMessageId=1720003124774&teamName=FortiChat%20Global%20Channels&channelName=swat_fap_fsw_fex_switch_access&createdTime=1720003124774)
- [Support Forum](https://forum.proxmox.com/threads/unable-to-create-sdn-vnet-without-tag.148566/)

### **Verify Nested Virtualization is Enabled** 
- https://pve.proxmox.com/wiki/Nested_Virtualization
- https://devopstales.github.io/virtualization/install-vmware-in-proxmox/
    - At CLI:	cat /sys/module/kvm_intel/parameters/nested
        - If it returns “Y”, proceed to Creation Step
        - If it returns “N”, follow steps in URL above to enable

### **ESXi VM Creation**
-	In PVE GUI  > Click "Create VM"
    - __General__
        -	Choose Node
        -	Choose VM_id (or use the default)
        -	Type VM Name
    - __OS__
        -	Add ESXi installation media
        -	Default values for 'Guest OS' (Linux 6.x – 2.6 Kernel)
    - __System__
        -	**Graphic card:** Default
        -	**Machine:** q35
        -	**BIOS:** SeaBIOS
        -	**SCSI Controller:** VMware PVSCSI                
    - __Disks__
        -	**Bus/Device:** SATA
        -	**Size:** minimum is 128GB
        -	**SSD emulation:** Check
        -	**Discard:** Check
        -   **Backup:** Un-Check
        
    - __CPU__
        -	**Cores:** 4
        -	**Type:** host
    -  __Memory__
        -	4GB is minimum, (Suggest 8GB)
    - __Network__
        -	**Model:** VMware vmxnet3
    - __Confirm__
        -	Click **Finish**

Wait for the VM Create process to complete (i.e. Status OK)

Add as many NICs as needed
- PVE GUI  > Click on ESXi VM > Hardware > Add > Network Device

### **Start ESXi VM**
-	Reduce size of system partition ({{% badge %}}Important{{% /badge %}} **MUST BE DONE AT INITIAL INSTALL**)
    - Background:
        - ESXi 7.0 introduced a system-storage boot media layout designed to ensure new features and capabilities could be added in future releases. The partition layout can consume up to 138GB of disk space, significantly limiting usable space to create a VMFS datastore on small server with finite hardware resources.
    - Documentation:
        - https://williamlam.com/2020/05/changing-the-default-size-of-the-esx-osdata-volume-in-esxi-7-0.html
    - "How-To" reduce system partition size:
        - Start host with install image
        - When ESXi installer window appears
        - Press Shift+O within 5 seconds to edit the boot options.
        - Add the following to the end of the prompt:
            - systemMediaSize=min

### **Post install MUST DO'S**
- Assign a License in DCUI 
    - Click on: Host/Manage/Licensing/Assign License
-	Enable SSH
    - Click on: Host / Actions / Services / Enable Secure Shell (SSH)
- Enable SSH on boot:  
    - Click on: Host/Manage/Services/Right click TSM-SSH/Policy/Select "Start and stop with host" 
- Configure DCUI
    - Click on: Host/Manage/System/Advanced Settings
        - UserVars.DcuiTimeOut Value=0
        - UserVars.HostClientSessionTimeout Value=0
-	Edit NTP Settings
    - Click on: Host/Manage/System/Time & date
    - Enable NTP client/Start and stop with host/208.91.112.63  	<=ntp1.fortiguard.com
