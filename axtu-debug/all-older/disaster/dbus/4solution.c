>>>
1. using a 1.4 axtu
2. update dbus64 only-----then error dep fail
3. change dep check loop form 5 to 50
4. then a nasty dep list is given see ../dbus_error/dbus-dep.e
5. installed everything, with some confilcts ../dbus_error/dbus-conflict.e
ANSWER: the conflicts is natrual, if dbus i386 and x86_64 are installed together there will be no conflicts
it is  because GetOtherArchPackages() is not working well in rpmengine.

Note:  NetworkManager-glib is also in the list, that means it can be installed by its nature

>>>see ../219.c first
1. when I know the "first update rpm" tricks, things shall be 
   easier. maybe we do not need the 5->50 tricks any more
2. let's test
<error-log>
06/09/09 07:20:03 classRpmEngine Can not find the requir
ed package. DepCount=15, DepTotalCount=1
06/09/09 07:20:03 classRpmEngine        bind-libs = 30:9
.3.4-10.P1.1AXS3 is needed by bind-9.3.4-10.P1.1AXS3.x86
_64
06/09/09 07:20:03 classRpmEngine        bind = 30:9.3.3-
10.5AXS3 is needed by (installed) bind-chroot-9.3.3-10.5
AXS3.x86_64
06/09/09 07:20:03 classRpmEngine        bind = 30:9.3.3-
10.5AXS3 is needed by (installed) caching-nameserver-9.3
.3-10.5AXS3.x86_64
06/09/09 07:20:03 GUI Reqiured Packages were not found.
(Package Requirement Loop) See /var/log/axtu/error.log

<error-log/>
3. but if you click  elfutil64 only, all the packages are listed
   as dep files, and the update is done perfectly.
4. then I did the same the Networkmanager-glib, then the error
   is exactly like the error given above, interesting.
5. hal is OK
>>>anyway let's 5->100
1. dbus64 is OK (with file confilicts)
2. Networkmanager-glib------ok
3. newt--i386---------------ok
4. acl64--------------------ok
5. anaconda64---------------ok
7. dbus32-------------------ok
8. kernel-------------------ok----older kernels are still there
9. redcalstle-app-----------ok
