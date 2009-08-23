#!/bin/sh
#
# Test system setup ! v0.3.5
# Software Maintenance Team 
#

# repository 
repo_server=lunar
repo_server_user=mttest
# mt=maintennance test
repo_server_path=/home/$repo_server_user/mt_images/
#localserver
img_repo=/mnt/sdb1



# dont touch!?? 
partition_lable=/mt$$


tmp_f=/tmp/m$$
mnt_chk=
mkdir -p $img_repo &> /dev/null

cleanup() {
	if [ ! -z $mnt_chk ]; then
		umount /opt/dev &> /dev/null
		umount $disk_partition
		echo $disk_partition unmounted..
	fi
	rm -rf $tmp_f
}

usage() {
cat <<usage_lala
 `basename $0` -c
  # to check the mt_test images from repository server $repo_server
	
 `basename $0` -d -t TARGET_IMAGE_NAME
  # to download a test system image from repository server $repo_server
  # to local reposigory.

 `basename $0` -i -t TARGET_IMAGE_NAME -p TARGET_PARTITION
  # to restore to TARGET_PARTITION

 `basename $0` -id -t TARGET_IMAGE_NAME -p TARGET_PARTITION
  # to downalod a test system image and restore to TARGET_PARTITION
 
 `basename $0` -s -t IMAGE_NAME -p TARGET_PARTITION
  # to save a test system as IMAGE_NAME in local repository 
 
 `basename $0` -u -t IMAGE_NAME
  # to upload a test system image to the server 

 `basename $0` -su -t IMAGE_NAME -p TARGET-PARTITION
  # to save a test system system and upload it to the repository server 

** local repository is currently "$img_repo". you can setup in this script

 ex)
  `basename $0` -c
 # images in the repository server will be displayed
 
  `basename $0` -di -t axs3x86_64_20090606.tar -p /dev/sda5
 # it will download the test images (only when it has not downloaed yet) 
   and restore the system to /dev/sda5

  `basename $0` -d -t axs3x86_64_20090606.tar 
 # it will download axs3x86_64_20090606.tar from the repository server

  `basename $0` -u -t axs3x86_64_20090707.tar
 # it will upload axs3x86_64_20090707.tar from $img_repo to $repo_server

  `basename $0` -su -t axs3x86_64_20090606.tar -p /dev/sda5
 # it will save a test system on /dev/sda5 as axs3x86_64_20090606.tar
   and upload it to the repository server $repo_server


usage_lala
}


trap 'cleanup' EXIT
trap 'cleanup; exit 13' 2

