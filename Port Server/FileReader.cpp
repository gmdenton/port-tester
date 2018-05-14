/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "FileReader.h"
#include "Params.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

void FileReader::OpenFile(string file) {
    ifstream myFile(file.c_str());
	if (myFile.is_open())
	{
		printf("Successfully opened data file %s /n ",file.c_str());
		while (!myFile.eof())
		{
			getline(myFile, sLine);
			List.insert(List.end(),ReadLine());
			sLine.clear();
		}
		myFile.close();
	}
	else
	{
		printf("Unable to open data file %s /n ", file.c_str());
		exit(1);
	}
}

Params FileReader::ReadLine() {
	int comma_pos;
	comma_pos = sLine.find(",",0);
	Params *Param(new Params());
	Param->set_IPAddress(sLine.substr(0,comma_pos));
	Param->set_Port( atoi( sLine.substr(comma_pos +1, sLine.length() -1).c_str()));
	return *Param;
}
