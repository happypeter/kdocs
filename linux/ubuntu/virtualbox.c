virtualbox

INStallation:

1. you have to issue $apt-get update   on a newly installed ubuntu 8.04/8.10

2. $apt-get install virtualbox

USAGE:

right Ctl to release to mouse

What you can do when virtualbox is naughty

alt+ctl+F1-------switch to tty0
alt+ctl+F7--------back to X
$ps aux | grep virtual | awk '{print $2}' | xargs kill -9     //kill virtualbox
virtualbox

===
I've done above successfully, but this time I failed since no kernel module is found, 
NOTE: the reason is my current kernel in use
peter@peter-dt:~/kdocs/linux/ubuntu$ uname -r
2.6.24-19-generic
is older then the virtual-box module


so I $sudo apt-get install virtualbox-ose-modules-generic
then 2.6.24-24-generic kernel and kernel-module are installed at the same time.

