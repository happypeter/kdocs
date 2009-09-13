do everything under ubuntu
last change in 10_17_2008
config

| A- Serial Device : /dev/ttyS0 |

| E - Bps/Par/Bits : 115200 8N1 |

| F - Hardware Flow Control : No |

| G - Software Flow Control : No |



Transferring files

      To send a file to target board:
   1.

      Run 'rz' in minicom, No parameters are needed-------

      Peter: as long as lrzsz is installed this step is not necessary
   2.

      In Minicom, this is done with [Ctrl-Alt] + Z and then S (using zmodem), which brings up a file selection dialog.

To receive a file from the target board:

1. Transmit the file(s) using 'sz' in minicom, specifying them as arguments.

2. The host terminal will detect and accept the transfer automatically.

If the transfer does nothing, or if you encounter a "Failure executing protocol" error, while trying to send a file with Zmodem under minicom, you should install a Y/Z modem. On debian based systems, such as ubuntu, run the following command

# apt-get install lrzsz ---------------it is necessary on peter ubuntu

*****************************

now i

vivi->> load flash kernel x

then

Ctrl+a s -->chosse zImage

but see the error

+-----------[xmodem upload - Press CTRL-C to quit]------------+

|Retry 0: NAK on sector |

|Retry 0: NAK on sector |

|Retry 0: Retry Count Exceeded |

| |

|Transfer incomplete |

but this is fixed by

vivi->>param set xmodem_initial_timeout 3000000

^_^a lot i need to learn about vivi

