+++
title = "Create FortiGate VMs"
type = "default"
weight = 50
+++

- If you get the error {{% badge %}}No route to host{{% /badge %}} with any of the following steps, use the **[Troubleshoot Ansible](/Extras/Troubleshoot_Ansible)** steps

### Copy Bootstrap ISO's, Create VM's, Start VM's
- from Terminal in OOB
{{% tab title="RDP to OOB" %}}
````bash
cd /home/fortinet/automation/ansible/fortinet
````
{{% /tab %}}
    - Copy bootstrap ISO's to Proxmox server
    {{% tab title="RDP to OOB" %}}
````bash
./copy_fgt_bootstrap_iso.sh ../vars/all-hosts.yml  <PVE server name>
````
{{% /tab %}}
    - Create the FGT VM's on Proxmox
    {{% tab title="RDP to OOB" %}}
````bash
./create-vm.sh              ../vars/all-hosts.yml  <PVE server name>  fortigate_sdwan v7.6.6.M
````
{{% /tab %}}
    - Start the VM's just created
    {{% tab title="RDP to OOB" %}}
````bash
./start_remove_vm.sh        ../vars/all-hosts.yml  <PVE server name>  fortigate_sdwan started
````
{{% /tab %}}

### Pull FortiFlex Tokens
- Pull FortiFlex tokens from FortiCare and place them in **.lic** files
{{% tab title="Continuing from Terminal in OOB" %}}
````bash
cd /home/fortinet/automation/ansible/fortiflex
````
{{% /tab %}}
{{% tab title="Continuing from Terminal in OOB" %}}
````bash
./flex-entitlements.sh 
````
{{% /tab %}}
- Verify `/home/fortinet/automation/ansible/fortinet/license` has ***.lic files** with the content of your FortiFlex tokens  

### Install FortiFlex Tokens
**Note:** This next script will "fail", but is successful if VM’s reboot 
- Make sure all FortiGate VMs have fully started before exeucting the following.
    - Suggest opening FGT's console windows and verifying login prompt showing for all FGT's.
{{% tab title="Continuing from Terminal in OOB" %}}
````bash
cd /home/fortinet/automation/ansible/fortinet
````
{{% /tab %}}
{{% tab title="Continuing from Terminal in OOB" %}}
````bash
./install_flex_token.sh  fortigate_sdwan
````
{{% /tab %}}

### Finish Configuring FortiGates
- Make sure all FortiGate VMs have fully started before exeucting the following.
    - Suggest opening FGT's console windows and verifying login prompt showing for all FGT's.
{{% tab title="Continuing from Terminal in OOB" %}}
````bash
./configure_fgt.sh       fortigate_sdwan
````
{{% /tab %}}
{{% tab title="Continuing from Terminal in OOB" %}}
````bash
./make_ha.sh             fortigate_hub_ha
````
{{% /tab %}}