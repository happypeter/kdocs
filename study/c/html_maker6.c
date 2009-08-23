/*******html maker**********/
#include <stdio.h>
#include <string.h>
char str[80];
char str1[80];

char *string(char **argv)
{

strcpy(str,argv[1]);
strcat(str,".html");
return str;

}
char *string1(char **argv)
{

strcpy(str1,argv[1]);
return str1;

}



int main (int argc, char **argv)
{
    if (argc==1)
    {
        printf("Usage:\n \t ./a.out <inputfilename>\n");
        return 0;
    }

    FILE *in;
    FILE *out;
    char ch;
    char c[]="<a href=\"";
    char c0[]="\">";
    char c1[]="</a>";
    in=fopen(string1(argv),"r");
    out=fopen(string(argv),"w");
    fprintf(out,"%s",c);
    while(1)
    {
        ch=fgetc(in);
        if(ch=='-') break;
        fputc(ch,out);
    }
    fprintf(out,"%s",c0);

     while(1)
    {
        ch=fgetc(in);
        if(ch=='-') continue;
        if(ch=='\n') break;
        fputc(ch,out);
    }

    fprintf(out,"%s",c1);
    
    fclose(in);
    fclose(out);

    return 0;
}
