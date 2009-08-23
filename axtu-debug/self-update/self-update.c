Now we want to add rpm requires to axtu, so I need to know how self-update works.
>>>in the function check(), we see
<>
if (m_bSelfUpdate == true) // nodeps force option.
        {
                return 0;
        }
</>

that means if it is self-update, check will not be executed, thus even we add "Require: rpm>=xxx"
in axtu spec, dep check will not be carried out, since DealwithDependence() is called by check().

>>>
<>
 if (it->strName == "self")
                                {
                                        headerInfo.bSelfUpdate = true;
                                }

<>

>>>first I add 
<patch>
	%package gui
	Summary: Asianux TSN Updater graphical user interface
	Group: Utilities/System
	Requires : qt axtu-tui
+++	Requires: rpm >= 4.4.2.3
	Prereq: /sbin/chkconfig, /sbin/service

	%description gui
	Asianux TSN Updater graphical user interface
	%package tui
	Summary: Asianux TSN Updater textual user interface
	Group: Utilities/System
	Requires: newt axtu-libs
+++	Requires: rpm >= 4.4.2.3
	Obsoletes: hsupdater axtu

<patch/>

then i 
</>
[root@dhcp29 x86_64]# rpm -Uvh --test *
error: Failed dependencies:
        rpm >= 4.4.2.3 is needed by axtu-gui-1.5.0-19.x86_64
        rpm >= 4.4.2.3 is needed by axtu-tui-1.5.0-19.x86_64
</>
NOTE:
<> 
$rpm -qpR axtu-gui-1.5.0-19.x86_64.rpm
...
rpm >= 4.4.2.3
rpmlib(CompressedFileNames) <= 3.0.4-1
//--------------why is this???----see ../rpm-test.e to see the current rpm installed when building this package
rpmlib(PayloadFilesHavePrefix) <= 4.0-1
</>
>>> but anyway we need to modifiy the source to enable dep check
but the rediculous thing is when we try to update axtu, the axtu in charge is the old one
so no matter how we change the new axtu, old axtu will ignore dep check anyway.
> so maybe we can simply put rpm into self and update it the same time we update axtu.


>>>now I cp my 19 axtu to 246:UPDATE:
1. if you click gui,  then rpm will be updated together as dep
2. but if you only choose devel, no deps
3. usesually axtu-gui shall be dependent on axtu-lib, but we do not write it in SPEC

>>>

 if (it->strName == "self")
now I want to know why axtu packages are named "self"

it here is iterator of m_vectorCacheDirInfo, which is obtained in
ReadCacheDirInfo()
 m_vectorCacheDirInfo.push_back(cacheDirInfo);

we only concentrate on "strName"
cacheDirInfo.strName = *it;------another "it"
 m_rpmEngine->ReadCacheDirInfo(CONFIG_FILE);
./gui/axtu/classGui.cpp
#define CONFIG_FILE             "/etc/axtu/axtu.conf"

so now we know the answer
 as long as the package is in SELF dir on server
>>>but why when I put apr-xxx.rpm into SELF and run yumarch, then still only axtu packages are show on slefupdate list.
Let's hack
<>
if (it->strName == "self")
                                {
                                        headerInfo.bSelfUpdate = true;
                                }

</>
since the above is in a while loop, I know it marks all packages in SELF/ as "bSelfUpdate = true"
should including my apr.

then "itRemote" is the iterator of "m_setRemoteHeaderInfo.insert(headerInfo)"
so we have itRemote->bSelfUpdate
then finally it is used in
<> AddUpdateInstallList(&fileInfo,strNameR, \
                                                strVerR,strRelR,itRemote->strEpoch, \
                                                strArchR,itRemote->nType,       \
                                                itRemote->bSelfUpdate, CheckSmp(strNameR));
</>
so now I understand why my apr is not on the self-update list.
it is simply because it is not newer then local apr.
so I cp the rpm-4.4.2.3-9.2AXS3.x86_64 into SELF
and it shows up on the list with all axtu packages! great.

>>>so I click yes, since selfupdate use force nodeps, so everyting is installed 
try to update elfutil----failed 
so maybe i need to put all rpm's deps into SELF
<>
(1) rpm-devel-4.4.2.3-9.2AXS3.x86_64 [Selected package]
(2) nss-3.12.2.0-2AXS3.x86_64 [Dependency package]
(3) popt-1.10.2.3-9.2AXS3.x86_64 [Dependency package]
(4) rpm-libs-4.4.2.3-9.2AXS3.x86_64 [Dependency package]
(5) nspr-4.7.3-2AXS3.x86_64 [Dependency package]
<>
so when I installed the above package, then 
elfutil----done
glibc------done
notification-deamo--done
Networkmanger-glib----failed
>so I make install 1.5 11AX axtu------(5->50 inside)
Networkmanger-glib-----done---(dbus added as deps)
kernel128-------done-----(old 53 kernel is still there)
//but maybe I need to update my os with 246 first, then test kernel again
kernel-headers-----------done(conflicts are still there)
e2spong-lib----------done
>>>OK now I think everything is OK, so I need to cp 11AX axtu and all rpm deps to 219/SELF
and test again
OK, I need 64bit axtu, so I ssh pluto(10.1.0.3)
NOTE: you do not need to reboot axtu manually, the auto restart is enough to use new epmlib.so
test again:
elfutil-----done
glibc------done
notification-deamo--done
Networkmanger-glib----done---(dbus added as deps)
kernel------all redcastle packages is added as deps, and old kernel is removed.
and old redcastle is also removed, crazy!!
full-update now-------failed with some libdbus.so problem.
connect to 246--ful-update------failed with only kernel problem--so it is ok
>>>now use a brandnew JI sys
1. update 246
2. connect to 219, fullupdate, when selfupdate axtu and rpm packages, no conflicts error
3. dep chceck passed, conflicts show up, but its only kernel-headers, nothing else
4. installation finished, no error, "no space" when removing old package
5. only kernel-devel is left.
6. old kernel and kmod are still there.
so I think now the RPM update issue is done.
I need to concentrated on kernel-delete problem, see ../delete-kernel/
