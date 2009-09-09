//http://doc.trolltech.com/3.3/qstring.html
#include <qstringlist.h>
#include <qfile.h>
#include <qapplication.h>
#include <iostream>
using namespace std;
QString strOb;
QStringList strObList;
QStringList sl2;
int main(int argc, char *argv[])
{
	QStringList ::Iterator it;
        QFile file("./in.txt");
	file.open(IO_ReadOnly);
	QTextStream in(&file);
        strOb = in.readLine();
	cout<<"strOb.ascii()----"<<strOb.ascii()<<endl;
	sl2= strObList.split(" ",strOb);
        it = sl2.begin(); //I can use .grep() to find obsolete
	while(1)
	{
		cout<<(*it++).ascii()<<endl;
		if((*it)==NULL) break;
	}
}
//now everything works, haha
