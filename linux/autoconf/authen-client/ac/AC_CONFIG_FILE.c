//so config.status will mainly use it

AC_CONFIG_FILES
4.6 Performing Configuration Actions
‘configure’ is designed so that it appears to do everything itself, but there is actually a
hidden slave: ‘config.status’. ‘configure’ is in charge of examining your system, but it is
‘config.status’ that actually takes the proper actions based on the results of ‘configure’.
//config.staus will require xxx.in to generated what listed inside AC_CONFIG_FILES()

The most typical task of ‘config.status’ is to instantiate files.
This section describes the common behavior of the four standard instantiating macros:
AC_CONFIG_FILES, AC_CONFIG_HEADERS, AC_CONFIG_COMMANDS and AC_CONFIG_LINKS.
They all have this prototype:
