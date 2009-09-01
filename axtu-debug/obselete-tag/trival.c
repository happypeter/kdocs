>>>>
when ob info is considered, the available number for notifer also changed,
 but I will not consider it until the main flow works fine
 if (m_rpmEngine->WriteNotifierInfo(m_nUpdateCount) == false)
>>>>
in oopslee's patch he ApplyObsoleteTag inside CreateUpdateInstalllist, which is quite good
but I can not do this easily since I have to get ob info from ReadHeader(), which is called after
CreateUpdateInstalllist.
<>
@@ -941,6 +947,8 @@ bool classRpmEngine::CreateUpdateInstall
       }
     }

+       ApplyObsoleteTag();
+
</>
Now the question is Can I mv ReadHeader() before CreateUpdateInstall in classGui?
A:No, at least not easy. since ReadHeader() does not read all hdr, but these from
nRet = m_Network->GetHeaders(vectorUpdate, vectorInstall);
so ReadHeader() dep on the output of CreateUpdateInstall(), so basiclly imporssible to 
mv it before CreateUpdateInstall().

>>>>so B obsletes A, B shall be on both install and update lists,
but even user click B on install list, B shall be updated.
axtu-1.5-obsolete-upgrade.patch seems to be related to this issue
>>>the rpm we use for ax3sp2, gives no warning when you install sos on a system having sysrport already installed.
How about the lastest rpm?
>>>never forget during dep check, it A requires B, which B obsoletes C, will axtu handle it properly?
>>>.
https://bugzilla.redhat.com/show_bug.cgi?id=200643
 Bug 200643 -  (yum-arch-obsolete) Obsoletes processing should be arch-aware 

>>>axtu-deamon requires modification
ApplyObsoletes() need to be added
like what I do to classGui.cpp,
this going to be easy, and tester can not found the trival update avaulable number any time soon:-)

>>>
JeongHong use CheckKernel() inside classRpmEngine::AddInstallElement(, it's cute, I want it too.
>>>
Since I now add CheckKernel inside AddInstallElement(), so I can remove some calls of CheckKernel() in
many functions, because these functions end up calling AddInstallElement(). 
