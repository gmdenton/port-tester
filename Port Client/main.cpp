/* 
 * File:   main.cpp
 * Author: gdenton
 *
 * Created on January 8, 2017, 4:19 PM
 */

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "SocketClient.h"
#include "../../Params.h"
#include "../../FileReader.h"

using namespace std;

/*
 * 
 */

void CreateSocket(Params param){
    SocketClient cl(param.Address(), param.Port());
    cl.Connect();
}

int main(int argc, char** argv) {

    if (argv[1] == NULL)
    {
        cout << "ERROR: Missing input parameter (1).\n IP address and port csv file name and path.";
        exit(1);
    }
   
    //Create filereader to load IP addresses and port numbers	
    FileReader fr;    
    fr.OpenFile(argv[1]);
    
    Params *SelectedParam = NULL;
    //iterate through file reader and create socket thread for each. 
    for (vector<Params>::iterator it=fr.List.begin(); it!=fr.List.end(); ++it)
    {
        SelectedParam = &*it;
        CreateSocket(*SelectedParam);
    }
    return 0;
}

