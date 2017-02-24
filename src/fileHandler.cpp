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

void fileHandler::copy() {

    for(int i = 1; i < 12; i++)
        copy(i); 
}

void fileHandler::copy(int cpt) {

	string output = gamePath;

    cout << "LOOOOOOOOOOAD" << endl;

	switch (cpt)
    {
        case 1:
        	output += "NanumBarunGothicBold.ttf";
        	break;

        case 2:
        	output += "NotoSansJP-Regular.otf";
        	break;

        case 3:
        	output += "Oswald-Bold_0.ttf";
        	break;

        case 4:
        	output += "Oswald-Light_0.ttf";
        	break;

        case 5:
        	output += "Oswald-Regular_0.ttf";
        	break;

        case 6:
        	output += "Roboto-Bold.ttf";
        	break;

        case 7:
        	output += "Roboto-Light.ttf";
        	break;

        case 8:
        	output += "Roboto-Medium.ttf";
        	break;

        case 9:
        	output += "Roboto-Regular.ttf";
        	break;

        case 10:
        	output += "ROSA Verde Normal.ttf";
        	break;

        case 11:
        	output += "simhei.ttf";
        	break;

        default:
            cout << "Done!" << endl;
    }


	ifstream ifs{fontPath ,  ios::binary};
   	ofstream ofs{output , ios::binary};
   	
   	char c;
   	while (ifs.get(c))
    	ofs.put(c);
}