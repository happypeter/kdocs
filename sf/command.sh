===copy all the local files to peter-home===

scp -r *  happypeter@frs.sourceforge.net:/home/userweb/h/ha/happypeter/htdocs

=== clone peter-home to local sys ===
not working...

scp -r happypeter@frs.sourceforge.net:/home/userweb/h/ha/happypeter/htdocs/* .

===login to peter-home===

sftp happypeter@frs.sourceforge.net

cd userweb/htdocs/

=== Project web access ===

sftp happypeter,tinylion@web.sourceforge.net

=== tinylion clone ===

git clone ssh://happypeter@tinylion.git.sourceforge.net/gitroot/tinylion 

=== ssh login ==

ssh -t happypeter, tinylion@shell.sourceforge.net create

//not so bad, haha I like it
