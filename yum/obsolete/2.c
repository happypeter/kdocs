http://yum.baseurl.org/wiki/YumPackageUpdates
above url page dicusses how yum obssoletes work
<sos.spec>
Provides: sysreport = 1.3.15-8
Obsoletes: sysreport
</>
http://yum.baseurl.org/wiki/YumCommands
yum list obsoletes
This command lists any obsoleting relationships between any available package and any installed package.


===
if You go here
<>
[root@dhcp17 rpmUtils]# pwd
/root/Desktop/yum/rpmUtils
[root@dhcp17 rpmUtils]# vim updates.py    
</>

you will find how YUM handle obsoletes
>>>if you see the ChangeLog
you will find almost 100 obsoletes desciption there|
