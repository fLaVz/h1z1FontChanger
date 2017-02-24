/***************************
****H1Z1 FONT CHANGER*******
*********BY FLAV************
***************************/

#include "functions.h"

static int CALLBACK BrowseCallbackProc(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{

    if (uMsg == BFFM_INITIALIZED)
    {
        std::string tmp = (const char *)lpData;
        SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);
    }

    return 0;
}


std::string BrowseFolder(std::string saved_path)
{
    TCHAR path[MAX_PATH];

    const char * path_param = saved_path.c_str();
    
    BROWSEINFO bi = { 0 };
    bi.lpszTitle = TEXT("Browse for game folder...");
    bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
    bi.lpfn = BrowseCallbackProc;
    bi.lParam = (LPARAM)path_param;

    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);

    if (pidl != 0)
    {
        //get the name of the folder and put it in path
        SHGetPathFromIDList(pidl, path);

        //free memory used
        IMalloc * imalloc = 0;
        if (SUCCEEDED(SHGetMalloc(&imalloc)))
        {
            imalloc->Free(pidl);
            imalloc->Release();
        }

        return path;
    }

    return "";
}


std::string findFile(HWND parentWindow)
{
	OPENFILENAME ofn;
	char path[MAX_PATH];

    //Variable qui va recevoir le chemin de la musique
	char filePath[MAX_PATH] = "";


    //Remplissage de la structure

    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = parentWindow;
    ofn.lpstrFile = filePath;
    ofn.nMaxFile = MAX_PATH;

    //Avec un filtre de fichiers audio
    ofn.lpstrFilter = "Font File\0*.ttf\0\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    
    //Si l'utilisateur clique sur "Ouvrir"
    if(GetOpenFileName(&ofn) == TRUE) {
    	strcpy(path, filePath);
    }

    return path;
}


void changeFont(std::string fontPath, std::string gamePath) {


	for(int i = 1; i < 12; i++)
		applyFont(fontPath, gamePath, i);

}

void applyFont(std::string fontPath, std::string gamePath, int i) {

	LPCSTR fPath;
	LPCSTR gPath;
	BOOL b;
	
	switch (i)
    {
        case 1:
        	gamePath += "/NanumBarunGothicBold.ttf";
        	fPath = fontPath.c_str();
			gPath = gamePath.c_str();
			b = CopyFile(fPath, gPath, 0);
			if(!b)
				std::cout << "ERROR" << std::endl;
			else
				std::cout << "file copyied Successfully" << std::endl;
			std::cout << gPath << std::endl;
        	break;

        case 2:
        	gamePath += "/NotoSansJP-Regular.otf";
        	fPath = fontPath.c_str();
			gPath = gamePath.c_str();
			b = CopyFile(fPath, gPath, 0);
			if(!b)
				std::cout << "ERROR" << std::endl;
			else
				std::cout << "file copyied Successfully" << std::endl;
			std::cout << gPath << std::endl;
        	break;

        case 3:
        	gamePath += "/Oswald-Bold_0.ttf";
        	fPath = fontPath.c_str();
			gPath = gamePath.c_str();
			b = CopyFile(fPath, gPath, 0);
			if(!b)
				std::cout << "ERROR" << std::endl;
			else
				std::cout << "file copyied Successfully" << std::endl;
			std::cout << gPath << std::endl;
        	break;

        case 4:
        	gamePath += "/Oswald-Light_0.ttf";
        	fPath = fontPath.c_str();
			gPath = gamePath.c_str();
			b = CopyFile(fPath, gPath, 0);
			if(!b)
				std::cout << "ERROR" << std::endl;
			else
				std::cout << "file copyied Successfully" << std::endl;
        	break;

        case 5:
        	gamePath += "/Oswald-Regular_0.ttf";
        	fPath = fontPath.c_str();
			gPath = gamePath.c_str();
			b = CopyFile(fPath, gPath, 0);
			if(!b)
				std::cout << "ERROR" << std::endl;
			else
				std::cout << "file copyied Successfully" << std::endl;
        	break;

        case 6:
        	gamePath += "/Roboto-Bold.ttf";
        	fPath = fontPath.c_str();
			gPath = gamePath.c_str();
			b = CopyFile(fPath, gPath, 0);
			if(!b)
				std::cout << "ERROR" << std::endl;
			else
				std::cout << "file copyied Successfully" << std::endl;
        	break;

        case 7:
        	gamePath += "/Roboto-Light.ttf";
        	fPath = fontPath.c_str();
			gPath = gamePath.c_str();
			b = CopyFile(fPath, gPath, 0);
			if(!b)
				std::cout << "ERROR" << std::endl;
			else
				std::cout << "file copyied Successfully" << std::endl;
        	break;

        case 8:
        	gamePath += "/Roboto-Medium.ttf";
        	fPath = fontPath.c_str();
			gPath = gamePath.c_str();
			b = CopyFile(fPath, gPath, 0);
			if(!b)
				std::cout << "ERROR" << std::endl;
			else
				std::cout << "file copyied Successfully" << std::endl;
        	break;

        case 9:
        	gamePath += "/Roboto-Regular.ttf";
        	fPath = fontPath.c_str();
			gPath = gamePath.c_str();
			b = CopyFile(fPath, gPath, 0);
			if(!b)
				std::cout << "ERROR" << std::endl;
			else
				std::cout << "file copyied Successfully" << std::endl;
        	break;

        case 10:
        	gamePath += "/ROSA Verde Normal.ttf";
        	fPath = fontPath.c_str();
			gPath = gamePath.c_str();
			b = CopyFile(fPath, gPath, 0);
			if(!b)
				std::cout << "ERROR" << std::endl;
			else
				std::cout << "file copyied Successfully" << std::endl;
        	break;

        case 11:
        	gamePath += "/simhei.ttf";
        	fPath = fontPath.c_str();
			gPath = gamePath.c_str();
			b = CopyFile(fPath, gPath, 0);
			if(!b)
				std::cout << "ERROR" << std::endl;
			else
				std::cout << "file copyied Successfully" << std::endl;
        	break;

        default:
            std::cout << "Done!" << std::endl;
    }



}