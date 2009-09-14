== AC_SUBST ==

<configure.ac>
 searchpath=`(LC_ALL=C /usr/bin/ldd /usr/bin/cc) 2>/dev/null |grep lib64`
        if test -z "$searchpath"; then
                AC_SUBST(libdir,/usr/lib)
        else
                AC_SUBST(libdir,/usr/lib64)
        fi
</>
for more about LC_ALL http://opengroup.org/onlinepubs/007908799/xbd/envvar.html

<Makefile.am>
LIBS = -L/usr/X11R6/lib -L$(libdir) -laxtu_shared -L$(QTDIR)/lib -lqt-mt -lXext -lX11 -lm -lpopt -lrpm 
</>
