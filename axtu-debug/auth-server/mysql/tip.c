>>>select * from persons;
>>> creat a user account
>grant select on asianux_authentication.authentication_info 
to username_string@localhost IDENTIFIED BY 'password_string';
>create user peter identified by "111111";
>>> in php
echo hello-------right
echo hello world-------wrong
echo "hello world"-----right
mysql_query("creat database my_db",$con)-----right
mysql_query("creat database my_db;",$con)----right
>>>
SELECT USER();
MySQL, you can write strings surrounded by either “'” or “"” characters
>>>select * from persons order by age;
>insert into persons values("peter",11);
