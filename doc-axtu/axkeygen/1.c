HOW to compile a static axkeychk
export P_K=svn+ssh://peter@10.1.0.96/SDSrepo/trunk/axkeygen
1. change the header path a little in axkeychk.c
	cd axkeychk/ 
	vim axkeychk.c 
	---#include "libaxkey.h" 
	+++#include "../libaxkey/libaxkey.h" cd libaxkey/ 

2. decide where to put the conf file
	vim libaxkey.c 
	---#define AXKEY_CONF      "/etc/axkey/axkey.conf"
	+++#define AXKEY_CONF      "./axkey.conf"

3. generate the modified libs
	make

4. copy it to the axkeychk/
	cp libaxkey.a ../axkeychk/

5. jump to axkeychk/
	cd ../axkeychk/ 

6. accroding to step2, copy axkey.conf here
	cp ../axkey-config/axkey.conf .

7. compilation
	gcc -c axkeychk.c -o axkeychk.o
	gcc -o ss axkeychk.o -L. -laxkey 

8. test it
<pre>
[root@localhost axkeychk]# ./ss -v 60348-3G63Q-F1U76-USKAD-RP6UT
Company:WT
Version:3
Revision:0
Category:ServerOS
ProductType:Basic
Platform:x86
Vendor:None
License:1
Serial:0000000001
[root@localhost axkeychk]# ldd ss
        linux-gate.so.1 =>  (0x004ad000)
        libc.so.6 => /lib/libc.so.6 (0x00110000)
        /lib/ld-linux.so.2 (0x003db000)
</pre>




