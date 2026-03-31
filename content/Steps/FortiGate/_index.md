+++
title = "Create FortiGate VMs"
type = "default"
weight = 50
+++

- If you get the error {{% badge %}}No route to host{{% /badge %}} with any of the following steps, use the **[Troubleshoot Ansible](/Extras/Troubleshoot_Ansible)** steps

{{% tab title="RDP to OOB" %}}
- from Terminal in OOB
    - Copy bootstrap ISO's to Proxmox server
    - Create the FGT VM's on Proxmox
    - Start the VM's just created
````bash
cd /home/fortinet/automation/ansible/fortinet

./copy_fgt_bootstrap_iso.sh ../vars/all-hosts.yml  <PVE server name>

./create-vm.sh              ../vars/all-hosts.yml  <PVE server name>  fortigate_sdwan v7.6.6.M

./start_remove_vm.sh        ../vars/all-hosts.yml  <PVE server name>  fortigate_sdwan started
````
{{% /tab %}}

{{% tab title="Continuing from Terminal in OOB" %}}
- Pull FortiFlex tokens from FortiCare and place them in **.lic** files
- Verify after this step: `/home/fortinet/automation/ansible/fortinet/license` has ***.lic files** with the content your FortiFlex tokens  
````bash
cd /home/fortinet/automation/ansible/fortiflex

./flex-entitlements.sh 
````
{{% /tab %}}

{{% tab title="Continuing from Terminal in OOB" %}}
**Note:** This next script will "fail", but is successful if VM’s reboot 

- Make sure all FortiGate VMs have fully started before exeucting the following.
    - Suggest opening FGT's console windows and verifying login prompt showing for all FGT's.

````bash
cd /home/fortinet/automation/ansible/fortinet

./install_flex_token.sh  fortigate_sdwan
````
{{% /tab %}}

{{% tab title="Continuing from Terminal in OOB" %}}
- Make sure all FortiGate VMs have fully started before exeucting the following.
    - Suggest opening FGT's console windows and verifying login prompt showing for all FGT's.
````bash

./configure_fgt.sh       fortigate_sdwan

./make_ha.sh             fortigate_hub_ha
````
{{% /tab %}}