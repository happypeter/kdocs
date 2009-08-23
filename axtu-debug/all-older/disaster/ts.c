>>>so if you update dbus64 on a new MT sys, you will see this.
<>
06/04/09 06:36:38 classRpmEngine failed to add to transaction  /var/c
ache/axtu/updates-released/packages/glibc-2.5-34.1AXS3.i686.rpm
<>
and this also happen to elfutil
>>>this happens here( know this by adding "3" here )
<>

                                rc = AddInstallElement(ts, hdr, strTe
mp, 0, 1);
                                if (rc > 0)
                                {
                                        headerFree(hdr);
                                        Fclose(fd);
                                        m_Logger->WriteLog_char(ERROR
_LOG, MYSELF_NAME, "failed to add to transaction3 ", strFullPath.c_st
r(), NULL);
                                        return -1;
                                }

</>
the "rc" here is obtained from
 rc = rpmtsAddInstallElement(ts, h, key, nUpgrade ,relocs);
it is in rpm, not part of axtu, and I see sth like "fixme"...god
NOTE: since the error is generated in rpmlib, so I make my decision to update rpm first,
finally, it is proved to be a wise choice.
