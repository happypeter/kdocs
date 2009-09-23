>>>>>>>>>a few days later, someone change the server a little, so we can not connect it right now
1. I am sure mysqld and httpd is running
2. we can usr phpAdmin to browse the db
3. we can connect 155 to generate the AK, and use it for 250, and it works
4. the src/ on 155 and 250 the same
5. the error is "Cannot connect with authen server"
>>>>>>>>>
1. error happens when axtu-client try to get AK, 
2. I use dhclient eth0 to the server, and the problem is gone
NOTE: zhuyu said it is because using 250 auth-server can not connect with support.reflag.com to get info 
