CPU Info:
Code:

cat /proc/cpuinfo
mpstat -P ALL
"Total CPUS: $(grep processor /proc/cpuinfo  | wc -l)"

Memory:
Code:

free -m
free -g
cat /proc/meminfo
echo "Total Memory:  $(grep 'MemTotal' /proc/meminfo | cut -d: -f2)"

Hdd info:
Code:

fdisk -l | grep Disk
dmesg  | egrep 'sd|hd' | grep disk
sdparm /dev/sda


