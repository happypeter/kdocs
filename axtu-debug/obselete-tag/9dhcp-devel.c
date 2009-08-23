>>>at git commit "mem leak on xenls! by adding a new vector in classRpmengine"
we have only x86_64 pump-devel installed, on install list we have libdhcp-devel of two platform, which is right
but on update list we only have i386 libdhcp-devel, and 2 of the same thing!
A: this is easy to fix, add arch check inside CopyObsoleterFromInstallToUpdate()
                                                                                       
>>>strange thing is if I install
pump-devel-0.8.24-1.2.2.1.i386.rpm   
pump-devel-0.8.24-1.2.2.1.x86_64.rpm 
both, axtu will die during ApplyObsoletes()
one or none axtu will have no such problem, just the above one.

>>>for now I put this aside for a while, and concentrate on why two i386 libdhcp-devel there on update list?
A: the reason is simple, No arch check in CopyObsoleterFromInstallToUpdate() so axtu will always get the i386 one.
with the commit " the two i386 libdhcp-devel problem solved ", x86_64 libdhcp-devel shows up.
but what if I add another pump-devel?
bad! problem still there.
>>>Now the situation gets sticky!
if I get rid of dbus-glib-devel, now it will be Ok even if two pump-devel is installed
see ../others/dbus.c --------things get crazy!
Anyway, when i386 and x86_64 dbus-glib-devel are installed, the libdhcp-devel is alright now!
Big problem is I can not explain this, try to explore, but the deps of dbus is really complex, so I stoped.

>>>let's consider this later! 
