https://bugzilla.redhat.com/show_bug.cgi?id=486566
   Description From  Nicolas Mailhot  2009-02-20 06:10:04 EDT

Since rpm sadly allows the installation of an obsoleted package on a system
that already includes the stuff obsoleting it (bug #486565), this situation
needs to be handled by yum.

Unfortunately since the obsoleting package is already installed on system yum
does not see the obsoleted package should be garbage collected and leaves it
installed.

This should be fixed
yum-3.2.21-9.fc11.noarch  

------- Comment #1 From seth vidal 2009-02-20 08:25:18 EDT -------

How did the obsoleted pkg get installed?  

------- Comment #2 From Nicolas Mailhot 2009-02-22 13:12:28 EDT -------

This is bug #486565 rpm lets users install already obsoleted packages with rpm
-Uvh without complaining at all  

>>>>
repodata/primary.xml.gz
rpm:obsoletes><rpm:entry name="sysreport"/></rpm:obsoletes>

so yum need to read info here to behave
$yum list obsolete

>>>>>>>>>what happens during "$yum list obsolete"
1. read 
http://127.0.0.1/peter-repo/repodata/primary.xml.gz
2. get obsoletes here and display it.
3. what is interesting in that I am not allowed to change primary.xml.gz,
otherwise I see "checksum failed", which is great
