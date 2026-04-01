+++
title = "Upgrade Existing OOB"
type = "default"
weight = 90
+++

Why would do this? 
- Rebuild OOB completely without losing Homepage, Guacamole, and Ansible configs
    - Want OOB built off a newer Ubuntu Template VM
    - Want latest Automation Ansible Build Scripts

### Backup Config ### 

- **Guacamole**
{{% tab title="from Terminal in /home/Fortinet/c_data/guacamole" %}}
````bash
docker compose ps
	 
docker compose exec guacamole-sql /bin/sh

sh-5.1# mysqldump -u root -p --all-databases > backup.sql
Enter password: password

sh-5.1# exit

docker compose cp guacamole-sql:/backup.sql ./backup.sql

````
{{% /tab %}}

    - SCP _backup.sql_ to your laptop

- **Ansible, Homepage, CoreDNS**
{{% tab title="from Terminal in /home/Fortinet" %}}
- The following is a single command all on one line
````bash
zip backup_config.zip automation/ansible/inventory/inventory.yml automation/ansible/vars/all-hosts.yml automation/ansible/vars/flex-serial-numbers.yml automation/ansible/vars/global.yml c_data/coredns/conf/zones/db.fortinet.internal c_data/coredns/conf/zones/db.home.internal c_data/homepage/config/bookmarks.yaml c_data/homepage/config/services.yaml c_data/homepage/config/settings.yaml c_data/homepage/config/widgets.yaml .ssh/ansible_key .ssh/ansible_key.pub
````
{{% /tab %}}

    - SCP _backup_config.zip_ to your laptop

- **Backup Complete**

### Restore Config ### 

- **Guacamole**
    - SCP backup.sql from laptop to OOB's _/home/Fortinet/c_data/guacamole_
{{% tab title="from Terminal in /home/Fortinet/c_data/guacamole" %}}
````bash
docker compose ps

docker compose cp ./backup.sql guacamole-sql:/backup.sql
	 
docker compose exec guacamole-sql /bin/sh

sh-5.1# mysql -u root -p <  ./backup.sql

Enter password: password

sh-5.1# exit

docker compose down

docker compose up –d

````
{{% /tab %}}

    
- **Ansible, Homepage, CoreDNS**
    - SCP _backup_config.zip_ from laptop to OOB's _/home/Fortinet_
{{% tab title="from Terminal in /home/Fortinet" %}}
````bash
unzip backup_config.zip
````
{{% /tab %}}

- **Restore Complete**