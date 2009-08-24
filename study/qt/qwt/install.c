Add QWT to F4 QT

1. trying to see if qwt works in my qt, I copy a simplest qwt-plot app, into my Vmware F4, compile and the error is because of the lack of qwt_plot.h, so I $cd $QTDIR/include and add a file named qwt_plot.h, now error remains but qwt_plot is found. The complition fails not because there are many #include”” in qwt_plot.h that I do not have.

2. they say qwt is archtecture indepenfent

3. now I know I ‘d better add the whole qwt.

4. http://jaist.dl.sourceforge.net/sourceforge/qwt/qwt-5.0.0rc1.pdf

the UM

https://qwt.svn.sourceforge.net/svnroot/qwt/trunk/qwt/examples/bode/

real impletation examples

https://qwt.svn.sourceforge.net/svnroot/qwt/trunk/qwt/designer/

I do not know what is a designer but it must be useful

https://qwt.svn.sourceforge.net/svnroot/qwt/trunk/qwt/INSTALL]

qwt Introduction
============
 
Qwt uses qmake to build all its components and examples.
qmake is part of a Qt distribution.
 
qmake reads project files, that contain the options and rules how to
build a certain project. A project file ends with the suffix "*.pro".
Files that end with the suffix "*.pri" are included by the project
files and contain definitions, that are common for several project files.
 
qwtconfig.pri is read by all project files of the Qwt package.
So the first step is to edit qwtconfig.pri to adjust it to your
needs.
 
 
A) Unix Qt3/Qt4
==========================
 
qmake
make
make install
 
If you have installed a shared library it's path has to be known to
the run-time linker of your operating system. On Linux systems read
"man ldconfig" ( or google for it ). Another option is to use
the LD_LIBRARY_PATH (on some systems LIBPATH is used instead, on MacOSX
it is called DYLD_LIBRARY_PATH) environment variable.
 
If you only want to check the Qwt examples without installing something,
you can set the LD_LIBRARY_PATH to the lib directory
of your local build.
 
If you didn't enable autobuilding of the examples in qwtconfig.pri
you have to build the examples this way:
 
cd examples
qmake
make
peter: I did all above in my F4 and succeed,what they mention about runtime linker problems was solved by $export LD_LIBRARY_PATH=$/qwt5.2/lib(some ldd needed by the examples during runtime). Just like that I $cd /examples/$qmake and $make, then I see a executable file.
 
 

D) Qtopia Core(peter: http://trolltech.com/products/qt/qt-embedded/qt-for-embedded-linux-1/qt-for-embedded-linux
Here, they say: Qt for Embedded Linux® (formerly known as Qtopia Core) is the leading application framework
http://trolltech.com/downloads/opensource#qt-open-source-edition
the QT for embedded linux can be download here, it is a QT download website not a qtopia one, so maybe we can say qt for e is not qtopia, but its name is still qtopia-core-opensource-src-4.3.3.tar.gz,
haha, confusing, but it is what they say on trolltek website, can not be wrong.
March 12, 2008
Qtopia Core -> Qt for Embedded Linux
Two years ago [the new version of Qt/Embedded changed its name to Qtopia Core]，however, now, Nokia have bought trolltech, the name Qtopia core is change into [Qt for Embedded Linux]，for more info, refer to LinuxDevices.com  [Re-named graphics framework tapped for media streamer]。


I only tested Qwt with Qtopia Core in qvfb (Virtual Framebuffer Devivce)
Emulator on my Linux box. To build Qwt for the emulator was as simple as
for a regular Unix build.
 
qmake
make
 
E) Qtopia (!= Qtopia Core)
 
I once compiled the Qwt library against Qtopia 4.2.0 successfully - but
not more. It should be possible to build and install Qwt, but it's
not done yet.
 
Good luck !
 

https://qwt.svn.sourceforge.net/svnroot/qwt/trunk/qwt/

everything above

https://qwt.svn.sourceforge.net/svnroot/qwt/trunk/qwt/CHANGES

here, they say QT2 in not supported any more, what is the version of my QT? Mine is higher than v3, so no need to worry. From v4 of qwt, it starts to support qtopia.

 

