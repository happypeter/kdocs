wget http://127.0.0.1/peter-repo/repodata/primary.xml.gz
works

/////////////===============
int classNetwork::GetHeader()
{
        uerr_t err_value;
        vector<structRepoInfo>::iterator it;
        string url;
        char *szMoveCmd;

        for(it=m_vectorRepoInfo.begin();it!=m_vectorRepoInfo.end();it++)
        {
//              m_clsDown->setTargetDir(it->strLocalHeaderDir.c_str());
                m_clsDown->setTargetDir("/home/peter/tmp/");
//              url = m_clsConfParser->StripRString(it->strUrl, '/');
//		url=url.substr(0,url.rfind("/"));  // remove RPMS
//              url.append(".header.info");
                url ="http://127.0.0.1/peter-repo/repodata/primary.xml.gz";
                m_Logger->WriteLog_char(ERROR_LOG,"getting--1...peter... ",url.c_str(), NULL);
                m_clsDown->setTimestamping();
                m_clsDown->setUrl(url);
                err_value=m_clsDown->getFile();
        
//////////////////============

===
since it looks stupid to have wget tree in axtu tree, so I want to remove it.
retrieve_url() is actually what is mainly used in axtu, but when I hacking down into wget/
I soon understand it is not so easy to drag this function out, since it depends on two many other files, 
so it is even cleaner to have wget used as a whole rather then have many changed wget files.
===
in classDownloader.h, there is even
#include <wget/config.h>
so I need to study GNU autotools a liitle again
