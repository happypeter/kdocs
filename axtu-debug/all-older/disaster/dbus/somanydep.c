here I want to study why so many deps is added, as in ../dbus-error/dbus-dep.e
The theroy the dicussion here based on is this 
<>
 if you want to install dbus-lib64, this operation will natrually delete the old version fo dbus, thus any package reguires
older dbus-lib, shall be delete and upgrade, so that's just normal
<>
it just like when kernel is updated, if you use rpm command, then it will be a error message"kernel is needed by (installed)redcastle", whereas axtu simply add redcastle to the dep list, which is the right thing to do.
>>>now I just want to know how these dbus deps are added. let's focus on ../dbus-error/dbus-dep.e
<>
[root@dhcp25 rpms]# rpm -qp --requires dbus-1.1.2-12AXS3.x86_64.rpm
...
dbus-libs = 1.1.2-12AXS3
...
<>
so dbus-libs is needed here without any doubt

2. now it comes to dbus-glib, I typed many commands to find requires and provides,
I will say the case is differnt from the kernel---kmod issue.



<>
[root@dhcp25 dbus]# rpm -q --whatrequires libdbus-1.so.3
dbus-1.0.0-6.3.i386
dbus-glib-0.70-5.i386
avahi-0.6.16-1.i386
kdelibs-3.5.5-11.18AXS3.i386
hal-0.5.8.1-25.2AXS3.i386
gphoto2-2.2.0-3.i386
libgnomecups-0.2.2-8.i386
dbus-devel-1.0.0-6.3.i386
gnome-vfs2-2.16.2-4.i386
</>

<>
[root@dhcp29 ~]# rpm -q --requires NetworkManager-glib
/sbin/ldconfig
/sbin/ldconfig
dbus >= 0.90
dbus-glib >= 0.70
libc.so.6()(64bit)
libc.so.6(GLIBC_2.2.5)(64bit)
libdbus-1.so.3()(64bit)
libdbus-glib-1.so.2()(64bit)
libglib-2.0.so.0()(64bit)
libgthread-2.0.so.0()(64bit)
libnm_glib.so.0()(64bit)
libpthread.so.0()(64bit)
rpmlib(CompressedFileNames) <= 3.0.4-1
rpmlib(PayloadFilesHavePrefix) <= 4.0-1
rtld(GNU_HASH)

</>
plz note "rpmlib", what if I install rpm with version higher than 3.0.4-1?

ANSER: well, I need to say I can make all thing clear,
but it is basiclly because the early dbus.rpm is divide into dbus+dbuslib.

