>>>so On a fresh MT_2 systerm
1. choose dbus32 only 
2. dep check done, dbus-lib is found
3. update successfully
4. when dbus-lib64 and dbus64 are all on install list---no error
5. When dbus64 on updatelist and dbuslib64 on installist
   dep check will fail, but there is no error saying dbus-lib is not found
>>>
I want to know how the deps are added, so I make a patch
../print.diff, and I get the ../dbus_error/p.e, now we know
NOTE: actually we do not need that patch the dbuglog is just there. See ../dbus_error/dbug.log
1. dbus-lib is read out correctly,even it is on install list, and even the arch is right
2. why dbus-glib is added, in the spec file, libdbus does not require it.
