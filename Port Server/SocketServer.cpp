#include "SocketServer.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
using namespace std;


SocketServer::SocketServer(int port) {
	fport = port;
}

int SocketServer::get_port() {
	return fport;
}

void SocketServer::set_port(int port) {
	fport = port;
}

void SocketServer::doSetup(){
	struct sockaddr_in serv_addr, cli_addr;
	
	/* First call to socket() function */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);

   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }
   
   /* Initialize socket structure */
   bzero((char *) &serv_addr, sizeof(serv_addr));
   
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = ntohs(fport);
   
   /* Now bind the host address using bind() call.*/
   if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR on binding");
      exit(1);
   }
   
   listen(sockfd,5);
   
   #ifdef _WIN32
    #ifdef _WIN64
     clilen = sizeof(cli_addr);
 #endif   
   #elif __linux__
     socklen_t clilen = sizeof(cli_addr);
  #endif	 
 
   
   
   /* Accept actual connection from the client */
   newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
	
   if (newsockfd < 0) {
      perror("ERROR on accept");
      exit(1);
   }
   else
       printf("Listening on port %d /n ", fport);
   
   /* If connection is established then start communicating */
   bzero(buffer,256);
   
   

#ifdef _WIN32
    #ifdef _WIN64
   n = recv( newsockfd,buffer,255, 0);
 #endif   
   #elif __linux__
     n = recv( newsockfd,buffer,255,0);
#endif	 

   if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }
     
   //printf("Connection successful \n");
   
   /* Write a response to the client */
   //n = send(newsockfd,"I got your message",18);
   
   if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
   }
}

void SocketServer::Start(){
   doSetup();	
}






