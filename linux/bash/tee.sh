>>>Example 1

<s.sh>
echo "this is a test"
<s.sh/>
<run.sh>
sh s.sh |tee $1-log
<run.sh/>

<t>
[root@dhcp25 test]# ls
run.sh  s.sh
[root@dhcp25 test]# vim run.sh
[root@dhcp25 test]# ./run.sh axtu
this is a test
[root@dhcp25 test]# ls
axtu-log  run.sh  s.sh
[root@dhcp25 test]#                       
<t/>

>>>Example2

<s.sh>
ls |tee file.txt
<s.sh/>
it works

>>>this can be useful
ls|grep xxx|tee file
