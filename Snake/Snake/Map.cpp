#include "Map.h"
#include "GameManager.h"


Map::Map()
{
	m_sAscii = std::string("") +
		u8"╔═══════════════════════╗" + "\n" +
		u8"║                       ║" + "\n" +
		u8"║                       ║" + "\n" +
		u8"║                       ║" + "\n" +
		u8"║                       ║" + "\n" +
		u8"║                       ║" + "\n" +
		u8"║                       ║" + "\n" +
		u8"║                       ║" + "\n" +
		u8"║                       ║" + "\n" +
		u8"║                       ║" + "\n" +
		u8"║                       ║" + "\n" +
		u8"║                       ║" + "\n" +
		u8"╚═══════════════════════╝" + "\n";
}

const std::string& Map::GetAscii()  const
{
	return m_sAscii;
}

int Map::GetHeight() const
{
	return 12;
}

int Map::GetWidth() const
{
	return 24;
}

void Map::Draw() const
{
	GameManagerInstance->Render(0, 0, GetAscii().c_str());
}

bool Map::IsWall(Tile tile) const
{
	if (tile.x <= 0 || tile.x >= GetWidth() || tile.y <= 0 || tile.y >= GetHeight())
	{
		return true;
	}

	return false;
}