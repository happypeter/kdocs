https://bugzilla.redhat.com/show_bug.cgi?id=507702
to see the above bug convince me that rpm people are doing big changes to obsoletes now,
so it is not wise to write ob support based on 4.4.2 rpm-lib, I have to change the axtu code a lot in the future.
>>>
http://rpm5.org/cvs/fileview?f=rpm/CHANGES&v=1.2288.2
5.1.5 -> 5.1.6:
 - jbj: generate Obsoletename index in rpmdb.
- jbj: add --whatconflicts/--whatobsoletes.
<wikipedia>
Major performance improvements, less memory consumption, support for xz aka LZMA compression and several important bugs fixes are part of this release. However, these benefits come at a cost in compatiblity: RPM 4.7 introduces a new file format, which means that it is not possible to upgrade to Fedora 11 from any version earlier than Fedora 10.
</>

>>>
rpmVersionCompare(Header first, Header second)----------has epoch in mind, so maybe I can use it for axtu one day.

