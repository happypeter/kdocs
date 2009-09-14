#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(axtu-authen-client, 1.2, yusop@haansoft.com)

AC_MSG_NOTICE([configuring for $PACKAGE_NAME $PACKAGE_VERSION])
AC_MSG_NOTICE([You can send e-mail($PACKAGE_BUGREPORT) for bug])

dnl
dnl Set the prefix
dnl
AC_SUBST(DEFAULT_PREFIX,/usr/share)

if (echo $prefix | grep -q NONE && true || false ) then
        AC_SUBST(prefix,$DEFAULT_PREFIX)
fi

AC_PREFIX_PROGRAM($prefix/$PACKAGE_NAME)

AC_CANONICAL_HOST
AC_DEFINE_UNQUOTED([OS_TYPE], "$host_os",
                   [Define to be the name of the operating system.])

dnl
dnl Set the libdir
dnl
if test -d "$libdir"; then
        AC_MSG_NOTICE([Using inputted value - $libdir])
else
        searchpath=`(LC_ALL=C /usr/bin/ldd /usr/bin/cc) 2>/dev/null |grep lib64`
        if test -z "$searchpath"; then
                AC_SUBST(libdir,/usr/lib)
        else
                AC_SUBST(libdir,/usr/lib64)
        fi
        AC_MSG_NOTICE([Using default value - $libdir])
fi

AC_CONFIG_SRCDIR([tui/main.cpp])
<manual>
AC_CONFIG_SRCDIR (unique-file-in-source-dir) [Macro]
unique-file-in-source-dir is some file that is in the package’s source directory;
configure checks for this file’s existence to make sure that the directory that it is
told contains the source code in fact does. Occasionally people accidentally specify
the wrong directory with ‘--srcdir’; this is a safety check. See Section 15.10
[configure Invocation], page 246, for more information.
</>


AC_CONFIG_HEADER([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AC_PROG_LIBTOOL

AM_INIT_AUTOMAKE(foreign)
AM_MAINTAINER_MODE

# Checks for libraries.
AC_CHECK_LIB([axtu_shared], [main],[],AC_MSG_ERROR([libaxtu_shared not found!!]))
# FIXME: Replace `main' with a function in `-lm':
AC_CHECK_LIB([m], [main])
# FIXME: Replace `main' with a function in `-ln':
AC_CHECK_LIB([n], [main])
# FIXME: Replace `main' with a function in `-lqt':
AC_CHECK_LIB([qt], [main])

# Checks for header files.
AC_FUNC_ALLOCA
//if alloca is found, then  #define HAVE_ALLOCA 1 in config.h

AC_HEADER_STDC
<manual>
AC_HEADER_STDC [Macro]
Define STDC_HEADERS if the system has C header files conforming to ANSI C89 (ISO
C90). Specifically, this macro checks for ‘stdlib.h’, ‘stdarg.h’, ‘string.h’, and
‘float.h’; if the system has those, it probably has the rest of the C89 header files.
</>
//now I see why AC_HEADER_STDC is listed as part of "Checks for header files."
AC_CHECK_HEADERS([arpa/inet.h fcntl.h limits.h netinet/in.h stdlib.h string.h sys/ioctl.h sys/socket.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
this result in 
#define HAVE_STDBOOL_H 1 
in config.h
<>
AC_CONFIG_FILES Test programs can use #if or #ifdef 
to check the values of preprocessor macros defined
by tests that have already run. For example, if you call AC_HEADER_STDBOOL, then later on
in ‘configure.ac’ you can have a test program that includes ‘stdbool.h’ conditionally:
#ifdef HAVE_STDBOOL_H
# include <stdbool.h>
#endif
</>
//the above reminds that in configure.ac everything sth is called, sth else related to it will be defined
and available for later use.

AC_C_CONST
AC_TYPE_PID_T
AC_TYPE_SIZE_T

# Checks for library functions.
AC_PROG_GCC_TRADITIONAL
AC_FUNC_MALLOC
AC_FUNC_MEMCMP
AC_FUNC_REALLOC
AC_FUNC_STAT
AC_CHECK_FUNCS([inet_ntoa memset socket uname])

AC_CONFIG_FILES([Makefile
                 libs/Makefile
		 gui/Makefile
		 gui/ui/Makefile
		 tui/Makefile
		 tui/ui/Makefile
		 cui/Makefile
		 cui/ui/Makefile
		 conf/Makefile
                 ])

//if i add conf/xxx here,  when 
$autoconf&&./configure
<error>
config.status: creating conf/xxx
config.status: error: cannot find input file: conf/xxx.in
</>
AC_OUTPUT
