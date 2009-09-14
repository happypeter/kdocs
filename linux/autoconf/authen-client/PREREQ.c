== AC_PREREQ(2.59) ==

<shell>
[root@dhcp17 bin]# autoconf -V
autoconf (GNU Autoconf) 2.59
</>

so 2.59 is currently installed on my os/
then I change in congiure.ac

<diff>
---AC_PREREQ(2.59)
+++AC_PREREQ(2.60)
</>

now the error when I run autoconf

<shell>
[root@dhcp17 axtu-authen-client]# autoconf
configure.ac:4: error: Autoconf version 2.60 or higher is required
configure.ac:4: the top level
autom4te: /usr/bin/m4 failed with exit status: 63
[root@dhcp17 axtu-authen-client]# man autoconf
</>

for manpage I know autoconf is used only to make a "configure" file out of "configure.ac"
m4 is called during this process, natrually
