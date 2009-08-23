see peki/linux/asianux/vmware.c
/root/peki/axtu-debug/self-update/list.c
>>>Now 
1. cp all the beta5 x86_64 packages into UPDATE/
NOTE: hwanii said he wanted all the old packages, do not remove the old packages(from AX3.0 orig) to make
the server the same as TSNHQ
2. 
<>
[root@dhcp16 RPMS]# pwd
/var/www/html/auth/asianux2/AXS3/x86_64/SELF/RPMS
[root@dhcp16 RPMS]# mv ../../UPDATE/RPMS/axtu* .  
</>
3. mv  ../../UPDATE/RPMS/rpm-4.4.2.3-9.2AXS3.x86_64.rpm .
4. [root@dhcp16 RPMS]# mv asianux-rpm-config-6.0-6AXS3.noarch.rpm ../../SELF/RPMS/
it is not a rpm deps but looks so related, haha
5. mv nss-3.12.2.0-2AXS3.x86_64.rpm  ../../SELF/RPMS/-----------this is not very clean, since there are lots of
    other packages, depending on nss. like nss-devel ...
6. [root@dhcp16 RPMS]# mv nspr-4.7.3-2AXS3.x86_64.rpm  ../../SELF/RPMS/
7. [root@dhcp25 Desktop]# scp *.rpm 10.1.0.65:/root/x86_64/SELF/RPMS/
root@10.1.0.65's password:
axtu-1.5.0-13AXS3.src.rpm                                                                  100% 1737KB   1.7MB/s   00:00
axtu-debuginfo-1.5.0-13AXS3.x86_64.rpm                                                     100% 2166KB   2.1MB/s   00:00
axtu-devel-1.5.0-13AXS3.x86_64.rpm                                                         100%   67KB  67.5KB/s   00:00
axtu-gui-1.5.0-13AXS3.x86_64.rpm                                                           100%  729KB 729.0KB/s   00:00
axtu-libs-1.5.0-13AXS3.x86_64.rpm                                                          100%  513KB 513.0KB/s   00:00
axtu-tui-1.5.0-13AXS3.x86_64.rpm                                                           100%  832KB 831.9KB/s   00:00
8.done

>>>>Now I want to test x86_64 orig-->beta5
1. this is the success-log
<>
06/23/09 03:59:20 Updated asianux-rpm-config-6.0-6AXS3.noarch
06/23/09 03:59:20 Updated axtu-authen-client-gui-1.5.1-2AXS3.x86_64
06/23/09 03:59:20 Updated axtu-authen-client-libs-1.5.1-2AXS3.x86_64
06/23/09 03:59:20 Updated axtu-authen-client-tui-1.5.1-2AXS3.x86_64
06/23/09 03:59:20 Updated axtu-devel-1.5.0-13AXS3.x86_64
06/23/09 03:59:20 Updated axtu-gui-1.5.0-13AXS3.x86_64
06/23/09 03:59:20 Updated axtu-libs-1.5.0-13AXS3.x86_64
06/23/09 03:59:20 Updated axtu-tui-1.5.0-13AXS3.x86_64
06/23/09 03:59:20 Updated nspr-4.7.3-2AXS3.x86_64
06/23/09 03:59:20 Updated nss-3.12.2.0-2AXS3.x86_64
06/23/09 03:59:20 Updated rpm-4.4.2.3-9.2AXS3.x86_64
</>
2. unfortunatelly axtu-common-info is left, so you start axtu, it will do self-update again.
it only install one package, then after another restart it is OK now.
3. 852 to update-->full-update-->inconpitibal package+obselte-tag shows up-->going...
4. Note in the success log there is no rpm-lib, so we end with a "required packages not found problem"
5. the error message is long, it is just like the error when "rpm not updated" 
6. Now I see
<>
[root@dhcp01 axtu]# rpm -qa|grep rpm
rpm-build-4.4.2-37.1AX
rpm-devel-4.4.2-37.1AX
rpmtools-0.3-24AX
rpm-4.4.2.3-9.2AXS3
rpm-libs-4.4.2-37.1AX
rpm-libs-4.4.2-37.1AX
rpm-python-4.4.2-37.1AX
libeasyrpm-0.3-5
asianux-rpm-config-6.0-6AXS3
rpm-devel-4.4.2-37.1AX
[root@dhcp01 axtu]#            
</>
two rpm-libs here------------one for x86, another for x86_64!!
>>>>suddenly I found there is no rpm-lib on 65:/SELF/
so I 
<>
[root@dhcp16 RPMS]# mv rpm-devel-4.4.2.3-9.2AXS3.x86_64.rpm ../../SELF/RPMS/
[root@dhcp16 RPMS]# mv rpm-libs-4.4.2.3-9.2AXS3.x86_64.rpm ../../SELF/RPMS/
</>
7. dep check passed, installing all the 850 packages...

8. done with no error
9. check
<>
[root@dhcp01 ~]# rpm -qa|grep kernel
kernel-devel-2.6.18-128.6AXS3
kernel-2.6.18-8.10AX
kernel-2.6.18-128.6AXS3
kernel-headers-2.6.18-128.6AXS3
kernel-devel-2.6.18-8.10AX
kernel-doc-2.6.18-128.6AXS3
[root@dhcp01 ~]# rpm -qa|grep kmod
kmod-redcastle-3.0.0-8.2.6.18_8.10AX
kmod-redcastle-3.0.2-23.2.6.18_128.6AXS3
[root@dhcp01 ~]#
</>
10. reboot----ok
>>>recover a brandnew x86_64 machine and test self-update,
1. "axtu-common-info is left" problem is still there, but Hwanii think it's OK
2. dep check passed, I think other things will all be OK.

>>>>until here, the x86_64 orig-->beta5 test is over.
the conclution is "NO PROBELM"
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
>>>now for x86 platform , will do orig-->RC test instead.
1. there is no /var/axtu/ on orig version on both 32 and 64 platform
2. I have difficulties connecting to 65. here in x86 platform
3. one thing is I mv redflag to wtec in db:connect_info
4. another is I use .../asianux/...  rather than ../asianux2/... as path in db:connect_info
5. fix the above 2 issue, the axtu register is done.
6. cp all the RC packages into UPDATE/
7. cp RPM packages into SELF/, according to /root/peki/axtu-debug/self-update/7list.c
8. when selfupdate is done, the error is "authentification failed"
9. I think this is because I fogot to copy axtu-authen-client into SELF
10. do it----and go back to fresh OS snapshot and test
11. like x86_64. the "axtu-common-info is left" problem is  there
12. dep check passed, installation on going...
13. now this message
<>
  file /usr/sbin/sysreport conflicts between attempted installs of sysreport-1.4.3-13.el5.1AXS3.noarch and sos-1.7-9.16
.2AXS3.noarch
 file /usr/share/sysreport/functions conflicts between attempted installs of sysreport-1.4.3-13.el5.1AXS3.noarch and s
os-1.7-9.16.2AXS3.noarc
</>
obselte tag maybe.
14. restore snapshot, and do everything again. then I see the "axtu-common-info" again, and I see,
<>
sysport is removed ...
pupm-devel is removed...
</>
>>>>>>>>>using a Just installed xen x86_64 sp1
1. connect to 246->full update->done
2. switch to 219->selfupdate
I see prelink and all the i386 packages during selfupdate, that means it is our final self-update solution
3. full update all the RC packages->end up with a "no enough space for installation error", kedlib is left unupdated.
4. do the whole process over again using vmware sp1, done without any error.
