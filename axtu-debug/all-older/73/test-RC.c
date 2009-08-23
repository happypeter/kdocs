Hwanii's test case:
1. from 3.0 oig directly to 250(RC)
2. do part update then full update
3. do part install then full install
4. do all above to i386 and x86_64 
5. then use gloria tar-os to do it.
/////////////////////////////////////////
>>>>>>>>>HERE x86: 3.0ori->250<<<<<<<<<<<<
////////////////////////////////////////
>>>14AX axtu with all rpm packages
1. cp all 14AX axtu to 250 x86/SELF
2. the success log
<>
06/23/09 23:54:00 Updated asianux-rpm-config-6.0-7AXS3.noarch
06/23/09 23:54:00 Updated axtu-authen-client-gui-1.5.1-2AXS3.i386
06/23/09 23:54:00 Updated axtu-authen-client-libs-1.5.1-2AXS3.i386
06/23/09 23:54:00 Updated axtu-authen-client-tui-1.5.1-2AXS3.i386
06/23/09 23:54:00 Updated axtu-devel-1.5.0-13AXS3.i386
06/23/09 23:54:00 Updated axtu-gui-1.5.0-13AXS3.i386
06/23/09 23:54:00 Updated axtu-libs-1.5.0-13AXS3.i386
06/23/09 23:54:00 Updated axtu-tui-1.5.0-13AXS3.i386
06/23/09 23:54:00 Updated nspr-4.7.3-2AXS3.i386
06/23/09 23:54:00 Updated nspr-devel-4.7.3-2AXS3.i386
06/23/09 23:54:00 Updated nss-3.12.2.0-2AXS3.i386
06/23/09 23:54:00 Updated nss-devel-3.12.2.0-2AXS3.i386
06/23/09 23:54:00 Updated nss-tools-3.12.2.0-2AXS3.i386
06/23/09 23:54:00 Updated popt-1.10.2.3-9.2AXS3.i386
06/23/09 23:54:00 Updated prelink-0.4.0-2AXS3.i386
06/23/09 23:54:00 Updated rpm-4.4.2.3-9.2AXS3.i386
06/23/09 23:54:00 Updated rpm-build-4.4.2.3-9.2AXS3.i386
06/23/09 23:54:00 Updated rpm-devel-4.4.2.3-9.2AXS3.i386
06/23/09 23:54:00 Updated rpm-libs-4.4.2.3-9.2AXS3.i386
06/23/09 23:54:0:0 Updated rpm-python-4.4.2.3-9.2AXS3.i386
06/23/09 23:54:00 Updated rpmtools-0.3-31AXS3.i386
</>
CORRECTION: here I forget to run "hsyum-arch SELF", so 14AX axtu is actually not installed
but since i<n<x, so system-netboot-noarch is not a problem here.
3. then self-update again for 
06/23/09 23:55:16 Updated axtu-common-info-1.0-3AXS3.noarch
4. compare it with ../self-update/self_x86_64.list-------there is no asianux-rpm-config in our list, other packages are OK.
5. system-config-netboot and openib are on update list.
6. click both and do update-----done perfectly
7. full update
8. sysreport conflicts shows up-----Jongwoo will patch for this soon
9. continue and update is done perfectly
10.self-update 14AX axtu and then click to install ant and axis---done
11.full-install----done perfectly
12.one thing worth nothing is that now the axtu gui looks ugly, reboot machine, it is pretty again.
/////////////////////////////////////////
>>>>>>>>>HERE x86_64: 3.0ori->250<<<<<<<<<<<<
////////////////////////////////////////
1. click self-update then I see a "unknow error occur"
2. click again and the error is gone
3. now
<success-log>
06/23/09 22:34:23 Updated asianux-rpm-config-6.0-6AXS3.noarch
06/23/09 22:34:23 Updated axtu-authen-client-gui-1.5.1-2AXS3.x86_64
06/23/09 22:34:23 Updated axtu-authen-client-libs-1.5.1-2AXS3.x86_64
06/23/09 22:34:23 Updated axtu-authen-client-tui-1.5.1-2AXS3.x86_64
06/23/09 22:34:23 Updated axtu-devel-1.5.0-13AXS3.x86_64
06/23/09 22:34:23 Updated axtu-gui-1.5.0-13AXS3.x86_64
06/23/09 22:34:23 Updated axtu-libs-1.5.0-13AXS3.x86_64
06/23/09 22:34:23 Updated axtu-tui-1.5.0-13AXS3.x86_64
06/23/09 22:34:23 Updated nspr-4.7.3-2AXS3.i386
06/23/09 22:34:23 Updated nspr-4.7.3-2AXS3.x86_64
06/23/09 22:34:23 Updated nspr-devel-4.7.3-2AXS3.i386
06/23/09 22:34:23 Updated nspr-devel-4.7.3-2AXS3.x86_64
06/23/09 22:34:23 Updated nss-3.12.2.0-2AXS3.i386
06/23/09 22:34:23 Updated nss-3.12.2.0-2AXS3.x86_64
06/23/09 22:34:23 Updated nss-devel-3.12.2.0-2AXS3.i386
06/23/09 22:34:23 Updated nss-devel-3.12.2.0-2AXS3.x86_64
06/23/09 22:34:23 Updated nss-tools-3.12.2.0-2AXS3.x86_64
06/23/09 22:34:23 Updated popt-1.10.2.3-9.2AXS3.i386
06/23/09 22:34:23 Updated popt-1.10.2.3-9.2AXS3.x86_64
06/23/09 22:34:23 Updated prelink-0.4.0-2AXS3.x86_64
06/23/09 22:34:23 Updated rpm-4.4.2.3-9.2AXS3.x86_64
06/23/09 22:34:23 Updated rpm-build-4.4.2.3-9.2AXS3.x86_64
06/23/09 22:34:23 Updated rpm-devel-4.4.2.3-9.2AXS3.i386
06/23/09 22:34:23 Updated rpm-devel-4.4.2.3-9.2AXS3.x86_64
06/23/09 22:34:23 Updated rpm-libs-4.4.2.3-9.2AXS3.i386
06/23/09 22:34:23 Updated rpm-libs-4.4.2.3-9.2AXS3.x86_64
06/23/09 22:34:23 Updated rpm-python-4.4.2.3-9.2AXS3.x86_64
06/23/09 22:34:23 Updated rpmtools-0.3-31AXS3.x86_64
</>
4. cp 14AX axtu to 250/x86_64
<>
06/23/09 22:45:52 Updated axtu-common-info-1.0-3AXS3.noarch
06/23/09 22:45:52 Updated axtu-devel-1.5.0-14AXS3.x86_64
06/23/09 22:45:52 Updated axtu-gui-1.5.0-14AXS3.x86_64
06/23/09 22:45:52 Updated axtu-libs-1.5.0-14AXS3.x86_64
06/23/09 22:45:52 Updated axtu-tui-1.5.0-14AXS3.x86_64
</>
5. compare with ../self-update/self_x86_64.list
two issue: 1. hwanii did not cp asianux-rpm-config-7AX  here
           2. there is no asianux-rpm-config in ../self-update/self_x86_64.list
6. system-config-netboot and openib are on update list.
7. click both and do update-----done perfectly
8. full-update-------perfectly done
9. click to install ant and axis---done
10.full-install----done perfectly
>>>>>>>>>>>>>>Now MT tar os<<<<<<<<<<<<<<<<<<<<<
1. luner----30sp1090709.tar-------is the modified tar-os
2  sh mtt_load_sys.sh -di -t 30sp1090709.tar  -p /dev/sdb1.
4. it does not work well so I 
<>
mount /dev/sdb1 /opt/
cd /
tar xvf 30sp1090709.tar
</>
I see "time in the future"
when I do tar xvf 
then I said to Lishu why we do not touch *
Lishu said it is stupid cause time stamp is useful
<>
touch ll
find . -newer ll
</>
5. finally Lishu gave up so I just continue with this little problem
6. Quan Wenli said she would give another tar-os based on May one, which has no time-stamp problem, so I need to wait. 
