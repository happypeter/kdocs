http://www.newty.de/fpt/index.html
When you want to call a function DoIt() at a certain point called label in your program, you just put the call of the function DoIt() at the point label in your source code. Then you compile your code and every time your program comes up to the point label, your function is called. Everything is ok. But what can you do, if you don't know at build-time which function has got to be called? What do you do, when you want to decide it at runtime? Maybe you want to use a so called Callback-Function or you want to select one function out of a pool of possible functions. However you can also solve the latter problem using a switch-statement, where you call the functions just like you want it, in the different branches. But there's still another way: Use a function pointer!
