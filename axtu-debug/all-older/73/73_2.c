>>>gloria report a bug full updating tar-os->219
"06/25/09 18:13:15 classRpmEngine Error is occured in rpmtsRun()"
see rpmtsRun.c for detail
but all the packages are installed. the last page shows "failed"
so hwanii want me do 3.0orig->246->219
1. now even connecting to 246, the "axtu-common-info" issue remain,
so I believe it is orig OS who is reponsible.
2. done with 246 no error, so I want to take a snopshot, but failed.
3. NOTE: axtu looks very ugly now. Nerver see this before
4. installation done with 219, now "removing old versions ..."
5. done without any error

>>>
Hwanii want to compare the difference between
peter: 3.0orig->246->219
glorai:tar-os->219
so I run on both platform
$rpm -qa|tee gloria.rpm
$rpm -qa|tee peter.rpm
then cp them to my machine
diff -u gloria.rpm peter.rpm >a.diff
two many difference!
so I 
[root@dhcp25 rpmdiff]# cat peter.rpm |sort|tee sort-peter.rpm

diff -u sort-gloria.rpm sort-peter.rpm >a.diff 
still many difference, but that is natrual, eg. there is no kernel-xen on 3.0orig
but sp1 has it.

>>>since gloria's error happens during removing old version of software, 
so now hwanii want to see if old version of packages are removed or not.
so I generate ../diff/xxx


