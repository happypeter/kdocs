#include <stdio.h>
void p1(int i)
{
printf("------%d\n",i);
}
void p2(int i)
{
printf("-----%d\n",(i+1));
}
choose(void (*p)(int), int i)
//choose((*p)(int), int i)--------wrong
{
p(i);
}


int main()
{
choose(&p2,1);

}
