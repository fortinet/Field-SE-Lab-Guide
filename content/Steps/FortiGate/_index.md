+++
title = "Create FortiGate VMs"
type = "default"
weight = 50
+++

RDP to OOB.

{{% tab title="from Terminal in OOB" %}}
````bash
cd /home/fortinet/automation/ansible/fortinet

./copy_fgt_bootstrap_iso.sh ../vars/all-hosts.yml  <PVE server name>

./create-vm.sh              ../vars/all-hosts.yml  <PVE server name>  fortigate_sdwan v7.6.3.F

./start_remove_vm.sh        ../vars/all-hosts.yml  <PVE server name>  fortigate_sdwan started
````
{{% /tab %}}

Make sure all FortiGate VMs have fully started before exeucting the following.

Suggest opening console windows and verifying login prompt showing.

{{% tab title="from Terminal in OOB" %}}
````bash
./install_flex_token.sh  fortigate_sdwan	**Note: Ansible will say failed, but is successful if VM’s reboot** 

./configure_fgt.sh       fortigate_sdwan

./make_ha.sh             fortigate_hub_ha
````
{{% /tab %}}