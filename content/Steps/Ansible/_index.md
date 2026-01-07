+++
title = "Ansible Prerequisites"
type = "default"
weight = 30
+++

**SSH Key**
- Generate SSH Key on Ubuntu-OOB
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
ssh-keygen -t rsa -b 4096 -C se_lab@fortinet.internal
  File 	     =>  /home/fortinet/.ssh/ansible_key
  Passphrase =>  <none> just hit enter twice
````
{{% /tab %}} 
-	Place public key on Proxmox
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
ssh-copy-id -i /home/fortinet/.ssh/ansible_key root@<your pve server name>
````
{{% /tab %}} 
- Prompted with the following, respond “yes”
````bash
The authenticity of host 'pve01 (172.16.3.121)' can't be established.
This key is not known by any other names.
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
````
- Prompted for <your pve server name> password
    - < enter password >
- Verify ability to ssh from Ubuntu-OOB to each PVE server in the cluster without a password
    - **Note:** The first time only, you will be prompted similar to sequence above

{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
ssh root@<your pve server name 01>
ssh root@<your pve server name 02>
````
{{% /tab %}} 

-	Edit Ansible global.vars file
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
cat /home/fortinet/.ssh/ansible_key.pub
````
{{% /tab %}}
    - Highlight, Right Click and Copy ansible_key.pub contents
    ![ansible_key_pub](ansible_key_pub.png)
    - Edit **global.yml** located in **/home/Fortinet/automation/ansible/vars/**
        - **proxmox_IaC_sshkey** is located at bottom of file
        - *MAKE SURE* there are single quotes at beginning and end of key
            ![global_yml](global_yml.png) 

**Ansible API Token**
- On PVE Server => create Automation User and API Token (with full Administrator access)
    - Click on: Datacenter/Permissions/Groups
        - Click on Create button	
        - Name:	IaC-admin-users
        ![Ansible_API_1](Ansible_API_1.png)
    - Click on: Datacenter/Permissions
        - Click: Add => Group Permission
            - Path: 	/
            - Group:	IaC-admin-users
            - Role: 	Administrator
            - Propagate: 	Checked
        ![Ansible_API_2](Ansible_API_2.png)
    - Click on: Datacenter/Permissions/Users
        - Click: Add
            - User name: 	IaC
            - Realm: 	Linux PAM standard authentication
            - Group:	IaC-admin-users
            - Expires:	never
            - Enabled:	checked
        ![Ansible_API_3](Ansible_API_3.png)
    - Click on: Datacenter/Permissions/API Tokens
        - Click: Add
            - User: IaC
            - Token ID: Automation
            - Privilege Separation: Unchecked
        ![Ansible_API_4](Ansible_API_4.png)
    - Copy the Token ID and Secret generated
        - **Note:** Secret value is only displayed once when token generated
        ![Ansible_API_5](Ansible_API_5.png)
- On Ubuntu-OOB VM
    - Edit **global.yaml** located in **/home/fortinet/automation/ansible/vars/**
    - Update the following:
        - Token ID and Secret
        - fortinet_timezone: US/Central
        - proxmox_api_host: pve01		<= DNS name of PVE Server
        - proxmox_storage: NFS-VMS	<= if not using NAS this should be lvm-local
        - proxmox_ubuntu_template_name: Ubuntu-Template <= Name of Proxmox template used for ansible
        ![global_yml_api](global_yml_api.png)

**DNS**

All hosts and VMs can be resolved by name.
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
ping <your pve server name>
ping Ubuntu-OOB
````
{{% /tab %}} 


**Global VARS File on Ubuntu-OOB:**

The following file is updated with your lab’s specific configuration:

~~~~bash
/home/fortinet/automation/ansible/vars/global.yml
~~~~
- API User/Token/host	
- *Storage* - Directory where VM Disk Images and qcow2 files being imported
- *Storage_Name* - Name of Storage 
- Ubuntu Template Name and vmid
![alt](/images/pic-global_yml.png)

**QCOW2 Files Uploaded**

qcow2 files must have the following format:

< 3 letters > dash < version > .qcow2
- FGT-v7.4.8.M.qcow2
- FMG-v7.6.4.F.qcow2
- FAZ-v7.4.8.M.qcow2

![alt](/images/pic-import_qcow2.png)
