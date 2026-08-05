+++
title = "List of All Ansible Scripts"
type = "default"
weight = 10
+++

### **Ubuntu VM's**
| | |
| :--- | :--- |
| [create_ubuntu_vm.sh](/Field-SE-Lab-Guide/steps/ubuntu/#create-ubuntu-vms) | [host vars file name] [pve node] [group] |
| [create_tcgui.sh](/Field-SE-Lab-Guide/steps/tcgui/) | [host vars file name] [pve node] [group] |
| [configure_tcgui.sh](/Field-SE-Lab-Guide/steps/tcgui/) | [group] |
| [configure_gns3.sh](/Field-SE-Lab-Guide/extras/gns3/) | [group] |
| [wallpaper_update.sh](/Field-SE-Lab-Guide/steps/ubuntu/#finish-configuring-ubuntu-vms) | [group] |
| [start_stop_remove_vm.sh](/Field-SE-Lab-Guide/steps/ubuntu/#create-ubuntu-vms) | [vars host file name] [pve node] [group] [started  stopped  absent ] |
| update.sh | [group] |

### **FortiFlex Tokens**
| | |
| :--- | :--- |
| [flex-configs-list.sh](/Field-SE-Lab-Guide/steps/fortigate/#list-fortiflex-config-ids) | |
| [flex-entitlements.sh](/Field-SE-Lab-Guide/steps/fortigate/#pull-fortiflex-tokens) | [ConfigID] |
| flex-regenerate-token.sh | [vars serial number file] [group name] |

### **Fortinet VM's**
| | |
| :--- | :--- |
| [copy_fgt_bootstrap_iso.sh](/Field-SE-Lab-Guide/steps/fortigate/#copy-bootstrap-isos-create-vms-start-vms) | [vars host file name] [pve node] |
| [create-vm.sh](/Field-SE-Lab-Guide/steps/fortigate/#copy-bootstrap-isos-create-vms-start-vms) | [host vars file name] [pve node] [group] [image name] |
| [configure_fgt.sh](/Field-SE-Lab-Guide/steps/fortigate/#finish-configuring-fortigates) | [hosts group] |
| [configure_faz.sh](/Field-SE-Lab-Guide/steps/fortianalyzer/#configuraton-of-fortianalyzer-from-oob) | [hosts group] |
| [configure_fmg.sh](/Field-SE-Lab-Guide/steps/fortimanager/#configuraton-of-fortimanager-from-oob) | [hosts group] |
| [install_flex_token.sh](/Field-SE-Lab-Guide/steps/fortigate/#install-fortiflex-tokens) | [hosts group] |
| [make_ha.sh](/Field-SE-Lab-Guide/steps/fortigate/#finish-configuring-fortigates) | [hosts group] |
| [start_remove_vm.sh](/Field-SE-Lab-Guide/steps/fortigate/#copy-bootstrap-isos-create-vms-start-vms) | [vars host file] [pve node][group] [started  absent ] |
| shutdown.sh | [hosts group] |
