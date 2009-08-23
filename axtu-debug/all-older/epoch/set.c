5_15_2009
I will 
CompareVerRel()-->CompareEpoVerRel()



NOTE: There is a CompareVerRel() inside CompareHeaderInfo()
but CompareHeaderInfo() is not used anywhere.

>>>in rpm/lib/rpmvercom.c,
they also use 1, -1, 0 to mean >0 <0 =0----good

>>>
Now My problem is how to handle itRemote
m_setRemoteHeaderInfo-------the pakages are sorted by Name->Version->Rel
Can I make it into Name->Epcho->Version->Real
>>>so I need to study how it is genertated

1. cacheDirInfo.strHeaderInfoFile = strTemp + "/header.info";
strTemp = strPath + "/" + *it;
  >so it must be
  >155:/var/www/html/auth/asianux/AXS3-RF/x86/UPDATE/RPMS/headers/header.info    
2.fin.open(it->strHeaderInfoFile.c_str());

3. headerInfo.nType = nType;
   headerInfo.strEpoch.assign(strTemp, 0, index1);
4.if (m_setRemoteHeaderInfo.insert(headerInfo).second)

>>>if I want elements in m_setRemoteHeaderInfo  sorted with epoch concern,
i need to add epoch comparison inside
CompareHeaderInfo2()
since we have
 headerInfo.strEpoch.assign(strTemp, 0, index1);
so it will be easy to add  epoch comparison .

>>>then what i did inside  
while(strOldName2 == strNameR)
will no longer be necessary, which is great
the logic get much simplier this way.

>>>then no need to change the epoch statements inside
if(strNameR == strNameL)
and everything shoud be OK for both update and install lists.

