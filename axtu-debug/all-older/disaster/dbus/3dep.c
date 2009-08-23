>>>So here we are going to do sth very interesting
trying to find out how dep file is found

1. RPMPROB_REQUIRES is the keyword in ../dbus_error/dbuglog
2. it is a case of rpmProblem in 
   int classRpmEngine::GetRequiredPkgFromRemote(rpmProblem prob, struct structRPMInfo *result) 
3. p = ps->probs + i;
   int classRpmEngine::DealwithDependence(rpmts ts,  rpmps ps)
4. result = DealwithDependence(ts, ps);
   ps = rpmtsProblems(ts);//I know dbus is now in ts

>>>
Take look at this
<>
[root@dhcp26 ~]# rpm -e --test dbus-1.0.0-6.3.x86_64
error: Failed dependencies:
        libdbus-1.so.3()(64bit) is needed by (installed) dbus-glib-0.70-5.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) dbus-python-0.70-7.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) avahi-0.6.16-1.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) cups-1.2.4-11.14.6.2AX.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) dbus-qt-0.62-16.1AX.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) kdelibs-3.5.5-11.18AXS3.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) hal-0.5.8.1-25.2AXS3.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) gphoto2-2.2.0-3.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) notification-daemon-0.3.5-8.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) libnotify-0.4.2-6.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) libgnomecups-0.2.2-8.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) notify-python-0.1.0-3.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) NetworkManager-glib-0.6.4-6.1AX.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) dbus-devel-1.0.0-6.3.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) kdebase-3.5.5-23.40AXS3.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) fileshareui-1.0-1229.9AXS3.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) printershareui-1.0-0110AXS3.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) shared-1.0-0108.1AXS3.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) bind-9.3.3-10.1AXS3.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) lime-providers-1.3.12-1AXS3.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) gnome-vfs2-2.16.2-4.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) gnome-mount-0.5-3.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) krb5-auth-dialog-0.7-1.x86_64
<>
then we can explain ../dbus_error/dbuglog,
because our new dbus does not have libs, so  after finding dbus-libs,axtu will check again
then rpmprobelm will be libdus.so not found, so axtu will try to install dbus-lib, but if you install the 
higher version of dbus-lib, it will requires a higher version of dbus-glib and notification-daemon and ...
thus the dbuglog is seen.
1. if you want to install dbus-lib64, this operation will natrually delete the old version fo dbus, thus any package reguires
older dbus-lib, shall be delete and upgrade, so that's just normal
2. it simply has nothing to do with libs are within the package dbus, or be seperated. let's say libs are still inside dbus,
   then if you update dbus, you still need to upgrade any package dep on libdbus.so
3. it is just like if you want to upgrade libc.so, and the new version is incompatibal with old one. that means all your 
   software need to be upgrade, it is horriable but just natral:-)
4. we can also explain why when dbus and dbus-lib are all on install list it can be installed without any error,
   that's because I issued "rpm -e dbus --nodeps".---after so all the older versions of programs that dep on older libdbus
   will have problems.

>>>
so the real problem is not axtu add odd packages. it because axtu can not find out all the deps for these added packages.
now for me the right solution shall be satisfy all the deps at once, then install them all!

1. but when I update dbus32, the dbug log is the same, lots of packages are add, but finally only dbus-lib is shown on the 
   dep list, which is right. I think that's because axtu check the local package, if it is conpatiable with the new 
   libdbus.so, then just ignore it, that's also natrual,
2. but I need to study the 64 case.
3. but on a fresh MT systerm, dbus32 also has problem, see ../dbus32.e/.
4. <>
   result = GetRequiredPkgFromRemote(p, requiredRPM);
   </>
   result==-3 means found package already installed and it shall be ignored.
   so maybe in debug log you see 10 packages are added, finally only 2 are on dep list, that's because this.


