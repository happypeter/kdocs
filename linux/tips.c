chmod -x filename -------to eleminate green color
>>>
>>>
cat /proc/cpuinfo
~
>>>
Ctrl+Alt+D-----------hide the active window
Ctrl+Alt+L-----------Lock thr current session
>>>
dhclient eth0-----------get IP

>>> ln -s /mnt/ubuntu vms
now I want to delete vms
<>
[root@dhcp25 ~]# rm -rf vms/
rm: cannot remove `vms/': Not a directory
[root@dhcp25 ~]# ls
15axtu-authen-client  Desktop  others  peki  s  test  vms
[root@dhcp25 ~]# unlink vms/
unlink: cannot unlink `vms/': Not a directory
</>

>>>symbolic links

<>
[root@dhcp16 test]# ls
d1  s2
[root@dhcp16 test]# file s2/
s2/: directory
[root@dhcp16 test]# rm -rf s2/
rm: cannot remove `s2/': Not a directory
[root@dhcp16 test]# ls d1/
d2
[root@dhcp16 test]# ls d1/d2/
ii
[root@dhcp16 test]# ls
d1  s2
[root@dhcp16 test]# ln -s  d1 s1
[root@dhcp16 test]# ls
d1  s1  s2
[root@dhcp16 test]# rm s1
rm: remove symbolic link `s1'? y
</>
so we can rm s1 easily,
<>
[root@dhcp16 test]# unlink s2/
unlink: cannot unlink `s2/': Not a directory
[root@dhcp16 test]# rm -rf s2/
rm: cannot remove `s2/': Not a directory
[root@dhcp16 test]# rmdir s2/
rmdir: s2/: Not a directory
</>
Now we see s2 is not easy to rm.
we can do it this way.
<>
[root@dhcp16 test]# cd d1/
[root@dhcp16 d1]# ls
d2
[root@dhcp16 d1]# mv d2/ d3
[root@dhcp16 d1]# cd ..
[root@dhcp16 test]# ls
d1  s2
[root@dhcp16 test]# rm s2
rm: remove symbolic link `s2'? y
[root@dhcp16 test]#               
</>
less /proc/cpuinfo
