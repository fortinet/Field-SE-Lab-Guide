+++
title = "Post Installation - Must Do's"
type = "default"
weight = 20
+++

1.	Login to GUI
    - https://\<host name\> or \<IP address\>:8006
    - Log in as **root (realm PAM)** with password chosen during installation.
![Login](Login.png)
2. Firewall Settings
    - Node > Firewall > Option 
![Node_Firewall](Node_Firewall.png)
    - Datacenter > Firewall > Options
![Data_Center_Firewall](Data_Center_Firewall.png)
3. Configure **apt-get update** and update PVE server
    - Node > Updates > Repositories
![Config_apt_get_update](Config_apt_get_update.png)
        - Add: Repository >  No-Subscription
        - Disable: `https://enterprise.proxmox.com/debian/ceph-quincy`
        - Disable: `https://enterprise.proxmox.com/debian/pve`
![Repositories](Repositories.png)
        - Perform upgrade from either CLI or GUI
{{% tab title="from PVE Shell" %}}
- If at the end of the following commands, it says reboot....do it.
````bash
apt update –y
apt dist-upgrade –y
apt upgrade -y

````
{{% /tab %}}
![Update](Update.png)
4. Allow uploading and importing of qcow2 files
    - Add **import** to /etc/pve/storage.cfg file
{{% tab title="storage.cfg" %}}
````bash
dir: local
        path /var/lib/vz
        content iso,vztmpl,backup,import
````
{{% /tab %}}
    - Then you should see **Import** listed
![Import_Ability](Import_Ability.png)


