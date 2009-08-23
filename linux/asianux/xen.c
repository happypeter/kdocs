How to Install xen on ASianux

1. axtu -i -----install all xen suff
2. vim /etc/grub/menu.1st------in ubuntu
   add xen-kernel entry to 1.
   you can copy the entry-adding lines from asianux: /boot/grub/menu.1st
3. reboot and use xen kernel sys
4. chkconfig --level 345 xend on ----------set boot time start
5. we need a ftp server to use xen
   cp rpms from ISOs to /var/ftp/pub/...
7 virt-install
  ansewer the install path with
 ftp://10.1.0.72/pub/axs3sp1/
8. I remember Hwanii construst pub/axs3sp1/ this way
<>
[root@dhcp25 ~]# mount -o loop Asianux-30-SP1-x86_64-release-disc2.iso b4/
[root@dhcp25 ~]# cp b4/* peter-pub/ -rf
cp: overwrite `peter-pub/Asianux/RPMS/TRANS.TBL'? y
cp: overwrite `peter-pub/Asianux/TRANS.TBL'? y
cp: overwrite `peter-pub/Documents/ls-lR'? y
cp: overwrite `peter-pub/Documents/MD5SUMS'? y
cp: overwrite `peter-pub/Documents/TRANS.TBL'? y
cp: overwrite `peter-pub/TRANS.TBL'? y
cp: overwrite `peter-pub/Unsupport/TRANS.TBL'? y
</>
but when I do this myself, the size of axs3sp1/ I make is a little bigger than hwanii's by 7m or so, 
>>>>
libvir: error : this function is not supported by the hypervisor: virConnectNumOfDefinedNetworks
libvir: error : this function is not supported by the hypervisor: virConnectNumOfNetworks
--the error does not matter

if you want to stop a xen guest use $init 0

>>>
<>
[root@dhcp23 mnt]# cd ubuntu/
[root@dhcp23 ubuntu]# cd VMs/
[root@dhcp23 VMs]# ls
AXS3SP1x86_64  AXS3SP1x86_64_just_installed
[root@dhcp23 VMs]# cp AXS3SP1x86_64 AXS3SP1x86_64_246 -rf
</>

>>>
Blow is from xen User Mannul
<>
2.5.1   GRUB Configuration
An entry should be added to grub.conf (often found under /boot/ or /boot/grub/)
to allow Xen / XenLinux to boot. This file is sometimes called menu.lst, depending
on your distribution. The entry should look something like the following:
title Xen 3.0 / XenLinux 2.6
   kernel /boot/xen-3.0.gz dom0_mem=262144
   module /boot/vmlinuz-2.6-xen0 root=/dev/sda4 ro console=tty0
</>

>>>>>>>
add a new xen-machine.
1. copy the 10G old machine

[root@dhcp23 VMs]# cp AXS3SP1x86_64 AXS3SP1x86_64_246 -rf

2. copy a conf file
cp  /etc/xen/AXS3SP1x86_64 /etc/xen/AXS3SP1x86_64_just_installed
vi /etc/xen/AXS3SP1x86_64_just_installed ----------change "name, disk, uuid, mac"

4. xm create -c /etc/xen/AXS3SP1x86_64_just_installed ------choose xen kernel and boot it
   xm --help

3. vim guest-asianux:/boot/grub/menu,1st
   delete all the kernel entry but the xen-kernel in use now

4. virt-manager

>>>When I try to intall xen myself, I alway blocked by the 
<>
127.0.0.1

/sp1/

</> 

No matter I am using ftp or http.
Even I am here on my labtop using hwanii constructed ftp/pub/
