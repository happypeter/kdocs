<>

root@dhcp25 x86_64]# rpm -Uvh hello-ui-1.0-1.x86_64.rpm
error: Failed dependencies:
        hello-doc=1.0-1 is needed by hello-ui-1.0-1.x86_64
[root@dhcp25 x86_64]# rpm -Uvh hello-ui-1.0-1.x86_64.rpm  hello-doc-1.0-1.x86_64.rpm
error: Failed dependencies:
        hello-doc=1.0-1 is needed by hello-ui-1.0-1.x86_64
[root@dhcp25 x86_64]# rpm -q --provides  hello-doc-1.0-1.x86_64.rpm
package hello-doc-1.0-1.x86_64.rpm is not installed
[root@dhcp25 x86_64]# rpm -qp --provides  hello-doc-1.0-1.x86_64.rpm
hello-doc = 1.0-1

</>
Change the spec file a little, then we see
<>
[root@dhcp25 x86_64]# rpm -qp --provides  hello-doc-1.0-1.x86_64.rpm
hello-doc = 1.0-1
[root@dhcp25 x86_64]# rpm -Uvh hello-ui-1.0-1.x86_64.rpm
error: Failed dependencies:
        hello-doc = 1.0-1 is needed by hello-ui-1.0-1.x86_64
[root@dhcp25 x86_64]# rpm -Uvh hello-ui-1.0-1.x86_64.rpm  hello-doc-1.0-1.x86_64.rpm
Preparing...                ########################################### [100%]
   1:hello-doc              ########################################### [ 50%]
   2:hello-ui               ########################################### [100%]

</>
