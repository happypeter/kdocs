glibc is reponsible for "libc.so.6 ..." errors
and it looks horriable, so I'd better fix it first.
>>>
1. so I first update sys with 246
2. then click glibc 64 on the update list connecting to 219
3. dep file list is given 
4. installed perfectly

>>>
then how comes dbus can not find glibc as dep file
Now if you update dbus, the libc problem is no longer there,
then though, we see
<>
06/02/09 06:43:29 classRpmEngine Can not find the required package. DepCount=15, DepTotalCount=1
06/02/09 06:43:29 classRpmEngine        libnssutil3.so()(64bit) is needed by NetworkManager-glib-0.7.0-4.1AXS3.x86_64
06/02/09 06:43:29 classRpmEngine        bind = 30:9.3.3-10.5AXS3 is needed by (installed) bind-chroot-9.3.3-10.5AXS3.x86_64
06/02/09 06:43:29 classRpmEngine        bind = 30:9.3.3-10.5AXS3 is needed by (installed) caching-nameserver-9.3.3-10.5AXS3.x
86_64
06/02/09 06:43:29 GUI Reqiured Packages were not found. (Package Requirement Loop) See /var/log/axtu/error.log
</>
When you update NetworkManager-glib only you will see the "bind", problem,
so now the problem is simply why dus depend on NetworkManager-glib.

