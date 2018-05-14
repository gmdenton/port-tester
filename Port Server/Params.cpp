/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Params.h"
#include <string.h>

using namespace std;

void Params::set_IPAddress(string addr) {
  IPAddress = addr;	
}

void Params::set_Port(int aport) {
  IPPort = aport;	
}


