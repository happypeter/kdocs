#include <stdio.h>

int main()
{
char * dp;
dp="hello";
char s[10];//writing char *s will cause segfualt
sprintf(s,"%s",dp);
printf("------%s---\n",s);
}

