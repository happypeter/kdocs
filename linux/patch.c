diff+patch
diff -Nurp filea fileb >peter.patch

>>>

Patches can be undone, or reversed, with the '-R' option:

 $ patch -R < mods.diff

>>>
patch usually do not mind if the file to patch is changed only if the so called 

"context" is not changed
>>>
use hexdump to diff binary files
