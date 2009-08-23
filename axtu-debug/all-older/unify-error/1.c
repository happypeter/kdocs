Steps to Reproduce:
  1. On client, remove wireshark package.
     # rpm -e wireshark --nodeps
  2. On server, delete wireshark rpm file from repository.
  3. Update wireshark-gnome with using axtu, and see the error message.
     "Network error. See /var/log/axtu/error.log"

>using newer version of axtu the error here is 
>"Cannot connetct with TSN server. See /var/log/axtu/error.log"
>this is obviously not true. I want to change it into "Pack not found in repo", or sth




  1. On client, remove wireshark package.
     # rpm -e wireshark --nodeps
  2. On server, delete wireshark header file from repository.
  3. Update wireshark-gnome with using axtu, and see the error message.
     "The UpdateServer URL is not correct." 
>using newer version of axtu the error here is "Cannot connetct with TSN server."


  1. On client, remove wireshark package.
     # rpm -e wireshark --nodeps
  2. On server, delete wireshark from list.
  3. Update wireshark-gnome with using axtu, and see the error message.
     "Required Packages were not found. (Package Requirement Loop) See
/var/log/axtu/error.log"

>this error message has no problem, it means dep check failed.
>you will get the same error, if you delete rpm in  repo and run $hsyum-arch .

CONCLUTION:

>the errors are produced by the mismanipulation of server maintainer. I will prefer to 
>keep them different, because they are produced by different mismanipulations.

>if the errors are unified, that simply make it more difficult to solve the server side problem 

>if server maintainer is doing his job right, end-user will never see these errors.



>>>HOWEVER, IF YOU UNPLUG THE NET CABLE, THE ERROR WILL BE "Cannot connetct with TSN server."
WHICH IS A RIGHT ONE,SO IF I MODIFIED IT INTO "Required data were not found on server", then it seems 
the connection is available, so that's lying as well.
So the best way is to distinguish the different cases, rather then rudely change the error message.
