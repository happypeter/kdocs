>>>so now at git commit " mem leak on xenls! by adding a new vector in classRpmengine"
see the error-message ../others/mem-leaking.e
I can not test my code in xen machine any more.
And what I want origially out of this commit is actually:
1. change the code but still ganrentee (kmod-redcastle dep kernel)&&( knernel-doc shall update)
//this seems works here with the patch, I test it carefully the code is right
//but when I have the vm machine I will test it again but updating kmod-redcalstle.
2. If I click sos on install list, it should be updated
//no working, why?
solved with this patch
<>
-	m_vectorUpdateList.insert(m_vectorUpdateList.begin()+nCount, *(itInstall--));
+	m_vectorUpdateList.insert(m_vectorUpdateList.begin()+nCount, *(itInstall));
</>
Now the things in m_vectorObsoleteToUpdate.push_back(*itInstall); is right 
and they are
<>
08/14/09 06:31:30 ppppp----it->strName--- zabbix-web-mysql
08/14/09 06:31:30 ppppp----it->strName--- zabbix-web-mysql
08/14/09 06:31:30 ppppp----it->strName--- compat-dapl
08/14/09 06:31:30 ppppp----it->strName--- compat-dapl
08/14/09 06:31:30 ppppp----it->strName--- libdhcp-devel
08/14/09 06:31:30 ppppp----it->strName--- libdhcp-devel
08/14/09 06:31:30 ppppp----it->strName--- sos
</>
what is obsoleted by zabbix-web-mysql, is installed so zabbix-web-mysql is right here.
compat-dapl obsoletes udapl which is not installed, so why it is here?
A: it's because compat-dapl obsoletes another pkg named dapl, which is installed
so this means my OB patches can actually handle more than 1 ob case.Great.

>>>
another interesting thing is dbus-glib-devel is actully also detected as a case above.
since it obsoletes dbus-devel, which is installed. but we have now
<current local status>
[root@dhcp17 ~]# rpm -q --qf '%{obsoletes}\n' dbus-glib-devel
dbus-devel
dbus-devel
[root@dhcp17 ~]# rpm -qa|grep dbus-devel
dbus-devel-1.0.0-6.3.i386
dbus-devel-1.0.0-6.3.x86_64
[root@dhcp17 ~]#
</>
so axtu can not find it on install list, so CopyObsoleterFromInstallToUpdate() fails to cp it to update list
but since dbus-glib-devel it self is installed, so it will natrually be on update list.
so even though the local status is buggy, and axtu got confused at some steps, but finally everything true out right
next time user try to update dbus-glib-devel, dbus-devel will be removed naturally, so the local systerm error is fixed.
>>>
