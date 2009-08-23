>>>
> fatal: protocol error: expected sha/ref, got ‘

The above error is caused by wrong repository cloning. 
On your project page there are two links, one is public and the other one is for contributors:
Public Clone 
URL: git://github.com/xxx/yyy.git Your Clone 
URL: git@github.com:xxx/yyy.git 
So use the second one.


===
when you try to add ssh pub key, add it to your account rather then to every repo.
You will need different keys for every repo.

