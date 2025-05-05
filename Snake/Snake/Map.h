#pragma once

#include <string>
#include <vector>

struct Tile;

class Map
{
public:
	Map();

	const std::string& GetAscii() const;
	int GetHeight() const;
	int GetWidth() const;
	void Draw() const;

	bool IsWall(Tile tile) const;

protected:
	std::string m_sAscii;
};

static Map* MapInstance = new Map();