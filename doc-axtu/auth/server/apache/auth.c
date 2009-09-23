>>>refer to apache doc/A.A.A---http://httpd.apache.org/docs/2.0/howto/auth.html#related
1. htpasswd -c /usr/local/apache/passwd/passwords peter
2. Now in conf.d/auth_mysql.conf
<>
AuthType Basic
AuthName "Restricted Files"
AuthUserFile /usr/local/apache/passwd/passwords
require user peter 
</>
3. works!

>>>I add in httpd.conf, this line
LoadModule mysql_auth_module modules/mod_auth_mysql.so
but I see error when I run $apachectl graceful


>>>
<Directory /var/www/html/peter/>
    AuthName "MySQL group authenticated zone"
    AuthType Basic
    AuthMYSQLEnable on
    AuthMySQLUser authuser
    AuthMySQLPassword PaSsW0Rd
    AuthMySQLDB auth
    AuthMySQLUserTable users
    AuthMySQLNameField user_name
    AuthMySQLPasswordField user_passwd
    require valid-user
</Directory>

* I type in testuser and testpass, then it is done

>>>
<Directory /var/www/html/peter/>
    AuthName "MySQL group authenticated zone"
    AuthType Basic
    AuthMYSQLEnable on
    AuthMySQLUser axtu
    AuthMySQLPassword axtu
    AuthMySQLDB auth
    AuthMySQLUserTable users
    AuthMySQLNameField user_name
    AuthMySQLPasswordField user_passwd
    require valid-user
</Directory>
then I run
>INSERT INTO users VALUES ('axtu',  ENCRYPT('axtu'), 'user'); 
1. Now  type in testuser and testpass, then failed.
2. GRANT SELECT ON auth.users TO axtu@localhost IDENTIFIED BY 'axtu'; 
3. done

>>>on 155
<>

mysql> CREATE DATABASE auth;
Query OK, 1 row affected (0.03 sec)

mysql> USE auth;
Database changed
mysql> CREATE TABLE users (
    -> user_name CHAR(30) NOT NULL,
    -> user_passwd CHAR(20) NOT NULL,
    ->  PRIMARY KEY (user_name)
    ->  );
Query OK, 0 rows affected (0.05 sec)

mysql>  INSERT INTO users VALUES ('peter', ENCRYPT('111111'));
Query OK, 1 row affected (0.01 sec)

</>
then I can get s, without doing anything else.
that means I should not  worry about GRANT things.

>>>
Now I do the same to 155:/auth/asianux2/AXS3-RF/x86/UPDATE
it works as I expected
<Directory /var/www/html/auth/asianux2/AXS3-RF/x86/UPDATE>
    AuthName "Peter zone"
    AuthType Basic
    AuthMYSQLEnable on
    AuthMySQLUser axtu
    AuthMySQLPassword axtu
    AuthMySQLDB auth
    AuthMySQLUserTable users
    AuthMySQLNameField user_name
    AuthMySQLPasswordField user_passwd
    require valid-user
</Directory>

