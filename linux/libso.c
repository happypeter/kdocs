/////////
//Shared library
//Now I have a hello.c
///////
void sayhello()
{
printf("hello\n");
}
/////
//end of hello.c
////
/*
then i issue
$gcc -shared -Wl,-soname,libhello.so.1 -o libhello.so.1.0 hello.o
Very Important Note: if you type a space before “-soname”, you will
get the error: disorgnized option..
now
$ln -s libhello.so.1.0 libhello.so.1
now
$cp libhello.* /usr/lib
*/
/////
//main.c
////
#include<stdio.h>
main()
{
sayhello();
}
/*
then
gcc -c main.c
then
$gcc main.o -lhello
now
i see a.out, which is a executable file using so lib file libhello.so.1
*/

