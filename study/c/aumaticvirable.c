automatic variables  have undefined initial value, if you only want to manipulate certainly bits, you should set all bits to 0 manually.

for example when I want to read epoch I used strTmp[0],
so I need to
<code>
strTmp[0]=0;
</code>
otherwise, what I read out is shit.
