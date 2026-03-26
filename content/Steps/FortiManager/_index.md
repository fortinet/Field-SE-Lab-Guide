+++
title = "Create FortiManager VM"
type = "default"
weight = 60
+++

RDP to OOB.

{{% tab title="from Terminal in OOB" %}}
````bash
cd /home/fortinet/automation/ansible/fortinet

./create-vm.sh        ../vars/all-hosts.yml  <PVE server name> 	fmg  v7.6.4.F

./start_remove_vm.sh  ../vars/all-hosts.yml  <PVE server name> 	fmg  started
````
{{% /tab %}}

Make sure FortiManager VM has fully started before continuing.

Suggest opening console windows and verifying login prompt showing.

**Configure FortiManager**

From the VM’s console on ProxMox 

Login using admin / "no password"

Set Password to this [Lab's standard](/Prerequisites#user-name--passwords-utilizes-the-following-standard) :  	
````bash
Leadership-1
````
**Note:** Starting with 7.6.4 a password policy for local users is enabled and configured by default. Password must have at least 8 characters and must contain uppercase letter(s), lowercase letter(s), number(s), and special character(s).

Configure interfaces so the Ubuntu-OOB can run Ansible modules
````bash
config system interface
    edit "port1"
        unset mode
    next    
    edit "port2"
        set ip 10.100.55.12/24
        set allowaccess ping https ssh http
        set serviceaccess fgtupdates
    next
end
````

Allow VM device registration.	

**Note:**  A new “feature” was added in v7.6.3 to disable VM registration.

Disable change notes
````bash
config system global
    set fgfm-allow-vm enable 
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

````
{{% /tab %}}
**Note:**  Run the following command from OOB 3x.

It will fail on Port 1, and then work, and then fail on Port3 and then work, and on the third run, all tasks run successfully.

{{% tab title="from Terminal in OOB" %}}
````bash
./configure_fmg.sh  fmg
````
{{% /tab %}}

From the VM’s console on ProxMox 

Login to FortiManager's console using: admin / Fort1net!

**Note:**  After this command, the system will automatically reboot

		
{{% tab title="Inject FortiFlex Token" %}}
````bash
execute  vm-license  <token>
````
{{% /tab %}}