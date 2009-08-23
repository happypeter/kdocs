>>>
<s.sh>
cat ./dd |awk -F "=" '{ if ($1=="if") print $1 ;print $2}'
</s.sh>

<dd>
if=xx
<dd/>
<test>
[root@dhcp25 test]# sh s.sh
if
xx
[root@dhcp25 test]#  
</test>
<dd>
ii=xx
<dd/>
<test>
[root@dhcp25 test]# sh s.sh
xx
[root@dhcp25 test]#        
</test>
~
>>>
