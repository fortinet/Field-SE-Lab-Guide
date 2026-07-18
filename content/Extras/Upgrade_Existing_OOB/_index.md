+++
title = "Upgrade Existing OOB"
type = "default"
weight = 90
+++

Why would do this? 
- Rebuild OOB completely without losing Homepage, Guacamole, and Ansible configs
    - Want OOB built off a newer Ubuntu Template VM
    - Want latest Ansible Scripts

### **Backup Configs** ### 

### Guacamole

{{% tab title="from Terminal in /home/Fortinet/c_data/guacamole" %}}
````bash
cd  /home/fortinet/c_data/guacamole
````
````bash
docker compose ps
````
````bash
docker compose exec guacamole-sql /bin/sh
````
````bash
sh-5.1# mysqldump -u root -p --all-databases --set-gtid-purged=OFF > backup.sql
````
````bash
Enter password: password
````
````bash
sh-5.1# exit
````
````bash
docker compose cp guacamole-sql:/backup.sql ./backup.sql
````
- **Optional:** SCP _backup.sql_ to your laptop ( always good to have a copy not on the VM )
{{% /tab %}}

### Ansible, Homepage, CoreDNS
{{% tab title="from Terminal in /home/Fortinet" %}}

````bash
cd /home/fortinet
````

- The following is a single command all on one line
````bash
zip backup_config.zip automation/ansible/inventory/inventory.yml automation/ansible/vars/all-hosts.yml automation/ansible/vars/flex-serial-numbers.yml automation/ansible/vars/global.yml c_data/coredns/conf/zones/db.fortinet.internal c_data/coredns/conf/zones/db.home.internal c_data/homepage/config/bookmarks.yaml c_data/homepage/config/services.yaml c_data/homepage/config/settings.yaml c_data/homepage/config/widgets.yaml .ssh/ansible_key .ssh/ansible_key.pub
````
- **Optional:** SCP _**backup_config.zip**_ to your laptop ( always good to have a copy off the VM )
{{% /tab %}}


### Start Upgrade
{{% tab title="from Terminal in OOB" %}}
- Pull the latest OOB install scripts from github repository
````bash
cd /home/fortinet/Downloads/
````
````bash
git clone https://github.com/fortinet/Field-SE-Lab-OOB /home/fortinet/Downloads
````
````bash
chmod 744 *.sh
````
{{% /tab %}}

{{% tab title="from Terminal in OOB" %}}
- Run the following script _**ONLY IF**_ changing the external default subnet from 172.16.3.x (provide ONLY the first 3 octets)
- Example: ./update_subnet.sh 192.168.10

````bash

./update_subnet.sh <external subnet to SE Lab> 
````
{{% /tab %}}
{{% tab title="from Terminal in OOB" %}}
- Next start the install script
````bash

./OOB_Install.sh

````
- When you see the following message
    - **File '/usr/share/keyrings/docker-archive-keyring.gpg' exists. Overwrite? (y/N)**
- Type **y** and hit < enter >
- **Note:** VM will auto reboot after “OOB_Install.sh” script runs
{{% /tab %}}

### **Restore Config** ### 

### Guacamole

{{% tab title="from Terminal in /home/Fortinet/c_data/guacamole" %}}
- _**backup.sql**_ should be in the _**/home/Fortinet/c_data/guacamole**_ directory.  If not, SCP from laptop.
````bash
cd  /home/fortinet/c_data/guacamole
````
````bash
docker compose ps
````
````bash
docker compose cp ./dump.sql guacamole-sql:/backup.sql
````
````bash
docker compose exec guacamole-sql /bin/sh
````
````bash
sh-5.1# mysql -u root -p <  ./dump.sql
````
````bash
Enter password: password
````
````bash
sh-5.1# exit
````
````bash
docker compose down
````
````bash
docker compose up –d
````
{{% /tab %}}

    
### Ansible, Homepage, CoreDNS

{{% tab title="from Terminal in /home/Fortinet" %}}
- _**backup_config.zip**_ should be in the _**/home/Fortinet**_ directory.  If not, SCP from laptop.
````bash
cd /home/fortinet
````
````bash
unzip backup_config.zip
````
- Choose [A]ll
````bash
replace automation/ansible/inventory/inventory.yml? [y]es, [n]o, [A]ll, [N]one, [r]ename: A
````
{{% /tab %}}
{{% tab title="from Terminal in /home/Fortinet/coredns" %}}
- Restart CoreDNS
````bash
cd /home/fortinet/c_data/coredns/

````
````bash
docker compose down
````
````bash
docker compose up –d
````
{{% /tab %}}

### Verification 
- "homepage" is working
    - via Work Laptop browser: [http://172.16.3.80](http://172.16.3.80) **(URL should reflect your subnet if not-default)**
- Guacamole is working
    - via Work Laptop browser: [http://172.16.3.80:8080/guacamole](http://172.16.3.80:8080/guacamole) **(URL should reflect your subnet if not-default)**
        - **User:** 		*guacadmin*
        - **Password:** 	*guacadmin*
- DNS is working
{{% tab title="from Terminal" %}}
````bash
ping oob
{{% /tab %}}
{{% tab title="from Terminal" %}}
````bash
ping oob.home.internal
{{% /tab %}}
{{% tab title="from Terminal" %}}
````bash
ping oob.fortinet.internal
{{% /tab %}}
{{% tab title="from Terminal" %}}
````bash
ping <pve server name>
````
{{% /tab %}}

### Upgrade Complete ###