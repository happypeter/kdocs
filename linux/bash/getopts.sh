usage()
{
cat<< sss
Usage:
sh  s.sh  -c
sh s.sh -t cc -p dd
sss
}

while getopts "ct:p:" option
do
        case $option in
        c)
                echo sleeping...
                sleep 5
                echo wake up now
        ;;
        t)
                echo hello
        ;;
        p)
                echo world
        ;;
        *)
                usage
        ;;
        esac
done


