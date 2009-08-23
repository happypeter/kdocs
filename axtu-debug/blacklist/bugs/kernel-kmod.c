http://bugzilla.asianux.com/show_bug.cgi?id=6514
After add depended kernel to blacklist, update kmod-redcastle still succeed.
>>>
at first sight, I thought maybe there is no blacklist check during Dealwithdependency()
but tested with other pkgs, then I know it is not ture.
Why kernel is special here?

A: axtu traditionlly only apply blacklist check to pkgs to be updated, since kernel is always installed,
hence this bug.
<>
  if (nUpgrade)
        {
                if (CheckBlacklist((const char *)key) == true)
                {
                        m_vectorBlockedUpdatePackages.push_back((const char *)key);
                }

</>

I want to set this WANTNOBUG for two reasons:
1. kmod-redcasltle can not work without the matching kernel,
so user should not updated it after setting the matching kernel to blacklisted
All in all, this bug can only be seen when the manipulation is wrong.

2. the point of using blacklist is to avoid useful value being removed from systerm,
e.g, you install firefox through the tar ball. Then if you do not set firefox as blacklisted,
axtu will remove your former firefox eventhough it is the lastest version!

so it will be rediculous to use it for pkg you want to install, since nothing will be deleted this way.
And this is just way axtu is initially designed this way.
