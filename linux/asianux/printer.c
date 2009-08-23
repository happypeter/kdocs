http://hplipopensource.com/
Choose RHEL 5.0
$hp-setup ---------to install plugin
done
then a error "PPD file not found"
/etc/init.d/cups start  ---------is required here

here I used defualt one hp-laserjet_p1007.ppd.gz.
<>
[root@localhost doc]# cd /usr/share/cups/model/HP/hp-laserjet_p1007
hp-laserjet_p1007-hpijs.ppd.gz  hp-laserjet_p1007.ppd.gz
</>
finish. no error.
but when i open a pdf, and print
error is "lp:Error--no deault destination available"
reboot my machine, now the error is 
error is "lp:Error--shedualer is not responding"
However open a pic or webpage you can print

if you use hp-print, you can print pdf as well
