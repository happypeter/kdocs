AC_CANONICAL_HOST

==manual==
AC_CANONICAL_HOST [Macro]
Compute the canonical host-system type variable, host, and its three individual parts
host_cpu, host_vendor, and host_os.
If ‘--host’ was specified, then host is the canonicalization of host_alias by
config.sub, otherwise it defaults to build.

http://en.wikipedia.org/wiki/Canonical#Computer_science
the usual or standard state or manner of something


=======
7.1 Defining C Preprocessor Symbols
A common action to take in response to a feature test is to define a C preprocessor symbol indicating
the results of the test. That is done by calling AC_DEFINE or AC_DEFINE_UNQUOTED.
