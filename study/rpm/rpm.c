rpm --rebuilddb
>>>
[root@dhcp26 ~]# rpm -q --whatprovides libelf.so.1
elfutils-libelf-0.125-3.i386
[root@dhcp26 ~]# rpm -q --whatprovides libel
no package provides libel

>>>check requires
[root@tsnlocaltest RPMS]# rpm -qpR kmod-redcastle-3.0.2-21.2.6.18_128.5AXS3.x86_64.rpm
warning: kmod-redcastle-3.0.2-21.2.6.18_128.5AXS3.x86_64.rpm: V3 DSA signature: NOKEY, key ID a83bd72e
/bin/sh
/bin/sh
/sbin/depmod
/sbin/depmod
kernel-x86_64 = 2.6.18-128.5AXS3
redcastle-app >= 3.0.2-17
redcastle-data >= 3.0.2-20
redcastle-manager >= 3.0.2-17
redcastle-pam >= 3.0.2-16
rpmlib(CompressedFileNames) <= 3.0.4-1
rpmlib(PayloadFilesHavePrefix) <= 4.0-1
rpmlib(VersionedDependencies) <= 3.0.3-1
>>>

rpm --querytags 
>>>
%_query_all_fmt %{name}-%{version}-%{release}.%{arch}
add the above line to /etc/rpm/macros

>>>
rpm -Fhv --test rpm-* popt-1.10.2.3-9.2AXS3.* nss-* nspr-*
>>>
rpm -qpl dbus-libs-1.1.2-12AXS3.x86_64.rpm
~
>>>
rpm -q --provides xxx.rpm
rpm -qR xxx

rpm

//the following two command helped me to fix one of my bug
# rpm -qf incompatible-conf
# rpm -qi axtu-common-info
<>
[root@dhcp25 etc]# rpm -qf oppd.conf
opfc-StatusDaemon-1.0.1-1.2AX.x86_64
[root@dhcp25 etc]# rpm -qf sensors.conf
lm_sensors-2.10.0-3.1.2AXS3.x86_64
lm_sensors-2.10.0-3.1.2AXS3.i386
</>
>>>
# rpm -qa --qf '%{name}-------%{epoch}\n'|grep 2

# rpm -qp --qf '%{epoch}\n' irqbalance-debuginfo-1.13-6.i386.rpm


#rpmbuild -ba xxx.spec

#rpm -q --changlog package-name

#rpm -qa | grep kernel-devel


# rpm -q --scripts tcsh //  Listing the scripts in a packages

#rpm -ql rpm-devel // Listing the files in a package

#rpm2cpio xxx.rpm | cpio -div

http://home.fnal.gov/~dawson/howto/RPM-Build-Example2.html

>>>below is from max rpm
# rpm -qf /bin/ls
fileutils-3.12-3

If you happen to point RPM at a file it didn't install, you'll get a message similar to the following:
# rpm -qf .cshrc
file /home/ed/.cshrc is not owned by any package

>>>
[root@dhcp23 OTHERS]# rpm -q --whatprovides libc.so.6
glibc-2.5-18.1AXS3
[root@dhcp23 OTHERS]# rpm -q --provides glibc-2.5-18.1AXS3|less
 <>

[root@dhcp23 rpms]# rpm -qf --provides glibc-2.5-34.1AXS3.x86_64.rpm
file /root/rpms/glibc-2.5-34.1AXS3.x86_64.rpm is not owned by any package
[root@dhcp23 rpms]# rpm -qf --provides /bin/ls
config(coreutils) = 5.97-12.1
fileutils = 5.97
sh-utils = 5.97
stat
textutils = 5.97
coreutils = 5.97-12.1

</>       
rpm -q --requires glibc-devel-2.5-18.1AXS3   


