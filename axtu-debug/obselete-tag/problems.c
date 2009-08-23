>>>
P1:
when pump-devel is installed, and libdhcp-devel is on axtu install list, you click libdhcp-devel,
and it will get installed, no conflicts no warning, pump-devel will not be removed.
But if libdhcp-devel is on update list, pump-devel will be removed, which is right.
A1: I think it is all about the flag: nUpdate in axtu, so shall be not difficult to solve,
an I can refer to oopsless update patches.
the right logic shall be if A obsoletes B, 
if(B)
	update A no matter it is on update-list or installist
if(!B)//nothing we need to do, just consider A as a nomarmal pkg
	if(A)
		now A is on update-list, just update it
	if(!A)
		now A shall only on installist, just install it.

>>>
P2: 
if A obsoletes B, the first time axtu will remove B from both lists,
but when A get installed, ReadHeader() can not get ob info in A hdr any more, so B will show up on the lists again.
Big problem. So maybe we need to query local db before :CreateUpdateInstallList()

this is just what they are talking about here:
https://bugzilla.redhat.com/show_bug.cgi?id=486566
<>
http://rpm5.org/cvs/fileview?f=rpm/CHANGES&v=1.2288.2
5.1.5 -> 5.1.6:
 - jbj: generate Obsoletename index in rpmdb.
</>
<>
https://bugzilla.redhat.com/show_bug.cgi?id=486565
Comment #2 From  Jeff Johnson  2009-02-20 19:14:28 EDT  -------

Obsoletes are not saved persistently, and are applied only as an event in the
current transaction. RPM has always behaved this way ...  
</>
//I don't understand why Jeff said this, because I can find ob info easily
<>
[root@dhcp17 rpm2html-1.8.3]# rpm -qa --obsoletes|grep sysr
(none)sysreport
[root@dhcp17 rpm2html-1.8.3]#   
</>
>>>
P3:
if people are using jhtu, if B+ is on installist while A&&!B==true, in thi`s case, if user click B+,
will it be updated as it should? it seems jhtu does not concern about this.

A: No, he has CheckObsoleteToUpdate() to do the job.
I've tested it. when sysrport is installed, sos will show up on install-list, this is OK, but when I click sos to install it
there will be file conflicts with sysreport. in the same case, I click libdhcp-devel, there is no conflicts,but pump-devel
is not removed, which is wrong. So no matter on update or install list, obsoleters should always be Updated. 
But if the obsoleted is not installed, it is OK, to treat obsoleter as normal package and install it.

>>>
P4:
after git commit " sos and libdhcp-devel are on Update list now, Hooray..."
sos and dhcp-devel are copy to update list, which is good.
but when you want to set them blacklisted, you can not find them, maybe I need to change gui/setup/
A: axtu just works this way, see peki/axtu-debug/blacklist/1.c

>>>
P5:
at git commit " mem leak on xenls! by adding a new vector in classRpmengine"
we have only x86_64 pump-devel installed, on install list we have libdhcp-devel of two platform, which is right
but on update list we only have i386 libdhcp-devel, and 2 of the same thing! 
A: this is easy to fix, add arch check inside CopyObsoleterFromInstallToUpdate()
