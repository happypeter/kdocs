>>>
B1:
http://bugzilla.asianux.com/show_bug.cgi?id=6487
Some conflicts related to obselete tags
A: my patch can cover this.

>>>
B2:
http://bugzilla.asianux.com/show_bug.cgi?id=4396
there is no "Obsolete" tab in the libdhcp spec to make pump "obsolete"

>>>
B3:
http://bugzilla.asianux.com/show_bug.cgi?id=5994
There is no warning when axtu remove obsoleted package.

>>>
B4:
http://bugzilla.asianux.com/show_bug.cgi?id=5997
Can not remove package sysreport when user install package sos.
A: my patch can cover this.

>>>
B5:
http://bugzilla.asianux.com/show_bug.cgi?id=6013
[Test Case 2135] Axtu will remove sysreport even it is in blacklist during updating.

>>>
B6:
http://bugzilla.asianux.com/show_bug.cgi?id=6171
[Test Case 2135] Can not remove package sysreport after update package sos. (package sysreport was installed in system before
A: my patch can cover this.
>>>
B7:
http://bugzilla.asianux.com/show_bug.cgi?id=6172
[Test Case 2135] Package sysreport can't be in INSTALL list after update package sos. (package sysreport was installed in system before)
A: Let's wait for  YUM team to fix it first!
see ../problem.c: P2:
>>>
B7:
http://bugzilla.asianux.com/show_bug.cgi?id=6173
[Test Case 2135] Package sysreport can't be in INSTALL list after install package sos. (package sysreport wasn't installed in system before)

>>>
B8:
http://bugzilla.asianux.com/show_bug.cgi?id=6174
[Test Case 2135] Package sos won't be installed when install package sos. (package sysreport was installed in system before and in blacklist)

