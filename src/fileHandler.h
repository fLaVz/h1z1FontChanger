#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>


class fileHandler {

	std::string fontPath;
	std::string gamePath;

public:

	fileHandler();

	void setFontPath(std::string path);
	void setGamePath(std::string path);

	std::string getFontPath();
	std::string getGamePath();
};

#endif