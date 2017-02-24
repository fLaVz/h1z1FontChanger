#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <windows.h>
#include <iostream>
#include <shlobj.h>
#include <sstream>

#include "fileHandler.h"



static int CALLBACK BrowseCallbackProc(HWND, UINT, LPARAM, LPARAM);
std::string BrowseFolder(std::string);
std::string findFile(HWND);

void changeFont(std::string, std::string);
void applyFont(std::string, std::string, int);

#endif