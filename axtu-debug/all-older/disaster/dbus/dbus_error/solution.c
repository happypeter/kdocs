Running into this?

bash$ sudo rpm -e zlib-devel
error: "zlib-devel" specifies multiple packages

This is because zlib-devel.i386 and zlib-devel.x86_64 are both installed. It is possible to remove them individually:

bash$ sudo rpm -e zlib-devel.i386
bash$ sudo rpm -e zlib-devel.x86_64

By default, Fedora, CentOS and RedHat shells do not specify the architecture of an RPM in the query format. This can lead to duplicate entries from queries:

bash$ rpm -q zlib-devel
zlib-devel-1.2.3-14.fc8
zlib-devel-1.2.3-14.fc8

You can use the --queryformat switch when running rpm -q, or configure the query format setting in ~/.rpmmacros.

bash$ rpm -q --queryformat "%{name}.%{arch}\n" zlib-devel
zlib-devel.i386
zlib-devel.x86_64
bash$ cat ~/.rpmmacros
%_query_all_fmt %%{name}-%%{version}-%%{release}.%%{arch}
bash$ rpm -q zlib-devel
zlib-devel-1.2.3-14.fc8.i386
zlib-devel-1.2.3-14.fc8.x86_64
