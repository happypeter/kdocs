1. install ubuntu first
2. install asianux S3SP1
3. vim /etc/fstab -----on asianux
   /dev/sda6               /mnt/ubuntu             ext3    defaults        0 0
   add the above line to its tail, then automount is set.
4. find the xen kernel boot Entry in asiannux:/boot/grub
   add it to ubuntu grub.conf
5. you need to 
[root@dhcp17 ubuntu]# mount -f /dev/sda2 /mnt/ubuntu/boot/
before you see anything in /mnt/ubuntu/boot/
