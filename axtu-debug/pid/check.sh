#!/bin/bash
# Description:
# It checkout those files whose other group have write permission. It doesn't check files under /proc.
#
# Usage:
# sh OtherGroup_WritePermission_check.sh
# vi result.txt

find / ! -type l -perm -o+w > other_write.list

for i in `cat other_write.list` ; do
        if [ -f $i -o -d $i ] ; then
                stat -c '%n             %A' $i 2>/dev/null
                echo -e ""
        fi
done > other_write.detail

#rm other_write.list
cat other_write.detail |grep /proc -v > result.txt
#rm other_write.detail

exit 0


