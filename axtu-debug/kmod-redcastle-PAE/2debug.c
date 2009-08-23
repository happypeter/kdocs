* in DealwithDependence()
* there is a line
 if (AddFile(tmp, REQDEP, requiredRPM->upgradeFlag) < 0)// let's call it "d" way
// the "select" way----if(m_rpmEngine->AddFile(strFullPath.c_str(), UPDATE, 1) != 0)

* kernel is added this way if you do not click it during "select package"
* but unfortunate it does not work well as the "select" way
* so what is the difference between to two ways?
- 1. in the "s" way, kernel is added as a UPDATE rather than REQDEP, 
- so I change the REQDEP into UPDATE, it works but does not solve the real problem
- 2. another diff is the last param is a 1 in the "s" way, so I change the one in d way
- it make no difference, cause if the package is a kernel, GetFile will change this param unconditionally

>>>Now Let's look at the whole picture of " classGui::ProceedUpdate()"
then we see if kernel is added in Check(), then the redcastle functions:
CheckKmodRedcastle()----return true if there is no kernel
RemoveKernelAndKmodRedcastle()
GetAddedKmodRedcastleFile()
can do nothing to it. because Check() is called after all of them.

>>>
*dep log is written here// the last part of Check()
<>  
  rpmpsPrint(NULL, probs);
                WriteDepLog(probs);
</p>
* and it is generated here
probs = rpmtsProblems(m_rpmTs);
* so the problem is about m_rpmTs, it is passed to Check() but it changed in
* DealwithDependence(), kernel is added here

>>>haha, so we believe DealwithDependence ruined our m_rpmTs,
using  AddInstallElement()
so I add
nUpgrade=0;
inside AddInstallElement(),
Now all the problem is gone. Haha!

>>>Anyway we need to add kernel exception in 
 rc = AddInstallElement(ts, requiredRPM->h, strTemp, 0, upgrade); 
char * strTemp = strdup(tmp);-------the filename is here
* I think I can change strTemp in to a C++ string and then use .find("kernel")
* below is my patch
<>
int classRpmEngine::AddInstallElement(rpmts ts, Header h, const fnpyKey key, rpmReloca
tion *relocs, int nUpgrade)
{
        if (access((const char *)key, F_OK) != 0)
        {
                return -1;
        }
/************peter--begin********************/
string s_1;
s_1=(string)((const char *)key);
if(s_1.find("kernel")!= string::npos);
{
        nUpgrade=0;
}
/************peter--end********************/

        if (nUpgrade)
        {

</>
and it works
* then I test the PAE case, also works


>>>>>>>>>>New trouble<<<<<<<<<<<<<<
Gloria find axtu will alway install all the packages, and huwnii is angry about this.
it is all because a ";"
<>

if(s_1.find("kernel")!= string::npos);
{
        nUpgrade=0;
}

</>
so stupid
>>>
Any way I removed the  ";"
Now 
common packages------not installed anymore which is good
kmod-redcastle-------installed properly
kmod-redcastle-PAE---done, only click+no conflic messages

>>>so the pam and app conflics bugs that are reopened by Gloria might already disapper now.
