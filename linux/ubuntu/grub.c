Now I am using AX3 for my work, but now the ubuntu grub is boot up everytime and I need to choose the entry manually
every time. so I need to change grub.
1. cd /mnt/ubuntu
2. mount -t ext3 /dev/sda1  boot/
3. cd boot/grub/
4. vim menu.lst
---timeout         100
+++timeout         1
5. mv the AX3 entry to the beginning
7. done
