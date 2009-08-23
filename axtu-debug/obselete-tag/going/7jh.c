>>>haha, now jhtu is in my hands
and I see the whole structure of JH's patch is rather simple:
1. collect OB info in OpenHeader()
2. call ApplyObsoleteTag()
3. that's all.
 he didn't modify classGui, he added ApplyObsoleteTag() into ReadHeaders(),
the flow is the same as mine. but it bring namesapce pollution. so I still like my way.
if you do list modification inside a function called ReadHeaders(), it simplely means no body can 
trust the name of your function name anymore, which bring difficulties reading the code.
>>>
bool classRpmEngine::ApplyObsoleteTag()
{
        m_vectorObsoleteToUpdate.clear();
        if(RemoveObsoletedPackages() == false)
        if(CopyObsoletePackagesFromInstallToUpdate() == false)

}

so now I see my AdddUpdateInstallList() is not really necessary, since if a obsoleter
is on updatelist, I should not copy it to install list. so I think I will have
CopyObsoleterFromInstallToUpdate()
>>>
RemoveObsoletedPackages() do the same thing as my RemoveUpdateInstallList(), but much
more complicated, why?

>>>one thing is strange, there is no sth like IsPackageInstalled()?
A: it is done inside CopyObsoletePackagesFromInstallToUpdate()
>>>















