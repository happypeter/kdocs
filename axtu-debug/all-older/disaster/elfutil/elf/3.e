root@dhcp23 test]# rpm -Uvh --test elfutils-0.137-3AXS3.x86_64.rpm
warning: elfutils-0.137-3AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
error: Failed dependencies:
        elfutils-libelf-x86_64 = 0.137-3AXS3 is needed by elfutils-0.137-3AXS3.x86_64
        elfutils-libs-x86_64 = 0.137-3AXS3 is needed by elfutils-0.137-3AXS3.x86_64
        libasm.so.1()(64bit) is needed by elfutils-0.137-3AXS3.x86_64
        libasm.so.1(ELFUTILS_1.0)(64bit) is needed by elfutils-0.137-3AXS3.x86_64
        libdw.so.1(ELFUTILS_0.126)(64bit) is needed by elfutils-0.137-3AXS3.x86_64
        libdw.so.1(ELFUTILS_0.127)(64bit) is needed by elfutils-0.137-3AXS3.x86_64
        libdw.so.1(ELFUTILS_0.130)(64bit) is needed by elfutils-0.137-3AXS3.x86_64
        libelf.so.1(ELFUTILS_1.3)(64bit) is needed by elfutils-0.137-3AXS3.x86_64
        libelf.so.1(ELFUTILS_1.4)(64bit) is needed by elfutils-0.137-3AXS3.x86_64
        elfutils > 0.125-3 conflicts with elfutils-libelf-0.125-3.x86_64
        elfutils > 0.125-3 conflicts with elfutils-libelf-0.125-3.i386
        elfutils > 0.125-3 conflicts with elfutils-libs-0.125-3.i386
        elfutils > 0.125-3 conflicts with elfutils-libs-0.125-3.x86_64
[root@dhcp23 test]# rpm -Uvh --test elfutils-0.137-3AXS3.x86_64.rpm elfutils-libelf-0.137-3AXS3.x86_64.rpm
warning: elfutils-0.137-3AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
error: Failed dependencies:
        elfutils-libs-x86_64 = 0.137-3AXS3 is needed by elfutils-0.137-3AXS3.x86_64
        libasm.so.1()(64bit) is needed by elfutils-0.137-3AXS3.x86_64
        libasm.so.1(ELFUTILS_1.0)(64bit) is needed by elfutils-0.137-3AXS3.x86_64
        libdw.so.1(ELFUTILS_0.126)(64bit) is needed by elfutils-0.137-3AXS3.x86_64
        libdw.so.1(ELFUTILS_0.127)(64bit) is needed by elfutils-0.137-3AXS3.x86_64
        libdw.so.1(ELFUTILS_0.130)(64bit) is needed by elfutils-0.137-3AXS3.x86_64
        elfutils > 0.125-3 conflicts with elfutils-libelf-0.125-3.i386
        elfutils > 0.125-3 conflicts with elfutils-libs-0.125-3.i386
        elfutils > 0.125-3 conflicts with elfutils-libs-0.125-3.x86_64
[root@dhcp23 test]# rpm -Uvh --test elfutils-0.137-3AXS3.x86_64.rpm elfutils-libelf-0.137-3AXS3.x86_64.rpm elfutils-libs-0.137-3AXS3.x86_64.rpm
warning: elfutils-0.137-3AXS3.x86_64.rpm: Header V3 DSA signature: NOKEY, key ID a83bd72e
error: Failed dependencies:
        elfutils > 0.125-3 conflicts with elfutils-libelf-0.125-3.i386
        elfutils > 0.125-3 conflicts with elfutils-libs-0.125-3.i386
        elfutils-libs > 0.125-3 conflicts with elfutils-libelf-0.125-3.i386
[root@dhcp23 test]#                                                        
