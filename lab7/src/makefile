CC=gcc

all: tcpserver tcpclient udpserver udpclient

tcpserver: 
	$(CC) tcpserver.c -o tcpserver 

tcpclient: 
	$(CC) tcpclient.c -o tcpclient
 
udpserver: 
	$(CC) udpserver.c -o udpserver 

udpclient: 
	$(CC) udpclient.c -o udpclient

clean :
	rm tcpclient tcpserver udpclient udpserver
