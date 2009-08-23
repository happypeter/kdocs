[root@localhost ~]# chkconfig --level 345 xend on
error reading information on service xend: No such file or directory
[root@localhost ~]# service xend status
xend: unrecognized service
[root@localhost RPMS]# rpm -Uvh  xen-libs-3.0.3-41.7AXS3.i386.rpm
warning: xen-libs-3.0.3-41.7AXS3.i386.rpm: Header V3 DSA signature: NOKEY, key ID 172988ea
Preparing...                ########################################### [100%]
   1:xen-libs               ########################################### [100%]
[root@localhost RPMS]# service xend start
xend: unrecognized service
>>>
[root@localhost ~]# mount -o loop sp1-disc3.iso peki/
[root@localhost ~]# cd peki/
[root@localhost peki]# ls
Asianux  Documents  TRANS.TBL  Unsupport
[root@localhost peki]# cd Asianux/
[root@localhost Asianux]# ls
RPMS  TRANS.TBL
[root@localhost Asianux]# cd RPMS/
[root@localhost RPMS]# ls|grep xen
xen-3.0.3-41.7AXS3.i386.rpm
[root@localhost RPMS]# rpm -Uvh xen-3.0.3-41.7AXS3.i386.rpm
warning: xen-3.0.3-41.7AXS3.i386.rpm: Header V3 DSA signature: NOKEY, key ID 172988ea
error: Failed dependencies:
        python-virtinst is needed by xen-3.0.3-41.7AXS3.i386
[root@localhost RPMS]# ls|grep python-virtinst
python-virtinst-0.103.0-3.1AXS3.noarch.rpm
[root@localhost RPMS]# rpm -Uvh xen-3.0.3-41.7AXS3.i386.rpm python-virtinst-0.103.0-3.1AXS3.noarch.rpm
warning: xen-3.0.3-41.7AXS3.i386.rpm: Header V3 DSA signature: NOKEY, key ID 172988ea
error: Failed dependencies:
        libvirt-python >= 0.2.1 is needed by python-virtinst-0.103.0-3.1AXS3.noarch
[root@localhost RPMS]# ls|grep libvirt-python
libvirt-python-0.2.3-9.2AXS3.i386.rpm
[root@localhost RPMS]# rpm -Uvh xen-3.0.3-41.7AXS3.i386.rpm python-virtinst-0.103.0-3.1AXS3.noarch.rpm libvirt-python-0.2.3-9.2AXS3.i386.rpm
warning: xen-3.0.3-41.7AXS3.i386.rpm: Header V3 DSA signature: NOKEY, key ID 172988ea
error: Failed dependencies:
        libvirt = 0.2.3 is needed by libvirt-python-0.2.3-9.2AXS3.i386
        libvirt.so.0 is needed by libvirt-python-0.2.3-9.2AXS3.i386
[root@localhost RPMS]# ls|grep libvirt
libvirt-0.2.3-9.2AXS3.i386.rpm
libvirt-devel-0.2.3-9.2AXS3.i386.rpm
libvirt-python-0.2.3-9.2AXS3.i386.rpm
[root@localhost RPMS]# rpm -Uvh xen-3.0.3-41.7AXS3.i386.rpm python-virtinst-0.103.0-3.1AXS3.noarch.rpm libvirt-python-0.2.3-9.2AXS3.i386.rpm libvirt-0.2.3-9.2AXS3.i386.rpm
warning: xen-3.0.3-41.7AXS3.i386.rpm: Header V3 DSA signature: NOKEY, key ID 172988ea
Preparing...                ########################################### [100%]
   1:libvirt                ########################################### [ 25%]
   2:xen                    ########################################### [ 50%]
   3:python-virtinst        ########################################### [ 75%]
   4:libvirt-python         ########################################### [100%]
[root@localhost RPMS]# service xend start
Starting xend:                                             [  OK  ]
>>>
[root@localhost ~]# service vsftpd start
Starting vsftpd for vsftpd: 
[root@localhost RPMS]# virt-install
libvir: QEMU error : connect: /var/run/libvirt/qemud-sock: No such file or directory
libvir: warning : Failed to find the network: Is the daemon running ?
What is the name of your virtual machine? sp1
 How much RAM should be allocated (in megabytes)? 500
 What would you like to use as the disk (path)? /usr/local/xen/x.disc
 How large would you like the disk (/usr/local/xen/x.disc) to be (in gigabytes)? 20
 Would you like to enable graphics support? (yes or no) yes
 What is the install location? ftp://127.0.0.1/pub


Starting install...
Retrieving Fedora...                                               0 B 00:00
Retrieving vmlinuz...     100% |=========================| 2.0 MB    00:00
Retrieving initrd.img...  100% |=========================| 4.9 MB    00:00
Creating storage file...  100% |=========================|  20 GB    00:00
Creating domain...                                                 0 B 00:01

VNC Viewer Free Edition 4.1.2 for X - built Mar 14 2008 04:49:10
Copyright (C) 2002-2005 RealVNC Ltd.
See http://www.realvnc.com for information on VNC.

Sat Jun 20 17:02:35 2009
 CConn:       connected to host localhost port 5900
 CConnection: Server supports RFB protocol version 3.8
 CConnection: Using RFB protocol version 3.8
 TXImage:     Using default colormap and visual, TrueColor, depth 24.
 CConn:       Using pixel format depth 6 (8bpp) rgb222
 CConn:       Using ZRLE encoding

Sat Jun 20 17:02:36 2009
 CConn:       Throughput 2000 kbit/s - changing to full colour
 CConn:       Using pixel format depth 24 (32bpp) little-endian rgb888
 CConn:       Throughput 20000 kbit/s - changing to hextile encoding
 CConn:       Using hextile encoding
Domain installation still in progress.  You can reconnect
to the console to complete the installation process.

                                
>>>
http://www.techotopia.com/index.php/Installing_a_Xen_Guest_OS_from_the_Command-line_(virt-install)
http://download.fedora.redhat.com/pub/fedora/linux/releases/10/Fedora/i386/os/     

[root@localhost /]# virt-install
libvir: QEMU error : connect: /var/run/libvirt/qemud-sock: No such file or directory
libvir: warning : Failed to find the network: Is the daemon running ?
What is the name of your virtual machine? ssd17
 How much RAM should be allocated (in megabytes)? 500
 What would you like to use as the disk (path)? /s.dic
 Would you like to enable graphics support? (yes or no) yes
 What is the install location? http://peter.com/sp1/


Starting install...
Retrieving Asianux...     100% |=========================| 1.2 kB    00:00
Retrieving vmlinuz...     100% |=========================| 2.0 MB    00:00
Retrieving initrd.img...  100% |=========================| 4.9 MB    00:00
Creating domain...                                                 0 B 00:01

VNC Viewer Free Edition 4.1.2 for X - built Mar 14 2008 04:49:10
Copyright (C) 2002-2005 RealVNC Ltd.
See http://www.realvnc.com for information on VNC.
>>>now vnc can not start,
this is beacuse I add in /etc/hosts
127.0.0.1    peter.com
rm it.
then vnc has no problem
>>>


                       +-----------+ Error +------------+
                       |                                |
                       | Unable to retrieve             |
                       | http://127.0.0.1//sp1/images/  |
                       | minstg2.img.                   |
                       |                                |
                       |            +----+              |
                       |            | OK |              |
                       |            +----+              |
                       |                                |
                       |                                |
                       +--------------------------------+

``                           
