Now I want to do it with a hello world
1. we have only one file named "hello.c"
2. we make a Makefile.am
<>
bin_PROGRAMS            = hello
hello_SOURCES           = hello.c
</>
3. we need a configure.ac
4. people say we can get it using autoscan, but I failed
5. so I copy one from a online hello example.
7. run $autoreconf -fvi
8. configure&&make--------done
9. see ../others/hello1/

>>>now we work on ../others/hello2/
I add this line
CFLAGS="$CFLAGS -O2 -Wall -Wno-implicit -static"
into configure.ac
then 
./configure
make



>>>static-compile
<>
[root@dhcp25 test-hello2]# ls
aclocal.m4      config.h       config.sub    hello     install-sh   ltmain.sh  Makefile.am
autom4te.cache  config-h.in    configure     hello.c   libhello.a   main.c     Makefile.in
bootstrap       config.log     configure.ac  hello.lo  libhello.la  main.o     missing
config.guess    config.status  depcomp       hello.o   libtool      Makefile   stamp-h1
[root@dhcp25 test-hello2]# gcc -g -o xxx main.o  -L. libhello.a
[root@dhcp25 test-hello2]# ldd xxx
        libc.so.6 => /lib64/libc.so.6 (0x0000003523200000)
        /lib64/ld-linux-x86-64.so.2 (0x0000003522e00000)
</>
<>
[root@dhcp25 hello]# ldd hello
        libc.so.6 => /lib64/libc.so.6 (0x0000003523200000)
        /lib64/ld-linux-x86-64.so.2 (0x0000003522e00000)
</>



>>>now we cp hello2 test-hello2
1. ./bootstrp
2. ./configure
3. make
4. then we have
<>
[root@dhcp25 test-hello2]# ls
aclocal.m4      config.guess  config.log     configure     hello     hello.o      libtool    main.o       Makefile.in
autom4te.cache  config.h      config.status  configure.ac  hello.c   install-sh   ltmain.sh  Makefile     missing
bootstrap       config-h.in   config.sub     depcomp       hello.lo  libhello.la  main.c     Makefile.am  stamp-h1
[root@dhcp25 test-hello2]# gcc -o xxx main.o -L.lib/ lhello
gcc: lhello: No such file or directory
[root@dhcp25 test-hello2]# gcc -o xxx main.o -L.lib/ -lhello
/usr/bin/ld: cannot find -lhello
collect2: ld returned 1 exit status
[root@dhcp25 test-hello2]# ls .libs/
hello  hello.o  libhello.a  libhello.la  libhello.lai  libhello.so  libhello.so.0  libhello.so.0.0.0
[root@dhcp25 test-hello2]# cp .libs/libhello.a  .
[root@dhcp25 test-hello2]# gcc -o xxx main.o -L. -lhello
[root@dhcp25 test-hello2]# ldd xxx
        libc.so.6 => /lib64/libc.so.6 (0x0000003523200000)
        /lib64/ld-linux-x86-64.so.2 (0x0000003522e00000)
[root@dhcp25 test-hello2]# ldd .libs/hello
        libhello.so.0 => not found
        libc.so.6 => /lib64/libc.so.6 (0x0000003523200000)
        /lib64/ld-linux-x86-64.so.2 (0x0000003522e00000)
[root@dhcp25 test-hello2]# gcc -o ggg main.o -L. libhello.a
[root@dhcp25 test-hello2]# ldd ggg
        libc.so.6 => /lib64/libc.so.6 (0x0000003523200000)
        /lib64/ld-linux-x86-64.so.2 (0x0000003522e00000)
</>
5. so we know how to use a libhello.a now
