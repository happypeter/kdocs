How stupid! now I I am developing axtu which is in qt3.3
now my problem is simply I can not display a QSting object.

===
I know how to initial one
QSting q="myname";
===
but I can not cout<<q;
under qt4.5 , we have
std::string toStdString () const
so we can simply 
cout<<q.toStdString()<<endl;
but this is not available in 3.3, then how can I do it?!
===
finally I find out I can use
cout<<"newstr.ascii()----"<<newstr.ascii()<<endl;

