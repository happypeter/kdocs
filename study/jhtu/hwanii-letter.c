 	
Peter,

As I said, this source was made based on AXTU source including the following features.
Please study it. If you have questions of find someting different from the description
below, please share with us.

1. rpm 4.6(4.7) support
 - Adopted to new API of 4.6(=4.7)  (AXS3 is on 4.3???..)

2. Fix in dependency checking engine.
 - new engine checks files of each package as well.
   It may cause slow operation.
   It was to solve some problem they met with few packages (They don' remember the
   names of packages)
  
   (I think the problem could have been the same problem as what we solved by
   including RPM package and few others into SELF repository.)

3. obsolete tag handling
 - This is different from JongWoo's packages. (It is not a temporary fix)
   It does not deal with the blacklist related bugs we have found nor the warning messages.
   The other behavior are the same as our plan.

4. epoch handing
 - you know this.. it is maybe a little bit different from your patch.



Cheers,
Hwanii


