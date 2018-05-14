/* 
 * File:   SocketServer.h
 * Author: gdenton
 *
 * Created on 27 December 2016, 12:46 PM
 */

#ifndef SOCKETSERVER_H
#define	SOCKETSERVER_H

class SocketServer {
public:
	void set_port(int port);
	int get_port(void);
	SocketServer(int port);
	void Start();
	
private:
	int sockfd, newsockfd, fport, clilen;
	char buffer[256];
	int  n;
	void doSetup();
	
};


#endif	/* SOCKETSERVER_H */

