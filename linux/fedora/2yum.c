<>http://www.fedoraguide.info/index.php?title=Main_Page#How_To_use_Yum
Is there a graphical (GUI) version for Yum

There are several types of software to help in the graphical area for yum.
Yumex

su -c 'yum -y install yumex'
</>

yum install kernel-devel gcc
system->admin->add/remove software

<>

  How to open files as root user via right click

    * Read #General Notes 
    *
    * gedit $HOME/.gnome2/nautilus-scripts/Open\ as\ root
    *
    *     * Insert the following lines into the new file 
    *
    *     for uri in $NAUTILUS_SCRIPT_SELECTED_URIS; do
    *     	gnome-"gnome-open $uri" &
    *     	done
    *
    *     	    * Save the edited file 
    *
    *     	    chmod +x $HOME/.gnome2/nautilus-scripts/Open\ as\ root
    *
    *     	    Right click on file -> Scripts -> Open as root
    *

</>

http://www.phy.duke.edu/~rgb/General/yum_HOWTO/
