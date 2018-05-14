/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileReader.h
 * Author: gdenton
 *
 * Created on December 31, 2016, 9:59 PM
 */

#include "Params.h"
#include <string>
#include <string.h>
#include <vector>

using namespace std;

#ifndef FILEREADER_H
#define FILEREADER_H


class FileReader {
	string sLine;
	
public:
	vector<Params> List;
	void OpenFile(string); 
	Params ReadLine();
};


#endif /* FILEREADER_H */

