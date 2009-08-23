http://bugzilla.asianux.com/show_bug.cgi?id=6362
As they say kernel header should be rpm -U
But I did this successfully, which means kernel header will not bothers axtu,
if they are of old versions
<>
[root@localhost rpms]# rpm -ivh kernel-headers-2.6.18-8.11AX.i386.rpm
Preparing...                                                            (100%########################################### [100%]
   1:kernel-headers                                                     (  1%########################################### [100%]
[root@localhost rpms]# rpm -ivh kernel-headers-2.6.18-8.12AX.i386.rpm
Preparing...                                                            (100%########################################### [100%]
   1:kernel-headers                                                     (  1%########################################### [100%]
[root@localhost rpms]# rpm -ivh kernel-headers-2.6.18-8.13AX.i386.rpm
Preparing...                                                            (100%########################################### [100%]
   1:kernel-headers                                                     (  1%########################################### [100%]
[root@localhost rpms]# rpm -ivh kernel-headers-2.6.18-8.14AX.i386.rpm
Preparing...                                                            (100%########################################### [100%]
   1:kernel-headers                                                     (  1%########################################### [100%]
[root@localhost rpms]# rpm -ivh kernel-headers-2.6.18-8.15AX.i386.rpm
Preparing...                                                            (100%########################################### [100%]
   1:kernel-headers                                                     (  1%########################################### [100%]
[root@localhost rpms]# rpm -qa|grep kernel-headers
kernel-headers-2.6.18-8.15AX
kernel-headers-2.6.18-8.12AX
kernel-headers-2.6.18-8.13AX
kernel-headers-2.6.18-8.14AX
kernel-headers-2.6.18-8.11AX
</>
and on the same machine
<>

[root@localhost ~]# rpm -ivh kernel-headers-2.6.18-128.5AXS3.i386.rpm
Preparing...                                                            (100%########################################### [100%]
        file /usr/include/asm-generic/fcntl.h from install of kernel-headers-2.6.18-128.5AXS3 conflicts with file from package kernel-headers-2.6.18-8.12AX
        file /usr/include/asm/ioctls.h from install of kernel-headers-2.6.18-128.5AXS3 conflicts with file from package kernel-headers-2.6.18-8.12AX
        file /usr/include/asm/param.h from install of kernel-headers-2.6.18-128.5AXS3 conflicts with file from package kernel-headers-2.6.18-8.12AX
        file /usr/include/asm/setup.h from install of kernel-headers-2.6.18-128.5AXS3 conflicts with file from package kernel-headers-2.6.18-8.12AX
        file /usr/include/asm/unistd.h from install of kernel-headers-2.6.18-128.5AXS3 conflicts with file from package kernel-headers-2.6.18-8.12AX
        file /usr/include/linux/audit.h from install of kernel-headers-2.6.18-128.5AXS3 conflicts with file from package kernel-headers-2.6.18-8.12AX
        file /usr/include/linux/auto_fs4.h from install of kernel-headers-2.6.18-128.5AXS3 conflicts with file from package kernel-headers-2.6.18-8.12AX
        file /usr/include/linux/binfmts.h from install of kernel-headers-2.6.18-128.5AXS3 conflicts with file from package kernel-headers-2.6.18-8.12AX
        file /usr/include/linux/byteorder/swab.h from install of kernel-headers-2.6.18-128.5AXS3 conflicts with file from package kernel-headers-2.6.18-8.12AX
        file /usr/include/linux/cciss_ioctl.h from install of kernel-headers-2.6.18-128.5AXS3 conflicts with file from package kernel-headers-2.6.18-8.12A
</>

>>>Simon explained the reason for this:
if kernel header contents in different versions are the same. Then
you can update kernel-headers-xxx.rpm with rpm -ivh without any conflicts.
If not, conflicts occur!
>>>A big problem come with this is that even when change axtu, and use "rpm -Uvh"
for kernel-header-xxx.rpm for it. That means we no longer have right kernel headers for the earlier
version of kernels, which are still in use on the running systerm. That's bad.

>>>The easy way to solve this is to add some pre-install script to spec file, say delete all the related files first.
