+++
title = "Base Install"
type = "default"
weight = 10
+++

-	Download [latest ISO](https://www.proxmox.com/en/downloads/proxmox-virtual-environment/iso)
-	[Prepare USB Flash Drive](https://pve.proxmox.com/pve-docs/pve-admin-guide.html#installation_prepare_media)
-	Install using [Proxmox VE Installer](https://pve.proxmox.com/pve-docs/pve-admin-guide.html#installation_installer) 
-	Insert the prepared installation USB Flash Drive
-   Hit enter on “Install Proxmox VE (Graphical)"![Graphical Install](Graphical_Install.png)
- Agree to EULA![EULA](EULA.png)
-	Configure Hard disk by clicking “Next” for default (use whole drive, in a default configuration)![Config_Hard_Drive](Config_Hard_Drive.png)
-	Configure Country, Time Zone, Keyboard and click “next” ![Country_TZ_Keyboard](Country_TZ_Keyboard.png)
-	Set root user password, enter a valid email address and click “next”![root_password](root_password.png)
- Set Management Interface, Hostname (full FQDN), IP address/subnet, Gateway, DNS![Management_Network_Config](Management_Network_Config.png)
- Uncheck **Automatically Reboot after successful installation**  (provides time to remove USB Flash Drive)
-	Confirm information displayed and click **Next**
![Summary](Summary.png)
- Remove USB Flash Drive, click **Reboot** ![Success_Install](Success.png)

