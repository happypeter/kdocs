utf8->gb->big5->utf8
from simplified chinese to troditional chinese
ssh root@10.1.0.163
passwd: abc123
$grep history|grep autogb

>>>Below is what LiShu did for me:
* name your file "peter" and save simpilfied Chinese inside
* then run the following three lines then you will get traditional Chinese.
<>
  autogb -i utf8 -o gb < peter > peter.gb
  autogb -i gb -o big5 < peter.gb > peter.big5 
  autogb -i big5 -o utf8 < peter.big5 > peter.big5.utf8
</>
