>>>
[root@dhcp17 ~]# rpm --querytags|grep OBS
OBSOLETENAME
OBSOLETES
OBSOLETEFLAGS
OBSOLETEVERSION
[root@tsnlocaltest RPMS]# rpm -qp --qf '%{NAME}--%{OBSOLETES}-%{OBSOLETEVERSION}\n' libdhcp-devel-1.20-6AXS3.x86_64.rpm
warning: libdhcp-devel-1.20-6AXS3.x86_64.rpm: V3 DSA signature: NOKEY, key ID a83bd72e
libdhcp-devel--pump-devel-0.8.24
>>>so I need to hacking down to see how rpm do this
NOTE: here upper case =lower case e.g OBSOLETES=obsoletes
>>>anyway with a modified version of headerDump()  I can get obsoletename(and obsolete versoion and tag, if I want)
now we have
  structRPMInfo * rpmInfo = GetHeaderInfo(h, 9, nIndex);
now it seems natrue to add my getObsoleteName() into GetHeaderInfo(), so that means we need to add fileds in structRPMInfo(defined in hscommon.h).
such as "obsoletename","obsoleteversion"
see ../ structRPMInfo.c for detail
>>>now the big problem is when we generate updatelist, we only read UPDATE.header.info
this way we can not handle ob(=obsolete), that means if 
Case1. A1.1 obsoletes A1.0&B1.0, but there is B1.1 available,
then B1.1 will show up on update list, which is not good.
Case2. A1.1 obsoletes B1.0, but there is no B1.1 in repo, then no update available for B
which is not true sine A1.1 is there, it is only that axtu can not add A1.1 since there is no A1.0.

for C1, we can still handle by removing B1.1 later, but How to handle C2? so that means we have to do sth
before updatelist is generated.

>>>so what when need to do is
1. read hdr info before generating update list, solve the C1 and C2 problem
2. when user see update list and click C2-A1.1, tell user B1.0 will be removed.
