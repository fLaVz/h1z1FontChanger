#include "fileHandler.h"

using namespace std;

fileHandler::fileHandler() {

	fontPath = "";
	gamePath = "";
}

void fileHandler::setFontPath(string path) {
    fontPath = path;
    cout << fontPath << endl;
}

void fileHandler::setGamePath(string path) {
    gamePath = path;
    cout << gamePath << endl;
}

std::string fileHandler::getFontPath() {

    return fontPath;
}

std::string fileHandler::getGamePath() {

    return gamePath;
}
