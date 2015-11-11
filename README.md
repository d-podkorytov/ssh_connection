SSH_CONNECTIONS is program for allow SSH access to Host by IP, others is
denied.

INSTALLATION:

1) make clean && make
2) cp ssh_connect /bin

Add line with allowed networks to file /etc/ssh/sshrc        
Every networks just first part of allowed address.

For example:

/bin/ssh_connect 192.168.1. 10. 91.11.1.1

This line permits access only from 192.168.1.X 10.X.X.X and 91.11.1.1 hosts,
others is denied.

Watch out about remote installation for SSH_CONNECT.
Wrong addereses in /etc/ssh/sshrc can lock you next entering to system.
After remote installation first try to enter in second session and dont close
first.

From time to time take a look to audit log /var/log/ssh_connect.log

With best wishes, Dmitry Podkorytov

 