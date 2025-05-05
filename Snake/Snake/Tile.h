#pragma once
#include "Directions.h"

struct Tile
{
	Tile(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	bool operator==(Tile other)
	{
		return (x == other.x && y == other.y);
	}
	Tile operator+(Direction other)
	{
		return Tile(x + other.x, y + other.y);
	}
	Tile& operator+=(Direction other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	int x;
	int y;
private:

};


