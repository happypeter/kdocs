if you add this
<>  
     string s_1;
        s_1=(string)((const char *)key);
+++//peter
+++m_Logger->WriteLog_char(ERROR_LOG, "peter",key,NULL);
        if(s_1.find("kernel")!= string::npos)//if the package is a kernel install it
        {
<>
into rpm engine, you will see all the packages including selected ones and dep ones are added here.
so I can add Checkkernel here.
and I can add 
<>
if(s_1.find("kernel")!= string::npos)
{
	
	nUpgrade=0;
	if(s_1.find("kernel-header")!= string::npos)
	{
	nUpgrade=1;
	}

}
</>
then kernel-header will be updated rather then installed, which is what we need.
NOTE: hawnii also mentioned kernel-doc, I did not see kernel-doc in "Checkkernel()"
so troditionally it is updated, but now it is just like "kernel-headers" being installed
test it, there is no conflcts during installation
<>
[root@dhcp29 ~]# rpm -qa|grep kernel-doc
kernel-doc-2.6.18-53.11AXS3
kernel-doc-2.6.18-128.5AXS3
</>
Hwanii: plz UPdated kernel-doc as kernel-headers
so I need to add 
" if(s_1.find("kernel-doc")!= string::npos)"
I think
