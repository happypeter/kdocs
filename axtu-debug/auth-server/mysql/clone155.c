Now I want my own test machine, so first step is to make a clone of 155, on my xen machine(67)
>>>cp src/-------service httpd start
1. server internal error #001
2. that means DB not connected well
3. that's no wonder, since there is no db on 67.
>>>cp phpAdmin------service mysqld start
1. all it needs is httpd and mysqld
2. it just works, haha
>>>cp db
1. cp 155 "/var/lib/mysql/asianux_authentication" to xen
chmod 660 *
chown -c mysql * 
chgrp -c mysql *
then $ll, we see everything on xen is exactly the same as 155
2. but using phpMyadmin, I still can not open asianux_authentication
3. cd ..&&chown -c mysql asianux_authentication&&chgrp -c mysql asianux_authentication
4. now I can browse it in phpAdmin
>>>reg done, error is "required data not found"
1. this is because I do have repo on xen
2. so I make a "/var/www/html/auth/asianux2/AXS3-RF/x86_64/SELF"
3. cp hsyum-arch and yum-arch  to xen and chmod +x
4. now the error is
<>
File "/usr/bin/yum-arch", line 22, in ?
    import pullheaders
ImportError: No module named pullheaders
</>
this is solved by "scp -r 10.1.0.155:/usr/share/yum/ .  "
5. now the "required data not found" remains
6. when I cnstruct SELF anf UPDATE, and error is gone
8. use "127.0.0.1       update.redflag-linux.com" on xen--works

>>>now hawnii installed a vmware-server machine for this
1. https://10.1.0.73:8333/ui/#
10.1.0.65 is the server
2.
ID:root
PW: abc123
3. login 65
[root@dhcp16 asianux2]# chkconfig --level 345 mysqld on
[root@dhcp16 asianux2]# chkconfig --level 345 httpd on
4. do the copy like I did to xen
5. done~
>>>
but when I run hsyum-arch I see this
<>
ignoring bad rpm: kudzu-1.2.57.1.15-1.1AXS3.x86_64.rpm

   Total: 1305
   Used: 0
   Src: 0

</>
import a key, then the error is 
<>
ignoring bad rpm: cairo-devel-1.2.4-3.1AX.i386.rpm
Digesting rpms 99 % complete: cups-libs-1.2.4-11.14.4.1AX.i386.rpmError opening rpm cups-libs-1.2.4-11.14.4.1AX.i386.rpm - error public key not available

ignoring bad rpm: cups-libs-1.2.4-11.14.4.1AX.i386.rpm
Digesting rpms 100 % complete: kudzu-1.2.57.1.15-1.1AXS3.x86_64.rpm
   Total: 1305
   Used: 1026
   Src: 0

</>

actually we need another key for ia32 packages
<>
[root@dhcp16 x86_64]# cd /usr/share/doc/asianux-release/
[root@dhcp16 asianux-release]# ls
EULA  EULA.ja  EULA.ko  EULA.zh_CN  EULA.zh_TW  GPL  INSTALLATION  README  RPM-GPG-KEY  RPM-GPG-KEY.ia32
[root@dhcp16 asianux-release]# rpm --import RPM-GPG-KEY
[root@dhcp16 asianux-release]# rpm --import RPM-GPG-KEY.ia32
[root@dhcp16 asianux-release]# cd
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
>>>when I've done above,
hsyum-arch works in x86_64 and x86
so I go to romi:Asianux-30-ppc-beta4-disc1-200706221800.iso
$cd Documents/
get the key for ppc--------it works.
>>>however ia64 is not so simple, i use a iso/KEY, but it does not work
 scp peter@romi:/project/pool/Quartet-sp2/ia64/pool/RPMS/asianux-release-3.0-11AXS3.ia64.rpm .
<>
[peter@romi RPMS]$ rpm -qp --changelog asianux-release-3.0-11AXS3.ia64.rpm
warning: asianux-release-3.0-11AXS3.ia64.rpm: V3 DSA signature: NOKEY, key ID 9efa95c8

* Thu Feb 28 2008 Hua Jie <jiehua@redflag-linux.com> 3.0-7AXS3
- correct RPM-GPG-KEY-ia64   //pay attention here
</>
