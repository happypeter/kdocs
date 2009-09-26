http://yum.baseurl.org/wiki/WritingYumPlugins
I first check the above url and knows sth basic about

init_hook -------------<slotname>_hook

===
[root@dhcp08 yum-plugins]# pwd
/usr/lib/yum-plugins
[root@dhcp08 yum-plugins]# ls
hello.py  hello.pyc  installonlyn.py  installonlyn.pyc  installonlyn.pyo
===
vim /etc/yum/pluginconf.d/hello.conf  
===
now it works, haha
