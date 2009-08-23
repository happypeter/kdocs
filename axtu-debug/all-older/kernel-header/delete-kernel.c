see ./self-update/selfupdate.c first
With 1.5.0 11Ax axtu installed, and RPM installed first
bug#6369 Axtu deletes old kernel when updating kernel.
is still here.
>>>according to my former test, if we use 1.4 axtu, there is no such problem,
so it seems my patch is to blame.
NOTE: no! it is not my patch, it's Jongwoo's obselete tags patch
>>>if we only click kernel, then kmod-redcalstle will be add as dep.
I guess it is only because axtu decide to rpm -U kernel,
thus the old kernel will be remove, since old redcastle dep on old kernel,
so axtu decide to update redcastle as well, it is actually the right thing to do.
otherwise, we simple has a broken redcastle installed.
But why kernel is updated, now?
ANSWER: see jongwoo's patch below to know why.
>>>based on the os just full-updated by 219, I rpm -e 128kernel
and then update again using axtu. old kernel are still there!!
And I am just using 11AXaxtu+newrpms

>>>Using a JI sys, connect to 219(using 11AX axtu+rpms)
1. click kernel on updatelist, then redcastle is added as dep
according to my earlier test, if I continue, old kernel will be deleted.
2. click kmod only, then the right kernel and app pam will be added as dep
   click go, old kernel is still there-------so my patch works
   but old redcastle is removed--------------bad, bad
3. rpm -e kernel-128 --nodeps
4. update kernel only, old kernel is deleted!!!

>>>
1. add in int classRpmEngine::AddInstallElement(rpmts ts, Header h, const fnpyKey key, rpmRelocation *relocs, int nUpgrade)
nUpgrade=1;
click kernel, then kmod is added.
2. now nUpgrade=0,
kmod is not added.
old kernel NOT deleted.
3. add nothing
kmod is not added.
old kernel NOT deleted.--------sys only has 53 kmod mow
update kmod--------53 kmod is NOT deleted
NOTE: the above two lines is due to I do "make install" to update axtu, thus Jongwoo's patch is ignored.

>>>so now the conclution is 
On my systerm I have 
53 kernel & 53 kmod-----------they are not a pair, cause the earlier kernel is deleted before.
128 kernel & 128 kmod
I rm the 128 pair.
then click kernel to update it only,
everything is OK, I can not reproduce the "delete old kernel problem"
>>>>have the above in mind, and now I will get a brandnew JI sys to test
ok, i click kernel
kmod
pam 
app
manger
are all added as dep
1. so I click "cancle" not to install it
2. the I svn co 1.5----11AX source is got
3. make install
4. click kernel->no dep->install done->53 kernel still there!!!
5. so I install 219 axtu 11AX again, using --force.
7. then deps again!!!
8. so cd 1.5&&make install-->53 kernel still there!!!
9. so I install 219 axtu 11AX again, using --force. again
10.deps again. God!
11.I clearly remember the 11AX axtu on 219, I compile it myself on pluto
12.why the difference between "make install" and "rpm -Uvh"?
NOTE: Jongwoo applied 5 patches, "make install" does not give a shit to patches
Below is from one of his patches
<>

@@ -2772,6 +2777,15 @@ int classRpmEngine::AddInstallElement(rp

        }

+       if (g_bObsoleteCase1Upgrade == true) {
+               nUpgrade = 1;
+               g_bObsoleteCase1Upgrade = false;
+       }
+       if (g_bObsoleteCase2Upgrade == true) {
+               nUpgrade = 1;
+               g_bObsoleteCase2Upgrade = false;
+       }
+
        int rc=0;

        rc = rpmtsAddInstallElement(ts, h, key, nUpgrade ,relocs);

</>
13. so I remove this lines form Jongwoo's patch, then login pluto, and get a 12AX axtu
14. no deps--------53 kernel still there!!!
15. rm 128 kernel, click 128 kmod only, then I got this
<>


[root@dhcp29 ~]# rpm -qa|grep axtu
axtu-authen-client-gui-1.5.1-2AXS3
axtu-gui-1.5.0-12AXS3
axtu-tui-1.5.0-12AXS3
axtu-devel-1.5.0-12AXS3
axtu-authen-client-libs-1.5.1-2AXS3
axtu-libs-1.5.0-12AXS3
axtu-common-info-1.0-3AXS3
axtu-debuginfo-1.5.0-12AXS3
axtu-authen-client-tui-1.5.1-2AXS3
[root@dhcp29 ~]# rpm -qa|grep kernel
kernel-doc-2.6.18-53.11AXS3
kernel-headers-2.6.18-53.11AXS3
kernel-xen-devel-2.6.18-53.11AXS3
kernel-xen-2.6.18-53.11AXS3
kernel-2.6.18-128.5AXS3
kernel-2.6.18-53.11AXS3
kernel-devel-2.6.18-53.11AXS3
[root@dhcp29 ~]# rpm -qa|grep kmod
kmod-redcastle-3.0.2-21.2.6.18_128.5AXS3
kmod-redcastle-3.0.2-6.2.6.18_53.11AXS3

</>
which means everything is perfect
