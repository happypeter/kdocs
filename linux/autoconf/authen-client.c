Now I want to study axtu-authen-client autoconf systerm, since its much easier than the one of axtu
>>>AC_SUBST
in configure.ac
 searchpath=`(LC_ALL=C /usr/bin/ldd /usr/bin/cc) 2>/dev/null |grep lib64`
        if test -z "$searchpath"; then
                AC_SUBST(libdir,/usr/lib)
        else
                AC_SUBST(libdir,/usr/lib64)
        fi

in Makefile.am
LIBS = -L/usr/X11R6/lib -L$(libdir) -laxtu_shared -L$(QTDIR)/lib -lqt-mt -lXext -lX11 -lm -lpopt -lrpm 
>>>
