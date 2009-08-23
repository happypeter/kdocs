Now I am doing axtu development, now if I simply run git push
then all the .o and .a files will be in remote repo, which I hate.
so I need to know how to commit and push specific files.
now I do a test here in git/
$git mv git.c 1.c
$git commit 1.c -m "from git.c"
then inside anther clone of this repo
git pull
you will get 1.c, but git.c is still there! Be careful.
>>> the right solution is use git commit and push as before,
just never run  git add .
>>>
<error>You asked me to pull without telling me which branch you</>
<sulo>
$git pull git@github.com:happypeter/axtu.git
</>

=== git diff ===
[root@dhcp17 test-axtu]# git add .
[root@dhcp17 test-axtu]# git diff --cached
diff --git a/ChangeLog b/ChangeLog
index b34b813..a69811a 100644
--- a/ChangeLog
+++ b/ChangeLog
@@ -1,3 +1,5 @@
+peter
+xxx

