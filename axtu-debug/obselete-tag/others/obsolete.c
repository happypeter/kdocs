RMTAG_OBSOLETENAME---------------python use this
for axtu I need 
headerGetEntry RPMTAG_OBSOLETES
http://riksun.riken.go.jp/pub/pub/Linux/vine/Vine-1.1/i386/misc/src/rpm/lib/depends.c
http://www.ibiblio.org/pub/historic-linux/distributions/redhat/5.0/i386/misc/src/rpm/
  if (headerGetEntry(h, RPMTAG_OBSOLETES, NULL, (void *) &obsoletes, &count)) {
>>>>>>
[root@dhcp03 ~]#  rpm -qa --qf '%{name}-------%{provides}------%{obsoletes}\n'|grep sos
sos-------sysreport------sysreport
>>>>>>>
https://bugzilla.redhat.com/show_bug.cgi?id=486565  
 Bug 486565 -  rpm -Uvh does not consider obsoletes  
rpm -Uvh sos
will give no warning, but sysrepot will be removed.
rpm -Uvh sysreport will give a file conflicts info, which is good
but if there is no cofilicting files, the obsoleted pkg will be installed
without any concern about the one that obsoletes it is already there.
see this for the reason:

<https://bugzilla.redhat.com/show_bug.cgi?id=486565>
Comment #2 From  Jeff Johnson  2009-02-20 19:14:28 EDT  -------

Obsoletes are not saved persistently, and are applied only as an event in the
current
transaction. RPM has always behaved this way ...  
</>

But as I know people are trying to add obsoletes into rpmdb(/var/lib/rpm).
<http://rpm5.org/cvs/fileview?f=rpm/CHANGES&v=1.2288.2>
5.1.5 -> 5.1.6:
 - jbj: generate Obsoletename index in rpmdb.
</>
so maybe in the futher rpm -Uvh can check the info here, to decide if the pkg is obsoleted or not.

