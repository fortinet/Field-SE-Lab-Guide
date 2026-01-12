+++
title = "Create TCGUI VM"
type = "default"
weight = 40
+++

RDP to OOB.

{{% tab title="from Terminal in OOB" %}}
````bash
cd /home/fortinet/automation/ansible/ubuntu

./create_tcgui.sh          ../vars/all-hosts.yml  <PVE server name>  ubuntu_tcgui

./start_stop_remove_vm.sh  ../vars/all-hosts.yml  <PVE server name>  ubuntu_tcgui started
````
{{% /tab %}}

Make sure TCGUI VM has fully started (GUI is up and running) before exeucting the following.

Suggest opening TCGUI's console window on PVE to verify.

{{% tab title="from Terminal in OOB" %}}
````bash
./configure_tcgui.sh   ubuntu_tcgui

./wallpaper_update.sh  ubuntu_tcgui
````
{{% /tab %}}