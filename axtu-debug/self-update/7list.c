>>> here is all the packages I should put into self
1. rpm
2. all the deps given by axtu
<>
(1) rpm-devel-4.4.2.3-9.2AXS3.x86_64 [Selected package]
(2) nss-3.12.2.0-2AXS3.x86_64 [Dependency package]
(3) popt-1.10.2.3-9.2AXS3.x86_64 [Dependency package]
(4) rpm-libs-4.4.2.3-9.2AXS3.x86_64 [Dependency package]
(5) nspr-4.7.3-2AXS3.x86_64 [Dependency package]
</>
//rpm -p --requirs rpm, then you see why "nss","nspr" are added here.
<>
libnspr4.so()(64bit)
libnss3.so()(64bit)
</>
see ../others/nss-nspr.c to know why nss and nspr is added here
3. asianux-rpm-config-6.0-6AXS3.noarch.rpm
 not a rpm deps but looks so related, haha
4.
<list>
rpm
nss
popt
rpm-libs
nspr
asianux-rpm-config
axtu*
<list/>
Hwanii said for x86_64 platform, we will put i386 "rpm-lib nspr nss popt" into self to avoid later conflicts.
I agree.
there are rpm-build and rpm-devel, Hwanii want them all
NOTE: gloria report another bug: "error in rpmts()", 
when I run rpm -q rpm
i see rpm-biild in the list, so maybe we should add rpm-build as well.
I need to test.
>>>Hwanii said if a  package generate by rpm-xxx.src.rpm, and at the same time it is in our iso, it shoud be in SELF/
so I check rpm.spec
and see
<spec>------found in iso
libs-----------yes
delvel---------yes
build----------yes
python---------yes
apidocs--------no
popt-----------yes
<spec/>
<iso>
./Asianux/RPMS/rpm-build-4.4.2.3-9.2AXS3.x86_64.rpm
./Asianux/RPMS/rpm-devel-4.4.2.3-9.2AXS3.i386.rpm
./Asianux/RPMS/rpm-devel-4.4.2.3-9.2AXS3.x86_64.rpm
./Asianux/RPMS/rpm-libs-4.4.2.3-9.2AXS3.i386.rpm
./Asianux/RPMS/rpm-libs-4.4.2.3-9.2AXS3.x86_64.rpm
./Asianux/RPMS/rpm-python-4.4.2.3-9.2AXS3.x86_64.rpm
//no apidocs here
./Asianux/RPMS/popt-1.10.2.3-9.2AXS3.i386.rpm
./Asianux/RPMS/popt-1.10.2.3-9.2AXS3.x86_64.rpm
</iso>
>>>Hwanii setup a fresh 3.0orig systerm, and say he want to see "rpm -Uvh" has
no warnings, and find out which packages are needed.
1. so I cp the SELF on 219 to the fresh machine
2. then I see this 
<>
[root@localhost self]# rpm -Uvh --test rpm-4.4.2.3-9.2AXS3.x86_64.rpm rpm-libs-4.4.2.3-9.2AXS3.x86_64.rpm nspr-4.7.3-2AXS3.x86_64.rpm nss-3.12.2.0-2AXS3.x86_64.rpm
warning: rpm-4.4.2.3-9.2AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
error: Failed dependencies:
        popt = 1.10.2.3-9.2AXS3 is needed by rpm-4.4.2.3-9.2AXS3.x86_64
        popt = 1.10.2.3-9.2AXS3 is needed by rpm-libs-4.4.2.3-9.2AXS3.x86_64
        prelink <= 0.3.9-2 conflicts with nss-3.12.2.0-2AXS3.x86_64
        rpm = 4.4.2-37.1AX is needed by (installed) rpm-python-4.4.2-37.1AX.x86_64
        rpm = 4.4.2-37.1AX is needed by (installed) rpm-libs-4.4.2-37.1AX.i386
        rpm = 4.4.2-37.1AX is needed by (installed) rpm-devel-4.4.2-37.1AX.i386
        rpm = 4.4.2-37.1AX is needed by (installed) rpm-devel-4.4.2-37.1AX.x86_64
        rpm = 4.4.2-37.1AX is needed by (installed) rpm-build-4.4.2-37.1AX.x86_64

</>
so this is explain why hanii want rpm-devel and python things.
3.
<> 
[root@localhost self]# rpm -Uvh --test rpm-4.4.2.3-9.2AXS3.x86_64.rpm rpm-libs-4.4.2.3-9.2AXS3.x86_64.rpm nspr-4.7.3-2AXS3.x86_64.rpm nss-3.12.2.0-2AXS3.x86_64.rpm popt-1.10.2.3-9.2AXS3.x86_64.rpm  rpm-build-4.4.2.3-9.2AXS3.x86_64.rpm rpm-devel-4.4.2.3-9.2AXS3.x86_64.rpm  rpm-python-4.4.2.3-9.2AXS3.x86_64.rpm
warning: rpm-4.4.2.3-9.2AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
error: Failed dependencies:
        prelink <= 0.3.9-2 conflicts with nss-3.12.2.0-2AXS3.x86_64
        rpm = 4.4.2-37.1AX is needed by (installed) rpm-libs-4.4.2-37.1AX.i386
        rpm = 4.4.2-37.1AX is needed by (installed) rpm-devel-4.4.2-37.1AX.i386
