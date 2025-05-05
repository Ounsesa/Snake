#include "GameManager.h"
#include <windows.h>

GameManager* GameManagerInstance = new GameManager();

void GameManager::InitGameManager()
{
	_snake = new Snake(SNAKE_X, SNAKE_Y, SNAKE_START_BODY_LENGTH, SNAKE_START_LOOK);
	gameFinished = false;
}

void GameManager::Update()
{
	_snake->Update();
}

void GameManager::Render(short _iX, short _iY, const char* _sString, int _iColor, bool _bDrawBlankSpaces)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, _iColor);

	COORD oInitialCoord = { _iX, _iY };
	SetConsoleCursorPosition(hConsole, oInitialCoord);

	const size_t uLength(strlen(_sString));
	short iCurrentX = _iX;
	short iCurrentY = _iY;
	for (unsigned int i = 0; i < uLength; ++i)
	{
		if (_sString[i] == '\n')
		{
			iCurrentX = _iX;
			++iCurrentY;
			COORD oCoord = { iCurrentX, iCurrentY };
			SetConsoleCursorPosition(hConsole, oCoord);
		}
		else
		{
			if (_sString[i] == ' ' && !_bDrawBlankSpaces)
			{
				COORD oCoord = { iCurrentX - 1, iCurrentY };
				SetConsoleCursorPosition(hConsole, oCoord);
			}
			else
			{
				printf("%c", _sString[i]);
			}
			iCurrentX++;
		}
	}
	SetConsoleTextAttribute(hConsole, 15);
}

void GameManager::SetWhiteSpace(short _iX, short _iY)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 1);

	COORD oCoord = { _iX,_iY };
	SetConsoleCursorPosition(hConsole, oCoord);
	printf(" ");
	SetConsoleTextAttribute(hConsole, 15);
}
