<ss.py>
#!/usr/bin/python
import sys
sys.path.insert(0, '/root/')
import peter
</ss.py>

<peter.py>
print ddd
</peter.py>

$mv pete.py ~/
$./ss.py
ddd
and I see a pyc file is generated

>>>
Now I want to know where 'import' try to find module, so I
<>
>>> import sys
>>> sys.path
['', '/usr/lib64/python24.zip', '/usr/lib64/python2.4', '/usr/lib64/python2.4/plat-linux2', '/usr/lib64/python2.4/lib-tk', '/usr/lib64/python2.4/lib-dynload', '/usr/lib64/python2.4/site-packages', '/usr/lib64/python2.4/site-packages/Numeric', '/usr/lib64/python2.4/site-packages/gtk-2.0', '/usr/lib/python2.4/site-packages']
>>>
</>

>>>maybe the following and explain why I can not find "sys.py". though there is 'import sys'
<>
http://docs.python.org/library/intro.html
Some modules are written in C and built in to the Python interpreter; others are written in Python and imported in source form.
</>

/usr/lib/python2.4/site-packages/yum/__init__.py

The Python interpreter has a number of functions built into it that are always available.

http://mohammed.morsi.org/blog/?q=node/220
/usr/bin/yum simply calls out to /usr/share/yum/yummain.py which then instantiates classes deriving from YumBase. YumBase defined in the yum library /usr/lib/python2.5/site-packages/yum/, specifically __init__.py, is the main interface into the API and will provide alot of the high level functionality that you would want to access.
