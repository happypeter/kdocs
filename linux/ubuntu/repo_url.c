sudo sysv-rc-conf------to say bootup settings

go to /etc/apt
change  sources.list
into 
<>

deb http://ftp.sjtu.edu.cn/ubuntu/ intrepid main multiverse restricted universe
deb http://ftp.sjtu.edu.cn/ubuntu/ intrepid-backports main multiverse restricted universe
deb http://ftp.sjtu.edu.cn/ubuntu/ intrepid-proposed main multiverse restricted universe
deb http://ftp.sjtu.edu.cn/ubuntu/ intrepid-security main multiverse restricted universe
deb http://ftp.sjtu.edu.cn/ubuntu/ intrepid-updates main multiverse restricted universe
deb-src http://ftp.sjtu.edu.cn/ubuntu/ intrepid main multiverse restricted universe
deb-src http://ftp.sjtu.edu.cn/ubuntu/ intrepid-backports main multiverse restricted universe
deb-src http://ftp.sjtu.edu.cn/ubuntu/ intrepid-proposed main multiverse restricted universe
deb-src http://ftp.sjtu.edu.cn/ubuntu/ intrepid-security main multiverse restricted universe
deb-src http://ftp.sjtu.edu.cn/ubuntu/ intrepid-updates main multiverse restricted universe

</>
then update will be faster
