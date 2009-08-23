>>>Look at how debian guys treat obsoletes

<>
   for (pkgCache::PkgIterator I = Cache.PkgBegin(); I.end() == false; I++)
   {
      // CNC:2002-07-23
      if (I->CurrentVer != 0)
      {
         // Was it obsoleted?
         bool Obsoleted = false;
         for (pkgCache::DepIterator D = I.RevDependsList(); D.end() == false; D++)
         {
            if (D->Type == pkgCache::Dep::Obsoletes &&
                Cache[D.ParentPkg()].CandidateVer != 0 &&
                Cache[D.ParentPkg()].CandidateVerIter(Cache).Downloadable() == true &&
                (pkgCache::Version*)D.ParentVer() == Cache[D.ParentPkg()].CandidateVer &&
                Cache.VS().CheckDep(I.CurrentVer().VerStr(), D) == true &&
                Cache.GetPkgPriority(D.ParentPkg()) >= Cache.GetPkgPriority(I))
            {
               Cache.MarkInstall(D.ParentPkg(),true);
               Obsoleted = true;
               break;
            }
         }
         if (Obsoleted == false)
            Cache.MarkInstall(I,true);
      }
   }
</>
