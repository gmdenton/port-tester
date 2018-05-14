/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SocketClient.h
 * Author: gdenton
 *
 * Created on January 1, 2017, 10:27 AM
 */

#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>

using namespace std;

#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

class SocketClient {
private:
   int sockfd, fport, n;
   struct hostent *server;
   char buffer[256];
   string fip;
   void doSetup();
public:
    void set_port(int port);
    int get_port(void);
    void set_IP(string IP);
    string get_IP(void);
    SocketClient(string IP, int port);
    void Connect(); 
};

#endif /* SOCKETCLIENT_H */

