>>>
ReadRemoteHeaderInfo()
ReadLocalHeaderInfo()
they generate
struct structHeaderInfo
{
        string strEpoch;
        string strNVRA;
        int nType;              
        bool bSelfUpdate;
};//in hscommon.c

to be used in CreateUpdateInstallList()
so ob info are not concerned here.
>>>
but as mentioned I can modify the lists brfore showList()

classGui::InitRpm()
{
vector <structFileInfo> vectorInstall = m_rpmEngine->GetInstallList();
 vector <structFileInfo> vectorUpdate = m_rpmEngine->GetUpdateList();
nRet = m_Network->GetHeaders(vectorUpdate, vectorInstall);
ReadHeaders()    //I want to modify this to add ob info to m_vectorRPMInfo
//I want to add ApplyObsoletes() to modify update and install list
}

SO we know ReadHeaders() does not read all hdr files, but if A obsolete sth, it must be presented in either
update or install list(more likely on install list), so I think no problem here.

>>>>Now let's code
so I add the framework of ApplyObsoletes() in 
classGui
classRpmengine

refer to ReadHeaders()
and it works well,
so now all I need to do is to implement 
int classRpmEngine::ApplyObsoletes()
to modify update and install lists.

