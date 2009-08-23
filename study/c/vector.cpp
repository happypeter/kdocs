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
peter.reserve(100);
for(it=peter.begin();it!=peter.end();it++)
//for(it=peter.begin();it!=peter.end()-40;it++)---------there will be no segfault
//but if you insert 222 rather than 2, segfualt again
{
        if(*it<3)
        {
                peter.insert(it--,2);//segfault here! why?
        }
}

for(it=peter.begin();it!=peter.end();it++)
{
        cout<<"LOOP3:\t"<<*it<<endl;
}


}


