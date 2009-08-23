What is strange now is dus_error/4.e,
which means unrelated deps are added by axtu dep checking,
what Hwanii want now, is print out how they are added step by step
this is need to be done in 
classRpmEngine::DealwithDependence()
>>>
1. it is easy, so we now get ../dbus_error/5.e
2. the package name is from "requiredRPM->name", which is generated in
3. 6.e is obtained  when you choosing
   dus-----i386
   dus-----x86_64
  at the same time on update list


>>>dbus----meeting discussion
1. dbus-lib-xxx.rpm is newly added
2. in earlier version of dbus the libs are in dbus-xxx.rpm
   if you update dbus first, then all the libs will be deleted
3. that is why ../dbus/error happens
4. since now dbus itself has no such libs, if you do not have dbus-lib.rpm
   and want you update dbus, all the libs will be deleted.
~
5. so that means if we use a systerm with early version dbus-lib.rpm will installed.
   there might be no error
6. HuaJie also said libc.so is also too old

>>> dus and dbus-libs requires each other, Huajie said it is natrual, though uncommon.

<>
%package libs
Summary: Libraries for accessing D-BUS
Group: Development/Libraries
Requires: %name = %{version}-%{release}
</>
//"%name" here is just what you have as "Name:"

>>>according to ../glibc/
we believe glibc is perfect
what is wrong is why dbus can not find it
>>>now with the glic problem out of the way
if you go installist
click dbus-lib64, then it will say I reguire dbus
and do the installation successfully.
but there is the conflict message as you see when it is done by rpm command.

>>>Now I need to consider Hwanii's installlist theory again.
so I test it with "apr-util-devel", and in this case,
Hwanii is right. if one of the deps are on install list, axtu can not find it!!!
I need to check the code.
I even mv to a 32 bit package "audit-devel", same error.

>>>so I delete the dbus-lib for both 32 bit and 64bit
when I update dbus32-------done without error
..............dbus64-------error
>>>if you install dbus-lib64 on local systerm then update dbus64---done
>>>there is a possibility that when a dbus64 check dep, the 32lib is found on local OS
so dep is satisfied wrongly, that's why it won't check again on install list for libs
>one thing is important that in the spec
dbus64 
Requires: dbus-libs = %{version}-%{release}
so there is no arch
which means 32bit libs can really satisfy this require.
>So I will delete the 32bit lib and then update dbus64, see what will happen 
