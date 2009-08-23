//>>>I am doing the following test on 65, which is a SP1.
1. first we see old rpm does not require nss and nspr
[root@dhcp16 RPMS]# rpm -q --requires rpm
/bin/bash
/bin/sh
/bin/sh
/bin/sh
/bin/sh
beecrypt >= 4.1.2
config(rpm) = 4.4.2-37.1AX
fileutils
libbeecrypt.so.6()(64bit)
libbz2.so.1()(64bit)
libc.so.6()(64bit)
libc.so.6(GLIBC_2.2.5)(64bit)
libc.so.6(GLIBC_2.3)(64bit)
libdl.so.2()(64bit)
libelf.so.1()(64bit)
libm.so.6()(64bit)
libpopt.so.0()(64bit)
libpthread.so.0()(64bit)
libpthread.so.0(GLIBC_2.2.5)(64bit)
librpm-4.4.so()(64bit)
librpmbuild-4.4.so()(64bit)
librpmdb-4.4.so()(64bit)
librpmio-4.4.so()(64bit)
librt.so.1()(64bit)
libselinux.so.1()(64bit)
libsqlite3.so.0()(64bit)
libz.so.1()(64bit)
popt = 1.10.2
rpmlib(CompressedFileNames) <= 3.0.4-1
rpmlib(VersionedDependencies) <= 3.0.3-1
rtld(GNU_HASH)
shadow-utils
2. but new one(on beta5) does
[root@dhcp16 RPMS]# rpm -qp --requires rpm-4.4.2.3-9.2AXS3.x86_64.rpm
/bin/bash
/bin/sh
/bin/sh
config(rpm) = 4.4.2.3-9.2AXS3
coreutils
crontabs
libbz2.so.1()(64bit)
libc.so.6()(64bit)
libc.so.6(GLIBC_2.2.5)(64bit)
libc.so.6(GLIBC_2.3)(64bit)
libc.so.6(GLIBC_2.3.4)(64bit)
libc.so.6(GLIBC_2.4)(64bit)
libdl.so.2()(64bit)
libelf.so.1()(64bit)
libm.so.6()(64bit)
libnspr4.so()(64bit)
libnss3.so()(64bit)
libnssutil3.so()(64bit)
libplc4.so()(64bit)
libplds4.so()(64bit)
libpopt.so.0()(64bit)
libpthread.so.0()(64bit)
libpthread.so.0(GLIBC_2.2.5)(64bit)
librpm-4.4.so()(64bit)
librpmbuild-4.4.so()(64bit)
librpmdb-4.4.so()(64bit)
librpmio-4.4.so()(64bit)
librt.so.1()(64bit)
libselinux.so.1()(64bit)
libsqlite3.so.0()(64bit)
libz.so.1()(64bit)
logrotate
popt = 1.10.2.3-9.2AXS3
rpm-libs = 4.4.2.3-9.2AXS3
rpmlib(CompressedFileNames) <= 3.0.4-1
rpmlib(PayloadFilesHavePrefix) <= 4.0-1
rtld(GNU_HASH)
[root@dhcp16 RPMS]#    
3. old nss also provide libnss3.so()(64bit) but not libnssutil3.so()(64bit)
[root@dhcp16 RPMS]# rpm -q --provides nss|grep "libnss3.so()(64bit)"
libnss3.so()(64bit)
[root@dhcp16 RPMS]# rpm -q --provides nss|grep "libnssutil3.so()(64bit)"
[root@dhcp16 RPMS]# rpm -q --provides nss|grep "libnssutil3.so()(64bit)"
4. however new package has it
<>
[root@dhcp16 RPMS]# rpm -qp --provides nss-3.12.2.0-2AXS3.x86_64.rpm|grep "libnssutil3.so()(64bit)"
libnssutil3.so()(64bit)
</>    

5. that's why axtu will add nss as rpm dep,    
6. and nss has dep on nspr
<>
[root@dhcp16 RPMS]# rpm -qp --requires nss-3.12.2.0-2AXS3.x86_64.rpm|grep "nspr"
libnspr4.so()(64bit)
nspr >= 4.6.99
</>        
