SSH keys

1. on my laptop as common user peter

$ ssh-keygen -t dsa

then i shall have in /home/peter/.ssh a pair of keys   (public key: id_dsa and private key: id_dsa.pub)

2. now on romi
#mkdir peter/.ssh
copy my public key here with the name authorized_keys

3. now I can login romi safer with my ssh keysd
//login for the first time I need to type 111111 to active to key
//but if I need to login in other machines I still need the former passwd: peter1983

4. when I reinstall my local OS, I need to do the above 3 step again.
but when I am trying to copy sth form romi to my local machine, I see warning related to romi: ./ssh/knownhost
the solution is simply deleting this file, it will be created again automatically


HOW  to open ssh ports in ubuntu
$ sudo apt-get install openssh-server

$sudo /etc/init.d/networking restart

ON  fedora or asianux
#service sshd start/status/stopo
#vim /etc/ssh/sshd_config


>>>how to login 155 conviniently
1. on ubuntu as root user, issue
$ssh-keygen
2. copy the pub key to 155 as its authorized_keys
3. on ubuntu
$vim /etc/hosts
add
10.1.0,155    test
4. then we can login with
$ssh test
without using passwd

>>>starting ssh on Asianux
1. vim /etc/ssh/sshd_config
   change the correaponding line into
<>
#PermitRootLogin no
PermitRootLogin yes
</>

2. service sshd start

3. chkconfig --level 345 sshd on ----------set boot time start
4. done


>>>when I try to ssh 67, which is the new vmware machine on 73.
I see this
<>
[root@dhcp25 ~]# ssh 10.1.0.56
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@    WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED!     @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
IT IS POSSIBLE THAT SOMEONE IS DOING SOMETHING NASTY!
</>

1. on my local machine
2. vim /root/.ssh/known_hosts
3. delete the key for fomer 67 machine.(it was for former xen machine)-----it just conflicts with the new 67 machine.
4. done.
