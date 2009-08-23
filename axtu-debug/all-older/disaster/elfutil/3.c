>>>so on a MT_systerm connecting to 219
1. click only elfutil-libdef-devel
2. see ../log.e/
3. the error message "peter..." is added in AddInstallElements
4. maybe this means the %{arch} is not a probelm here at all.
5. when I change the dep check loop from 5 to 50, error log changed, but still the similar probelm

>>>when I install glibc properly, and then choose all the elfutil packages on updatelist
then I believe all the problem in ../log.e/ will be soloved. 
then I see ../log2.e, 
the error is just what we saw during the meeting with Huajie.
but see the debug log we know 
<>
06/08/09 02:22:34 classRpmEngine Find required packages :  /var/cache/axtu/updates-released/packages/elfutils-devel-static-0.
137-3AXS3.i386.rpm
</>
so "i386" in  "elfutils-devel-static-i386" is not a problem.
what really matters is this
<>
06/08/09 02:22:34 classRpmEngine failed to add to transaction  /var/cache/axtu/updates-released/packages/elfutils-devel-stati
c-0.137-3AXS3.x86_64.rpm
</>
just like what happened to glibc
