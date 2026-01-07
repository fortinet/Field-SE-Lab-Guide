+++
title = "Create Ubuntu VM Template"
type = "default"
weight = 10
+++

### Create the VM
In PVE GUI  > (left click) Datacenter > (right click) Node > Create VM
![Create_VM](Create_VM.png)

- General
    - Choose Node
    - Choose VM_id == 491
    - Type VM Name == Ubuntu-Template
- OS
    - Use CD/DVD disc image
    - Storage: <your Proxmox storage, if no NAS, then “local-lvm”>	
    - ISO Image: Ubuntu_Installer.iso
    - Default values for 'Guest OS' (Linux 6.x – 2.6 Kernel)
- System
    - Leave Defaults:
        - Graphic Card: Default     
        - Machine: Default (i440fx)	
        - Bios: Default (SeaBios)    
        - SCSI: VirtIO single
    - Tick: “Qemu Agent”
- Disks
    - Create Disk (SCSI 0, <your Proxmox storage, if no NAS, then “local-lvm”>, 32GB, uncheck Backup)
- CPU
    - Cores == 2 cores
    - Type == Default (x86-64-v2-AES)
- Memory
    - 2 GB is minimum...recommend 4 GB 
- Network
    - Bridge == vmbr0
    - Untick Firewall
- Confirm
    - Click Finish

- Add a 2nd NIC
    - In PVE GUI > (left click) Datacenter > Node > VM (one just created) > Hardware > Add > Network Device
        - Bridge == FTNTMGT  (uncheck Firewall)

- VM’s config should look like the following.
![VM_Config](VM_Config.png)

### Install Ubuntu
- In PVE GUI  > (left click) Datacenter > Node > VM (the vm just created)
    - Click on Console and Click on Start
- Press Enter on “Try or Install Ubuntu” (if no keys pressed, GRUB will timeout and choose this option)
-	If following appears, you can safely ignore it as both NICs have NOT been fully configured yet.
![Connection_Failed](Connection_Failed.png)
-	Choose Language, Accessibility - Click Next, Choose Keyboard, Internet Do Not Connect,  
-	Click on Install Ubuntu, Interactive installation, Apps – Default selection, Do not install proprietary software
-	Erase disk and install Ubuntu (start from scratch on selected disk) 
    |  |  |
    | :- | :- | 
    | Your name	| fortinet (all lower case) |
    | Computer name	| ubuntu-template |
    | User name	| fortinet (all lower case) |
    | Password | password |
    | Leave checked “Require my password to login” | <= critical for next script to run successfully |
    |Timezone | America/Chicago |
-	Click on “Install”
-	When screen says:
    - “Ubuntu 24.04.3 LTS installed and ready to use”
    -  Click on “Restart Now”
- At the prompt to remove installation media
    - In PVE GUI  
        - Datacenter > Node > VM (one just created) >  Hardware > CD/DVD Drive > Edit 
            - Tick “Do not use any media”
        - Datacenter > Node > VM (one just created) >  Hardware > Add > Cloud-Init
            - Bus/Device: SCSI 1
            - Storage: <your Proxmox storage, if no NAS, then “local-lvm”>
            - Format: QEMU image formate (if it's available)
![Cloud_Init_Add](Cloud_Init_Add.png)
    - Config Cloud-Init
![Cloud_Init_Config](Cloud_Init_Config.png)  
- Go back to VM console and press “Enter”
- Wait for VM to reboot
- Login user "fortinet"
|  |  |
| :- | :- | 
| Welcome to Ubuntu 24.04.3 LTS | Click Next | 
| Enable Ubuntu Pro | Tick “Skip for now”, Click Skip | 
| No, don’t share system data | Click Next | 
| Get started with more applications | Click Finish|
- If following dialog box pops up, Click “Remind Me Later”
![Software_Updater](Software_Updater.png)

### Install Packages and User Config
{{% tab title="from Terminal in Ubuntu VM" %}}
~~~~bash
sudo apt install git -y
git clone https://github.com/stevesweeneywisc/SE-Lab-Ubuntu-Template /home/fortinet/Downloads
cd /home/fortinet/Downloads/
chmod 777 *.sh
./Ubuntu_Base_Install.sh
~~~~
{{% /tab %}}
- System will reboot after script runs
- Login user "fortinet"
- Remove keyring password
    - **Note:** This is not a secure way to setup Ubuntu.  However, it is done for ease of use in Lab environment.  If you don’t do this, the RDP password WILL change to a random string after every reboot
    - Open Utilities folder
![Key_Ring_1](Key_Ring_1.png)
    - Open “Passwords and Keys”
![Key_Ring_2](Key_Ring_2.png)
    - Right Click on Login, and choose Change Password
![Key_Ring_3](Key_Ring_3.png)
    - Enter the old password: "password"
![Key_Ring_4](Key_Ring_4.png)
    - Leave new password blank for both and click “Continue”
![Key_Ring_5](Key_Ring_5.png)
    - Store passwords unencrypted? Click Continue
![Key_Ring_6](Key_Ring_6.png)
- Configure user “fortinet” for “Automatic Login”
    - Settings
![Config_User_1](Config_User_1.png)
    - System/Users
![Config_User_2](Config_User_2.png)
    - Unlock and Enable “Automatic Login”
![Config_User_3](Config_User_3.png)

### Verify Configuration and Prep Cloud-Init
- Reboot and verify auto login
- RDP to VM
{{% tab title="from Terminal in Ubuntu VM" %}}
~~~~bash
sudo cloud-init clean -–machine-id
sudo shutdown now
~~~~
{{% /tab %}}
### Convert VM to Template
 - In PVE GUI  
    - Datacenter > Node > VM (one just created) >  Cloud-Init > Edit
    - Remove IP Address 
![Cloud_Init_Remove_IP](Cloud_Init_Remove_IP.png)
    - Datacenter > Node > Right Click on VM (one just created) > Convert to template
![Convert_to_Template](Convert_to_Template.png)

### Complete




