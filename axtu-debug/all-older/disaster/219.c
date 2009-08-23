see 246.c <***> first
1. so I left the glib2-devel unchanged
2. now I connect to 219
3. click glibc219--64bit, update done----great
4. 1.5 8AX axtu in use
5. then I try a full-update, since glibc is installed
   the error list is very short, the dbus and elfutil and
   sth like this
6. we know the dbus problem can be solved by changing dep 
   check loop form 5 to 50. and I know elfutil is related to dbus.
7. 5->50, full-update, the dbus error still there
8. but click dbu64 only, lots of dep is seen and all are installed properly.
9. then run full-update again, the error is mainly elfutil "transaction" issue.
10.then I suddenly rememeber, last time when I could update elfutil packages
   I update rpm itself beforehand.
11.so now I click rpm64, done with lots of deps
12.then run update again, now dep check passed, installation on going
13.I think it is a big breakthrough, new elf build with new rpm 
   so fail to add to transaction if axtu still use the old rpm,
   very good explanation to many problems.
14.Installation done with no error! only conflicts, including 
   my kernel-headers conflicts.NOTE: using 1.5 9AX axtu with 5->50
15.so now I think dbus can also be done in full-update, if only
   we install the latest rpm first. But I am not sure about glibc.
>>>>anyway we need to test again
1. I am using 15-8AX axtu, update with 246
2. expect for the kernel-header conflicts, everything is perfect, glibc64 are updated successfully
3. now move to 219 and update rpm first
4. 5 is still 5, I do not want to use 50 now
5. full-update
<error-log>
06/09/09 05:38:00 classRpmEngine        gtk-vnc = 0.3.2
is needed by gtk-vnc-python-0.3.2-3AXS3.x86_64
06/09/09 05:38:00 classRpmEngine        libgtk-vnc-1.0.s
o.0()(64bit) is needed by gtk-vnc-python-0.3.2-3AXS3.x86
_64
06/09/09 05:38:00 GUI Reqiured Packages were not found.
(Package Requirement Loop) See /var/log/axtu/error.log
<error-log/>
<debug>
6/09/09 05:37:51 classRpmEngine RPMPROB_REQUIRES Packag
eNEVR:virt-manager-0.5.3-10.1AXS3.x86_64,  AlterNEVR:R g
tk-vnc-python
06/09/09 05:37:51 classRpmEngine Find required packages
:  /var/cache/axtu/updates-released/packages/gtk-vnc-pyt
hon-0.3.2-3AXS3.x86_64.rpm
<debug/> 
6. great, no debus probelm
>>>let's do not wait, try 5->50 now
1. using 1.5-9AX axtu source code
2. go to tarball/axtu/, 5->50,and $make install
3. NOTE: this way we do have Jongwoo's patch in the binary.
4. full-update---->dep check passed--->Installing...
5. conflict list is given but is only about kernel-header---good
6. finally it end up with a "no enough space"
7. then run axtu -u again, only 4 packages left, three of them   are "zabbix" packages, which are marked incompatiable. the
   other is time-runner, I do not know why
8. anyway, big big success. 
