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

- Update Ansible global.vars file
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
cat /home/fortinet/.ssh/ansible_key.pub
````
{{% /tab %}}
    - Highlight, Right Click and Copy ansible_key.pub contents
    ![ansible_key_pub](ansible_key_pub.png)
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
cd /home/fortinet/automation/ansible/vars
./upate_sshkey.sh <right click - paste SSH KEY here>
````
{{% /tab %}}

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

**Global VARS File on Ubuntu-OOB**
- Update **global.yml** file located in **/home/fortinet/automation/ansible/vars/**
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
cd /home/fortinet/automation/ansible/vars
````
{{% /tab %}}
    - **proxmox_api_token_secret:**
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
./upate_api_token_secret.sh  <right click - paste Token Secret here>
````
{{% /tab %}}
    - **fortinet_timezone:** US/Central <= Default Timzone **(no change needed if this is your timezone)**
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
./upate_timezone.sh  <examples: US/Eastern, US/Mountain, US/Pacific>
````
{{% /tab %}}
    - **proxmox_api_host:** pve01		<= Default PVE Server name **(no change needed if already this name)**
    - If different than 'pve01', then need to do all three of the following
        - Edit file **/automation/ansible/vars/all-hosts.yml**
            -   Search for pve01 and change to your server name
        - Edit file **/automation/ansible/inventory/inventory.yml**
            -   Search for pve01 and change to your server name
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
./upate_pve_server_name.sh  <Your PVE Server Name>
````
{{% /tab %}}
    - **proxmox_storage_name:** local-lvm	<= if storage on PVE, or NAS name if not
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
./upate_storage_name.sh  <local-lvm if default, or NAS name if not>
````
{{% /tab %}}
    - **proxmox_storage:** /var/lib/vz	<= if storage on PVE, or /mnt/pve/<NFS name> for NAS
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
./upate_VM_image_directory.sh  <directory where VM images reside>
````
{{% /tab %}}
    - **proxmox_ubuntu_template_name:** Ubuntu-Template <= Name of Ubuntu template
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
./upate_ubuntu_template_name.sh  <VM Template Name>
````
{{% /tab %}}
    - **proxmox_ubuntu_template_vmid:** 491 <= VMID of Ubuntu VM Template
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
./upate_ubuntu_template_vmid.sh  <VM Template VMID>
````
{{% /tab %}}
    - **Verify**
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
cat global.yml
````
{{% /tab %}}
    ![alt](/images/pic-global_yml.png)

**DNS**

All hosts and VMs can be resolved by name.
{{% tab title="from Ubuntu-OOB Terminal" %}}
````bash
ping <your pve server name>
ping Ubuntu-OOB
````
{{% /tab %}} 

**QCOW2 Files Uploaded**

qcow2 files must have the following format:

< 3 letters > dash < version > .qcow2
- FGT-v7.4.8.M.qcow2
- FMG-v7.6.4.F.qcow2
- FAZ-v7.4.8.M.qcow2

![alt](/images/pic-import_qcow2.png)
