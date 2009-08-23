#include <stdio.h>

char * getstring();
char s[10];//s need to be globle, otherwise you just retrun a local adress in getstring()
int main()
{
printf("%s\n", getstring());
}
char * getstring()
{
char * dp;
dp="hello";
sprintf(s,"%s",dp);
return s;
}

//make s static local also works
#include <stdio.h>

char * getstring();
int main()
{
printf("%s\n", getstring());
}
char * getstring()
{
char * dp;
static char s[10];
dp="hello";
sprintf(s,"%s",dp);
return s;
}
