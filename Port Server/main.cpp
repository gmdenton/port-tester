/* 
 * File:   main.cpp
 * Author: gdenton
 *
 * Created on 25 December 2016, 5:13 PM
 */
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <pthread.h>


#include "SocketServer.h"
#include "Params.h"
#include "FileReader.h"


using namespace std;

//
void *createSocket(void *port){
    long portno;
    portno = (long)port;
    int pt = (int)portno;
    SocketServer server(pt); 
    server.Start();
}

void CreateSingleSocket(int port){
    SocketServer server(port); 
    server.Start();
}


int main(int argc, char** argv) {
    
    /*Use for testing*/
    //argv[1] = "/home/gdenton/IPs.txt";
    //check we have an input file.
    if (argv[1] == NULL)
    {
        cout << "ERROR: Missing input parameter (1). IP address and port csv file name and path./n";
        exit(1);
    } 
    //Create filereader to load IP addresses and port numbers	
    FileReader fr;    
    fr.OpenFile(argv[1]);
    //create thread array for each port loaded from file.    
    pthread_t svrthread[fr.List.size()]; 
   
    int noThread = 0;
    
    Params *SelectedParam = NULL;
    //iterate through file reader and create socket thread for each. 
    
    for (vector<Params>::iterator it=fr.List.begin(); it!=fr.List.end(); ++it)
    {
        SelectedParam = &*it;
        pthread_create(&svrthread[noThread], NULL, createSocket, (void *)SelectedParam->Port());
        /*use for testing single socket instance*/
        //CreateSingleSocket(SelectedParam->Port()); 
        noThread++;
    }
    //join socket threads to main thread.
    for (int i = 0; i < noThread; i++)
        pthread_join(svrthread[i], NULL);
    
return 0;
}




