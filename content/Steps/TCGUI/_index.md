+++
title = "Create TCGUI VM"
type = "default"
weight = 40
+++

- If you receive an error {{% badge %}}No route to host{{% /badge %}} with any of the following steps, use the **[Troubleshoot Ansible](/Extras/Troubleshoot_Ansible)** steps

- from Terminal in OOB
{{% tab title="RDP to OOB" %}}
````bash
cd /home/fortinet/automation/ansible/ubuntu
````
{{% /tab %}}
{{% tab title="RDP to OOB" %}}
````bash
./create_tcgui.sh          ../vars/all-hosts.yml  <PVE server name>  ubuntu_tcgui
````
{{% /tab %}}
{{% tab title="RDP to OOB" %}}
````bash
./start_stop_remove_vm.sh  ../vars/all-hosts.yml  <PVE server name>  ubuntu_tcgui started
````
{{% /tab %}}


- Make sure TCGUI VM has fully started (GUI is up and running) before exeucting the following.
- Suggest opening TCGUI's console window on PVE to verify before continuing.

{{% tab title="Continuing from Terminal in OOB" %}}
````bash
./configure_tcgui.sh   ubuntu_tcgui
````
{{% /tab %}}
{{% tab title="Continuing from Terminal in OOB" %}}
````bash
./wallpaper_update.sh  ubuntu_tcgui
````
{{% /tab %}}
{{% tab title="Continuing from Terminal in OOB" %}}
````bash
./start_stop_remove_vm.sh ../vars/all-hosts.yml <PVE server name> ubuntu_tcgui stopped
````
{{% /tab %}}
{{% tab title="Continuing from Terminal in OOB" %}}
````bash
./start_stop_remove_vm.sh ../vars/all-hosts.yml <PVE server name> ubuntu_tcgui started
````
{{% /tab %}}

