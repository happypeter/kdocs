>>>doing it refering to  blacklist also make sense
>>>Now I think I need a vector to store obsolete info first,
1.
so I add a struct in hscommon.h first,
struct structObsolete
{
        string pkgname;
        string obsoletename;
        string obsoleteversion;
};

2. do everything like structFileInfo,
but when I add classRpmEngine.h
        vector <structObsolete> m_vectorObsolete;
axtu will die. why?
NOTE: later I found it only happens on my xen machine, so it must be mem leaking
even
vector<string> PPPP;
will bring the same problem.
but 
int peter;------------works.
int peter[10000];-----error
int peter[1];---------works
int peter[2]----------works
int peter[3]----------error
int peter[10]---------error
int peter()-----------works
3. finally I decide to wirte 
        vector <structObsolete> m_vectorObsolete;
outside
class classRpmEngine
then axtu will work
4.and the below patch works as expected 
<>
--------------------------- libs/classRpmEngine.cpp ---------------------------
index c155671..78b304d 100644
@@ -731,6 +731,24 @@ bool classRpmEngine::CreateUpdateInstallList()
 
 	structFileInfo fileInfo;
 
+//peter-gg
+/*
+structObsolete obsolete;
+obsolete.pkgname="peter";
+obsolete.obsoletename="wgz";
+obsolete.obsoleteversion="0.1";
+m_vectorObsolete.reserve(1000);
+m_vectorObsolete.push_back(obsolete);
+vector <structObsolete>::iterator it_ob;
+for(it_ob=m_vectorObsolete.begin();it_ob!=m_vectorObsolete.end();it_ob++) 
+{
+	if (it_ob->pkgname == "peter") 
+	{
+		m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME,"pkgname", NULL);
+	}
+}
+*/
+//end
 	int nTotal = m_setRemoteHeaderInfo.size();
 	int nEscapeCount = 0;

</>
>>>
I meet a problem and solve it as follows
<>
Warning: cannot pass objects of non-POD type 'struct std::string' through '...'

Warning message: cannot pass objects of non-POD type 'struct std::string' through '...'; call will abort at runtime.

You are, for instance, trying to print a C++ std::string directly to printf.

std::string foo;
printf( "Foo: %s\n", foo );

The result in run-time can be something like Illegal instruction (core dumped). The proper way to handle the std::string to printf is to use the c_str method:

std::string foo;
printf( "Foo: %s\n", foo.c_str() );
</>

>>>>>one thing is annoying is that 
in InitRpm()
CreateUpdateInstallList() is called before
ReadHeaders()
but luckily ShowList(); comes after InitRpm()
so even the lists are created I can still modify it according to the obsolete-info I get from
ReadHeaders()
before showing the list to users
I need to add a function at the end of InitRpm to modify installlist and updatelist