</>
now I see hawnii is right wanting other arch packages.
4.
<>
[root@localhost self]# rpm -Uvh --test rpm-4.4.2.3-9.2AXS3.x86_64.rpm rpm-libs-4.4.2.3-9.2AXS3.x86_64.rpm nspr-4.7.3-2AXS3.x86_64.rpm nss-3.12.2.0-2AXS3.x86_64.rpm popt-1.10.2.3-9.2AXS3.x86_64.rpm  rpm-build-4.4.2.3-9.2AXS3.x86_64.rpm rpm-devel-4.4.2.3-9.2AXS3.x86_64.rpm  rpm-python-4.4.2.3-9.2AXS3.x86_64.rpm rpm-libs-4.4.2.3-9.2AXS3.i386.rpm  nss-3.12.2.0-2AXS3.i386.rpm
warning: rpm-4.4.2.3-9.2AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
warning: rpm-libs-4.4.2.3-9.2AXS3.i386.rpm: Header V3 DSA signature: NOKEY, key ID 172988ea
error: Failed dependencies:
        prelink <= 0.3.9-2 conflicts with nss-3.12.2.0-2AXS3.x86_64
        prelink <= 0.3.9-2 conflicts with nss-3.12.2.0-2AXS3.i386
        rpm = 4.4.2-37.1AX is needed by (installed) rpm-devel-4.4.2-37.1AX.i386
        nss = 3.11.5-3 is needed by (installed) nss-tools-3.11.5-3.x86_64
        nss = 3.11.5-3 is needed by (installed) nss-devel-3.11.5-3.x86_64
        nss = 3.11.5-3 is needed by (installed) nss-devel-3.11.5-3.i386
</>
5.------------------
<>
[root@localhost self]# rpm -Uvh --test rpm-4.4.2.3-9.2AXS3.x86_64.rpm rpm-libs-4.4.2.3-9.2AXS3.x86_64.rpm nspr-4.7.3-2AXS3.x86_64.rpm nss-3.12.2.0-2AXS3.x86_64.rpm popt-1.10.2.3-9.2AXS3.x86_64.rpm  rpm-build-4.4.2.3-9.2AXS3.x86_64.rpm rpm-devel-4.4.2.3-9.2AXS3.x86_64.rpm  rpm-python-4.4.2.3-9.2AXS3.x86_64.rpm rpm-libs-4.4.2.3-9.2AXS3.i386.rpm  nss-3.12.2.0-2AXS3.i386.rpm  rpm-devel-4.4.2.3-9.2AXS3.i386.rpm
warning: rpm-4.4.2.3-9.2AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
warning: rpm-libs-4.4.2.3-9.2AXS3.i386.rpm: Header V3 DSA signature: NOKEY, key ID 172988ea
error: Failed dependencies:
        prelink <= 0.3.9-2 conflicts with nss-3.12.2.0-2AXS3.x86_64
        prelink <= 0.3.9-2 conflicts with nss-3.12.2.0-2AXS3.i386
        nss = 3.11.5-3 is needed by (installed) nss-tools-3.11.5-3.x86_64
        nss = 3.11.5-3 is needed by (installed) nss-devel-3.11.5-3.x86_64
        nss = 3.11.5-3 is needed by (installed) nss-devel-3.11.5-3.i386
</>
6.--------------------
<>
[root@localhost self]# rpm -Uvh --test rpm-4.4.2.3-9.2AXS3.x86_64.rpm rpm-libs-4.4.2.3-9.2AXS3.x86_64.rpm nspr-4.7.3-2AXS3.x86_64.rpm nss-3.12.2.0-2AXS3.x86_64.rpm popt-1.10.2.3-9.2AXS3.x86_64.rpm  rpm-build-4.4.2.3-9.2AXS3.x86_64.rpm rpm-devel-4.4.2.3-9.2AXS3.x86_64.rpm  rpm-python-4.4.2.3-9.2AXS3.x86_64.rpm rpm-libs-4.4.2.3-9.2AXS3.i386.rpm  nss-3.12.2.0-2AXS3.i386.rpm  rpm-devel-4.4.2.3-9.2AXS3.i386.rpm prelink-0.4.0-2AXS3.x86_64.rpm nss-devel-3.12.2.0-2AXS3.x86_64.rpm  nss-tools-3.12.2.0-2AXS3.x86_64.rpm
warning: rpm-4.4.2.3-9.2AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
warning: rpm-libs-4.4.2.3-9.2AXS3.i386.rpm: Header V3 DSA signature: NOKEY, key ID 172988ea
error: Failed dependencies:
        nspr-devel >= 4.6.99 is needed by nss-devel-3.12.2.0-2AXS3.x86_64
