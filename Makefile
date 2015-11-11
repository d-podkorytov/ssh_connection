all: ssh_connect.c  Makefile
	gcc ssh_connect.c -o ssh_connect
clean:
	rm -f ssh_connect *~
	
install: all
	cp ssh_connect /usr/bin
	cat profile >> /etc/ssh/sshrc
	echo Dont forget check /etc/ssh/sshrc for checking allowed networks. 

tgz:
	(cd .. && tar cvfz ssh_connection.tgz ssh_connection && ls -l | grep ssh_connect )