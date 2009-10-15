===
http://yum.baseurl.org/wiki/Faq
Q. 8: Yum is very nice at updating my kernel, but I use the (nvidia | openafs | other module) and yum doesn't seem to handle it well. Could you fix yum to handle this for me?

A. This is a known and non-trivial problem, but people are talking and working on it. Please read ideas on [WWW] this plugin and messages from [WWW] the Google search of the yum archives to get more details.

===

<http://docs.fedoraproject.org/yum/en/sn-yum-customizing.html#sn-yum-configfiles>
[Note]	Plugin Installed by Default

Fedora Core includes the installonlyn plugin. This plugin modifies yum to remove excess kernel packages, so that no more than a set number of kernels exist on the system. By default, installonlyn retains the two most current kernels, and automatically removes older kernel packages. 
</>
