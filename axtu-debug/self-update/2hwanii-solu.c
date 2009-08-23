>>>now hwanii want this
1. do NOT add reguires in SPEC
2. change source code, make axtu install rpm before any other package

>>>so in gui/main.cpp
we first check()
then run()
so we can just do sth in check(), add "rpm newer version check",  like what is done to axtu self-update
1. during generating updateinstallist, if "rpm-" is found, rm all other packages form updateinstallist
2. continue, let dep check be carried out in Check();
3. install rpm and all its deps, then go back to updateinstallist generating.

>>>how to restart axtu
<>
QMessageBox::information(this, staticTitle, tr("The TSN Updater has been updated.  It must restart."));
                delete m_rpmEngine;
                m_rpmEngine = NULL;
<\>

>>>engine1.diff, is made
so that I see the lastest version of rpm in error-log

>>>now I get ../others/d1.diff, so now
1. when axtu find rpm on update list, it will stop CreatUpdateinstalllist()
2. then go to classGui.cpp, restart axtu
3. the problem is restart again and again, because rpm can not be installed.

>>>NOW, one question is that do we really need to reboot axtu to use new rpmlib.so.
the real question is that Is so lib  alway  in memory, when its caller is running?
1. I think the answer is YES, cause axtu-pmengine use a lot of functions in rpmlib.so.
2. so before the class rpmengine is "delete"ed, rpmlib.so shall be in memory as well.

>>>so if we reboot axtu for rpmlib, I think the warning message would better be 
"axtu requires a newer version of rpm to function properly, plz click Yes to install rpm and restart axtu"

&&&---%%%% see 3jun-sulo.c to continue
