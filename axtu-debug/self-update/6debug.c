>>> now I want to do rpm update like self update 
1. so I need to add one boolaen value in
bool classRpmEngine::AddUpdateInstallList(structFileInfo *fileInfo,string strName,string strVer,string strRel,string strEpoch
,string strArch,int nType,bool bSelfUpdate,bool bUpdate,bool newrpm)
2. so I need to change its declearation and and all its implimetaion will a false.
3. until there will be no compilation error anymore.
4. 

