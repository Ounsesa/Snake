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
	bool CollisionWithBody(Tile other);

private:
	void ReadInput();
	void Move();
	bool CheckDeadCollision();
	void CheckFoodCollision();
	std::deque<Tile> body;
	Tile head;
	Direction lookingDirection;

	int bodyGrowth = 0;

	void CreateInitialBody(int length);
	
};