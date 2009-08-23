So now
1. add ob into structRPMInfo, and save it into a vector----which is easy for me now
2. if A obsoletes B, and B is installed locally, show A on both update and install list, which ignore higher
   version of B if there is one
3. dep check or anything else, I do not care for now

>>>work flow
1. study hawnii's obsolete tag requirement (the excel file)
2. study JongWoo's OB patches (totally 8)
3. study OB related bugs(no matter fixed or not)
4. study JeongHun's patch
5. make the logic
6. do the code
7. test if the patch covers all JongWoo's patches or not
8. test if the patch fixs all the related bugs or not(one by one)
9. examine potentail probelems and perfect the patch
