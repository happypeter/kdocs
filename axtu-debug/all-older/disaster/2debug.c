If I really believe the 1.5.0-8AX axtu has no problem, 
I can use it to full-update with 246 on JI_2
so do it now:
1. first I see the kernel-header conflict probelm as I exepected
2. installation done
3. deleting old version fo packages ------"no enough space..."
4. exactly the same as MT axtu is in use.
5. reboot axtu, then update "no package available", which is great.

>>>that means axtu does not have problem it is 219 has big probelm.
Continue update with 219, now the error is in ../error_log3/

reboot axtu and run update again, Now only choose dbus-devel,
the error is 
<>
05/29/09 05:05:26 classRpmEngine Can not find the required package. DepCount=15, DepTotalCount=2
05/29/09 05:05:26 classRpmEngine        libnssutil3.so()(64bit) is needed by NetworkManager-glib-0.7.0-4.1AXS3.x86_64
05/29/09 05:05:26 classRpmEngine        bind-libs = 30:9.3.4-10.P1.1AXS3 is needed by bind-9.3.4-10.P1.1AXS3.x86_64
05/29/09 05:05:26 classRpmEngine        bind = 30:9.3.3-10.5AXS3 is needed by (installed) bind-chroot-9.3.3-10.5AXS3.x86_64
05/29/09 05:05:26 classRpmEngine        bind = 30:9.3.3-10.5AXS3 is needed by (installed) caching-nameserver-9.3.3-10.5AXS3.x86_64
05/29/09 05:05:26 GUI Reqiured Packages were not found. (Package Requirement Loop) See /var/log/axtu/error.log

</>

Haha, this is a real problem, which gloria and hwanii alse saw.
so why bind is added to the list!!!
>>>I believe 246 also has dbus-devel, I want to update it with 246.
let's see what happens
1. use MT axtu
2. choose dbus-devel x86_64
3. done without error

then I run full-update(No space error is gone, great),
now I  cp 219 rpms to 155
1. use MT axtu
2. update dbus-devel x86_64  only
3. same "bind" error
4. rpm -e bind-devel, then run axtu install, error: can not download: NetworkManager-glib-0.7.0-4.1AXS3.x86_64.hdr
5. this is MT axtu. so it is not my fault
6, now even you run update, you still can not download header 
   because of "Can not download NetworkManager-glib-0.7.0-4.1AXS3.x86_64"
7. If I remove NetworkManager-glib-0.7.0-4.1AXS3.x86_64 from repo, 
   same error occur,but now it is "ORbitxxx" that is naughty
8. I ceate a UPDATE on 155, if you put NetworkManager-glib-0.7.0-4.1AXS3.x86_64 in,
   then read header will fail, but it's OK to use many other rpms for 219
ANSWER: the above problem is because axtu-authen-server is buggy, 
	thus the reg done but access can not be done.
>>>anyway I believe some bad packages are responsible for all trouble
first I will concentrat on dbus: see ../dbus_error, which can well explain
error_log1, but I can not say for sure whether it is a systerm problem or dbus probelm
1. Use a JI machine
2. connect to 219
3. try to update dbus only with axtu----fail
4. down load and run $rpm -Uvh dbus-----same error as in the MT sys
5. since the 246 dbus package are all installed well, so I can believe
   the dbus package itself has problem
6. then I download three older version of dbus and run the test 
   so ../dbus/error3, and show it clear that the lastest dbus itself is buggy
