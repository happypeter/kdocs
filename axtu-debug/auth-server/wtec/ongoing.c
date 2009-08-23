On going

1. if nothing is changed in server and client, when you delete /var/axtu/axtu-authen  //the ak

the error is : product key is not right

2. when I use my own client, the the product key is accepted, now it requires user ID, and passwd, of course I do not have the ones
for wtec, so I just use user3+abc123, when I press finish, the error is "can not connect with authen server", I know I need to change
/etc/hosts

3. when I change /etc/hosts, add

10.1.0.155        peter.wt.com

now the error is "product number is not correct, retry or sign up", if you press sign up, you will be connect to
http://peter.wt.com, which is what I wrote in conf/xxx.conf [signup], so I do not need to worry about this.

4, one good thing now is, if I change /user/share/axtu-auth-client/.conf/xxx.conf

change
WT http://peter.wt.com/auth/src/authitification.php";
into
WT http;//peter.wt.com/
Now the error turns into
"can not connect to authen server",
that's great, that means I can now connect auth server with wtec product number.

5. One Problem here is
in /var/axtu/xxx.conf
selected  is chnaged form WT to "NONE", once the auth server is connected. 
//if you set WT  a wrong authen addr, it will be changed from what ever to WT and will not be changed again.
It's obvious that nothing is wrong of client side, it is the lack of server side db value that is responsible.
I will hold the problem now, but it requires more attention later.

6. so at git master time Apr 16 09:47:55(you can see it with $git log), I think the client side is perfect.


>>>>>>>>>>>>>>>>>>>>>>>Time for the Server Side

