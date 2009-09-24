Today Wenli asked me when axtu write success log, so I study here


it is done in gui/axtu/classGui.cpp
RpmLogging(nAction,strRpmName...
which is inside 
ShowCompleteMessage(
which is called by classGui::ShowFinishPage(int nErr)



int classGui::ProceedUpdate()
{
	result = m_rpmEngine->Check();
	nRet = m_rpmEngine->Run();
	ShowFinishPage(nRet);
}

>>>Another quetion is success log is written after "Removing old version of software.." or not ?

classRpmEngine::myRpmShowProgress(
{
g_callBackRun(int(((rpmcliProgressCurrent)*100. + nPercent)/rpmcliPackagesTotal), nPercent, "Installation progress
 g_callBackRun(nPercent, nPercent, "Removing old versio
}

since success log shall be written after "Installation"
so now it is obvious that it happens after "Removing.."
myRpmShowProgress is called in Run()
so now everything is clear!

>>>>>>>>>>>>one thing that confuse me is that how myRpmShowProgress works
how the parameter is passed
anyway it is the callback for rpmtsRun()
<axtu>
 rc = rpmtsRun(m_rpmTs, NULL, (rpmprobFilterFlags)probFilter);
</>
<rpm>
int rpmtsRun(rpmts ts, rpmps okProbs, rpmprobFilterFlags ignoreSet)
 * Get transaction flags, i.e. bits that control rpmtsRun().
 * Set transaction flags, i.e. bits that control rpmtsRun().
 * @warning This call must be made before rpmtsRun() for
./lib/rpmts.h
</>
<rpm>
[root@dhcp17 rpm-4.4.2.3]# xxx RPMCALLBACK_UNINST_STOP
    REGISTER_ENUM(RPMCALLBACK_UNINST_STOP);
./python/rpmmodule.c
                ptr = rpmtsNotify(ts, fi->te, RPMCALLBACK_UNINST_STOP, 0, 100);
            psm->what = RPMCALLBACK_UNINST_STOP;
./lib/psm.c
    case RPMCALLBACK_UNINST_STOP:
./lib/rpminstall.c
    RPMCALLBACK_UNINST_STOP     = (1 <<  9),
./rpmio/rpmmessages.h
[root@dhcp17 rpm-4.4.2.3]#
</>
