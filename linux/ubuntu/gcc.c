last change in 11_1_2008

on a newly installed ubuntu 8.04
error:
/usr/bin/ld crtl.o not found when compiling with gcc

the solution is:

1. sudo apt-get update ---------------------sometimes it is necessary, while sometimes not

2. sudo apt-get install linux-libc-dev

3. sudo apt-get install libc6-dev
