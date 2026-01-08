+++
title = "Guacamole"
type = "default"
weight = 30
+++

### Change/Add/Delete Guacamole Connections
Open browswer and login to `http://172.16.3.80:8080/guacamole`
- **User/Password:** guacadmin / guacadmin
- Click on **Settings**
![Guac1](Guac_1.png)<br />
- Click on **Connections**
![Guac2](Guac_2.png)<br />
- Configure SSH	
![Config_SSH](Config_SSH.png)<br />
- Configure RDP (for Ubuntu)
![Config_RDP_Ubuntu](Config_RDP_Ubuntu.png)<br />
- Configure RDP (for Windows)
![Config_RDP_Windows](Config_RDP_Windows.png)

### Add Guacamole URL’s to homepage
- Launch a connection from guacadmin / Home
![Guac_Home](Guac_Home.png)<br />
- Copy the URL
![Copy_URL](Copy_URL.png)<br />  
- Add to homepage’s bookmark.yaml file **/home/fortinet/c_data/homepage/config/bookmarks.yml**
![homepage_yaml](homepage_yaml.png)<br />
- From the homepage click on the link
![homepage_web](homepage_web.png)<br />


### Source/Details
- [Create](https://guacamole.apache.org/doc/gug/jdbc-auth.html#creating-the-guacamole-database) the Guacamole database
- [Create a user](https://guacamole.apache.org/doc/gug/jdbc-auth.html#granting-guacamole-access-to-the-database) for Guacamole database
- Configure [connection settings](https://guacamole.apache.org/doc/gug/administration.html)
- [MySQL dump and restore](https://dev.mysql.com/doc/refman/8.0/en/using-mysqldump.html) 