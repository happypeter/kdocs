>>>below is the way how oopslee treated it
<>
+#define CASE1_PACKAGE_A "sysreport"
+#define CASE1_PACKAGE_B "sos"
+#define CASE2_PACKAGE_A "pump-devel"
+#define CASE2_PACKAGE_B "libdhcp-devel"
</>

[root@tsnlocaltest RPMS]# rpm -qp --obsoletes sos-1.7-9.16.2AXS3.noarch.rpm
warning: sos-1.7-9.16.2AXS3.noarch.rpm: V3 DSA signature: NOKEY, key ID a83bd72e
sysreport
[root@tsnlocaltest RPMS]# rpm -qp --obsoletes  libdhcp-devel-1.20-6AXS3.x86_64.rpm
warning: libdhcp-devel-1.20-6AXS3.x86_64.rpm: V3 DSA signature: NOKEY, key ID a83bd72e
pump-devel <= 0.8.24
>>>>>>>>>>
if I serch 
headerGetEntry
in rpm/ I can see lots of cases like how to read name epoch ... out of a header file
but no obsolete tag
in axtu classRpmEngine::OpenHeader()
if I add
<>
	const char * strNameLii;
        const char * obsolete;
        headerGetEntry(h, RPMTAG_NAME, NULL, (void **)&strNameLii, NULL);
        headerGetEntry(h, RPMTAG_OBSOLETES, NULL, (void **)&obsolete, NULL);
        m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME, "obsolete-",obsolete,NULL);
        m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME, "name-----",strNameLii,NULL);
</>
I can read all the names out of the repo hdr file, and the obsolete is also read out, but it is not human readable

>>>when I add 
<>
//peter
        const char * strNameLii;
        const char * obsolete[4];
        const char *ob[4];
        ob[0]="sys-peter";
        int c;
        m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME, "ob[0]----",ob[0],NULL);
        headerGetEntry(h, RPMTAG_NAME, NULL, (void **)&strNameLii, NULL);
        m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME, "name-----",strNameLii,NULL);
        headerGetEntry(h, RPMTAG_OBSOLETES, NULL, (void **)&obsolete, &c);
        if(c==1) m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME, "c=1","sss",NULL);
        m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME, "obsolete[0]----",obsolete[0],NULL);
        m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME, "obsolete----",obsolete,NULL);
//end
</>
ob is print out right, while obsolete is not. that means obsolete is not in the format I imagined.

>>>>>>>below is from
<http://mit.edu/zacheiss/dev/rhlinux/redhat-6.1/misc/src/anaconda/rpmmodule/upgrade.c>
 rc = rpmdbFindPackage(db, obsoletes[obsoletesCount], &matches);
 rc = rpmdbFindPackage(db, name, &matches);
char *name;
char **obsoletes;
headerGetEntry((*pip)->h, RPMTAG_OBSOLETES, NULL,
                       (void **) &obsoletes, &obsoletesCount)
headerGetEntry(h, RPMTAG_NAME, NULL, (void **) &name, NULL);
</>
so if the above code is right, and I can print out name, it is just natural to print out obsolete.
but I failed!
