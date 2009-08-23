I can find pngs from jon's openclipart lib.
Now I want the sf same as github.
which means, I will have local copy of the data, but 
the remote site will be the final authority.
<>
[root@localhost sf]# scp -r  happypeter@frs.sourceforge.net:/home/userweb/h/ha/happypeter/htdocs .
</>
===ssh is definately what i must have
https://sourceforge.net/apps/trac/sourceforge/wiki/Shell service

all I need to do is

ssh -t USER,PROJECT@shell.sourceforge.net create

