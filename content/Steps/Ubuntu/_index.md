+++
title = "Create Ubuntu VMs"
type = "default"
weight = 80
+++

RDP to OOB.

{{% tab title="from Terminal in OOB" %}}
````bash
cd /home/fortinet/automation/ansible/ubuntu

./create_ubuntu_vm.sh ../vars/all-hosts.yml <name of your PVE server> ubuntu_sdwan

./start_stop_remove_vm.sh ../vars/all-hosts.yml <name of your PVE server> ubuntu_sdwan started

````
{{% /tab %}}

Make sure Ubuntu-x VMs have fully started (i.e. GUI is up and running) before exeucting the following.

Suggest opening console windows on PVE to verify.

{{% tab title="from Terminal in OOB" %}}
````bash
./wallpaper_update.sh ubuntu_sdwan
````
{{% /tab %}}