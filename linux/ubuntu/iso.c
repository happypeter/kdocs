last change in 10_20_2008

http://ubuntuforums.org/archive/index.php/t-6509.html


November 29th, 2004, 09:35 AM

This is very helpful to backup your cd and dvd into iso images:

To make an ISO from your CD/DVD, place the media in your drive but do not mount it. If it automounts, unmount it. (ubuntu automount so you need to unmount, that's quite easy, just choose the option unmount from the shell).

dd if=/dev/dvd of=dvd.iso # for dvd

peter: the above works, a dvd.iso is obtianed, you do not need to umount dvd beforehand

dd if=/dev/cdrom of=cd.iso # for cdrom -------------works on Asianux as well

dd if=/dev/scd0 of=cd.iso # if cdrom is scsi

To make an ISO from files on your hard drive, create a directory which holds the files you want. Then use the mkisofs command.

mkisofs -o /tmp/cd.iso /tmp/directory/

This results in a file called cd.iso in folder /tmp which contains all the files and directories in /tmp/directory/.

when the iso is obtained, right click it and choose CD/DVD creater, soon you will own a new bootable disk. 
