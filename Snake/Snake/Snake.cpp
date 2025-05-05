#include "Snake.h"
#include "GameManager.h"
#include <Windows.h>
#include "Map.h"

void Snake::Draw()
{
	const char* face = nullptr;
	if (lookingDirection == Up)
	{
		face = s_AsciiLookUp;
	}
	else if (lookingDirection == Down)
	{
		face = s_AsciiLookDown;
	}
	else if (lookingDirection == Left)
	{
		face = s_AsciiLookLeft;
	}
	else
	{
		face = s_AsciiLookRight;
	}

	GameManagerInstance->Render(head.x, head.y, face);
	for (auto it = body.begin(); it != body.end(); it++)
	{		
		GameManagerInstance->Render(it->x, it->y, s_AsciiBody);
	}
}

void Snake::Update()
{
	if (!CheckCollision())
	{
		ReadInput();
		Move();
		Draw();
	}
}

void Snake::ReadInput()
{
	short uUpKeyState = GetKeyState('W');
	short uDownKeyState = GetKeyState('S');
	short uLeftKeyState = GetKeyState('A');
	short uRightKeyState = GetKeyState('D');

	Direction intentDirection = Down;

	if ((uDownKeyState & 0x8000) != 0)
	{
		intentDirection = Down;
	}
	else if ((uLeftKeyState & 0x8000) != 0)
	{
		intentDirection = Left;
	}
	else if ((uRightKeyState & 0x8000) != 0)
	{
		intentDirection = Right;
	}
	else if ((uUpKeyState & 0x8000) != 0)
	{
		intentDirection = Up;
	}

	if (!(intentDirection + lookingDirection == DirectionZero))
	{
		lookingDirection = intentDirection;
	}
}

void Snake::Move()
{
	Tile removed = body.back();
	body.pop_back();
	
	GameManagerInstance->SetWhiteSpace(removed.x, removed.y);

	removed = head;
	body.push_front(removed);
	head += lookingDirection;
}

bool Snake::CheckCollision()
{
	if (MapInstance->IsWall(head))
	{
		GameManagerInstance->gameFinished = true;
		return true;
	}

	for (auto it = body.begin(); it != body.end(); it++)
	{
		if (head == *it)
		{
			GameManagerInstance->gameFinished = true;
			return true;
		}
	}
	return false;
}

void Snake::CreateInitialBody(int length)
{
	Direction reverseDirection = lookingDirection.GetContrary();
	for (int i = 1; i <= length; i++)
	{
		body.push_back(Tile(head + reverseDirection * i));
	}
}
