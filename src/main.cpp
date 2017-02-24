/***************************
****H1Z1 FONT CHANGER*******
*********BY FLAV************
***********V1.0*************
***************************/

#include <windows.h>
#include <iostream>
#include <shlobj.h>
#include <sstream>

#include "functions.h"
#include "fileHandler.h"

#define ID_B_FONT 0
#define ID_B_GAME 1
#define ID_B_APPLY 2

using namespace std;

HINSTANCE instance;

LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);

int WinMain (HINSTANCE thisIns, HINSTANCE precedenteInstance,
LPSTR lignesDeCommande, int displayMode)
{
    HWND mainWndw;
    MSG message;
    WNDCLASS wc;
    fileHandler f;
  
    instance = thisIns;

    wc.style = 0;
    wc.lpfnWndProc = MainWndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = NULL;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(1 + COLOR_BTNFACE);
    wc.lpszMenuName =  NULL;
    wc.lpszClassName = "classeF";

    if(!RegisterClass(&wc)) 
        return FALSE;

    mainWndw = CreateWindow("classeF", "h1z1 Font Changer", WS_OVERLAPPEDWINDOW,
                                   CW_USEDEFAULT, CW_USEDEFAULT, 410, 300,
                                                   NULL, NULL, thisIns, NULL);
    if (!mainWndw) 
        return FALSE;

    ShowWindow(mainWndw, displayMode);
    UpdateWindow(mainWndw);


    while (GetMessage(&message, NULL, 0, 0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
    return message.wParam;
}


LRESULT CALLBACK MainWndProc(HWND mainWndw, UINT message, WPARAM wParam, LPARAM lParam)
{

    static HWND boutons[3] = {NULL};
    static fileHandler f;
    string gPath, fPath;
    HRESULT hr;


    switch (message)
    {
        case WM_CREATE:
            boutons[0] = CreateWindow("BUTTON", "Choose font", WS_CHILD | WS_VISIBLE,
        5, 5, 383, 30, mainWndw, ID_B_FONT, instance, NULL);
            boutons[1] = CreateWindow("BUTTON", "Locate game path", WS_CHILD | WS_VISIBLE,
        5, 45, 383, 30, mainWndw, ID_B_GAME, instance, NULL);
            boutons[2] = CreateWindow("BUTTON", "Change font", WS_CHILD | WS_VISIBLE,
        5, 85, 383, 30, mainWndw, ID_B_APPLY, instance, NULL);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case ID_B_FONT:
                    fPath = findFile(mainWndw);
                    f.setFontPath(fPath);
                    break;

                case ID_B_GAME:
                    gPath = BrowseFolder("C:");
                    f.setGamePath(gPath);
                    break;

                case ID_B_APPLY:  
                    changeFont(f.getFontPath(), f.getGamePath());
                    break;
            }
            return 0;

        default:
            return DefWindowProc(mainWndw, message, wParam, lParam);
    }
}