7.
 if( (strlen($authen_key) == 0) && (strlen($product_number) != 0)){
                                include "RegActions.php";

                                $return_value=RegAction($ref_ak,$ref_tk,$IsLocalProduct,$userid,
                                        $password,$system_name,$product_number,
                                        $ip,$mac,$arch,$hash_value,$host_name,$product_type);

8.
I changed the phps a lot now the error is "user ID and passwd not right"
that means the product number matched. good.

9. the userID and passwd check is in
RegDataCheck()
you need the signup page url to fix it, so I do nothing
I commented out RegDataCheck,
and now the error is
"product type not right"
I can see this error, because
of this file in /etc/axtu/tmp/authentification.php
with [authentifacation] and result=-3 inside
delete it and run axtu-auth-server again, it shows up, haha
in the client source file
#define ERR_PRODUCTTYPE_CHECK_FAIL      -3


10. this check is in
CheckInstalledOSName()
CheckInstalledOSPlatform()
both failed // I tested it
so I added the server db info and the problem solved.
Now in /etc/axtu/tmp/authentifacation.php--------------it is generarted by the server and read by the client to generate the error message
result=-11; //server internal error #003

11. Now I see AK and TK are successfully generated, and UsrID and other things are all saved successfully I authentication_info
and register_info
12.Now obviously sth wrong here
$num=$AuthenDB->GetRepositoryUrl($ref_ak,$product_type,$IsLocalProduct);

note: here, "if(!$IsLocalProduct)" is executed

13. In connect_info
Change "update.redflag.com" into "peter.wt.com", and now my job is done.hahahahha

"peter.wt.com" is in
axtu-authen-client/conf/axtu-authen-client-addr.conf.
Now if you see axtu->Setup, you will find peter.wt.com on the ui page

>>>>>the the reg process is done, but not access()
14. Now when you try to "access()" with the new AK
axtu(not axtu-authen-client) gives out a error "Cannot connect to the authentication server"
So I test it and find the access() in authen-client run successfully, but it seems the it gives sth wrong to axtu, so axtu compliants.

15.
#define AUTH_ERR_MSG   Cannot connect to the authentication server
 QMessageBox::critical(this, staticTitle, (AUTH_ERR_MSG));
show_NetworkErrorDialog(int nErr)
  else if (show_NetworkErrorDialog(nRet) == false)

 nRet = m_Network->GetHeader();
 nRet = m_Network->GetPackages();

 err_value=GetHdrFile(strUrl);
strUrl=it->strUrl + "/headers/" + strDownloadFileName;

#define CONFIG_FILE         "/etc/axtu/axtu.conf"
NOTE: there is no ./RPMS/packages/ dir, WHY???

according to the log file, the error happens around here
 m_Logger->WriteLog_char(DEBUG_LOG,"Cannot get .hdr",strTemp.c_str(),NULL);

GUI Network error(-3) is occured.

16. but if you use RF product key now, everything is right again. SO no need to change axtu I am sure.

Now even RF key does not work, and I even change 'src' to the former good one. still error for RF key.
 

>>>in Readme
and then You have to make a user that has the 'select' permission.

>grant select on asianux_authentication.authentication_info to username_string@localhost IDENTIFIED BY 'password_string';

grant select on asianux_authentication.authentication_info to axtu@localhost IDENTIFIED BY 'axtu';

$service mysqld restart-----------------won't help


>>>for redflag only----------I see selfupdate done successfully, but when axtu try to download sth in "UPDATE", same error as before
so I
[root@update conf.d]# vim auth_mysql.conf   ------------comment out "x86 update" part
[root@update conf.d]# apachectl graceful  ---------------restart apache
//pay attention to mysqld

then problem solved

1. now I am using my own src------works
2.

 # /etc/init.d/httpd restart
# /etc/init.d/mysqld restart

3. a very strange thing is this:
- when I am using a old version of axtu,
so I first connect to real redflag
it is nice, and I am asked If I want to update axtu itself,
I say no, then try to connect to 155.
Now the error is "Cannot connect with TSN server".
-the strange thing is When you try to connect real redflag now.
- the same error occur.

4. Now I know the reason: when you trying to connect 155, you write some garbage into
/etc/axtu/axtu.conf
[self]
<href="func....">
if you have this trash here, you won't be to connect anywhere, even you reboot.

5.  EchoRepositoryUrl() is doing this for us.

------> how /etc/axtu/axtu.conf is changed?

1. in axtu source code. it is named CONFIG_FILE

2. /var/axtu/.axtu.new is obtained is axtu-authen-client
- and then axtu will read its info and copy it into CONFIG_FILE

3. now I add 'return  false;' in sever code CheckInstalledOSName
so that the program can stop suddenly and I can see a file in
client side :/var/axtu/tmp/authentication.php
here I see the grabage <funtion.fopen()>

4. it is obviously generated on server side, but I need to find it first
so I study axtu-authen-client
GetDownloadFileName()----------it must be authentication.php

5. Jiuxing helped me to remove these garbage by adding
error_reporting(E_ALL & ~E_NOTICE);
in
log.php
and now nothing is in authentication.php
but still the same thing in axtu.conf

Now suddenly the problem disappears, before I do anything else-------maybe-Jiuxing is changing the php settings

***>>>Succeeded again using 155 RF<<<***

Now the ENV:
using my ongoing src/
using one of the old xxx.sql backups
and I changed /etc/httpd/conf.d/auth_mysql
run $...graceful
now I use my own clent/ branch w
<pre>
Date:   Thu Apr 16 09:47:55 2009 +0800

    change ui fo r test
</pre>

> now I am trying to use Wtec key
so I add info to db
then I see a product type error, so I add return true
now rigster done.
>now I see the error
fail to connect authentifation server
so I changed connect_info
change
update.redflag-linux.com
into
peter.wt.com
>now everything is right--------I test for the possible cases no problem,
so I will backup everything now in  /~/wtec-slo/
Now if you change auth_mysql.so back,
then the GUI(-3) error again
>On the auth_mysql issue, whatever happens to WTEC happens to RF as well,
which convince me that there is no need to change my souce code any more

>.
/etc/httpd/logs/error_log-------------useful


>>>NOW, all my attention shall be paid to auth_mysql.conf problem

1. mysql -u root -p < mysql_script_for_move_id_field.sql-------------makes no difference

2. /etc/init.d/mysqld restart------------then I see "server internal error 001", reboot 155, then the error gone

3. 
