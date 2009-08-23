I am quit anoyed by the sp1 pdfviewers:
<>
kdegraphics-kpdf-3.5.5-3.4AX.x86_64
xpdf-3.01-28.6AXS3.x86_64
</>
I like the ubuntu one a lot, whose name is
"Evince Document Viewe"
But it is basiclly desingned for gnome.
>>>
so I think I would better to update my own kpdf and xpdf first,
and see if they can fullfill my needs.-------no updates on server!!!
>>>Hwajie said adobe is good.
1../AdbeRdr9.1.1-1_i486linux_enu.bin
2.Enter installation directory for Adobe Reader 9.1.1 [/opt]
3.[root@dhcp25 bin]# rpm -e kdegraphics-kpdf-3.5.5-3.4AX.x86_64 xpdf-3.01-28.6AXS3.x86_64
[root@dhcp25 bin]# kpdf
bash: /usr/bin/kpdf: No such file or directory
[root@dhcp25 bin]# ln -s acroread /usr/bin/kpdf
[root@dhcp25 bin]# kpdf
[root@dhcp25 bin]# pwd
/opt/Adobe/Reader9/bin
[root@dhcp25 bin]# ln -s acroread /usr/bin/kpdf    
4. haha, done! 

