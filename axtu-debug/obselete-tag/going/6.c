OK now I have all the ob info from ReadHeader()
saved in m_vectorRPMInfo, so
1. if ob exsists for a specific it (m_vectorRPMInfo), remove the obsoleted tag from both lists
2. check the obsoleted tag installed or not. if YES, add the tag obsoletes it to both lists
   if NO, only added it to installlist
3. oopslee's patch helps a lot

>>>OK, now I have my git repo for axtu, so I do not need to take too much stupid notes any more.

>>>I want to test my  RemoveUpdateInstallList(),
so now I have sysreport on update list and pump-devel on installlist(sos and libdhcp-devel on inlist as well)
OK, my toy works well.

>>>now I want to implement AdddUpdateInstallList(), inside which I will call IsPackageInstalled()
 now we only need to conentrate on what we need to add, since RemoveUpdateInstallList() works so nicely
1. now what we have is A2>[A1]+B+[C]+[D]+...
2. now let's say B=1,if installed, B=0, if not.

if(B && A1)//here B=1 stands for any of B C D ... is installed
	A2 is alredy on update-list----no need to add it to installlist
if(B && !A1)
	add A1 to update-lists-----Since A2 is alredy on install-list
if(!B) 
	do nothing-----------------Since A2 knows where to go

GREAT LOGIC! SIMPLE BUT COVERS EVERYTHING!

>>>to determine B, I need 
<>
for(i=0;(*it)->obsoleteName[i];i++) //refer to how they use provideName
		{
			if(IsPackageInstalled((*it)->obsoleteName[0])==true)
			{
				break;
			}
		}
</>
>>> maybe I shall wait for JeongHun Kim's patch

