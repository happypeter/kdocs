GIT
>>>
git init
git add
git commit -a -m "useful info"
git tag v0.1
git tag v0,1 xxxxxx

git branch stable v2.5 # start a new branch named "stable" based on v2.5 

git branch -d branchname   # delete a branch

>>>how to delete tags?

>>>peter@peter-laptop:~/peki/.git/refs/remotes/origin$ vim master

what is in master is the last commit number

$git mv svn svn.c
#git rm sds

>>>when you do nothing else, but you encounter a
"[rejected!]" error, when you try to push
that must because comit conficts, 
which means you've done another commit&push in another repo
you can check it with $git log

>>>Asianux git
1. download the lastest tar ball from git-scm.com
2. configure->make->make install
3. at the beginning I can not clone anything from web
4. but today I went to /mnt/ubuntu/home/peter/peki, and run $git pull
7. after that I can do anything, haha, do not know why

>>>how to merge
[root@dhcp03 libs]# git branch
  master
* test2
[root@dhcp03 libs]# git checkout master
Switched to branch 'master'
[root@dhcp03 libs]# git merge test2

>>>add remote repo----from github.com
  git config --global user.name "Your Name"
  git config --global user.email happypeter1983@gmail.com
Next steps:

  mkdir axtu
  cd axtu
  git init
  touch README
  git add README
  git commit -m 'first commit'
  git remote add origin git@github.com:happypeter/axtu.git
  git push origin master
>>>today I copy the ssh key from host machine to my xen vm, and it works for "git pull"   


>>>OK I am makeing a change on branch test
git branch test
git checkout test
//make a change
git diff -p master -- . > my-patch.txt
then I
peter@peter-laptop:~/kdocs/linux/git$ git checkout master 
M	linux/git/1.c
Switched to branch "master"
peter@peter-laptop:~/kdocs/linux/git$ git apply  my-patch.txt
linux/git/my-patch.txt:10: trailing whitespace.
>>>today I copy the ssh key from host machine to my xen vm, and it works for "git pull"   
linux/git/my-patch.txt:18: trailing whitespace.
 
error: patch failed: linux/git/1.c:53
error: linux/git/1.c: patch does not apply
//fuck failed 
