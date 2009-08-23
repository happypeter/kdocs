>>>to use headerDump()
1. cp header_internal.h to axtu/libs/
2. add #include "header_internal.h" into classRpmEngine.h
3. so If I add in
OpenHeader()
<>
        char * strNameLii;
        char ** obsolete;
        int c;
        headerGetEntry(h, RPMTAG_NAME, NULL, (void **)&strNameLii, NULL);
        m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME, "name-----",strNameLii,NULL);
string pp_1;
pp_1=(string)(const char*)strNameLii;
if(pp_1.find("libdhcp-devel")!= string::npos)
{
        m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME, "xxxxx----",strNameLii,NULL);
FILE *pp;
pp=fopen("/peter.c","w");
headerDump(h, pp, HEADER_DUMP_INLINE, rpmTagTable);
}
</>
4. I get all I need in peter.c
<>
Entry      : 043 (1090)RPMTAG_OBSOLETENAME STRING_ARRAY       0xfffffbd0 00000001
       Data: 000 pump-devel
...
Entry      : 050 (1115)RPMTAG_OBSOLETEVERSION STRING_ARRAY       0xfffffbd0 00000001
       Data: 000 0.8.24
</>

>>>so this means I can read the defination of headerDump() 
and have my own version of it, to do my obsolete tag job
