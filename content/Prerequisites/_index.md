+++
title = "Prerequisites"
type = "default"
weight = 20
+++

### Proxmox Virtual Environment (PVE)
- This lab requires (obviously), a Hypervisor.  This lab was written and installation scripts tested with Proxmox 9.x  

### Accessibility and Tools
- Proxmox Server accessible from your Work laptop via
    -	Web Console <ip address:8006>
    -	SSH	

### Work laptop has installed or equivalent capable applications:
-	[7-zip](https://www.7-zip.org/)
-	[WinSCP](https://winscp.net/eng/download.php)
-	[Multi-Tabbed PuTTY](https://ttyplus.com/multi-tabbed-putty/)
-	RDP (%windir%\system32\mstsc.exe)
-	Browser - all testing for this build guide was done with [Firefox](https://www.firefox.com/en-US/)

### IP Addressing and Naming Convention Assumptions 
- Subnet 172.16.3.x/24 with IP's reserved from .2 thru .125
    - Used for the physical interface of the PVE server
    - Installation scripts assumes this subnet and IP range
    - Documented in {{% button href="IP%20Scheme.xlsx?download" style="tip" icon="angle-down" %}}IP Scheme.xlsx{{% /button %}}
    - Shown in the [topology](/Introduction#se-lab-topology)
- If unable to use subnet 172.16.3.x/24 and reserve IP's from .2 thru .125
    - Then several modifications are required as described [here](/Extras/External_Subnet)

### User Name / Passwords utilizes the following standard
- User Name: fortinet (all lowercase)
- Password: password (all lowercase)

### Basic Understanding and Knowledge of Linux CLI Commands
- [source](https://cheatography.com/davechild/cheat-sheets/linux-command-line?target=_blank)
![Linux_Commands](Linux_Commands.png)

### Edit text files in Ubuntu (one of the following)
- vi
    - [cheat sheet](https://devhints.io/vim?target=_blank)
    - [how to use](https://www.freecodecamp.org/news/vim-beginners-guide/?target=_blank)
- nano
    - [how to use](https://www.nano-editor.org/dist/latest/cheatsheet.html?target=_blank) 
- Ubuntu [GNOME GUI Text Editor](GUI_Text_Editor.png?target=_blank)

### Upload ISO and qcow2 Files
![Import Files](Import_Files.png)
- Ubuntu Desktop - [64-bit Desktop ISO Image](https://ubuntu.com/download/desktop?target=_blank) 
    - **Note:** Install Scripts tested with 24.04.3 LTS
- Fortinet (FGT/FMG/FAZ) firmware qcow2 files
    - qcow2 files must use the following format:
        - < 3 letters > dash < version > .qcow2
        - FGT-v7.4.8.M.qcow2
        - FMG-v7.6.4.F.qcow2
        - FAZ-v7.4.8.M.qcow2

![alt](pic-import_qcow2.png)


### Ready to start the build
- **[Steps To Build This Lab](Steps)**