root@10.1.0.40:/mnt/ xxx.tar---------the latest MT sys
abc123


===========Hwanii script to make tar test sys=====================
VMare-server
add hardware->add harddisk
boot the vm
then
fdisk -l
/dev/sdb-----is the one we added

fdisk /dev/sdb
#mount /dev/sdb1 /opt--------maybe this is in hwanii's script
sh mtt_load_sys.sh -c
sh mtt_load_sys.sh -di -t 30sp109,tar -p /dev/sdb1
<>
[root@dhcp15 ~]# sh mtt_load_sys.sh -c
30sp1090616.tar
axs3_i386_mtest090522.tar
test_image.tar
[root@dhcp15 ~]# sh mtt_load_sys.sh -di -t 30sp1090616.tar /      
===================Hwanii end=====================================`
>>>Actully the doc given by gloria teach me better
1. have a partition or disk, say sda2
2. mount it to /opt ---------have to be "/opt"
3. tar xvf ...
4. copy /opt/boot/grub/grub.conf-----the entry to /boot/grub/grub.conf
<>
## START:30sp1090616.tar Automatically generated entry..
title Asianux Server 3 (Quartet SP1) (2.6.18-53.23AXS3)
        root (hd1,0)
        kernel /boot/vmlinuz-2.6.18-53.23AXS3 ro root=LABEL=/mt3121
        initrd /boot/initrd-2.6.18-53.23AXS3.img

## END:30sp1090616.tar
</>
I think (hd1,0)=sdb1

>>>Can not init 5 to see gui
1. system-config-display-------works, /etc/X11/xorg.conf
2. basiclly what has been done is change the driver form "nv" to "vmware"
3.but when I init 5------still can not be done
Huajie said it is because I am already in level5,
all i need to do is $startx---------done


<GLORIA-INSTUCTION>
Evnironment setup
1. requires 7G space, 15G is prefered
2. 10.1.0.40:/mnt/ x86 and x86_64 tar go here
3. change grup setting
4. config X
5. 


1.make clear lable of a partition（make sure the size fo the partition is more than 10G，15G is preferred）
#e2lable /dev/sda5
let's say the vaulue we get is /1
2.format it
#mkfs.ext3 /dev/sda5 <-- since we want to put our systerm on sda5
3.
#mount /dev/sda5 /opt NOTE: has to be /opt
#cd /  --------this step is necessary
#tar xvf mtest.tar
then everything will go into /opt
4.change grub setting
title Asianux Server 3 (Quartet) (2.6.18-8.16AX)
root (hd0,4) <-- sda5
kernel /boot/vmlinuz-2.6.18-8.16AX ro root=LABEL=/1 <-- the label we got in step 1
initrd /boot/initrd-2.6.18-8.16AX.im

change lable of the partition
#e2lable /dev/sda5 /1 NOTE:do it before reboot
#vi /opt/etc/fstab change lable into /1

5.generate initrd。
#cp /etc/modprobe.conf /opt/etc/
#chroot /opt
#cd boot
#mv initrd-2.6.18-8.16AX.img initrd-2.6.18-8.16AX.img.bak
#mkinitrd -f initrd-2.6.18-8.16AX.img 2.6.18-8.16AX
#exit
6. reboot 
7. done

</>
