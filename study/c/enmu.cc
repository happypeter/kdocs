//http://www.cplusplus.com/doc/tutorial/other_data_types/
#include <iostream>

using namespace std;

int main()
{
enum color_t{green, red, blue} mycolor;
mycolor=green;
if(mycolor==green)
	cout<<"mycolor==1"<<endl;
if(mycolor==2)
	cout<<"mycolor==red"<<endl;
if(mycolor==blue)
	cout<<"mycolor==blue"<<endl;

return 0;
}
