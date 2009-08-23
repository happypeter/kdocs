SDS
NOTE:
SDS will fail to readout package info if you have format error in spec file,
even it is a missing '*' in the changlog

>>>SDS can change Bugzilla info automaticlly
1. change status: received->fixed
2. sent a comment to bugzilla

>>>choose Current<->mantaivence
check Bugzilla->type

>>>every time I apply a patch, I need to change spec file of my package
1. release number must be changed
2. add changelog


>>>If you want to build
$ssh 10.1.0.8 --------------jupiter(32 bit)
Note: 10.1.0.3-------------64 bit
      10.1.0.4-------------suteng

NOTE: login jupiter first

$rm -rf tmp/everything
################
sudo  /project/bin/axbldpkg -j Quartet-sp2  -V 3.0  -w ~/sds/ -t /home/peter/tmp/    axtu
//for 1.4 MT, use below
sudo  /project/bin/axbldpkg -j Quartet-sp2  -V 3.0-maint  -w ~/sds/ -t /home/peter/tmp/    axtu
###############
but when I use this to do MT(1.4) I see
<romi>
PACKAGE NAME:       axtu
PACKAGE VERSION:    1.5
ls: /home/peter/sds//packages/axtu/1.5/*.spec: No such file or directory
No such spec file.

ERROR PACKAGE(S):
        axtu
* Removing working directory...
* Removing working directory in virbuild...

open log file? (y/n) [y]: n
Canceled.
PLEASE CHECK /tmp/axbld.log.28050!!
[peter@pluto ~]$ sudo  /project/bin/axbldpkg -j Quartet-sp2  -V 3.0  -w ~/sds/ -t /home/peter/tmp/    axtu  
</>
What shall I do ?
sudo  /project/bin/axbldpkg -j Quartet-sp2  -V 3.0-maint  -w ~/sds/ -t /home/peter/tmp/    axtu
//3.0-maint is from VERMAP

>>>test case study:
1.
$cd /usr/share/doc/asianux-release/
$rpm --import RPM-GPG-KEY
<>
[root@dhcp16 x86_64]# cd /usr/share/doc/asianux-release/
[root@dhcp16 asianux-release]# ls
EULA  EULA.ja  EULA.ko  EULA.zh_CN  EULA.zh_TW  GPL  INSTALLATION  README  RPM-GPG-KEY  RPM-GPG-KEY.ia32
[root@dhcp16 asianux-release]# rpm --import RPM-GPG-KEY
[root@dhcp16 asianux-release]# rpm --import RPM-GPG-KEY.ia32
[root@dhcp16 asianux-release]# cd
[root@dhcp16 ~]# ls
anaconda-ks.cfg  Desktop  install.log  install.log.syslog  x86_64
[root@dhcp16 ~]# cd x86_64/
[root@dhcp16 x86_64]# ls
BASE  BASE.header.info  SELF  SELF.header.info  UPDATE  UPDATE.header.info
[root@dhcp16 x86_64]# hsyum-arch UPDATE
=== HS Updater Server Inforamtion File Creator =================
Found Target Directories : ./RPMS
Digesting rpms 100 % complete: kudzu-1.2.57.1.15-1.1AXS3.x86_64.rpm             m86_64.rpm.rpm
   Total: 1305
   Used: 1305
   Src: 0

Writing header.info file
</> 
* you only need to do it once, but if it is not done, error when you issue "rpm -K xxx.rpm"




>>>Bugzilla
<>
Hi Developers,

For beta4 release, I don't run the script to change the status to
INTEGRATED.
Please do it by yourself after you confirmed that CD includes your fix.
This has to be completed by 05/25.

Thank you,
-Jun
</>
* to do this, I need to wait a email for this beta, then If I see
* xxx-9AX is inside the list. that means ...5,6,7,8 will also be 
* integrated.
*


>>>VERMAP-DIR

as long as they do not touch axtu,
I do not need to update it on romi:/home/peter/sds/VERMAP-DIR
