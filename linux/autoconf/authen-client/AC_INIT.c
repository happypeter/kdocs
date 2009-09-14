
<diff>
--- AC_INIT(axtu-authen-client, 1.2, yusop@haansoft.com)
+++ AC_INIT(peter-axtu-authen-client, 9.1.2, peter@haansoft.com)
AC_MSG_NOTICE([configuring for $PACKAGE_NAME $PACKAGE_VERSION])
AC_MSG_NOTICE([You can send e-mail($PACKAGE_BUGREPORT) for bug])
</>

<shell>
[root@dhcp17 axtu-authen-client]# autoconf
[root@dhcp17 axtu-authen-client]# ./configure |grep peter
configure: configuring for peter-axtu-authen-client 9.1.2
configure: You can send e-mail(peter@haansoft.com) for bug
</>

so it seems to me now is AC_INIT just set up three ENV variable implicitly
