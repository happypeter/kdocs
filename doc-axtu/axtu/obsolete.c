to implement axtu obsolete tag support, I need to read out "obsoletes" from server-side hdr files.
Last time when I read epoch, it is in local rpmdb. but they are not so different!
All I need to do is to readout info from Header.
    RPMTAG_OBSOLETENAME  

