
Summary: best hello
Name: hello
Version: 1.0
Release: 1
Group: System Environment/Base
Url: http://www.peter.org/
Source: hello.tar.gz
License: GPLv2+
BuildRoot: %{_tmppath}/%{name}

%description
The RPM Package Manager (RPM) is a powerful command line driven
%package ui
Summary:  Libraries for manipulating RPM packages
Group: Development/Libraries
License: GPLv2+ and LGPLv2+ with exceptions

%description ui
This package contains the RPM shared libraries.
%package doc
Summary:  Libraries for manipulating RPM packages
Group: Development/Libraries
License: GPLv2+ and LGPLv2+ with exceptions

%description doc
This package contains the RPM shared libraries.


%prep
%setup -n hello
%build
make
%install
mkdir -p $RPM_BUILD_ROOT/bin
mkdir -p $RPM_BUILD_ROOT/usr/share/doc/
cp peter $RPM_BUILD_ROOT/bin
cp peter-doc   $RPM_BUILD_ROOT/usr/share/doc/
%clean
rm -rf $RPM_BUILD_ROOT

%post

%files ui
%defattr(-,root,root,-)
/bin/peter
%files doc
%defattr(-,root,root,-)
/usr/share/doc/peter-doc

%changelog
* Mon Mar 02 2009 Peter Wang <peter.wang@asianux.com> 1.0-1
- peter study

