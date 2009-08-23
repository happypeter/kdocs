>>>Example1
<s.sh>
if [ -z "$PETER" ]; then
        echo no peter
else
        echo peter is here
fi
<s.sh/>
then we have
<test>
[root@dhcp25 test]# sh s.sh
no peter
[root@dhcp25 test]# export PETER=peter
[root@dhcp25 test]# sh s.sh
peter is here
<test/>

>>>Example2
<s.sh>
rm dd
if [ $? = 0 ]; then
        echo "###########dd is deleted##########"
else
        echo "###########there is no dd##########"
        exit 1
fi
<s.sh/>

<test>
[root@dhcp25 test]# sh s.sh
rm: cannot remove dd  No such file or directory
###########there is no dd##########
[root@dhcp25 test]# vim dd
[root@dhcp25 test]# sh s.sh
###########dd is deleted##########
<test/>
>>>Example3
<s.sh>
pr()
{
for loop in ls *
do
echo hh
done
}
pr
<s.sh/>
//do + done is like {+}
<t>
[root@dhcp25 test]# sh s.sh
hh
hh
hh
[root@dhcp25 test]# ls
peki  s.sh
[root@dhcp25 test]# vim dd
[root@dhcp25 test]# sh s.sh
hh
hh
hh
hh
<t/>
>>>>>>>>>>>>>>>>>>
cat << as  >> /root/test/peter

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
as

>>>>>>>>>>>>>>>>>>>>>>>>>>>
