>>>I need to be careful to use the returned strings 
<>

int classRpmEngine::AddInstallElement(rpmts ts, Header h, const fnpyKey key, rpmRelocation *relocs, int nUpgrade)
{
        if (access((const char *)key, F_OK) != 0)
        {
                return -1;
        }
        int nRet;
        const char * strName;
        const char * strVersion;
        const char * strRelease;
        const char * strArch;
        headerGetEntry(h, RPMTAG_NAME, NULL, (void **)&strName, NULL);
        headerGetEntry(h, RPMTAG_VERSION, NULL, (void **)&strVersion, NULL);
        headerGetEntry(h, RPMTAG_RELEASE, NULL, (void **)&strRelease, NULL);
        headerGetEntry(h, RPMTAG_ARCH, NULL, (void **)&strArch, NULL);
        //do I need to free the pointers here?
//peter-begin
        m_Logger->WriteLog_char(ERROR_LOG, strName, "+++++++",NULL);
        m_Logger->WriteLog_char(ERROR_LOG, strVersion, "+++++++",NULL);
        m_Logger->WriteLog_char(ERROR_LOG, strRelease, "+++++++",NULL);
        m_Logger->WriteLog_char(ERROR_LOG, strArch, "+++++++",NULL);
        if((string)strName=="kernel")//with out the cast, it won't work
        {
                m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME, "(string)--such stpupid if",NULL);
        }

//end
        nRet = CheckKernel(strName); //however CheckKernel kindly accept it without cast, and works well
        if ((nRet == 0)||(nRet == 2))
        {
//peter-b
        string s_1;
        s_1=(string)((const char *)key);
//      if(s_1.find("kernel")!= string::npos)//if the package is a kernel install it
        if((string)strName=="kernel")
        {
                m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME, "strName==kernel",NULL);
        }
        else
        {
                m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME, "sth wrong",NULL);
        }
//end
                nUpgrade = 0;
        }

</>
