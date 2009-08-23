=== ssh not working ===

[root@localhost ~]# ssh  happypeter@frs.sourceforge.net
happypeter@frs.sourceforge.net's password:
Last login: Sat Aug 15 08:28:48 2009 from 125.39.34.215

Welcome to frs.sourceforge.net

This is a restricted Shell Account
You cannot execute anything here.

Connection to frs.sourceforge.net closed.


=== scp works well ===

scp -r *  happypeter@frs.sourceforge.net:/home/userweb/h/ha/happypeter/htdocs

=== sftp is the way to edit it ===

[root@localhost web]# sftp happypeter@frs.sourceforge.net
Connecting to frs.sourceforge.net...
happypeter@frs.sourceforge.net's password:
sftp> ls
diary-dump.xml  uploads         userweb
sftp> cd userweb

=== Project web access ===

[root@localhost ~]# sftp happypeter,tinylion@web.sourceforge.net



=== useful tips ===
<>
[root@localhost html]# sftp happypeter@frs.sourceforge.net
Connecting to frs.sourceforge.net...
happypeter@frs.sourceforge.net's password:
sftp> ls
diary-dump.xml  uploads         userweb
sftp> cd userweb/htdocs
sftp> ls
baronchon_giant_panda_1.png      chinesefly.jpg                   default.css
html                             index.html                       life.html
repo                             story.html                       tech.html
sftp> rm chinesefly.jpg
Removing /home/userweb/h/ha/happypeter/htdocs/chinesefly.jpg
sftp> put story.html
Uploading story.html to /home/userweb/h/ha/happypeter/htdocs/story.html
story.html                                                       100% 1928     1.9KB/s   00:01
sftp> put life.html
Uploading life.html to /home/userweb/h/ha/happypeter/htdocs/life.html
life.html                                                        100% 2071     2.0KB/s   00:00
sftp> put tech.html
Uploading tech.html to /home/userweb/h/ha/happypeter/htdocs/tech.html
tech.html 
</>
