find ~/linux-2.6.20.12-sunxq/include/asm -name gpio.h -print
 
cd ~/linux-2.6.20.12-sunxq/include/asm
 
grep -r s3c2410_gpio_getpin .
 
find path -name "filename" -print|grep "string"
 
find /lib -name "*lib"
 
find / -name "linux" -print //now you will see all the file named linux
 
find / -name "hw_irq*" -print
 
find . -exec grep "sss" "{}" \; -print 
************
#find -name *spi*
 
all files under the current directory
 
with 'spi' in their name is listed out for you soon
**************
>>>
For example, to find files whose name contains the word ‘mkdir’:
 $ locate mkdir
 /usr/man/man1/mkdir.1.gz
 /usr/man/man2/mkdir.2.gz
 /bin/mkdir



 grep "inc" * --p


$find . -name "rc.conf" -print

>>>How to search for a string in a selection of files (-exec grep ...).

    find . -exec grep "www.athabasca" '{}' \; -print
>>>my xxx
<bin/xxx>
find . -exec grep "$1" '{}' \; -print
#peter add
<bin/xxx>                                                   
