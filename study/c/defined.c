#include <stdio.h>

int main()
{
#if defined(__x86_64__)
printf("defined(__x86_64__)\n");
#else
printf("not defined\n");
#endif
}
//this works as expected on my laptop
