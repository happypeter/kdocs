>>>
git clone http://createrepo.baseurl.org/git/createrepo.git
>>>
http://www.informit.com/articles/article.aspx?p=440160-------set up a yum repo--HOWTO
/etc/yum
>>>Use creatrepo on AX3SP1
1. change /etc/yum.repo.d/asianux.repo
baseurl = http://127.0.0.1/peter
2. I put xpdf  into the dir in asianux.repo

3. $creatrepo

4. run $yum list-----then I see the right info
5. but when I copy sos into peter/------the $creatrepo
6. $yum list can only give the xpdf info, even though I rm xpdf and run $creatrepo again
7. delete all the xml in /var/cache/yum, now it is OK

>>>
1. AX3SP1 has creatrepo installed as default
2. yum-arch is not, since it is considered obselete
3. /etc/yum.conf==/etc/axtu/axtu.conf

>>>
mv what's in /etc/yum.repo.d/asianux.repo
to /etc/yum.conf
then everything still works, good
>>>
$yum list available --------run this to test if the repo is found or not

baseurl = http://127.0.0.1/peter     ---------works
baseurl = http://10.1.0.155/peter     ---------works

