
>>>on my desktop
//click install missing plugins when browing with firefox

[peter@localhost Desktop]$ rpm -Uvh flash-plugin-10.0.32.18-release.i386.rpm
error: can't create transaction lock on /var/lib/rpm/__db.000
[peter@localhost Desktop]$ sudo rpm -Uvh flash-plugin-10.0.32.18-release.i386.rpm
Password:
Preparing...                ########################################### [100%]
   1:flash-plugin           ########################################### [100%]
//haha, works

>>>on my laptop
[root@dhcp17 Desktop]# rpm -i flash-plugin-10.0.32.18-release.i386.rpm
        file /usr/lib/flash-plugin/README from install of flash-plugin-10.0.32.18-release.i386 conflicts with file from package flash-plugin-10.0.22.87-release.i386
        file /usr/lib/flash-plugin/libflashplayer.so from install of flash-plugin-10.0.32.18-release.i386 conflicts with file from package flash-plugin-10.0.22.87-release.i386
[root@dhcp17 Desktop]# rpm -qa|grep flash
flash-plugin-10.0.22.87-release.i386
[root@dhcp17 Desktop]# rpm -Uvh flash-plugin-10.0.32.18-release.i386.rpm
Preparing...                ########################################### [100%]
   1:flash-plugin           ########################################### [100%]
[root@dhcp17 Desktop]#    
//any way it does not work                                                        
