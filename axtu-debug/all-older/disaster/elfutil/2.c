NOTE: when newer version of rpmlib is in use, the "-%{arch}"probelm disapper
so this file become useless

Now we concentrated on, how axtu find dep files on the server.

* in the function
int classRpmEngine::DealwithDependence(rpmts ts,  rpmps ps)
* there is the function
int classRpmEngine::GetRequiredPkgFromRemote(rpmProblem prob, struct structRPMInfo *result)
* which use
rc = GetFromRPMInfoListFromRemote(m_vectorRPMInfo, name, version, (char *)strArchPkg.c_str(), type, compare, result);

there is 
<>
 m_vectorRPMInfo.push_back(rpmInfo);
</>
in the function
<>
int classRpmEngine::OpenHeader(string strFilePath, int nIndex, bool bUpgrade)
</>
m_vectorRPMInfo here is actually obtained from the hdr file in server, done by below code
<>
 strFullPath = it->strCachePath + "/headers/" + it->strName + "-" + it->strEpoch + "-" + it->strVersion + "-"
+ it->strRelease + "." + it->strArch + ".hdr";
                if(OpenHeader(strFullPath, it->nType, true) < 0)
</>


>>>>I think I can add a error log in 
GetFromRPMInfoListFromRemote()
to print  the strName out
and I see ./elf/4.e
"strName----- elfutils-libelf-x86_64", so the name is wrong

>>>
we can trun the SPEC back to solve this problem, but Huajie still believe this structure is good.
and suggest me to  add string check to axtu, if the strName include one of these"-i386:-x86_64:-ppc:--ppc64..."
simply remove it from the string name. Thus the name will match the name obtained from server:UPDATE.header.info.
>but if the arch is removed, then the arch info will be lost,axtu will find two package will same name, then how can it tell
if they are of different arch, or they are only same arch but different versions
-------NO, arch info is still there, axtu can handle this, see "classRpmEngine::CheckArch("
>so the better solution might be add arch info to the name got from server:UPDATE.header.info. 
-------NO, a name is a name, we should not add arch to it.
but since most other packages do not have "-%{arch}" in their "SPEC:%Requires:", so they will suffer.


>>>
Its actually easy to find out whether some other packages also has the same problem
if only we see -%{arch} in the error log file, we know it immediately.

