http://bugzilla.asianux.com/show_bug.cgi?id=6500

According to our 
obsolete tag treatment feature plan.xls
since sos obsoletes sysreport 
if sos is available on server
       sysreport will not be shown on update list
       so there is no need to set it blacklisted
if sos is NOT available on server
       sysreport will be treated as normal pkg

Since I will soon remove oopslee's obsolete tag patches, and apply my own one,
so this bug will soon be fixed.
