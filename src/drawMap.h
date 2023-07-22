#pragma once
#include "mecro.h"

class drawMap
{
public:
	DrawMap();
	inline void gotoxy(int x, int y)
	{
		COORD pos = {x,y};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos)
	}
	void GridDraw(int Start_x, int Start_y, int Width, int Height); 
	~DrawMap();
}