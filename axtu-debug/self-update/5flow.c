NOTE: so finally I do not need to modified the code to update RPM,
all i need to do it cp them to SELF/, so this doc is not very useful now

>>>in Check()
we have
vectorInstall = GetAddedFile(UPDATE | REQDEP | OTHERDEP , vectorInstall);
for(it=vectorInstall.begin();it!=vectorInstall.end();it++)
rc=AddInstallPackage(m_rpmTs, it->strFile, it->nUpgrade);

then "m_rpmTs" is given to 
DealwithDependence(m_rpmTs, probs);

so obviously, if we want to install RPM only, we need to make
"vectorInstall" here contains only rpm-xxx.rpm
>>>
so we need to go backward to see
GetAddedFile()
1. the input is "m_vectorAddedFile"
2. output is "vectorInstall"

>>>
AddFile() is used to Add package to vector m_vectorAddedFile.
1. it shows up twice in DealwithDependence()------------shall be ignore
2. and once in GetOtherArchPackages()-------------------not important

ANSWER: so we can ignore AddFile(), RPM shall be added to m_vectorAddedFile before it.
but this might be useful
<>
/*!
@brief Clear vector m_vectorAddedFile.

Clear vector m_vectorAddedFile.
*/
void classRpmEngine::ClearAddedFiles()

</>


>>>haha, now I lost the way, so Let's do it the oppisite way.
RPM is read out the compare with local one, if newer then will be added by
AddUpdateInstallList()
1. "AddUpdateList(fileInfo); " is called by AddUpdateInstallList() to add RPM
2. haha got you!
<>
void classRpmEngine::AddUpdateList(structFileInfo *fileInfo)
{
        m_vectorUpdateList.push_back(*fileInfo);
}

</>
3. so what I need to do is "m_vectorUpdateList.clear()"
4. and then add RPM only

>>>but "m_vectorUpdateList"=="m_vectorAddedFile"?
1. we see 
<>
if(bSelfUpdate == true && m_bIgnoreSelfUpdate == false)
                {
                        m_bSelfUpdate = true;
                        m_vectorUpdateList.clear();
                        m_vectorInstallList.clear();
                }

</>
so if we want to update RPM only, we need to do sth likewise

2. then who will use m_vectorUpdateList
<>
vector <structFileInfo> classRpmEngine::GetUpdateList()
{
        return m_vectorUpdateList;
}

</>

3. vectorUpdateList = GetUpdateList();
4. then I can not connect "vectorUpdateList" with "m_vectorAddedFile"
5. but I believe do "m_vectorUpdateList.clear" is enough for me.
