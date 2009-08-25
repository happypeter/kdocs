petu==peter's updater

I want to use yum repo, which means the server side repo is created with creatrepo,
is there any project that has the C++ code to manipulate these xml files.

I checked apt-rpm, but is does not use yum repo at all.

Design Goals:

1. UI level yum clone
2. I don't mind copy lots of code from axtu, but what I want is to:
   2.1 remove authentiifcation
   2.2 have command line
3. separate GUI and main code, want YUM+packagekit structure.
