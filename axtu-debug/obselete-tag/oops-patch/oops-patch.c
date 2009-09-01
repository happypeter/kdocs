Patch0: axtu-1.5-obsolete-case.patch


Patch1: axtu-1.5-obsolete-upgrade.patch
//this patch is to solve this issue, when A>B (!A&&B)==true, then we need to add A
//to update list, but we actully shall install it.-----Now I tend to believe it shall be updated, because if you 
//rpm -i libdhcp-devel-xxx, pump-devel won't be removed
//P5 and P7 is the fix of the problem arised by this patch

Patch2: axtu-1.5-obsolete-bug.patch


Patch3: axtu-1.5-obsolete-warning.patch
//for the message box, see 10warning-messages.c

Patch4: axtu-1.5-obsolete-version-check.patch
//this patch has nothing to do the obsoleteVersion you get from hdr file
//It just means only libdhcp-devel the older than 1.20-1AXS3, shall be considered
//strange?
//but maybe I need to check all obsoleteversions myself


Patch5: axtu-1.5-obsolete-fix-upgrade.patch
//my current guess is Update sos all the time, no matter it is on update or install list
//no matter sysrport is installed or not, no matter sos itself is installed or not.
//my only worry here is if either sos and sysreport is installed, is it OK to just Update sos?
//
Patch6: axtu-1.5-obsolete-remove-updatelist.patch
//this patch shall go in P0

Patch7: axtu-1.5-obsolete-fix-upgrade-x86_64.patch

