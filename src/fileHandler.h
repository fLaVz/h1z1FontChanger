/***************************
****H1Z1 FONT CHANGER*******
*********BY FLAV************
***************************/

#pragma once

#include <iostream>
#include <fstream>


class fileHandler {

	std::string fontName;
	std::string gamePath;

public:

	fileHandler();
	
	void request();

	void copy(int cpt);
	void copy();
};