+++
title = "Troubleshoot Ansible"
type = "default"
weight = 50
+++

Below are common Ansible issues that require troubleshooting


### **No Route to Host** 
- Network Connectivity
    - Host reachable via ping (using IP address and hostname)
    - DNS Resolution using hostname, resolves to correct IP address
- SSH Connection
    - Via CLI: ssh <username>@<target_ip_address>
    - Via CLI: ssh <username>@<target_hostname>
- If target is Proxmox server (i.e. deploying a new VM on Proxmox )
    - Check Firewall Rules (In this lab, Proxmox should have Firewall turned off)
    - Check IP addresses match in the following files
        - /etc/network/interfaces
        - /etc/hosts
        - If not, after making these the same, reboot Proxmox
    - Check Self-Signed Certificate
        - The self-signed certificate connection details (IP or hostname in its Subject Alternative Names list) must match IP address from previous step.
        - If it doesn't, execute the next two steps
{{% tab title="from PVE Shell" %}}
- Force regeneration of self-cert
````bash
pvecm updatecerts --force
````
{{% /tab %}}
{{% tab title="from PVE Shell" %}}
- Restart the web interface services
````bash
systemctl restart pvedaemon pveproxy
````
{{% /tab %}}
