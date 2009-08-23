>>>
* the main rutine of php-axkey/
* test_axkey.php
* within it there is
* include ("axkey.php");
* axkey.php is used to load
* php_axkey.so
*
* >>>
* in test_axkey.php, what mattaters is actually this:
* axkey_get_val($kstr, 2); 
* which is provided by axkey.c,
* axkey.c will use libaxkey.c.
* So all the .c files must be in php_axkey.so now.
* >>>
* this way I think I am clear with php-axkey/ now.
* It is all about key info acquisition. like axkeychk/
* I do not need to study swig to know how to connect 
* C and PHP.
