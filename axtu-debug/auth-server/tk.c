>>>Now let's talk about where is tk saved on the client

1. in the source code of axtu
 m_strSavingFileWTk = strTkPathPrefix + szTkPathSuffix;
2.then make a command
 strCmdForTk   = (string)" -t " + m_strSavingFileWTk;
3. pass the command to axtu-auth-client
4. axtu-auth-client will save tk for axtu
