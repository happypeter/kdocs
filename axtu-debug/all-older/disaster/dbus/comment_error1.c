[root@dhcp23 rpms]# rpm -Uvh --test dbus-libs-1.1.2-12AXS3.x86_64.rpm
warning: dbus-libs-1.1.2-12AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
error: Failed dependencies:
        dbus = 1.1.2-12AXS3 is needed by dbus-libs-1.1.2-12AXS3.x86_64
[root@dhcp23 rpms]# rpm -Uvh --test dbus-libs-1.1.2-12AXS3.x86_64.rpm  dbus-1.1.2-12AXS3.i386.rpm
//>>>>peter* rpm itself is not very clear with arch check, it should give some wrong arch error.
warning: dbus-libs-1.1.2-12AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
warning: dbus-1.1.2-12AXS3.i386.rpm: Header V3 DSA signature: NOKEY, key ID 172988ea
error: Failed dependencies:
        libdbus-1.so.3 is needed by dbus-1.1.2-12AXS3.i386
        libdbus-1.so.3 is needed by (installed) dbus-glib-0.70-5.i386
        libdbus-1.so.3 is needed by (installed) avahi-0.6.16-1.i386
        libdbus-1.so.3 is needed by (installed) kdelibs-3.5.5-11.18AXS3.i386
        libdbus-1.so.3 is needed by (installed) hal-0.5.8.1-25.2AXS3.i386
        libdbus-1.so.3 is needed by (installed) gphoto2-2.2.0-3.i386
        libdbus-1.so.3 is needed by (installed) libgnomecups-0.2.2-8.i386
        libdbus-1.so.3 is needed by (installed) dbus-devel-1.0.0-6.3.i386
        libdbus-1.so.3 is needed by (installed) gnome-vfs2-2.16.2-4.i386
[root@dhcp23 rpms]# rpm -Uvh --test dbus-libs-1.1.2-12AXS3.x86_64.rpm  dbus-1.1.2-12AXS3.x86_64.rpm
warning: dbus-libs-1.1.2-12AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
//>>>peter* why the conflicts?
ANSWER: the conflicts is natrual, if dbus i386 and x86_64 are installed together there will be no conflicts
it is  because GetOtherArchPackages() is not working well in rpmengine.
Preparing...                ########################################### [100%]
        file /etc/dbus-1/session.conf from install of dbus-1.1.2-12AXS3 conflicts with file from package dbus-1.0.0-6.3
        file /etc/dbus-1/system.conf from install of dbus-1.1.2-12AXS3 conflicts with file from package dbus-1.0.0-6.3
        file /usr/share/man/man1/dbus-daemon.1.gz from install of dbus-1.1.2-12AXS3 conflicts with file from package dbus-1.0.0-6.3
        file /usr/share/man/man1/dbus-uuidgen.1.gz from install of dbus-1.1.2-12AXS3 conflicts with file from package dbus-1.0.0-6.3
[root@dhcp23 rpms]#            

[root@dhcp23 SRPMS]# rpm -e --test dbus-1.0.0-6.3
error: "dbus-1.0.0-6.3" specifies multiple packages
//the above is because you have dbus of two platform
//see ../dbus_error/solution.c                      
