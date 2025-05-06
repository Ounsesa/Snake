#pragma once
#include "Snake.h"
#include "Directions.h"
#include "Tile.h"

const int SNAKE_X = 5;
const int SNAKE_Y = 5;
const int SNAKE_START_BODY_LENGTH = 4;
const Direction SNAKE_START_LOOK = Down;
const int BODY_GROWTH_FOOD = 2;
const int FOOD_SCORE = 50;

class GameManager
{
public:
	bool gameFinished = false;


	void InitGameManager();
	
	void Update();
	void Render(short _iX, short _iY, const char* _sString, int _iColor = 15, bool _bDrawBlankSpaces = false);
	void SetWhiteSpace(short _iX, short _iY);
	void GenerateRandomFood();

	GameManager() {};
	Tile Food;
private:
	void PrintScore();
	Snake* _snake;
	int score = -FOOD_SCORE;
};

extern GameManager* GameManagerInstance;