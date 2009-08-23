Hwanii want me test by all the SP2-B3 rpms, I think it may help
>>>
1. mount -o loop xxx-beta3.dvd.iso /b3
2. mv all off the to 155:/UPDATE
3. choose MT_2 sys
4. choose dbus-devel x86_64  only, using 8AX axtu
5. see ../dbus/4.e
6. change it into MT axtu
7. do the same thing
8. exactly the same error occur
9. do the same connecting to 246
10.done without any error 
11.Now I know Beta3 also has problem

NOTE: I did step 9 cause I want to make sure there is no error on my local systerm
Now it is obvious there is none. 


>>>test SP2-alpha
1. copy all the rpms to 155
2. run hsyumarch UPDATE
3. same error, below is the dbus rpm in alpha ISO
<>
[root@dhcp23 RPMS]# rpm -Uvh --test dbus-1.1.2-12AXS3.x86_64.rpm
warning: dbus-1.1.2-12AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
error: Failed dependencies:
        dbus-libs = 1.1.2-12AXS3 is needed by dbus-1.1.2-12AXS3.x86_64
        libdbus-1.so.3()(64bit) is needed by dbus-1.1.2-12AXS3.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) dbus-glib-0.70-5.x86_64
        libdbus-1.so.3()(64bit) is needed by (installed) dbus-python-0.70-7.x86_64
<>

