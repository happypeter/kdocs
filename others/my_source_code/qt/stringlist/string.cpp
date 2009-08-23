#include <qstringlist.h>
#include <iostream>
using namespace std;
int main()
{      
 QStringList fonts;    
	fonts.append( "Times" );
    fonts += "Courier";
    fonts += "Courier New";
    fonts << "Helvetica [Cronyx]" << "Helvetica [Adobe]";
    
    for ( QStringList::Iterator it = fonts.begin(); it != fonts.end(); ++it ) {
        cout << *it << ":";
    }
    cout << endl;
    // Output:
    //  Times:Courier:Courier New:Helvetica [Cronyx]:Helvetica [Adobe]:
   QString allFonts = fonts.join( ", " );
    cout << allFonts << endl;
    // Output:
    //  Times, Courier, Courier New, Helvetica [Cronyx], Helvetica [Adobe]
    
    QString s = "Red\tGreen\tBlue";
    QStringList colors = QStringList::split( "\t", s );
    cout << colors.join( ", " ) << endl;
    // Output:
    //  Red, Green, Blue
return 0; 
}   
