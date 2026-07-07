+++
title = "Proxmox Configure"
type = "default"
weight = 6
+++

### Create VNETs

{{% tab title="from PVE Shell" %}}
````bash
cd /root
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
````bash
curl https://raw.githubusercontent.com/fortinet/Field-SE-Lab-OOB/refs/heads/main/automation/proxmox/Create_VNETs.sh > Create_VNETs.sh
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
````bash
chmod 777 Create_VNETs.sh
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
````bash
./Create_VNETs.sh
````
{{% /tab %}}

### Install proxmoxer on each PVE Server

- Starting with Proxmox 9.x, proxmoxer version 2.3 is required
    - Unforunately, "apt install -y python3-proxmoxer" will only install 2.2
- The following steps "force" installs proxmoxer version 2.3
- {{% badge %}}Note{{% /badge %}} "forcing" this install will result in the following (so don't be alarmed.)
    - **WARNING: Running pip as the 'root' user can result in broken permissions and conflicting behaviour with the system package manager, possibly rendering your system unusable.**
    - **DEPRECATION: Building 'x-y-z' using the legacy x-y-z mechanism, which will be removed in a future version**

{{% tab title="from PVE Shell" %}}
````bash
apt install pip
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
````bash
pip install requests --break-system-packages
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
````bash
pip install openssh-wrapper --break-system-packages
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
````bash
pip install ssh_paramiko --break-system-packages
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
````bash
pip install proxmoxer==2.3.0 --break-system-packages
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
- Verify proxmoxer version 2.3 is installed
````bash
python3 -c "import proxmoxer; print(proxmoxer.__version__)"
````
{{% /tab %}}


### Proxmox Server Configure Complete