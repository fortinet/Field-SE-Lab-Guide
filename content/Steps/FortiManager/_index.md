+++
title = "Create FortiManager VM"
type = "default"
weight = 60
+++

### Deploy FortiManager VM

- from Terminal in OOB
{{% tab title="from Terminal in OOB" %}}
````bash
cd /home/fortinet/automation/ansible/fortinet
````
{{% /tab %}}
{{% tab title="from Terminal in OOB" %}}
````bash
./create-vm.sh        ../vars/all-hosts.yml  <PVE server name> 	fmg  v7.6.6.M
````
{{% /tab %}}
{{% tab title="from Terminal in OOB" %}}
````bash
./start_remove_vm.sh  ../vars/all-hosts.yml  <PVE server name> 	fmg  started
````
{{% /tab %}}

- Make sure FortiManager VM has fully started before continuing.
    - Suggest opening console windows and verifying login prompt showing.

### Configure FortiManager from Console

{{% tab title="from FMG VM's console on Proxmox"%}}
- from FMG VM's console on Proxmox
- In the log in prompt, enter the initial/default log in:
    - username: admin, and no password
- Prompted to enter new password complying with new [password policy introduced in v7.6.4](https://docs.fortinet.com/document/fortimanager/7.6.0/new-features/244624/add-a-default-local-user-password-policy-7-6-4)

````bash
FMG-VM64-KVM login: admin
password: 

You are forced to change your password!
According to the password policy enforced on this device, please change your password!
New password must conform to the following policy:
minimum-length=8; must contain upper-case-letter lower-case-letter number non-alphanumeric; expire=0; password-history=0

New Password:
````
{{% /tab %}}

**Disable Password Policy and Set to Lab Standard** 
{{% tab title="from FMG VM's console on Proxmox"%}}
- Set a password that is compliant with Password Policy
    - Example: **Fortinet1!**
- Change admin password to [Lab's standard](/Prerequisites#user-name--passwords-utilizes-the-following-standard)
-  Allow admin user to use JSON
````bash
config system password-policy
     set status disable
end

config system admin user
   edit admin
     set password password
     set rpc-permit read-write
   next
end
````
- After typeing **end** you will be automatically logged out.  
- Log back in and continue
{{% /tab %}}

{{% tab title="from FMG VM's console on Proxmox"%}}
- Configure interfaces so Ubuntu-OOB can run Ansible modules
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
{{% /tab %}}

{{% tab title="from FMG VM's console on Proxmox"%}}
- Allow VM device registration. **Note:** A new “feature” was added starting in 7.6.3 to  [disable VM registration](https://docs.fortinet.com/document/fortimanager/7.6.3/release-notes/519207/special-notices#:~:text=Adding%20VM%20devices).
- Disable change notes **Note:** Starting in 7.0.2 a [change note is mandatory](https://docs.fortinet.com/document/fortimanager/7.0.0/new-features/944728/change-note-is-mandatory-for-every-object-and-policy-change-7-0-2#:~:text=Change%20notes%20are%20mandatory%20for%20every%20object,**set%20object%2Drevision%2Dobject%2Dmax:%20100**%20*%20**set%20object%2Drevision%2Dstatus:%20enable**) for every object and policy change.
````bash
config system global
    set fgfm-allow-vm enable 
    set object-revision-mandatory-note disable
end
````
{{% /tab %}}

### Configuraton of FortiManager from OOB
{{% tab title="from Terminal in OOB" %}}
- from Terminal in OOB 
````bash
cd /home/fortinet/automation/ansible/fortinet
````
- **Note:**  Run the following command 3 times.
    - It will fail on Port 1, and then work, and then fail on Port3 and then work, and on the third run, all tasks run successfully.
````bash
./configure_fmg.sh  fmg
````
{{% /tab %}}


### Inject FortiFlex Token
		
{{% tab title="from FMG VM's console on Proxmox"%}}
- Get FMG's FortiToken:
    - Here: **/home/Fortinet/automation/ansible/fortinet/license/FMG.lic**
    - Or: **https://support.fortinet.com**
- From FMG VM's console execute the following command
````bash
execute  vm-license  <token>
````
**Note:**  After this command, the system will automatically reboot
{{% /tab %}}

### FortiManager Complete