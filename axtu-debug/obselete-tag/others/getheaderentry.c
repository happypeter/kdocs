       { "RPMTAG_EPOCH",       1003,   RPM_INT32_TYPE },
http://www.rpm.org/max-rpm/s1-rpm-rpmlib-functions.html
RPM_INT32_TYPE — The entry contains a thirty-two-bit integer.
 { "RPMTAG_NAME",        1000,   RPM_STRING_TYPE },
RPM_STRING_TYPE — The entry contains a null-terminated character string. 
 { "RPMTAG_OBSOLETENAME",        1090,   RPM_STRING_ARRAY_TYPE },
 { "RPMTAG_OBSOLETES",   RPMTAG_OBSOLETENAME,    RPM_STRING_ARRAY_TYPE },
PM_STRING_ARRAY_TYPE — The entry contains an array of null-terminated strings. 
Note that if the entry type is RPM_STRING_ARRAY_TYPE, you must issue a free() on p when done with the data. 
http://www.rpm.org/max-rpm/s1-rpm-rpmlib-example-code.html---------need attention

>>>axtu also has good example for this
in classRpmEngine::GetHeaderInfo()
axtu uses
headerGetEntry(h, tag1[j], &pt2, (void **)&data, NULL)
to get data, and use
strdup((char *)data)
to read things out.

>>>one funny news is that apt has thrown away headerGetEntry().
git clone http://apt-rpm.org/scm/apt.git

<git log>
    Eliminate use of headerGetEntry() in rpmhandler
    - use raptHeader() methods instead, makes the whole thing a whole lot
      nicer and saner
</>

and they are using rpm/raptheader.cc instead. 
so rpm has C++ API? what version of rpm-lib they are using here?
