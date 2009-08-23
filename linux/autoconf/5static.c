<>
[root@dhcp25 ~]# gcc -static hello.c
[root@dhcp25 ~]# ldd a.out
        not a dynamic executable
[root@dhcp25 ~]# file a.out
a.out: ELF 64-bit LSB executable, AMD x86-64, version 1 (SYSV), for GNU/Linux 2.6.9, statically linked, for GNU/Linux 2.6.9, not stripped
[root@dhcp25 ~]# du a.out
576     a.out
[root@dhcp25 ~]# gcc hello.c -o a2.out
[root@dhcp25 ~]# du a2.out
8       a2.out

</>
>>>now how to compile rpm.a in(there is no .la for rpm, so libtool may not work well)


>>>another sulution is that
since axtu static linked in wget, we can use same method to link in rpm
