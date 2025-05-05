#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <cwchar>
#include "GameManager.h"
#include "Map.h"

#pragma execution_character_set( "utf-8" )

int main()
{
	SetConsoleOutputCP(65001);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hConsole, &cursorInfo);

	//May cause issues with the screen resolution. If so, comment this part
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 46;                   // Width of each character in the font
	cfi.dwFontSize.Y = 64;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	HWND wConsole = GetConsoleWindow();
	RECT r;
	GetWindowRect(wConsole, &r); //stores the console's current dimensions
	MoveWindow(wConsole, r.left, r.top, 1200, 1200, TRUE);

	GameManagerInstance->InitGameManager();

	while (!GameManagerInstance->gameFinished)
	{
		MapInstance->Draw();
		GameManagerInstance->Update();

		Sleep(250);
	}

	system("cls");
}
