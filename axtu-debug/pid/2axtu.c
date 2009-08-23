>>>when I run axtu, there is nothing in /var/tmp/(so it seems zhudan's bug report has some bug)
<[root@dhcp17 axtu]# vim ./libs/commondef.h>
#define AXTU_GUI_PID_FILE "/var/run/axtu/axtu-gui.pid"
</>
and I see
<>
[root@dhcp25 ddd]# ll /var/run/axtu/
total 8
-rw------- 1 root root 4 Aug 11 01:55 axtu-daemon.pid
-rw------- 1 root root 4 Aug 11 01:55 axtu-gui.pid
</>
so everything is OK

>>>axtu use the pid files this way
<gui/main.cpp>
if (CHSLock::Islock((AXTU_GUI_PID_FILE), (AXTU_GUI_EXE_FILE)) == true)
                {
                        bAlreadyExecuted = true;
                }
</>
to decide show the error message or not.
<>
        if(bAlreadyExecuted == true)
        {
                QMessageBox::critical(0, QObject::tr("Asianux TSN Updater"),  QObject::tr("TSN Updater is already running."));
                exit(2);
        }
</>

>>>if you grep in axtu source tree
<>
[root@dhcp17 axtu]# xxx "/var/tmp"  
#define         LAUNCHER_GUI_PID_FILE          "/var/tmp/axtu-launcher.pid"
</>
but it is defined but never used
<>
[root@dhcp17 axtu]# xxx LAUNCHER_GUI_PID_FILE
#define         LAUNCHER_GUI_PID_FILE          "/var/tmp/axtu-launcher.pid"
./gui/launcher/main.cpp
[root@dhcp17 axtu]#  
</>
>>>Now the question is who creat the pid file
<gui/main.cpp>
CHSLock::lock((AXTU_GUI_PID_FILE))
</>

<./libs/classLock.h>
        static bool lock(const char * strFilePath)
        {
                uint            nPID;
                char strPID[256];
                // Get current pid
                nPID = (int)getpid();
                sprintf(strPID, "%d",nPID);

                FILE * fout;
                if(access(strFilePath, F_OK) == 0)
                {
                        if(remove(strFilePath) != 0)
                        {
                                return false;
                        }
                }
                fout = fopen(strFilePath, "w");
                if( fwrite(strPID , sizeof(char) , strlen(strPID), fout) == 0)
                {
                        return false;
                }
                if(chmod(strFilePath, 0600) != 0)
                {
                        return false;
                }

                fclose(fout);

                return true;
        }
</>

>>>then I make a naughty patch
---if(chmod(strFilePath, 0600) != 0)
+++if(chmod(strFilePath, 0777) != 0)
and now
<>
[root@dhcp25 axtu]# ll /var/run/axtu/
total 8
-rw------- 1 root root 4 Aug 11 01:55 axtu-daemon.pid
-rwxrwxrwx 1 root root 5 Aug 11 02:49 axtu-gui.pid
[root@dhcp25 axtu]#  
</>
so now I use check.sh
strange thing is "grep /proc -v>result.txt"
does not work well for big files, there will be handruds of lines of write space before some
useful output,  which makes you easily ignore them.
but anyway I see in 
<other_write.detail>
/var/run/axtu/axtu-gui.pid              -rwxrwxrwx
</>
which is what I expected

