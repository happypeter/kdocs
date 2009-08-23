in configure.ac
I found CFLAG


in ./libs/Makefile.am
libaxtu_shared_la_LIBADD = wget/libhswget.la

>>>/root/1.5/tarball01/axtu/libs/libaxtu_shared.la
# Libraries that this one depends upon.
dependency_libs=' -L/usr/lib64 -ldl -lssl -lrt -lrpm -lpopt -lnewt 

>>>I delete all the Makefile.in, then run
aclocal
autoheader
autoconf
automake  ----------------input:Makefile.am Output:Makefile.in
--
./conigure----------------input:Makefile.in Output:Makefile
make
compilation done.

>>>
<>
[root@dhcp25 lib64]# ls libaxtu_
libaxtu_authen_client_shared.a         libaxtu_authen_client_shared.so.0.0.0  libaxtu_shared.so.0
libaxtu_authen_client_shared.la        libaxtu_shared.a                       libaxtu_shared.so.0.0.0
libaxtu_authen_client_shared.so        libaxtu_shared.la
libaxtu_authen_client_shared.so.0      libaxtu_shared.so
[root@dhcp25 lib64]# file libaxtu_shared.so
libaxtu_shared.so: symbolic link to `libaxtu_shared.so.0.0.0'
[root@dhcp25 lib64]# file libaxtu_shared.so.0.0.0
libaxtu_shared.so.0.0.0: ELF 64-bit LSB shared object, AMD x86-64, version 1 (SYSV), stripped
[root@dhcp25 lib64]# file libaxtu_shared.a
libaxtu_shared.a: current ar archive
</>
