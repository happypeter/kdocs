now my big question is can I use auth module to yum?
1. now I know auth-client get ak and tk form server then save them in files
2. axtu will read ak&&tk from the file, then add them to url to open the server data area protected by auth_mysql
if everything is as simple as this:
1. I do not need to modify auth-client, 
2. I just need to call it before yum starts
3. then make ak&&tk available for yum
4. now I need to add some code into yum, give yum a url with ak and tk
5. now the url is in a file too, there is even a possibility that I do not need to modify yum
6. I just write a seperate small program to add ak&tk to the url(s) in /etc/yum.repos.d

===
I need to study auth_mysql a little
as far as I know if a server area is not protected
the you can use http://url to visited
if it is protected by auth_mysql
then you need sth like http://url+ak+tk,
I need to know the exact format of http://url+ak+tk,
I believe I can find the format in axtu source code.
A: no such format, axtu just pass ak and tk as user and passwd
through a struct options, then wget use options in a low level way, so not a simply url as I imagined
so I need to know if yum use wget or not. 
