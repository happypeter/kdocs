the vmware tar-os does not work well, so we decide to use keith's big machine to install a MT sysyterm
>>>below is how hwanii do this
  921  fdisk /dev/sdb
#here n=new d=delete...
  922  mkfs.ext3 /dev/sdb1
#format the partition
  927  vi mtt_load_sys.sh
#change into "img_repo=/mnt/sdb1"
  929  mount /dev/sdb1 /mnt/sdb1
#this partition is used to store the tar file
  931  sh mtt_load_sys.sh -c
#show tars
  933  sh mtt_load_sys.sh -di -t 30sp1090616.tar -p /dev/sdb2
it ends here
<>
 failed to install grub of the test system on $disk_partition
 please install manually. you may edit host grub.conf to use it ... not a good idea though.
</>
>>>>so I need to cp grup entry myself
1. cp a entry from /opt/boot/grup/grup.conf to /boot/grup/grup.conf
2. reboot, now the error is 
<>
/boot/initrd-2.6.18-53.11AXS3.img not found...
<>
>>>to fix it see ../tar-os.c
<>
[root@dhcp24 opt]# cp /etc/modprobe.conf etc/
cp: overwrite `etc/modprobe.conf'? n
[root@dhcp24 opt]# diff /etc/modprobe.conf etc/modprobe.conf
[root@dhcp24 opt]# chroot /opt/
chroot: cannot run command `/bin/bash': Exec format error
[root@dhcp24 opt]# cd ..
[root@dhcp24 /]# chroot /opt/
chroot: cannot run command `/bin/bash': Exec format error
[root@dhcp24 /]# arch
i686
[root@dhcp24 /]# file /bin/bash
/bin/bash: ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), for GNU/Linux 2.6.9, dynamically linked (uses shared libs), for GNU/Linux 2.6.9, stripped
[root@dhcp24 /]# cd /opt/bin/
[root@dhcp24 bin]# file bash
bash: ELF 64-bit LSB executable, AMD x86-64, version 1 (SYSV), for GNU/Linux 2.6.9, dynamically linked (uses shared libs), for GNU/Linux 2.6.9, stripped
</>

//I think is because I am using a 32 bit systerm so I can not change root to use a 64 bit bash, Huajie said it simply can not be done
//so he extract a 32 bit initrd-xxx.img, replace all the binary files with 64 bit binarys in /opt/,
then boot the kernel and initrd with grub command, it works. and I add a entry to grub.conf myself, now everything is all right
//and another idea come to me maybe I can cp the vm-sever 64bit initrd.img file here.
