with Hwanii and Huajie
>>>elfutils-devel-static

>>>Hwanii think if the dep file is in install list, axtu won't be able to add it properly.
Can axtu be so stupid?

>>>elfutil -i386
1. if i386 considered part of the %{namae}, 
2. then its a probelm if older version did not has "i386" in its name.
ANSWER: actully, the above conclution is wrong, using new version rpmlib, everything will be OK



>>>>dbus
1. dbus-lib-xxx.rpm is newly added
2. in earlier version of dbus the libs are in dbus-xxx.rpm
3. that is why ../dbus/error happens
4. since now dbus itself has no such libs, if you do not have dbus-lib.rpm
   and want you update dbus, all the libs will be deleted.
NOTE: this is right.
