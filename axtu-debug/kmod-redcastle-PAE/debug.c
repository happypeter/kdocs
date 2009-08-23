>>>classRpmEngine.cpp-------Check(), WriteLog()
gui\axtu\classGui.cpp

Now I am trying to upgrade from
kmod-redcastle-3.0.2-6.2.6.18_53.11AXS3.i686.rpm
to
kmod-redcastle-3.0.2-9.2.6.18_53.14AXS3.i686.rpm


>>>error is 
Required Packages were not found see /var/log/axtu/error.log
<pre>
04/23/09 14:48:34 classRpmEngine Can not find the required package. DepCount=6, DepTotalCount=2
04/23/09 14:48:34 classRpmEngine        kernel-i686 = 2.6.18-53.14AXS3 is needed by kmod-redcastle-3.0.2-9.2.6.18_53.14AXS3.i686
04/23/09 14:48:34 classRpmEngine        redcastle-data >= 3.0.2-9 is needed by kmod-redcastle-3.0.2-9.2.6.18_53.14AXS3.i686
04/23/09 14:48:34 classRpmEngine        redcastle-manager >= 3.0.2-9 is needed by kmod-redcastle-3.0.2-9.2.6.18_53.14AXS3.i686
04/23/09 14:48:34 GUI Reqiured Packages were not found. (Package Requirement Loop) See /var/log/axtu/error.log
</pre>

>>>Normally axtu function this way

if(dep files in repo)
{
show_list_and_go();
}
else
error("...no found..");

>>>so when I add data and manager and 14AX kernel to the repo:
<pre>
04/23/09 17:39:55 classRpmEngine 	kernel-i686 = 2.6.18-53.11AXS3 is needed by (installed) kmod-redcastle-3.0.2-6.2.6.18_53.11AXS3.i686
04/23/09 17:39:55 classRpmEngine 	xen-hypervisor-abi = 3.1 is needed by (installed) xen-3.0.3-41.7AXS3.i386
</pre>


>>>Now even the 11AX kernel is in repo, the error remains:
04/23/09 18:23:27 classRpmEngine 	kernel-i686 = 2.6.18-53.11AXS3 is needed by (installed) kmod-redcastle-3.0.2-6.2.6.18_53.11AXS3.i686

* why is that axtu will check dep for old version of kmod-redcastle and even xen?
ANSWER: it is because when you use axtu this way(click kmod-redcastle, without clicking kernel), axtu will "rpm -U kernel", rather than "rpm -i kernel", and when '-U' axtu will try to remove 11AXkernel and xen-kernel, xen-hypervisor-abi is part of xen kernel.

>>>LUCILY LiShu helped me, and now all is clear!
<pre>
[root@localhost ~]# rpm -Uvh kernel-2.6.18-53.14AXS3.i686.rpm kmod-redcastle-3.0.2-9.2.6.18_53.14AXS3.i686.rpm redcastle-data-3.0.2-9.i386.rpm redcastle-manager-3.0.2-9.i386.rpm --test
error: Failed dependencies:
        xen-hypervisor-abi = 3.1 is needed by (installed) xen-3.0.3-41.7AXS3.i386
[root@localhost ~]# rpm -q --provides kernel|grep xen
kernel(rhel5_drivers_xen_core_ga) = 5308a7766723999bbea99a33dde1bbb76fee41ca
[root@localhost ~]# rpm -q --provides kmod-redcastle|grep xen
[root@localhost ~]# rpm -q --provide kernel|grep xen
--provide: unknown option
[root@localhost ~]# rpm -q --provides kernel|grep xen
kernel(rhel5_drivers_xen_core_ga) = 5308a7766723999bbea99a33dde1bbb76fee41ca
[root@localhost ~]# rpm -q --provides kernel-xen|grep xen
kernel-i686 = 2.6.18-53.11AXS3xen
xen-hypervisor-abi = 3.1
kernel(rhel5_arch_i386_mach_xen_ga) = f140ac8f99498655de6d2128067bff4946e3cbcf
kernel(rhel5_drivers_xen_core_ga) = 3c32f30960da8b0ab4909edc7fee3014160332e9
kernel-xen = 2.6.18-53.11AXS3
</pre>

>>>Now I click both kernel and kmod-redcastle, so everything works in a right way.
* that means when you click sth, axtu will check its mame, see if it is a kernel

----------------->


<pre>
 int nRet = CheckKernel(strName1);
        if (nRet == 0)
        {
                nUpgrade = 0;
                m_bKernelInstall = true;
        }

</pre>


rc=AddInstallPackage(m_rpmTs, it->strFile, it->nUpgrade);
</PRE>
/*!
@brief Add package to install or update.

Add Install or Update package to ts.
If there are same package diffrent arch will be install or update.

@param upgrade  0:install 1:upgrade(old version package will be delete).
@return 0 is ok.
*/
int classRpmEngine::AddInstallPackage(rpmts ts, const char * file, int upgrade)
{
</PRE>

result = DealwithDependence(m_rpmTs, probs);
is in Check()
but we did sth to kmod-redcastle before that, so is it still in the scope of DealwithDependence()?

* so it seems to me that all i need to do is to add "CheckKernel" some where
* NOTE: there will be a kmod-kvm is sp2--------Hold this for now.
*
>>>
the kernelCkeck() must be done 
**after** 
"Select Package"
vectorFileInfo = m_rpmEngine->GetUpdateList()
ShowList()
Do you want to Update?

**before**
showHideBox.SetMessage(tr("Dependency files exist!  Do
 you want continue?"));
DealwithDependence


>>>

 if (item->isOn() == true)
* then the package will be added by Addfile
*  if(m_rpmEngine->AddFile(strFullPath.c_str(), UPDATE, 1) != 0)
*  * thus the kernelCheck will be carried out, 
*  * that's why when you click kernel, then it will be installed 

>>>
GetAddedKmodRedcastleFile()
CheckKmodRedcastle()------is based on------vector<structAddedFile>::iterator it;
RemoveKernelAndKmodRedcastle(int nType)--------- vector <structAddedFile> vectorTemp;
GetKmodRedcastleName


------------->
         result = m_rpmEngine->Check();
 error message "Reqiured Packages were not found. (Package Requirement Loop) See %1%2" shows up acording to the return value.

so the -9 error is generated by 
DealwithDependence(m_rpmTs, probs);
and it must due to the param
m_rpmTs
is it generated in
AddInstallPackage(m_rpmTs, it->strFile, it->nUpgrade);
* when I change "nUpgrade" to 1, that means install everything
* Now the error is just as what I expected---same as "rpm -Uvh kernel kmod-xxx"
* but when I change it to 0, 
* the error is like "rpm -U kernel",---just like the one when we change noting
* rather than "rpm -i kernel kmod-xxx"---no error in this case
* so it seems to me that there is no need to modify nUpgrade
* 

So I need do sth to it.
 vectorInstall = GetAddedFile(UPDATE | REQDEP | OTHERDEP , vectorInstall);

