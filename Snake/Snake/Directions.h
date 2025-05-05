#pragma once

struct Direction{

public:
	Direction(int x, int y) : x(x), y(y) {}

	Direction GetContrary() const {
		return Direction(-x, -y);
	}
	bool operator==(Direction other)
	{
		return (x == other.x && y == other.y);
	}
	Direction operator*(int number)
	{
		return Direction(x * number, y * number);
	}
	Direction operator+(Direction other)
	{
		return Direction(x + other.x, y + other.y);
	}
	int x;
	int y;


};

static const Direction Up = Direction(0, -1);
static const Direction Down = Direction(0, 1);
static const Direction Left = Direction(-1, 0);
static const Direction Right = Direction(1, 0);
static const Direction DirectionZero = Direction(0, 0);