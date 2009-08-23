anyway 155 has no problem but 219 is buggy
1. use rpm -qpi system-config-netboot(scn for short)
2. then we found 155 is built earlier than 219, maybe it is beta5 package
3. anyway, I will cp 219 scn to 155 and test, no error
4. Hwanii cp 155 scn to 219, same error
5. so one packages can not make a differnece.
6. maybe I want to cp all.

>>>>>>>>>>After Lishu found me the BASE.header.info issue, things are more clear
now i386.e is also worth noting.
I mean i386 is also has strange stripNVRA break problem,
but the package is not lost.
however, our netboot is lost after stripNVRA break.

>>>>LI SHU help me hacking down the axtu source code for 2 hours.
He can not explain the "tripNVRA break" problem
but instead he give me another info:
if we print out all strNVRA, then we see
1. on x86_64 platform system-config-netboot-xxx.noarch is printed AFTER system-config-netboot-xxx.x86_64
2. for i386 platform system-config-netboot-xxx.noarch is printed BEFORE system-config-netboot-xxx.i386
REASON: i>n>x(i386>noarch>x86_64)
<classRpmEngine.h>
       else if(strcmp(strName1.c_str(), strName2.c_str()) == 0)
        {
                if(strArch1 < strArch2)
                {
                        nResult = true;
                }

</>
>>>
if this is the case, in axtu founction
<>
 /////////////
                // Same name pass and find last version in RemoteServer's PkgSet.
                while(strOldName2 == strNameR)
                {
</>
there is a problem.
because "last version" here is just the last one here with the same_name&&compatiable_arch.
I add this to rpmengine
<patch>
        itRemote = m_setRemoteHeaderInfo.begin();
        itLocal  = m_setLocalHeaderInfo.begin();
+++//peter
+++for(itRemote = m_setRemoteHeaderInfo.begin();itRemote != m_setRemoteHeaderInfo.end();itRemote++)
+++{
+++m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME,"-------------------", NULL);
+++m_Logger->WriteLog_char(ERROR_LOG, "sos",itRemote->strNVRA.c_str(), NULL);
+++}
  string msg;
  classLogger log;

</patch>
and I have itRemote.list------------maybe He is right!!!
because most packages are sorted well but system-config-netboot is not.
is seems that when axtu creat m_setRemoteHeaderInfo, the noarch is considered different arch and thus different packages.
see epoch/set.c, and I know everything happens here
<>
struct  DereferenceLess
{
  template <typename PtrType>
  bool operator()(PtrType pT1, PtrType pT2) const
    {
        return CompareHeaderInfo2(pT1, pT2);
    }
};
</>

>>>>>>>>>>>
Now we have issues to concern:
1. do we need to concern i486, i586 repalcing i386(CheckArch() issues)?
Huajie and Lishu said, no one can say it will never happen, but it is definately uncommon,
so we just ignore this for now.
2. this time the problem is noarch repalced x86_64, but in the future we may have x86_64 replace noarch

3. this part may bring problem as well 
<classRpmEngine.cpp>
   else if(nCompare == 0)
                        {
                                if(strArchR != strArchL)
                                {
                                        //      INSTALL CASE    BY      ARCHITECTURE
                                        AddUpdateInstallList(&fileInfo, \
                                                strNameR,strVerR,strRelR, \

</>
NOTE: this should not be a problem, since nCompare == 0 means local one and remote one has same ENVR,
it will never happen to "noarch replaces x86_64" cases.


<patch>
--- classRpmEngine.h.bak        2009-07-06 02:34:51.000000000 +0800
+++ classRpmEngine.h    2009-07-06 02:39:49.000000000 +0800
@@ -132,11 +132,12 @@
        }
        else if(strcmp(strName1.c_str(), strName2.c_str()) == 0)
        {
-               if(strArch1 < strArch2)
+               if((strArch1 < strArch2)&&!(strArch1 == "noarch" || strArch2 == "noarch"))
                {
                        nResult = true;
                }
-               else if( strArch1 == strArch2)
+               else if(( strArch1 == strArch2)||(strArch1 == "noarch" || strArch2 == "noarch"))
                {
                        if((headerInfo1.strEpoch)<(headerInfo2.strEpoch))
                        {

</>
>>>>>>>>>>
the patch works now we have 824 packages available connecting to 219. system-config0-netboot is on the list.
remove my patch now we have 822, haha, there is another guy.
so I need to print out the two update lists. 
<patch>
 for(it=m_vectorUpdateList.begin();it!=m_vectorUpdateList.end();it++)
        {
+++m_Logger->WriteLog_char(ERROR_LOG, it->strName.c_str(), it->strArch.c_str(), NULL);
                if (CheckBlacklist(it->strName) == true)
                {
<patch/>
the above patch give me the list and I find out it is "openib" from x86_64 to noarch,
so everything is OK, Lishu agree with me about this  package.
>>>>>>>>>>
1. full update 219 from sp1----done with no error, system-config-netboot is updated well

