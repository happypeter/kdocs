===http://doc.trolltech.com/4.5/qwidget.html
Each widget performs all painting operations from within its paintEvent() function. This is called whenever the widget needs to be redrawn, either as a result of some external change or when requested by the application.
===
pintEvent() is called whenever the widget needs to be repainted. Every widget displaying custom content must implement it. Painting using a QPainter can only take place in a paintEvent() or a function called by a paintEvent()
===
you do not need to call  paintEvent() to executed, it will be executed when the object is created or update()||resize()is called. Right?

===http://doc.trolltech.com/4.5/qwidget.html
Transparency and Double Buffering

===
Ispired by the anologclock.cpp example.
Now My idea is not to touch the background, therefore not to use QPixmap to cut and pasted, but to draw the lines sperately.it works.

Let's say step=5;
we first drawline(0,Ynew,5,Yold);
then mv this short line to x~(5,10),
Yold=Ynew
Ynew=newvalue
drawline(0,Ynew,5,Yold);
then we mv all the two old lines to the left and continue;
