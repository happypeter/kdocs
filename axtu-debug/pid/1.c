http://bugzilla.asianux.com/show_bug.cgi?id=6627
>>>
[root@dhcp17 tmp]# ./peter &
[2] 3400
[root@dhcp17 tmp]# pidof peter
3400 3399
[root@dhcp17 tmp]# pidof peter
3400 3399
[root@dhcp17 tmp]# killall peter
[root@dhcp17 tmp]# pidof peter
3399
[2]-  Terminated              ./peter
[root@dhcp17 tmp]# killall peter
[root@dhcp17 tmp]# pidof peter
3399
[root@dhcp17 tmp]# kill 3399
[root@dhcp17 tmp]# pidof peter
3399
[root@dhcp17 tmp]# ps aux|grep peter
root      3399  3.4  0.0   3608   272 pts/2    T    01:29   0:02 ./peter
root      3413  0.0  0.0  61928   708 pts/2    S+   01:30   0:00 grep peter
[root@dhcp17 tmp]# kill -KILL '3399
>
[root@dhcp17 tmp]# kill -KILL 3399
[root@dhcp17 tmp]# ps aux|grep peter
root      3451  0.0  0.0  61928   708 pts/2    S+   01:30   0:00 grep peter
[1]+  Killed                  ./peter
[root@dhcp17 tmp]#
>>>
say you have a program named peter, you can use this
# peter && ps -C peter | cut -d" " -f 1 > /var/run/peter.pid    
to creat a pid file, people say it is for the sake of sth like
<>
/usr/sbin/xinetd -stayalive -reuse -pidfile /var/run/xinetd.pid &
kill `cat /var/run/httpd.pid`
</> 
<>
What do you mean by it uses a pid file to start and stop services? A pid file doesn't start or stop anything, it's just a file with a number in it. It is kept in /var/run and is called by the name of the executable, plus a .pid extension. All it contains is the process id of the executable, which is the same thing ps will tell you when it lists it. Generally, programs which use pid files create one when they start, remove it when they quit, this way if you try running it again it will see that there's already a copy running by seeing the pid file and won't start a second copy as long as the pid file is there. If the program doesn't create the nessecary pid file, then without hacking it into the code, it's quite trivial to write a wrapper script around the program to create a pid file when it starts, delete it when it exits, and check that no pid file exists before allowing it to start. Check out the Advanced Bash Scripting Guide for more info about the scripting stuff
</>              

>>>but in the case of axtu, pid files are not necessary to check if the program is already running or not,
instead, if you vim /usr/bin/axtu
<>
pidcmd=`/sbin/pidof $CMD`
    if [ "$pidcmd" = "" ]; then
            exec $AXTUDIR/$ENV/$CMD &
    fi
</> 
simple enough
