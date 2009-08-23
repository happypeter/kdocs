http://bugzilla.asianux.com/show_bug.cgi?id=6371
Now it seems that this part of rpmegine
does not work well
<>
 }else if( strArchR == "noarch" || strArchL == "noarch"){
                                bFind = true;
</>
I can reproduce anywhere.
>>>
so I add into this
//peter
if(strNameR=="system-config-netboot")
{
m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME, "outside noarch,system-config-netboot",NULL);
         m_Logger->WriteLog_char(ERROR_LOG, "StrArchR",strArchR.c_str(),NULL);
         m_Logger->WriteLog_char(ERROR_LOG, "StrArchL",strArchL.c_str(),NULL);

m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME, "----444--------",NULL);

}
//peter
and find out remote arch is read out as "x86_64", while infact it is "noarch"
NOTE: now I know why there is a x86_64 system-config-netboot, it is in BASE/
155 has no such problem because, Hwanii deleted 155 BASE long time ago!
if you copy the BASE.header.info from 219 to 155, then same error

>>>
when I add this into readremoteheaderinfo
<>
if(headerInfo.strNVRA=="system-config-netboot-0.1.45.1-1.1AXS3.noarch")
m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME, "HELLO ", "system-config-netboot-0.1.45.1-1.1AXS3.noarch" ,NULL);
</>
the string is found right
>>>>>>>>>>>>>
<>

                        if(strOldName2 != strNameR || (strOldName2 == strNameR && !CheckArch(strOldArch2 , strArchR)))

                        {
                        //peter
if(strNameR=="system-config-netboot")
m_Logger->WriteLog_char(ERROR_LOG,"222----","break  under me",NULL);
//peter
                                itRemote--;
                                nCount--;
//peter
if(strNameR=="system-config-netboot")
m_Logger->WriteLog_char(ERROR_LOG,"555----","break  under me",NULL);
//peter

                                stripNVRA(itRemote->strNVRA, &strNameR, &strVerR, &strRelR, &strArchR);
//peter
if(strNameR=="system-config-netboot")
m_Logger->WriteLog_char(ERROR_LOG,"333----","break  under me",NULL);
//peter
                                break;
                        }
//peter
if(strNameR=="system-config-netboot")
m_Logger->WriteLog_char(ERROR_LOG,"44",strArchR.c_str(),NULL);
//peter

</>
the code is like above but I get the below error log
<>
07/01/09 07:40:30 11strArchR--- noarch
07/01/09 07:40:30 222---- break  under me
07/01/09 07:40:30 555---- break  under me
07/01/09 07:40:30 33333333333333strArchR--- noarch
</>

which means there is a break happens inside stripNVRA, strange!

>>>>>>>>>>>>>>
now I test system-config-kdump, the 222 555 shows up together and 333 is lost likewise, so same
stripNVRA issue, but the arch is always noarch, so finally it showup on the update list rightly.
system-config-keyboard is all like system-config-kdump
>>>>>>>>>>>>
system-securitylevel-tui are both x86_64 both locally and remotely, 222 555 333 shows up together.
>>>>>>>>>>>>>
test subversion which has both i386 and x86_64, so the conclution is for x86_64 222 555 333 go toghter
but i386 case is just like noarch.  but anyway they are show up well on update list.
>>>>>>>>>
so I swith to 155, and there is no error, see ../others/155.e
and you click it and it will updated correctly
here I didnot change anything of client side source code.
and I test 58 which is my own made 155 clone, it has same problem as 219.
SO now the problem is on 219 and 58, a x86_64 system-config-netboot is readout, while in fact
on all the three server: there is only one noarch system-config-netboot.
>>>>>>>>219 i386 platform no probelm for system-config-netboot.
