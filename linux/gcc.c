= PIC =
{{{
 Re: what is -fPIC gcc compile option
In much older versions of the compiler gcc there was a flag "-fPIC" which was an abbreviation for Position Independent Code, and this had to be passed to create library code objects, without that flag, code that is specific to the source would be used, and then the library would fail.

Gerald
}}}

= O2---optimization level 2 =
{{{
$man gcc
...
 -l library
           Search the library named library when linking.  (The second alternative with the library as
           a separate argument is only for POSIX compliance and is not recommended.)

           It makes a difference where in the command you write this option; the linker searches and
           processes libraries and object files in the order they are specified.  Thus, foo.o -lz
           bar.o searches library z after file foo.o but before bar.o.  If bar.o refers to functions
           in z, those functions may not be loaded.

           The linker searches a standard list of directories for the library, which is actually a
           file named liblibrary.a.  The linker then uses this file as if it had been specified
           precisely by name.

           The directories searched include several standard system directories plus any that you
           specify with -L.
}}}
