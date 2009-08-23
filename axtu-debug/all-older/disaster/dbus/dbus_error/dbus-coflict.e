      file /etc/dbus-1/session.conf from install of dbus-1.1.2-12AXS3 conflicts with file from package dbus-1.0.0-6.3
        file /etc/dbus-1/system.conf from install of dbus-1.1.2-12AXS3 conflicts with file from package dbus-1.0.0-6.3
//peter: usually confilics happen when you try to intall sth, but here dbus is updated properly,
// the  conflicts are because dbus32 are still there, so I do not think there is a way to avoid this, its just natrual
//same is ture of hal
        file /usr/share/man/man1/dbus-daemon.1.gz from install of dbus-1.1.2-12AXS3 conflicts with file from package dbus-1.0
.0-6.3
        file /usr/share/man/man1/dbus-uuidgen.1.gz from install of dbus-1.1.2-12AXS3 conflicts with file from package dbus-1.
0.0-6.3
        file /usr/share/hal/fdi/fdi.dtd from install of hal-0.5.8.1-38.1AXS3 conflicts with file from package hal-0.5.8.1-25.
2AXS3
        file /usr/share/hal/fdi/information/10freedesktop/20-video-quirk-pm-el5-lenovo.fdi from install of hal-0.5.8.1-38.1AX
S3 conflicts with file from package hal-0.5.8.1-25.2AXS3
        file /usr/share/hal/fdi/policy/10osvendor/10-power-mgmt-policy.fdi from install of hal-0.5.8.1-38.1AXS3 conflicts wit
h file from package hal-0.5.8.1-25.2AXS3
        file /usr/share/apps/kjava/kjava.jar from install of kdelibs-3.5.5-11.23AXS3 conflicts with file from package kdelibs
-3.5.5-11.18AXS
~
~
~
~

