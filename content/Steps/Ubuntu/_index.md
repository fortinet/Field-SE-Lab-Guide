+++
title = "Create Ubuntu VMs"
type = "default"
weight = 80
+++

- If you get the error {{% badge %}}No route to host{{% /badge %}} with any of the following steps, use the **[Troubleshoot Ansible](/Extras/Troubleshoot_Ansible)** steps

### Create Ubuntu VM's
- from Terminal in OOB
{{% tab title="RDP to OOB" %}}
````bash
cd /home/fortinet/automation/ansible/ubuntu
````
{{% /tab %}}
{{% tab title="RDP to OOB" %}}
````bash
./create_ubuntu_vm.sh      ../vars/all-hosts.yml  <PVE server name>  ubuntu_sdwan
````
{{% /tab %}}
{{% tab title="RDP to OOB" %}}
````bash
./start_stop_remove_vm.sh  ../vars/all-hosts.yml  <PVE server name>  ubuntu_sdwan started
````
{{% /tab %}}

### Finish Configuring Ubuntu VM's
- Make sure Ubuntu-x VMs have fully started (i.e. GUI is up and running) before exeucting the following.
    - Suggest opening console windows on PVE to verify.
{{% tab title="Continuing from Terminal in OOB" %}}
````bash
./wallpaper_update.sh  ubuntu_sdwan
````
{{% /tab %}}