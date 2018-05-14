/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Params.h
 * Author: gdenton
 *
 * Created on December 31, 2016, 8:25 PM
 */

#include <string.h>
#include <string>

using namespace std;

#include <string.h>
#include <string>

using namespace std;

#ifndef PARAMS_H
#define PARAMS_H


class Params {
	string IPAddress;
	int IPPort;
public:
	  void set_IPAddress (string);
	  void set_Port(int);	
	  string Address() {return IPAddress;}
	  int Port() {return IPPort;}
};

#endif /* PARAMS_H */

