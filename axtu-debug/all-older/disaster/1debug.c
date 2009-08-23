Yesterday hwanii creat a SP! xen machine
and full-update it with 246
but when you boot the sys again and run axtu update
there is still one paclage: gost-script left to update!
and when you try to update it it ends with a not enough disk space error.
even tough the current disk use is only 64%.
This is a liitle bug. And it is not my fault, cause what in use is the MT axtu
>>>
OK now I will continue, I connect xen to 219,
update axtu to Beta4 version 1.5.0-8AX
then run full-update again
now this error is in ../error_log1
1. so the error is mainly about 64bit libs,
   so I go and check and found they are all in /lib64
   so the problem is rpm can not find lib64/ now
ANSWER: the reason is clear when you $rpm -qa|grep glibc
	only 32bit glib is there! before connecting to 246, there were two.
	so 246 delete the 64glibc? not sure
>>>OK all the above I did to MT_2, Now I mv to another machine 
and try to do the same thing with MT axtu 
so I need to know how to stop self-update first
"rm all the rpms and run hsyumarch SELF on 219"
so error is exactly the same when I use the MT axtu

>>> but now the thing is maybe the MT xen machnie itself has problem
so I will use a just install version and try to update it with 246 first and the 219
and I will know if 219 is buggy
1. so I create JI_2(JustInstall), then use the MT axtu to full-update
   with 246, the installation is finished as I see, but after deleting old-versions, there is a error: No enough space for installation.
2. now I try 219 with the MT axtu, this time the symptom is different. Download file done, then dependency check done and
   show me the list. I press continue. the GUI give me a error message:" ...failed. "
   error log is in ../error_log2/
