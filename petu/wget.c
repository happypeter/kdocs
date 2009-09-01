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
//               url=url.substr(0,url.rfind("/"));  // remove RPMS
//              url.append(".header.info");
                url ="http://127.0.0.1/peter-repo/repodata/primary.xml.gz";
                m_Logger->WriteLog_char(ERROR_LOG,"getting--1...peter... ",url.c_str(), NULL);
                m_clsDown->setTimestamping();
                m_clsDown->setUrl(url);
                err_value=m_clsDown->getFile();
        /*
//////////////////============
