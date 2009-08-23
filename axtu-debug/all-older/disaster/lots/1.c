Cannot update lots of packages through axtu on x86_64 platform. Bug 6371
	
see ../dbus/4solution.c   first
1. so Jongwoo's patch solve everything,ah.
NOTE: it is not only because 5->50, installing rpm first is more important than this
2. now I click rpm only 
3. then all the rpm packages plus popt are all given as deps
4. done with a few conflicts

>>>
see ../dbus/dbus_error/dbus-dep.e
then we know
NetworkManager-glib and lots of other packages are installed anyway.

<>

NetworkManager-glib-0.7.0-4.1-------------done
dbus-1.1.2-12-----------------------------done
dbus-glib-0.73-8--------------------------done
dbus-libs-1.1.2-12------------------------done
kdelibs-3.5.5-11.23-----------------------done
hal-0.5.8.1-38.1--------------------------done
elfutils --- all the packages related it--done
policycoreutils-1.33.12-14.2--------------done by click it only 64bit
policycoreutils-newrole-1.33.12-14.2------done
libselinux-1.33.4-5.1.1-------------------done by click it only 64bit
libselinux-utils-1.33.4-5.1.1-------------done with a lot of conflicts
popt-1.10.2.3-9.2------------------------done
rpm-4.4.2.3-9.2--------------------------done
rpm-build-4.4.2.3-9.2--------------------done
rpm-libs-4.4.2.3-9.2---------------------done
rpm-python-4.4.2.3-9.2-------------------done
rpm-devel-4.4.2.3-9.2--------------------done
</>

>all the above test i did it using 1.5 9AX axtu (change 5->50), connecting to 219

>>>even we know there a ts prblem with elfutil packages, this time I did it by click elfutil64 only.
see elf-done.e
