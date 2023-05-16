#/ bin/sh
ifconfig | grep -r 'ether' | awk {'print $4'}
