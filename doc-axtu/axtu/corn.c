http://en.wikipedia.org/wiki/Cron
Cron enables users to schedule jobs (commands or shell scripts) to run automatically at a certain time or date
>>>basiclly corn is used in axtu to run 
 /usr/share/axtu/tui/axtu-cl -d --random=150 -y
at a certain interval of time
>>>
[root@dhcp17 etc]# rpm -qa|grep cron
crontabs-1.10-8.noarch
anacron-2.3-45.1AXS3.x86_64
vixie-cron-4.1-72AXS3.x86_64
lime-cron-0.9.12-1AXS3.x86_64
[root@dhcp17 etc]# rpm -ql crontabs-1.10-8.noarch
/etc/cron.daily
/etc/cron.hourly
/etc/cron.monthly
/etc/cron.weekly
/etc/crontab
/usr/bin/run-parts
[root@dhcp17 etc]# cd /etc/cron.daily
Now we see axtu,corn here
>>>>>>>>
[root@dhcp17 ~]# ps aux | grep crond
root      2251  0.0  0.0  75556  1132 ?        Ss   01:24   0:00 crond
root      5097  0.0  0.0  61928   712 pts/4    S+   03:25   0:00 grep crond
>>>>>>>>>>detailed usage go here
http://www.unixgeeks.org/security/newbie/unix/cron-1.html
