<>
[root@localhost php-axkey]# php test_axkey.php
PHP Warning:  PHP Startup: Unable to load dynamic library '/usr/lib/php/modules/oci8.so' - /usr/lib/php/modules/oci8.so: undefined symbol: OCITypeByRef in Unknown on line 0
</>

* but this does not really matter, 
* cause when I changed sth in my own so source file.
* the change works.
*


>>>
change the $kstr="" 
and the program works

>>>so it must work like this
in the righster page, user input their product key,
test_axkey.php will read it and pass it to $kstr
then all the info can be generated and WTEC and store 
them info their customer db