</>
7.-----------------------
<>
[root@localhost self]# scp 10.1.0.219:/root/peter/UPDATE/RPMS/nspr-deve*.rpm .
root@10.1.0.219's password:
nspr-devel-4.7.3-2AXS3.i386.rpm               100%  113KB 113.2KB/s   00:00
nspr-devel-4.7.3-2AXS3.x86_64.rpm             100%  113KB 113.2KB/s   00:00
[root@localhost self]# rpm -Uvh --test rpm-4.4.2.3-9.2AXS3.x86_64.rpm rpm-libs-4.4.2.3-9.2AXS3.x86_64.rpm nspr-4.7.3-2AXS3.x86_64.rpm nss-3.12.2.0-2AXS3.x86_64.rpm popt-1.10.2.3-9.2AXS3.x86_64.rpm  rpm-build-4.4.2.3-9.2AXS3.x86_64.rpm rpm-devel-4.4.2.3-9.2AXS3.x86_64.rpm  rpm-python-4.4.2.3-9.2AXS3.x86_64.rpm rpm-libs-4.4.2.3-9.2AXS3.i386.rpm  nss-3.12.2.0-2AXS3.i386.rpm  rpm-devel-4.4.2.3-9.2AXS3.i386.rpm prelink-0.4.0-2AXS3.x86_64.rpm nss-devel-3.12.2.0-2AXS3.x86_64.rpm  nss-tools-3.12.2.0-2AXS3.x86_64.rpm nspr-devel-4.7.3-2AXS3.x86_64.rpm
warning: rpm-4.4.2.3-9.2AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
warning: rpm-libs-4.4.2.3-9.2AXS3.i386.rpm: Header V3 DSA signature: NOKEY, key ID 172988ea
Preparing...                ########################################### [100%]
        file /usr/include/popt.h from install of popt-1.10.2.3-9.2AXS3 conflicts with file from package popt-1.10.2-37.1AX
</>
NOTE: we have two npsr-devel here, but I only add one
FINAL LIST
<list>//install both i386 and x86_64
rpm-build
rpm-python
rpm-devel
rpm
nss
popt
rpm-libs
nspr
asianux-rpm-config
axtu*
<list/>
8.----------------------
<>
[root@localhost self]# rpm -Uvh --test rpm-4.4.2.3-9.2AXS3.x86_64.rpm rpm-libs-4.4.2.3-9.2AXS3.x86_64.rpm nspr-4.7.3-2AXS3.x86_64.rpm nss-3.12.2.0-2AXS3.x86_64.rpm popt-1.10.2.3-9.2AXS3.x86_64.rpm  rpm-build-4.4.2.3-9.2AXS3.x86_64.rpm rpm-devel-4.4.2.3-9.2AXS3.x86_64.rpm  rpm-python-4.4.2.3-9.2AXS3.x86_64.rpm rpm-libs-4.4.2.3-9.2AXS3.i386.rpm  nss-3.12.2.0-2AXS3.i386.rpm  rpm-devel-4.4.2.3-9.2AXS3.i386.rpm prelink-0.4.0-2AXS3.x86_64.rpm nss-devel-3.12.2.0-2AXS3.x86_64.rpm  nss-tools-3.12.2.0-2AXS3.x86_64.rpm nspr-devel-4.7.3-2AXS3.x86_64.rpm popt-1.10.2.3-9.2AXS3.i386.rpm
warning: rpm-4.4.2.3-9.2AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
warning: rpm-libs-4.4.2.3-9.2AXS3.i386.rpm: Header V3 DSA signature: NOKEY, key ID 172988ea
Preparing...                ########################################### [100%]
</>

9. finally, dep are satisfied, but what I've done is only added necessary packages, there are still things we need to concern:
other arch packages: nspr-devel.i386-----------always insttall asa  a pair
not required by build from same src.rpm: like some nss things---------Hwanii said also needed. because errata based on src.rpm
from a src.rpm point of view never forget axtu-authen-client and axtu-common-info
10. since hwanii said differnat arch packages shall consided as a pair and always install together. so I need to do the test again.


>>>>>>>>>>>>>test again considering pair as one
1. so first we need to concern the package named "rpm", since there is only one
 in our iso and real system, so this one we need only one

2. Hwanii do it instead and finally we have ../others/self_x86_64.list
the principle is as following
* if it is required by rpm -Uvh, add it
* if it is arch pair, add it
* if it is from same src package and at the same time involoved into our iso, add it
* hwanii do the last step check by checking sds, using keith's script
* so the final src.rpm list is
<>
axtu
axtu-common-info
axtu-authen-client
nss
nspr
prelink
rpm
</>

3. he also make a list for i386 platform, it is simply the self_x86_64.list with all the x86_64 packages removed. 
