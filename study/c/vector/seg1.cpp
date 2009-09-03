#include<iostream>
#include<vector>

using namespace std;

int main()
{
vector <int> peter;
int i;
vector <int>::iterator it;
for(i=1;i<5;i++)
{
        peter.push_back(i);
}
for(it=peter.begin();it!=peter.end();it++)
{
      cout<<"LOOP1:\t"<<*it<<endl;
        if(*it==2)
        {
                peter.erase(it--);
        }
}
for(it=peter.begin();it!=peter.end();it++)
{
        cout<<"LOOP2:\t"<<*it<<endl;
}
peter.reserve(1000);
for(it=peter.begin();it!=peter.end();it++)
//for(it=peter.begin();it!=peter.end()-40;it++)---------there will be no segfault
//but if you insert 222 rather than 2, segfualt again
{
        if(*it==3)
	{  
		static int i=1;
		i++;    
		cout<<i<<endl;  
		peter.insert(it,2222);//segfault here! why?
/*A: see the output i, then I see vector is really smart enough,
 * so, when you first find the it where *it==3, then 2222 will be added before the it, so the it in *it==3, actually increamented since one element is added before it, so in the next loop *it==3 still true, so another 2222 will be added, which won't stop the next loop, until mem leak.  run ./a.out to see the output	*/
	}
}

for(it=peter.begin();it!=peter.end();it++)
{
        cout<<"LOOP3:\t"<<*it<<endl;
}


}
/*
 *
 * This effectively increases the vector size, which causes an automatic reallocation of the allocated storage space if, and only if, the new vector size surpases the current vector capacity. Reallocations in vector containers invalidate all previously obtained iterators, references and pointers.
 *
 * Because vectors keep an array format, insertions on positions other than the vector end are performed by moving all the elements between position and the end of the vector to their new positions, and then inserting the new element(s), which may not be a method as efficient as the insertion in other kinds of sequence containers (deque, list).
 * http://www.cplusplus.com/reference/stl/vector/insert/
 */

