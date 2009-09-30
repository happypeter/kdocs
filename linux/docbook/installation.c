1.First I install the following packages(using apt-get install xxx):

- docbook (maybe this step is not needed)
- xsltproc (the XSL Transformations Processor)
- docbook-xsl (stylesheets for HTML, XHTML, HTML Help and others)
- docbook-defguide (The Definitive Guide to DocBook - recommended)

(NOTE: docbook-defguide is installed in /usr/share/doc/docbook-defguide, there are all vesions of this manual, this is the right one for you, if you use other 
onlion versions, you will die in a lot of phrasing errors)

2. then the file test.xml and the following command
//////////////

 xsltproc -o test.html /usr/share/xml/docbook/stylesheet/nwalsh/xhtml/docbook.xsl test.xml

/////////////
3. the use of Makefile is easy

4. now I want to use fop to generate PDF file, but fop is java-based, so I need
   to install java first 

   $apt-get install sun-java6-bin

well, fop is not working!
===LINKS
http://www.oasis-open.org/docbook/documentation/reference/
http://www.docbook.org/tdg/en/html/docbook.html
https://help.ubuntu.com/community/DocBook

