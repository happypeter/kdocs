http://yum.baseurl.org/wiki/Faq
Q. 8: Yum is very nice at updating my kernel, but I use the (nvidia | openafs | other module) and yum doesn't seem to handle it well. Could you fix yum to handle this for me?

A. This is a known and non-trivial problem, but people are talking and working on it. Please read ideas on [WWW] this plugin and messages from [WWW] the Google search of the yum archives to get more details. 
Q. 9: How does yum handle updates/installs on x86_64 machines? ¶

A. There are times when it is beneficial to have both 32 and 64 bit versions of a package installed on a machine 
such as when another package only has a 32bit version and needs to access 32bit libraries of something that you
 would normally only install the 64bit package. So, if you do "yum install foo" then you will get both foo.i386.rpm
 and foo.x86_64.rpm installed on your system. This is the desired behavior in most cases even if it takes up more disk
 space. If you do a "yum install foo.x86_64" then you will only get the x86_64 package. 
>>>>>>>>>>>>.
http://yum.baseurl.org/wiki/YumPackageUpdates
above url page dicusses how yum obssoletes work
<sos.spec>
Provides: sysreport = 1.3.15-8
Obsoletes: sysreport
</>
http://yum.baseurl.org/wiki/YumCommands
yum list obsoletes
This command lists any obsoleting relationships between any available package and any installed package.
>>>>>
https://www.opensource.com/docs/en-US/Red_Hat_Enterprise_Linux/5/html/Deployment_Guide/c1-yum.html 
