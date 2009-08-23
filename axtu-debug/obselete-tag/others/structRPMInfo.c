now I want to add char **obsoletename in to this struct.
so now my quetions is it worth all the trouble? is this the right way to do it?
so here I am to see the flow of this struct.
>>>it make sense, if "char **obsoletename" is added in rpminfo, I can add sth like 
int classRpmEngine::GetRequiredPkgFromRemote(rpmProblem prob, struct structRPMInfo *result)
within DealwithDependence(), sth like removeobsoltedpkgfromlocal()


>>>now my question is that is there sth concerning obsoletes in
rpmProblem
see rpm/lib/rpmps.h, then I know rpmProblem does not care about obsoletes.
but it is OK, I can add my own ob processing function in DealwithDependence()
>>>
in OpenHeader()
 structRPMInfo * rpmInfo = GetHeaderInfo(h, 9, nIndex);
 m_vectorRPMInfo.push_back(rpmInfo);
so we have  m_vectorRPMInfo finally

>>>now I see 
int classRpmEngine::ReadHeaders()
we read out all the hdr info of all the pkgs clicked and store all the hdr info into m_vectorRPMInfo
1. classRpmEngine::FindHeaderFromRemote() uses m_vectorRPMInfo, but itself is not called in rpmengine but 
   in classGui.cpp
2. GetFromRPMInfoListFromRemote() 