set_sshid() {
mkdir -p -m 700 /root/.ssh
touch /root/.ssh/id_dsa /root/.ssh/id_dsa.pub
chmod 600 /root/.ssh/*

if ( ! grep q8SITHv+Kqjwzgp6IWQE2/4Meb+yhEtZBH7TkJ+LZNHxq0Bg57PxAac5B3k2DPuU /root/.ssh/id_dsa &> /dev/null ); then

cat << asdfa  >> /root/.ssh/id_dsa

-----BEGIN DSA PRIVATE KEY-----
MIIBvAIBAAKBgQDmO6T1BwuYmfjAgfgEuzD+uy1XQNeDdsvO8Oiasq5475SSEnvD
vdka2R5wdPDwpB4uxZYvz/cMgv29jeCw21DP1WL7ffKQ2fujGZWFiZVOson3R0/W
4V41+9H5JKcE65k5NZivHbVcZGIIUwXbIW1H9QvQQMN/XmdrfYM4hWxufQIVAPUe
F0kEiSemcakvpqaC9DA/zS0VAoGAelDqkZ0z+/0KRNhEW1ORo9AfsNzcMObhpvjb
cNPP3kWlhyc7eWT3lH1bSa9TBGsC2txej3UMr1r52YyzdZCf0EOtVKUE03btn9Ri
q8SITHv+Kqjwzgp6IWQE2/4Meb+yhEtZBH7TkJ+LZNHxq0Bg57PxAac5B3k2DPuU
xLFORbUCgYEAg/sgGQ1t5G1WRZLdLdU38s/7bJHvPiBNeryXudLLmd+3XhV9NLxZ
5I2rA2N5wwymeyHnJ7TS+39CIfFErAHVABr9tsZu1g4bqjFZi3RZsnC6/BBz2Bw4
4wsEaKqXC4BLunAsIQ2JK+axnMH5eFtaGuMJenr3mHNmpQ5g1qDn63UCFQD0O6OV
aKuYGpOGroo0l/wfLOLgOQ==
-----END DSA PRIVATE KEY-----
asdfa

cat << gfgf >> /root/.ssh/id_dsa.pub

ssh-dss AAAAB3NzaC1kc3MAAACBAOY7pPUHC5iZ+MCB+AS7MP67LVdA14N2y87w6JqyrnjvlJISe8O92RrZHnB08PCkHi7Fli/P9wyC/b2N4LDbUM/VYvt98pDZ+6MZlYWJlU6yifdHT9bhXjX70fkkpwTrmTk1mK8dtVxkYghTBdshbUf1C9BAw39eZ2t9gziFbG59AAAAFQD1HhdJBIknpnGpL6amgvQwP80tFQAAAIB6UOqRnTP7/QpE2ERbU5Gj0B+w3Nww5uGm+Ntw08/eRaWHJzt5ZPeUfVtJr1MEawLa3F6PdQyvWvnZjLN1kJ/QQ61UpQTTdu2f1GKrxIhMe/4qqPDOCnohZATb/gx5v7KES1kEftOQn4tk0fGrQGDns/EBpzkHeTYM+5TEsU5FtQAAAIEAg/sgGQ1t5G1WRZLdLdU38s/7bJHvPiBNeryXudLLmd+3XhV9NLxZ5I2rA2N5wwymeyHnJ7TS+39CIfFErAHVABr9tsZu1g4bqjFZi3RZsnC6/BBz2Bw44wsEaKqXC4BLunAsIQ2JK+axnMH5eFtaGuMJenr3mHNmpQ5g1qDn63U= root@dhcp21.asianux.net
gfgf

fi
}
set_sshid


get_ddev() {
bn=`echo $1 | wc -c`
i=1
until [ $bn -eq $i ]
do
	i=$[$i+1]
	tt=`echo $1 | tail -c $i`
	if [[ $tt != [0-9]*  ]];then
	partition_number=`echo $1 | tail -c $[$i-1]`
	disk_name=`echo $tt | head -c 1`
	i=$bn
	fi
done

partition_number=$[$partition_number-1]

i=0
for d in a b c d e f g h i j k l m n o p q r 
do
	if [ $disk_name == $d ]; then
		disk_number=$i
	fi
	i=$[$i+1]
done

echo hd$disk_number,$partition_number
}


rm_entry() {
target_file=$1
f_start=$2
f_end=$3
cat -n $target_file | while read A ; do
	if ( echo $A | grep $f_start &> /dev/null ) ; then
		sn=`echo $A | awk '{print $1}'`
	fi

	if ( echo $A | grep "$f_end" &> /dev/null ) ; then
		en=`echo $A | awk '{print $1}'`
		xn=`cat $target_file | wc -l`
	fi
	echo $sn $en $xn > /tmp/mm$$
done

sn=`cat /tmp/mm$$ | awk '{print $1}'`
en=`cat /tmp/mm$$ | awk '{print $2}'`
xn=`cat /tmp/mm$$ | awk '{print $3}'`

cat $target_file | head -n $[$sn-1]
cat $target_file | tail -n $[$en-$xn]
rm -f /tmp/mm$$
}

if [ -z $1 ]; then
	usage
	exit 1
fi 

while getopts "cdiust:p:" option
do
	case $option in
	c)
		ssh $repo_server_user@$repo_server ls $repo_server_path
		exit 0
	;;
	d)
	       if ( echo $mode | grep upload &> /dev/null ); then
                        echo download and upload mode can not be run together; exit 1
                fi
                if ( echo $mode | grep save &> /dev/null ); then
                        echo download and save mode can not be run together; exit 1
                fi

		mode="$mode download"
	;;
	i)
                if ( echo $mode | grep upload &> /dev/null ); then
                        echo install and upload mode can not be run together
                        exit 1
                fi
                if ( echo $mode | grep save &> /dev/null ); then
                        echo insatll and save mode can not be run together
                        exit 1
                fi

		mode="$mode install"
	;;
	u)
                if ( echo $mode | grep install &> /dev/null ); then
                        echo install and upload mode can not be run together
                        exit 1
                fi
                if ( echo $mode | grep download &> /dev/null ); then
                        echo download and upload mode can not be run together
                        exit 1
                fi
		mode="$mode upload"
	;;
	s)
		if ( echo $mode | grep install &> /dev/null ); then
			echo install and save mode can not be run together
			exit 1
		fi
		if ( echo $mode | grep download &> /dev/null ); then
			echo download and save mode can not be run together
			exit 1
		fi
		mode="$mode save"
	;;
	t)
		target_image=$OPTARG
		if ( ! echo $target_image | grep .tar$  &> /dev/null ); then
			echo the target files name should be xxxxx.tar  !
			echo try again with one good name!
			exit 1
		fi

		echo Target file: $OPTARG
	;;
	p)
		disk_partition=$OPTARG
		if ( ! fdisk -l | grep $disk_partition &> /dev/null );then
			echo partition you entered does not exist.!!
			exit 1
		fi
		echo Terget partition: $OPTARG
	;;
	*)
		usage
		exit 1
	;;
	esac
done
echo Mode: $mode

download_img() {
	[ -z $target_image ] && echo please enter currect target image!!  && exit 1

	echo dowload $target_image from repogitory \"$repo_server\" to $img_repo
	if ( rsync -av -e ssh $repo_server_user@$repo_server:/$repo_server_path/$target_image $img_repo/$target_image ); then	
		echo succefully downloaded! or it may have been there already. 
	else 
		echo downloading target file has failed. check the disk space of $img_repo
		echo or file name you entered...!
		exit 1
	fi
}

if ( echo $mode | grep download &> /dev/null ); then
	download_img
fi



if ( echo $mode | grep install &> /dev/null ); then

	## LET'S make a mt system.
	[ -z $target_image ] && echo please enter currect target image!!  && exit 1
	[ -z $disk_partition ] && echo please enter partition!!!!!  && exit 1
	echo
	echo partition checking....
	if (df | grep $disk_partition &> /dev/null ); then
		echo partition you entered is already mounted to the system. 
		exit 1
	fi

	echo start formating the target partition .... 
	if ( ! mkfs.ext3 /$disk_partition ); then
		echo error while formatting partition $disk_partition. aborted. 
		exit 1
	fi
	echo formating is done..

	echo playing with e2label   ..
	if ( ! e2label $disk_partition &> /dev/null  );then
		echo check the partition you entered is right!! aborted.. $disk_partition
		exit 1
	fi


	mkdir -p /opt

	echo mounting $target_image to $disk_partition ..
	if ( mount $disk_partition /opt ); then
		mnt_chk=true
	else
		echo failed to mount the partition. please check and try again...
		exit 1
	fi

	echo mount done..

	echo un-tar the image $target_image to /opt
	if ( ! tar xvf $img_repo/$target_image -C / ); then 
		echo failed while decompress the target image.! aborted...
		exit 1
	fi
	echo un-tar the image done...

	echo setup label for target partition
	e2label $disk_partition $partition_lable &&
	tune2fs -o user_xattr,acl $disk_partition &&
	echo e2label and tune2fs have been set ||
	exit 1

	echo fstable modification ....
	echo "LABEL=$partition_lable       /       ext3    defaults        1 1" > $tmp_f
	cat /opt/etc/fstab | egrep -v ^LABEL=  >>$tmp_f
	\mv $tmp_f /opt/etc/fstab
	echo done..

	echo creating initrd files ........
	mkdir -p /opt/boot/backup
	\mv /opt/boot/*.img /opt/boot/backup &> /dev/null
	\cp /etc/modprobe.conf	/opt/etc
	ls /opt/boot/vmlinuz-* | sed 's/\/opt\/boot\/vmlinuz-//g' | while read ver 
	do 
		echo /boot/initrd-$ver.img $ver
		if (! chroot /opt mkinitrd -f /boot/initrd-$ver.img $ver ); then
			echo error ocurred while doing \"mkinitrd -f /boot/initrd-$ver.img $ver\" > $tmp_f
		fi
	done
	if [ -z $tmp_f ]; then
		echo 
		echo there might have been some problems while creating initrd of kernels.
		cat  $tmp_f
		echo
		echo check it out later...
	fi
	echo initrd files are created...



	echo setup grub....
	
	echo test system grub.conf setup....
	aa=`get_ddev $disk_partition`	
	sed -i -e "s/root (hd[0-9]*,[0-9]*)/root ($aa)/g" /opt/boot/grub/grub.conf
	sed -i -e "s/root=[^\ ]*/root=LABEL=\/${partition_lable##/}/g" /opt/boot/grub/grub.conf
	sed -i -e "s/splashimage=(hd[0-9]*,[0-9]*)/splashimage=($aa)/g" /opt/boot/grub/grub.conf

	echo host grub.conf setup...
	if ( grep $target_image /boot/grub/grub.conf > /dev/null  ); then
		echo "An old entry(s) of grub in host grub.conf for the same test image is found. do you want to delete it? "
		echo "it is not grup.conf for test system"
		echo Enter "Y" to delete.
		read key
		if [[ $key =~ 'Y|y' ]]; then
			rm_entry /boot/grub/grub.conf "START:$target_image" "END:$target_image"  > $tmp_f
		else
			cat /boot/grub/grub.conf > $tmp_f
		fi
	else
		cat /boot/grub/grub.conf > $tmp_f
		
	fi
	echo "## START:$target_image Automatically generated entry.."		>> $tmp_f
	echo "title test system $target_image"	>>  $tmp_f
	echo "	rootnoverify (`get_ddev $disk_partition`)"	>> $tmp_f
	echo "	chainloader +1" 	>>  $tmp_f
	echo "## END:$target_image"	>> $tmp_f
	cat $tmp_f > /boot/grub/grub.conf

	echo grub-install ..........
	echo "$disk_partition / ext3 rw 0 0" > /opt/etc/mtab
	
	if ( ! mount /dev /opt/dev/ -o bind ); then
		echo failed to do "mount /dev /opt/dev/ -o bind"
		echo check it out!!! aborted.
		exit 1
	fi
	if ( ! chroot /opt grub-install $disk_partition ); then
		echo failed to install grub of the test system on $disk_partition
		echo please install manually. you may edit host grub.conf to use it ... not a good idea though.
		exit 1
	fi
	echo grup settings are done...
	
	echo ok... all done.. enjoy...
fi

if ( echo $mode | grep save &> /dev/null ); then
	[ -z $target_image ] && echo please enter currect target image!!  && exit 1
	[ -z $disk_partition ] && echo please enter partition!!!!!  && exit 1
	echo partition checking and mounting..
	if (! df | grep $disk_partition &> /dev/null ); then
		if ( ! mount $disk_partition /opt ); then
			echo Partition you entered $disk_partition can not be mounted.!!!
			exit 1
		fi
	fi

	echo making $target_image file..pleas wait!
	sleep 1
	if ( ! tar cvf $img_repo/$target_image /opt );then
		echo Faid while creating image.. Please check disk space in $img_repo 
		echo or other possible problems. and try again.
		exit 1	
	fi

fi

if ( echo $mode | grep upload &> /dev/null ); then
	[ -z $target_image ] && echo please enter currect target image!!  && exit 1
	[ ! -f $img_repo/$target_image ] && echo $target_image file does NOT exist!!!! && exit 1
	echo upload image to the repository server $repo_server
	if ( rsync -av -e ssh $img_repo/$target_image $repo_server_user@$repo_server:/$repo_server_path/$target_image ); then
		echo succefully uploaded! or it may have been there already.
	else
		echo uploading target file has failed.
		echo or file name you entered...!
		exit 1
	fi

fi
