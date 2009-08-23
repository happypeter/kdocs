Now if you connect to 246 and try to full-update
axtu will down load kernel again and again
hwanii said it's because kmod-redcalstle is 4
while kernel version is 5, or sth ...

>>> Now on a brandnew JI systerm, connect 246, full-update then error like this:
 redcastle-data >= 3.0.2-20 is needed by kmod-redcastle-3.0.2-22.2.6.18_53.23AXS3.x86_64
Hwanii told me it is a mistake not putting in the right data, so he will fix this soon
>>>today hwanii fixed this probelm
so I want to know wether 246 will delete the glibc
1. before anything is done
[root@dhcp30 ~]# rpm -qa|grep glibc
glibc-devel-2.5-18.1AXS3
glibc-common-2.5-18.1AXS3
glibc-2.5-18.1AXS3
glibc-headers-2.5-18.1AXS3
glibc-2.5-18.2AXS3
compat-glibc-2.3.4-2.26
glibc-utils-2.5-18.1AXS3
compat-glibc-2.3.4-2.26
glibc-2.5-18.1AXS3
glibc-common-2.5-18.2AXS3
compat-glibc-headers-2.3.4-2.26
glibc-devel-2.5-18.1AXS3
glibc-2.5-18.2AXS3
2. after install with 246
root@dhcp30 ~]# rpm -qa|grep glibc
glibc-2.5-18.2AXS3
glibc-headers-2.5-18.2AXS3
compat-glibc-2.3.4-2.26
glibc-utils-2.5-18.2AXS3
compat-glibc-2.3.4-2.26
glibc-devel-2.5-18.2AXS3
glibc-common-2.5-18.2AXS3
compat-glibc-headers-2.3.4-2.26
glibc-2.5-18.2AXS3
glibc-devel-2.5-18.2AXS3

3. so everyting is a OK.
4. installation saw a no enought disk space problem
5. but when i run axtu again, only one package is left on
   the updatelist it is glib2-devel-i386
6. try to update it, but "no space" problem is there, and it 
   not be installed.

<***>
