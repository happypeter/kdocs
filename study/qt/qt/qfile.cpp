////////////
//main part of this programme is from QT help manual
/////////////
#include<qstring.h>
#include<qfile.h>
#include<qtextstream.h>
int main()
{
	QString lines;
	QFile file("in.txt");
	if(file.open(IO_ReadOnly))
	{
		QTextStream stream(&file);
		QString line;
		int i=1;
		while(!stream.atEnd())
		{
			line=stream.readLine(); //line of text excloding /n
			printf("%3d: %s\n", i++,line.latin1());//no need to include stdio.h here
			lines +=line;
		}
		file.close();
	}
}
//run it under 3.3, works perfectly
