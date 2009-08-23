[root@dhcp17 axtu]# rpm -e dbus-devel-1.0.0-6.3.x86_64
error: Failed dependencies:
        dbus-devel >= 0.90 is needed by (installed) hal-devel-0.5.8.1-25.2AXS3.x86_64
        dbus-devel >= 0.90 is needed by (installed) hal-devel-0.5.8.1-25.2AXS3.i386
        dbus-devel >= 0.90 is needed by (installed) gnome-vfs2-devel-2.16.2-4.x86_64
        dbus-devel >= 0.90 is needed by (installed) gnome-vfs2-devel-2.16.2-4.i386
[root@dhcp17 axtu]# rpm -qa|grep dbus-d
dbus-devel-1.0.0-6.3.x86_64
[root@dhcp17 axtu]# rpm -q --qf '%{obsoletes}\n' dbus-glib-devel-0.73-8AXS3.x86_64
dbus-devel
[root@dhcp17 axtu]# rpm -q --qf '%{requires}\n' dbus-glib-devel-0.73-8AXS3.x86_64
dbus-devel
[root@dhcp17 axtu]# rpm -e dbus-devel-1.0.0-6.3.x86_64
error: Failed dependencies:
        dbus-devel >= 0.90 is needed by (installed) hal-devel-0.5.8.1-25.2AXS3.x86_64
        dbus-devel >= 0.90 is needed by (installed) hal-devel-0.5.8.1-25.2AXS3.i386
        dbus-devel >= 0.90 is needed by (installed) gnome-vfs2-devel-2.16.2-4.x86_64
        dbus-devel >= 0.90 is needed by (installed) gnome-vfs2-devel-2.16.2-4.i386
        dbus-devel is needed by (installed) dbus-glib-devel-0.73-8AXS3.i386
        dbus-devel is needed by (installed) dbus-glib-devel-0.73-8AXS3.x86_64
[root@dhcp17 axtu]#     
[root@dhcp17 ~]# rpm -q --qf '%{provides}\n' dbus-glib-devel-0.73-8AXS3.x86_64
dbus-glib-devel
[root@dhcp17 ~]#
                                
//from below, we see dbus-glib-devel is different form other package
// "rpm -Uvh obsoleter" can not remove the obsoleted.
<>
[root@dhcp17 tmp]# rpm -qa|grep dbus-glib-devel
dbus-glib-devel-0.73-8AXS3.x86_64
dbus-glib-devel-0.73-8AXS3.i386
[root@dhcp17 tmp]# rpm -e dbus-glib-devel-0.73-8AXS3.x86_64
[root@dhcp17 tmp]# rpm -Uvh dbus-glib-devel-0.73-8AXS3.x86_64.rpm
warning: dbus-glib-devel-0.73-8AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
Preparing...                ########################################### [100%]
   1:dbus-glib-devel        ########################################### [100%]
[root@dhcp17 tmp]# rpm -qa|grep dbus-deve
dbus-devel-1.0.0-6.3.x86_64
[root@dhcp17 tmp]#
</> 
