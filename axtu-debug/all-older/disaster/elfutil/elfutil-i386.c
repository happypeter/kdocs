elfutil-i386
>>>
1. I need to check the spec file for this
2. on a MT systerm connecting to 219
3. select all the elfutil on updatelist
4. the error is in elf/1.e 
5. note "elfutils-libelf-devel-static-i386"

>>>
so I make a diff of old spec and new one, ../elf/2.diff
1. note the "-Requires:" below
<>
Obsoletes: libelf libelf-devel
-Requires: elfutils-libelf = %{version}-%{release}
-Requires: elfutils-libs = %{version}-%{release}
-
-Patch0: elfutils-strip-copy-symtab.patch
-Source2: testfile16.symtab.bz2
-Source3: testfile16.symtab.debug.bz2
-
-# ExcludeArch: xxx
+Patch3: elfutils-0.137-fixes.patch
+Requires: elfutils-libelf-%{_arch} = %{version}-%{release}
+Requires: elfutils-libs-%{_arch} = %{version}-%{release}

</>
2. now I need to find out how axtu consider this.
   If "elfutils-libs-%{_arch}" is used as the file name serching
   but "elfutils-libs" is what we have then we will have trouble
3. on 219, the header info is like this
<>
0:elfutils-libs-0.137-3AXS3.x86_64=elfutils-libs-0.137-3AXS3.x86_64.rpm
0:elfutils-devel-static-0.137-3AXS3.i386=elfutils-devel-static-0.137-3AXS3.i386.rpm
</>

<>
elfutils-libelf-devel-static-0-0.137-3AXS3.x86_64.hdr
elfutils-libs-0-0.137-3AXS3.i386.hdr
elfutils-libs-0-0.137-3AXS3.x86_64
</>

4. we have 
<>
index1 = strTemp.find(":");
                                index2 = strTemp.find("=");

                                structHeaderInfo headerInfo;

                                headerInfo.nType = nType;
                                headerInfo.strEpoch.assign(strTemp, 0, index1);
                                headerInfo.strNVRA.assign(strTemp, index1 + 1 , index2-(index1 + 1));
</>
  and we have the name in GUI install list, so we believe in 
classRpmEngine::ReadRemoteHeaderInfo
  the file name is saved as "elfutils-libs".
>>>but rpm command do not care about this, so you can use it to install elfutil
but it also has confilicts problem. see ../elf/3.e
