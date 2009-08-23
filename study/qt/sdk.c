vim /etc/scripts/.qtconfig   
<>
# /etc/scripts/.qtconfig: QT configuration script
echo "Loading configuration script (/etc/scripts/.qtconfig) for QT ..."

if [ -d /opt/qtsdk-2009.03 ]; then
echo " ... configured to use qt 4.5.2 (/opt/qtsdk-2009.03)"

export QTDIR="/opt/qtsdk-2009.03"
export PATH="$QTDIR/bin:$QTDIR/qt/bin:$PATH"
export QMAKESPEC="linux-g++"
export CC="gcc"
else
echo "... QT 4.5.2 not found."
fi
</>
vim .bash_profile
<>
# Load QT configuration script
echo "find Qt config file..."
if [ -f /etc/scripts/.qtconfig ]; then
echo "Qt configuring ..."
. /etc/scripts/.qtconfig
echo "done"
fi
</>
>>>>>>>>>>>>>>>
<>
libQtGui.so: undefined reference to `FcFreeTypeQueryFace'
Solution
1. cd /usr/src
2. wget http://fontconfig.org/release/fontconfig-2.4.2.tar.gz
3. tar -zxf fontconfig-2.4.2.tar.gz
4. cd fontconfig-2.4.2
5. ./configure -prefix=/usr
6. make
7. make install
</>
>>>>>>>>>>>>>>
Now if I run any compiled examples, I see this error
<>
Fontconfig error: Cannot load default config file
</>
I must put the config files of fontconfig-2.4.2.tar.gz at a wrong place.
