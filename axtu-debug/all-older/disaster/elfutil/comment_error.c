[root@dhcp23 elfutil]# rpm -Uvh --test elfutils-libs-0.137-3AXS3.x86_64.rpm
warning: elfutils-libs-0.137-3AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
error: Failed dependencies:
        elfutils-libelf-x86_64 = 0.137-3AXS3 is needed by elfutils-libs-0.137-3AXS3.x86_64
        libelf.so.1(ELFUTILS_1.3)(64bit) is needed by elfutils-libs-0.137-3AXS3.x86_64
        libelf.so.1(ELFUTILS_1.4)(64bit) is needed by elfutils-libs-0.137-3AXS3.x86_64
        elfutils-libs > 0.125-3 conflicts with elfutils-libelf-0.125-3.x86_64
        elfutils-libs > 0.125-3 conflicts with elfutils-libelf-0.125-3.i386
/*

>>>its because of this
%package libelf
Summary: Library to read and write ELF files.
Group: Development/Tools
Conflicts: elfutils < %{version}-%{release}
Conflicts: elfutils > %{version}-%{release}
Conflicts: elfutils-libs < %{version}-%{release}
Conflicts: elfutils-libs > %{version}-%{release}
Conflicts: elfutils-libelf-devel < %{version}-%{release}
Conflicts: elfutils-libelf-devel > %{version}-%{release}

*/
[root@dhcp23 elfutil]# rpm -Uvh --test elfutils-libs-0.137-3AXS3.x86_64.rpm elfutils-libelf-0.137-3AXS3.x86_64.rpm
warning: elfutils-libs-0.137-3AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
error: Failed dependencies:
        elfutils-libs > 0.125-3 conflicts with elfutils-libelf-0.125-3.i386
[root@dhcp23 elfutil]# rpm -qa|grep elfu
elfutils-devel-0.125-3
elfutils-libelf-0.125-3
elfutils-devel-0.125-3
elfutils-libelf-devel-static-0.125-3
elfutils-libelf-0.125-3
elfutils-0.125-3
elfutils-libelf-devel-0.125-3
elfutils-devel-static-0.125-3
elfutils-libs-0.125-3
elfutils-libelf-devel-0.125-3
elfutils-libs-0.125-3
[root@dhcp23 elfutil]# rpm -qa|grep elfutils-libelf-0.125-3.i386
[root@dhcp23 elfutil]# rpm -qa|grep elfutils-libelf-0.125-3
elfutils-libelf-0.125-3
elfutils-libelf-0.125-3
//>>>peter--this is crazy, that is why they add "arch" in SPEC file "Require:"
[root@dhcp23 elfutil]#  
