/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "SocketClient.h"

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

using namespace std;

SocketClient::SocketClient(string IP, int port) {
    fip = IP;
    fport = port;
}

string SocketClient::get_IP(){
    return fip;
}
int SocketClient::get_port(){
    return fport;
}

void SocketClient::set_IP(string IP){
    fip = IP;
}

void SocketClient::set_port(int port){
    fport = port;
}

string getCurrentDate() {
 time_t t;
struct tm * ptr;
char buf [20];
time ( &t );
ptr= localtime ( &t );
strftime (buf,80," %d-%m-%Y %I:%M:%S",ptr);
puts (buf);
string str(buf, 80);
  return str;  
}

void SocketClient::doSetup() {
    struct sockaddr_in serv_addr;
    
    /* Create a socket point */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   
   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }
	
   server = gethostbyname(fip.c_str());
   
   if (server == NULL) {
      fprintf(stderr,"ERROR, no such host \n");
      exit(0);
   }
   
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   serv_addr.sin_port = htons(fport);
   printf("Current Time");
   printf("",getCurrentDate());
    /*attempt to connect to the server*/
    printf( "Connecting to %s on port: %d \n", fip.c_str(), fport); 
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
      printf("ERROR connecting \n");
      //exit(1);
   }
    else {
      printf("Connection successful \n");
      /*connection test was successful, so close the socket*/
      close(sockfd);
    }
    printf("");
  
}

void SocketClient::Connect() {
    /*Setup the socket instance*/
    doSetup(); 
}


