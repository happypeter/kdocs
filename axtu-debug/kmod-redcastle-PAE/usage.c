
useradd redcastle
passwd redcalstle

/usr/share/redcastle/sbin/mkinitdata -u redcastle -m enable

[root@dhcp29 ~]# service redcastle start

RedCastle doesn't support xen kernel.

so ZhuDan told me if I want to shift from "eable" to "warning"
I need to run
/usr/share/redcastle/sbin/mkinitdata -u redcastle -d
and 
service redcastle stop     (as root?)

Hwanii said he has some info that want to share with me about redcastle!

<>
  ------- Comment  #8 From xieyuhuan  2009-06-19 11:34:01  [reply] -------

I have found the reason of this bug,it is because redcastle-data.
When redcastle-data is in version 3.0.2-9,there is such problem;when
redcastle-data is in version 3.0.2-20 or higher,there is no problem.
I will attach what I did as attachment in detail.
So I change this bug to redcastle and since this problem has been solved by the
updated package redcaste-data-3.0.2-20,I think we can close this bug.
Thanks~~~~
</>
so I do not need to worry about this
 Bug 6388 Axtu cannot work with redcastle well now.
