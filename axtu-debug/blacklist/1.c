>>>Hwanii give me a clue
Blacklist shall be concidered at the very last step

>>>if you run axtu-setup and add pkg as balcked, axtu will generate
</etc/axtu/blacklist.conf>
[blacklist-update]
ORBit2 = 0
OpenIPMI = 0
libdhcp-devel = 0
</>
this is generated by setup, used by axtu.
>>>but now my problem is I can not see libdhcp-devel on the list, since it is a obsoleter
>>>Ah, now I suddenly find out the list is named "installed packages", so it is no wonder 
libdhcp-devel is not here, it is not installed. Now I install sos, then I can see sos on the list, even
thogh the lastest version of sos is now installed.
so the axtu logic is strange, 
but "oboselters are not on this list" is not a bug.
