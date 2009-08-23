>>>Now I want to reproduce what Gloria did, so I made a MT sys like her, on a vmware machine
see ../tar-os.c
I take a snapshot and continue.
>>>246
1. only 19 packages in update list
2. done full-update perfectly
>>>219
1. 593 packages left
2. machine died during installaton
3. abandon ship

>>>restore the snapshot do with 219 directly(Hwanii told me this is actully what gloria did)
machine dead during installation.
>>>see hwanii-scrip.c
now on a real machine tar-os, the error happens at the last second of "Removing old version..."
the GUI error is "Update has failed!"
error log is simple: "classRpmEngine Error is occured in rpmtsRun()"

>>>Now in a fresh tar-os, connecting to 246
1. 19 packages left to update
2. do full update
3. done perfectly
4. now move to 219
5. update four samba packages first---no error
6. do full-update---same error
>>>I use a xen machine sp1 systerm and do 219 full update-----no error


>>>Li shu came just now and brought big news
1. he believe the rpmtsRun() error is due to the execution of uninstall scirpt failed during some package are remvoed
   and the reason fall into the following two issues:
2. so he think we need to update glibc first, before everything just like RPM packages, we need to put it into self as well
3. we need to touch all the files in the tar os, to correct all the time error.
NOTE: when I succefully make in vmware sp1->246->219, Lishu gives up the glibc theory, but he insists the whlole thing is
not axtu but MT os problem, and the probelm is about time stamp.
He also mention to me that the glibc theory still worth noting in the future. Since when developer team build a new major 
version of ISO, they update there things first:gcc, glibc, and rpm.

