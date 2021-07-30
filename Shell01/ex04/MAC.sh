% ifconfig -a|grep 'ether'|sed 's/ether//g'|xargs|tr ' ' '\n' 
#prints all network connexions, finds lines containing MAC adresses, cuts out the "ether" string, cleans out the white spaces, then replaces
#the spaces with line breaks
