+++
title = "Create FortiAnalyzer VM"
type = "default"
weight = 70
+++


RDP to OOB.

{{% tab title="from Terminal in OOB" %}}
````bash
cd /home/fortinet/automation/ansible/fortinet

./create-vm.sh ../vars/all-hosts.yml 	<name of your PVE server> 	faz 	v7.6.4.F

./start_remove_vm.sh ../vars/all-hosts.yml <name of your PVE server> 	faz	started
````
{{% /tab %}}

Make sure FortiAnalyzer VM has fully started before continuing.

Suggest opening console windows and verifying login prompt showing.

**Configure FortiAnalyzer**

From the VM’s console on ProxMox 

Login using admin / "no password"

Set Password to the following:  	
````bash
Fort1net!
````
**Note:** Starting with 7.6.4 a password policy for local users is enabled and configured by default. Password must have at least 8 characters and must contain uppercase letter(s), lowercase letter(s), number(s), and special character(s).

Configure interfaces so the Ubuntu-OOB can run Ansible modules
````bash
config system interface
    edit "port1"
        unset mode
    next    
    edit "port2"
        set ip 10.100.55.2/24
        set allowaccess ping https ssh http
    next
end
````

Disable change notes
````bash
config system global
    set object-revision-mandatory-note disable
end
````

Allow admin user to use JSON 	

**Note:**  After this command, you will be automatically logged out

````bash
config system admin user
    edit "admin"
        set rpc-permit read-write
    next
end
````

RDP to OOB.
{{% tab title="from Terminal in OOB" %}}
````bash
cd /home/fortinet/automation/ansible/fortinet

./configure_fmg.sh  faz
````
{{% /tab %}}

From the VM’s console on ProxMox 

Login to FortiAnalyzer's console using: admin / Fort1net!

**Note:**  After this command, the system will automatically reboot

		
{{% tab title="Inject FortiFlex Token" %}}
````bash
execute vm-license <token>
````
{{% /tab %}}