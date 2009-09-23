>>>now I change
authentication_info
into
<>
authentication_key 	temporary_key 
peter 	                 111111
</>
1. try to use it to login, when I fail I realize 
passed shall be in crypt format
2. mysql> INSERT INTO authentication_info 
   VALUES ('peter', ENCRYPT('111111'),'','','','','','','','','','','','');
3. works.

>>>
reg-----succeed
acc-----fail
that must be the TK!
One thing is not good:
when I run axtu access() for many time,temporary_key in the DB does not change!
that means 
$AuthenDB->UpdateAuthenticationInfo(
does not work.

>>>suddenly I find there is file named xufen@xxx, it is a gz file, so I extract it
, unfortunately it is a src/, so it overwrite my src/, but the mixture works for everything
Strange.
temporary_key in the DB is changed!

1. check auth_mysql.conf, and reboot apache-------no problem
2. reboot client machine--------------------------no problem


>>>auctuallly, you don't need a mixture, xufen@xxx only works perfectly for WT key

the difference between my unchange_src and the xufen one is
 include "CheckProductNum.php"; 
comment out all the related statements in the unchange_src it will works as the xufeng one
Maybe it is because we
$AuthenDB->OpenDB
for more then once, so we see the failure trying to update the db
