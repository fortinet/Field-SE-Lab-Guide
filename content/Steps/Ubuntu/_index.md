+++
title = "Create Ubuntu VMs"
type = "default"
weight = 80
+++

- If you get the error {{% badge %}}No route to host{{% /badge %}} with any of the following steps, use the **[Troubleshoot Ansible](/Extras/Troubleshoot_Ansible)** steps


{{% tab title="RDP to OOB" %}}
- from Terminal in OOB
````bash
cd /home/fortinet/automation/ansible/ubuntu

./create_ubuntu_vm.sh      ../vars/all-hosts.yml  <PVE server name>  ubuntu_sdwan

./start_stop_remove_vm.sh  ../vars/all-hosts.yml  <PVE server name>  ubuntu_sdwan started

````
{{% /tab %}}


{{% tab title="Continuing from Terminal in OOB" %}}
- Make sure Ubuntu-x VMs have fully started (i.e. GUI is up and running) before exeucting the following.
- Suggest opening console windows on PVE to verify.

````bash
./wallpaper_update.sh  ubuntu_sdwan
````
{{% /tab %}}