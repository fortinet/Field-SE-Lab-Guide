+++
title = "Prerequisites"
type = "default"
weight = 20
+++

### IP Addressing and Naming Convention Assumptions 
- {{% badge style="important" title=" " style="red"%}}Dedicate a full class C network{{% /badge %}}
    - Minimally needed are IP's 4th Octet reserved from .2 thru .125
    - Installation scripts by default assumes this class C is  172.16.3.x/24
        - The subnet can be changed via a script during creation of OOB. 
- **The "outside" or (physical network)** of Proxmox as described above uses by default the subnet 172.16.3.x/24 with IP's reserved from .2 thru .125
    - Used for the physical interface of PVE server(s)
    - OOB (x.y.z.80) and TCGUI (x.y.z.90) IP addresses
    - OOB VIPs (x.y.z.-) to the "inside" (10.100.55.-)
    - As previously described, the "outside" subnet can be changed via a script during creation of OOB.
- **The "inside" (Proxmox VNETs)** in this lab use FNDN's IP addressing scheme
    - Documented [here](Introduction/ip_scheme)
    - Shown in the [topology](/Introduction#se-lab-topology)

### FortiCare Accuont with FortiFlex 
- This lab "works" with either Prepaid or Postpaid ([see bottom of page 3](https://www.fortinet.com/content/dam/fortinet/assets/data-sheets/og-flex-vm.pdf))
- The easiest to maintain is Postpaid  

### Proxmox Virtual Environment (PVE)
- This lab requires (obviously) a Hypervisor.  This lab was written and installation scripts tested with Proxmox 9.x  

### Accessibility and Tools
- Proxmox Server accessible from your Work laptop via
    -	Web Console via browser **_< PVE Server ip address:8006 >_**
    -	SSH	

### Work laptop has installed or equivalent capable applications:
-	[7-zip](https://www.7-zip.org/)
-	[WinSCP](https://winscp.net/eng/download.php)
-	[Multi-Tabbed PuTTY](https://ttyplus.com/multi-tabbed-putty/)
-	RDP (%windir%\system32\mstsc.exe)
-	Browser - all testing for this build guide was done with [Firefox](https://www.firefox.com/en-US/)

### User Name / Passwords utilizes the following standard
- Ubuntu VMs
    - User Name: fortinet (all lowercase)
    - Password: password (all lowercase)
- Fortinet VMs
    - User Name: admin (all lowercase)
    - Password: password (all lowercase) 
- {{% badge style="info" %}}While "password" should never be used in production, this being a non-internet facing lab, for simplicity and to reduce complexity disables the default password policy.{{% /badge %}}
    - Starting with v7.6.5 a [default password policy](https://docs.fortinet.com/document/fortigate/7.6.6/administration-guide/364729/password-policy) was introduced.  

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
- Ubuntu Desktop - [64-bit Desktop ISO Image](https://releases.ubuntu.com/noble/) 
    - {{% badge style="note" %}}Install Scripts tested with 24.04.4 LTS{{% /badge %}}

- Fortinet (FGT/FMG/FAZ) firmware qcow2 files
    - Below are examples of qcow2 file formats that must be followed for the ansible scripts to work successfully:
        - < 3 letters > dash < version > .qcow2
        - FGT-v7.4.11.M.qcow2
        - FMG-v7.6.6.M.qcow2
        - FAZ-v8.0.0.F.qcow2

![alt](pic-import_qcow2.png)

### Ready to start the build
- **[Steps To Build This Lab](Steps)**