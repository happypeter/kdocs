Now wtih the rpm+5->50 tricks, things seems to be OK, so I want a real env test
>>>connect to 246 with JI sys
1. update perfect
2. there is NO "no space" error

>>>connect to 155, to update axtu to 12AX and installed the latast rpms
<>
(1)axtu-authen-client-gui-1.5.1-2AXS3.x86_64
(2)axtu-authen-client-libs-1.5.1-2AXS3.x86_64
(3)axtu-authen-client-tui-1.5.1-2AXS3.x86_64
(4)axtu-common-info-1.0-3AXS3.noarch
(5)axtu-devel-1.5.0-12AXS3.x86_64
(6)axtu-gui-1.5.0-12AXS3.x86_64
(7)axtu-libs-1.5.0-12AXS3.x86_64
(8)axtu-tui-1.5.0-12AXS3.x86_64
(9)nspr-4.7.3-2AXS3.x86_64
(10)nss-3.12.2.0-2AXS3.x86_64
(11)popt-1.10.2.3-9.2AXS3.x86_64
(12)rpm-4.4.2.3-9.2AXS3.x86_64
(13)rpm-build-4.4.2.3-9.2AXS3.x86_64
(14)rpm-devel-4.4.2.3-9.2AXS3.x86_64
(15)rpm-libs-4.4.2.3-9.2AXS3.x86_64
(16)rpm-python-4.4.2.3-9.2AXS3.x86_64
</>

>>>connect to 219 do full-update
1. show dep list
2. show conflicts only kernel-header
3. done

>>>now do all above again, but now testing single files on 219
1.dbus--------done: networkmanager, bind, added as dep 
2.kernel------done: old kernels Not removed
3.redcastle---NOT done: 
<local>
[root@dhcp29 ~]# rpm -qa|grep kmod
kmod-redcastle-3.0.2-6.2.6.18_53.11AXS3
kmod-redcastle-3.0.2-22.2.6.18_53.23AXS3
<local/>
<219>
0:kmod-redcastle-3.0.2-21.2.6.18_128.5AXS3.x86_64=kmod-redcastle-3.0.2-21.2.6.18_128.5AXS3.x86_64.rpm
<219/>
so kmod is not on update list!!!
3.0.2-22.2.6 is from 246. so 246 kmod version is higher then 219 kmod version, bad bad!
NOTE: Gloria and hwanii kmow this, since 219=B4, for beta5 we provide a 23-126 kmod, so this problem soloved.
anyway, I will remove kmod-redcastle-3.0.2-22.2.6.18_53.23AXS3 fist for test.
done: kernel added as dep, old kernel and kmod are safe!
4. anaconda----done:e4fspong added as dep
5. busybox--done
6. kernel-doc----installed, we should update it
7. kernel-devel----installed, as it should
8. kernel-xen&kernel-xen-devel----insatalled as they should
9. kernel-headers---should be updated.
NOTE: now I finished all kernel stuff, so I need to add exception for kernel-headers and kernel-doc.
things will work perfectly for b4. I do not need the long exception list in Ceckkernel()`:
10.elfutil-----done
11.glibc-------done with its deps, glibc-devel is added here cause it requires specific version of glibc
   this is just the kmod--kernel case
12.hal-done
13.nspr--devel-i386---------done
14.kdelib-i386--------------done
15.libselinux---------------donw
16.policycoreutils----------done
NOTE:until here all packags in 
Bug 6371 Cannot update lots of packages through axtu on x86_64 platform.
done.
17. now 508 packages left(start with 577), so I think the test is enough.


>>>>>>>>>>>>>>>13AX axtu
1. 246 first
2. 155 only do self-update, including rpm stuff
<>
(1)axtu-authen-client-gui-1.5.1-2AXS3.x86_64
(2)axtu-authen-client-libs-1.5.1-2AXS3.x86_64
(3)axtu-authen-client-tui-1.5.1-2AXS3.x86_64
(4)axtu-common-info-1.0-3AXS3.noarch
(5)axtu-devel-1.5.0-13AXS3.x86_64
(6)axtu-gui-1.5.0-13AXS3.x86_64
(7)axtu-libs-1.5.0-13AXS3.x86_64
(8)axtu-tui-1.5.0-13AXS3.x86_64
(9)nspr-4.7.3-2AXS3.x86_64
(10)nss-3.12.2.0-2AXS3.x86_64
(11)popt-1.10.2.3-9.2AXS3.x86_64
(12)rpm-4.4.2.3-9.2AXS3.x86_64
(13)rpm-build-4.4.2.3-9.2AXS3.x86_64
(14)rpm-devel-4.4.2.3-9.2AXS3.x86_64
(15)rpm-libs-4.4.2.3-9.2AXS3.x86_64
(16)rpm-python-4.4.2.3-9.2AXS3.x86_64
</>
3. 219 now
4. 128 kernel----done: no deps
<>
[root@dhcp18 ~]# rpm -qa|grep kernel
kernel-doc-2.6.18-53.11AXS3
kernel-xen-2.6.18-53.23AXS3
kernel-devel-2.6.18-53.23AXS3
kernel-2.6.18-128.5AXS3
kernel-xen-devel-2.6.18-53.11AXS3
kernel-xen-2.6.18-53.11AXS3
kernel-2.6.18-53.11AXS3
kernel-headers-2.6.18-53.23AXS3
kernel-xen-devel-2.6.18-53.23AXS3
kernel-2.6.18-53.23AXS3
kernel-devel-2.6.18-53.11AXS3
</>
5. kmod-redcastle
<>
[root@dhcp18 ~]# rpm -e kmod-redcastle-3.0.2-22.2.6.18_53.23AXS3
[root@dhcp18 ~]# rpm -e kernel-2.6.18-128.5AXS3
[root@dhcp18 ~]#     
</>
click kmod only, kernel is added as dep
<>
[root@dhcp18 ~]# rpm -qa|grep kernel
kernel-doc-2.6.18-53.11AXS3
kernel-2.6.18-128.5AXS3
kernel-xen-2.6.18-53.23AXS3
kernel-devel-2.6.18-53.23AXS3
kernel-xen-devel-2.6.18-53.11AXS3
kernel-xen-2.6.18-53.11AXS3
kernel-2.6.18-53.11AXS3
kernel-headers-2.6.18-53.23AXS3
kernel-xen-devel-2.6.18-53.23AXS3
kernel-2.6.18-53.23AXS3
kernel-devel-2.6.18-53.11AXS3
[root@dhcp18 ~]# rpm -qa|grep kmod
kmod-redcastle-3.0.2-6.2.6.18_53.11AXS3
kmod-redcastle-3.0.2-21.2.6.18_128.5AXS3
</> 
6. kernel-header&kernel-doc
before I do anyting. we have

<>
[root@dhcp18 ~]# rpm -qa|grep kernel-heade
kernel-headers-2.6.18-53.23AXS3
[root@dhcp18 ~]# rpm -qa|grep kernel-doc
kernel-doc-2.6.18-53.11AXS3
</>
do update, no conflicts, then we have 
<>
[root@dhcp18 ~]# rpm -qa|grep kernel-doc
kernel-doc-2.6.18-128.5AXS3
[root@dhcp18 ~]# rpm -qa|grep kernel-header
kernel-headers-2.6.18-128.5AXS3
</>
7. dbus---done, conflicts
8. elfutil--done
9. firefox---done
