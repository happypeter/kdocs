>>>>>>>>Install 1.0.8 vmware-server
1. http://register.vmware.com/content/download-108.html
2. register and get the serail numbers
92801-Y6GD4-2G404-49J2W
90X24-YDA4J-270AL-494A0
98W0M-YDCD5-25N26-4AKR9
90X24-Y6G65-25H2N-4VJ3D
92R2M-Y4FD4-27HAH-49M39
92D8M-YDAFJ-2E00L-48PL5
90T8M-YFYDH-2GH05-4RQ8W
90T2H-Y4YD5-2EH2M-4JK1T
9A80M-Y4U4H-2GN0N-496L5
9AD01-Y4C4H-2G08K-4233D
90DA1-YDUFM-27M2K-4KH88
90T84-Y4FDM-254A6-4H0TR
9AWA5-YFG41-2GN84-43LJR
92R05-Y4Y4N-27N8M-48QHE
92E01-Y6G41-2EH0N-4K4JJ
9292H-YFADJ-250A1-4U3RT
92D24-YFAFJ-2GM8J-4KJVD
9A88M-YFZFJ-27101-4TKVD
92T05-Y4YD1-2GN83-427UN
9AW0M-Y4CD4-25006-4ANK4
90W0M-Y6AD1-2550L-4A1J8
98W0H-YFF4J-2GN0K-41QAT
9ATAJ-YDZ65-25M8N-4T111
9AR8N-Y6UF4-2EM21-4THTM
90904-Y4VF4-25H87-4ANJM
9AR80-YFV41-2G007-493VE
98XAJ-Y6ZDM-2ENAL-4K2L9
9A8A5-YDF4N-2EH8K-435LN
3.
[root@dhcp24 ~]# rpm -Uvh VMware-server-1.0.8-126538.i386.rpm
Preparing...                ########################################### [100%]
   1:VMware-server          ########################################### [100%]
[root@dhcp24 ~]# vmware-config.pl
...
Please specify a port for remote console connections to use [904]  
...
In which directory do you want to keep your virtual machine files?
[/var/lib/vmware/Virtual Machines] 
4. now the problem there is no enough space under / to creat new machines
what shall I do? 
easy, run vmware-config.pl again.
5. now it works if you go to that machine and 
$vmware
6. It seems that if I want to use it on my own machine I need to install vmare as well
7. so I did, but 
<73>
[root@dhcp24 ~]# hostname
dhcp24.asianux.net
</73> 
even though $ssh dhcp24.asianux.net
works
but I can not connect vmware using this hostname
===
Note: vmware on my laptop does not support 64 bit gurests, I need xen to use 64vm-guest
but on my laptop, I have to creat a 64 bit machine to install a 32 bit OS, haha, funny
