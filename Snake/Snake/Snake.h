#pragma once
#include <deque>
#include "Tile.h"
#include "Directions.h"

class Snake
{
	const char* s_AsciiBody = u8"■";
	const char* s_AsciiLookUp = u8"^";
	const char* s_AsciiLookDown = u8"v";
	const char* s_AsciiLookLeft = u8"<";
	const char* s_AsciiLookRight = u8">";
public:
	Snake(int startingX, int startingY, int startingBodyLength, Direction startingDirection)
		: lookingDirection(startingDirection)
		, head(startingX, startingY)
	{
		//head = Tile(startingX, startingY);
		CreateInitialBody(startingBodyLength);
	}

	void Draw();
	void Update();
	void ReadInput();
	void Move();
	bool CheckCollision();

private:
	std::deque<Tile> body;
	Tile head;
	Direction lookingDirection;

	void CreateInitialBody(int length);
	
};