# Process this file with autoconf to create configure.

AC_PREREQ(2.59)

AC_INIT([hello], [1.0], [peter@asianux.com])
AC_CONFIG_HEADERS([config-h.in:config.h])
#peter add the following line
AC_CHECK_LIB([rpm], [main],[],AC_MSG_ERROR([librpm not found!]))
AM_INIT_AUTOMAKE([1.9 foreign])
CFLAGS="$CFLAGS -O2 -Wall -Wno-implicit -static"
AC_PROG_CC
AC_C_CONST

AC_PROG_LIBTOOL

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
