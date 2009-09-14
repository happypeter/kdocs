Haha, this is not the real config.h
so it is generated as a substitution for "gcc -D"
see manual for detail

then I expect some souce file will have
#include <config.h>
but I could not find such file, 
all I see is:
in all the Makefiles finally obtained
CONFIG_HEADER = $(top_builddir)/config.h


Anyway 
AC_CONFIG_HEADER([config.h])
is always necessary as in configure.ac
