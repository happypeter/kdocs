>>>
I need to add sth like below before my ApplyObsoletes() 
<>
 string strObsolete = m_configEnv.GetOption("main", "obsolete");
        if(strObsolete != "false")
        {
                if(ApplyObsoleteTag() == false)
                {
                        return -1;
                }
        }
        return 0;
</>
