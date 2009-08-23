>>>now I want to write a hello world which link against librpm.so
<>
#include<rpm/rpmdb.h>
int main()
{

rpmdbMatchIterator mi;
rpmdbGetIteratorFileNum(mi);
}
</>

$gcc hellorpm.c -lrpm

then I got a a.out linked against librpm.so.


>>>
but how to static compile it, I think it is not simply add
CFLAG= -static
<>
[root@dhcp25 test]# gcc hellorpm.c -lrpm
[root@dhcp25 test]# gcc hellorpm.c -lrpm -static
/tmp/ccanKIN0.o: In function `main':
hellorpm.c:(.text+0xd): undefined reference to `rpmdbGetIteratorFileNum'
collect2: ld returned 1 exit status
</>
maybe its becausr "-lrpm" just means "librpm.so" not "librpm.a"

>>>
so Now I cp ../others/hello/
bootstrap  configure.ac   Makefile.am
and end up with a rpmdbGetIteratorFileNum not defined error as a expected
so I need to add -lrpm somewhere
so I study axtu/configure.ac
and finally add
AC_CHECK_LIB([rpm], [main],[],AC_MSG_ERROR([librpm not found!]))
it works
>now how to static compile
I add
CFLAGS="$CFLAGS -O2 -Wall -Wno-implicit -static"
No error, but the final binary still has dep on librpm.so
that's understandable, cause "-static" here only means if you have a source code for libhello.a
it will work for that, but not the for libc.so and other so form other place

<<<so I need to learn how to write configure.ac, so that the finally Makefile
can use librpm.a rather than so.

>>>The final Makefile is not very difficult, I see CFLAGS=-static -lrpm here.


>>>I copy all the rpm related .a libs int current location
<>
[root@dhcp25 test-hellorpm]# gcc -o xxx hellorpm.o -L.  -lrpm
hellorpm.o: In function `main':
/root/peki/autoconf/others/test-hellorpm/hellorpm.c:6: undefined reference to `rpmdbGetIteratorFileNum'
collect2: ld returned 1 exit status
[root@dhcp25 test-hellorpm]# gcc -o xxx hellorpm.o -L.  -lrpmdb
./librpmdb.a(rpmdb.o): In function `dbiIndexNewItem':
(.text+0x246): undefined reference to `vmefail'
./librpmdb.a(rpmdb.o): In function `rpmioFileExists':
(.text+0x260): undefined reference to `urlPath'
...
</>
1. obviously the function I use is defined in librpmdb.a
2. but lots of funtions in librpmdb.a,is defined in librpm.a
3. but when I add "-lrpm", it makes no dofference
4. gcc -static -o xxx hellorpm.o -L/usr/lib64  -lrpmdb -lrpm ------no difference

>>>
1. if we use 
$gcc -o xxx hellorpm.o -L/usr/lib64/  -lrpmdb
2. this means now we are using so 
3. it works, and the following may well explain why
<>
[root@dhcp25 test-hellorpm]# ls /usr/lib64/librpm
librpm-4.4.so       librpmbuild-4.4.so  librpmbuild.so      librpmdb.a          librpmio-4.4.so     librpmio.so
librpm.a            librpmbuild.a       librpmdb-4.4.so     librpmdb.so         librpmio.a          librpm.so
[root@dhcp25 test-hellorpm]# gcc -o xxx hellorpm.o -L/usr/lib64  -lrpmdb
[root@dhcp25 test-hellorpm]# gcc -o xxx hellorpm.o -L/usr/lib64  -lrpm
[root@dhcp25 test-hellorpm]# gcc -o xxx hellorpm.o -L/usr/lib64  -lrpmio
hellorpm.o: In function `main':
/root/peki/autoconf/others/test-hellorpm/hellorpm.c:6: undefined reference to `rpmdbGetIteratorFileNum'
collect2: ld returned 1 exit status
[root@dhcp25 test-hellorpm]# ldd /usr/lib64/librpmdb.so
        librpmio-4.4.so => /usr/lib64/librpmio-4.4.so (0x0000003525a00000)
        libpopt.so.0 => /usr/lib64/libpopt.so.0 (0x000000352e600000)
        libsqlite3.so.0 => /usr/lib64/libsqlite3.so.0 (0x0000003524e00000)
        libelf.so.1 => /usr/lib64/libelf.so.1 (0x0000003524a00000)
        libc.so.6 => /lib64/libc.so.6 (0x0000003523200000)
        libbeecrypt.so.6 => /usr/lib64/libbeecrypt.so.6 (0x0000003526200000)
        libm.so.6 => /lib64/libm.so.6 (0x0000003523600000)
        libdl.so.2 => /lib64/libdl.so.2 (0x0000003523a00000)
        libz.so.1 => /usr/lib64/libz.so.1 (0x0000003524200000)
        librt.so.1 => /lib64/librt.so.1 (0x0000003528e00000)
        libpthread.so.0 => /lib64/libpthread.so.0 (0x0000003523e00000)
        libbz2.so.1 => /usr/lib64/libbz2.so.1 (0x0000003531800000)
        libgcc_s.so.1 => /lib64/libgcc_s.so.1 (0x0000003524600000)
        /lib64/ld-linux-x86-64.so.2 (0x0000555555554000)
        libstdc++.so.6 => /usr/lib64/libstdc++.so.6 (0x0000003525600000)
[root@dhcp25 test-hellorpm]# ldd /usr/lib64/librpmio.so
        libbeecrypt.so.6 => /usr/lib64/libbeecrypt.so.6 (0x0000003526200000)
        libm.so.6 => /lib64/libm.so.6 (0x0000003523600000)
        libdl.so.2 => /lib64/libdl.so.2 (0x0000003523a00000)
        libz.so.1 => /usr/lib64/libz.so.1 (0x0000003524200000)
        librt.so.1 => /lib64/librt.so.1 (0x0000003528e00000)
        libpthread.so.0 => /lib64/libpthread.so.0 (0x0000003523e00000)
        libbz2.so.1 => /usr/lib64/libbz2.so.1 (0x0000003531800000)
        libgcc_s.so.1 => /lib64/libgcc_s.so.1 (0x0000003524600000)
        libc.so.6 => /lib64/libc.so.6 (0x0000003523200000)
        libstdc++.so.6 => /usr/lib64/libstdc++.so.6 (0x0000003525600000)
        /lib64/ld-linux-x86-64.so.2 (0x0000555555554000)
</>




>>> so now the question is we want to use 1.a which deps  on 2.a
how to do it?
