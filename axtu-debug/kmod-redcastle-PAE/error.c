<>

[root@localhost ~]# rpm -Uvh kernel-2.6.18-53.14AXS3.i686.rpm
error: Failed dependencies:
        kernel-i686 = 2.6.18-53.11AXS3 is needed by (installed) kmod-redcastle-3.0.2-6.2.6.18_53.11AXS3.i686
        xen-hypervisor-abi = 3.1 is needed by (installed) xen-3.0.3-41.7AXS3.i386
[root@localhost ~]# rpm -Uvh kernel-2.6.18-53.14AXS3.i686.rpm kmod-redcastle-3.0.2-9.2.6.18_53.14AXS3.i686.rpm
error: Failed dependencies:
        xen-hypervisor-abi = 3.1 is needed by (installed) xen-3.0.3-41.7AXS3.i386

</>
