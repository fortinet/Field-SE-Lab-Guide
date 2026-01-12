+++
title = "Change 172.16.3.x Subnet"
type = "default"
weight = 90
+++

{{% badge %}}Important{{% /badge %}} Not tested.  \
  \
**Change 172.16.3.x subnet that is the external subnet to Proxmox and the SE Lab** 

- Proxmox Server
    - Change IP address of **vmbr0**

- Change OOB’s eth0
    - Make sure VM is off 
    - Edit Cloud-Init
    - Turn VM on
    - Edit **/usr/local/bin/generate-dynamic-netplan.sh**
        - Search for and replace 172.16.3.80  with  x.y.z.80
    -	Reboot VM
    -	Verify via conky and/or cli (ip a) that only x.y.z.- exists and no 172.16.3.-

- Change contents of DNS zone file: 
    - **/home/Fortinet/c_data/coredns/conf/zones/db.home.internal**

- Change Ansible automation files
    - Edit file /automation/ansible/vars/all-hosts.yml
    - Search for the following 4 VM’s and change the 172.16.3.x’s to your subnet’s ip address/cidr
        -	OOB
        -	TCGUI
        -	FMG
        -	FAZ
