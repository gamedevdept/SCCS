#include <Windows.h>
#include "header.h"

void Cursor::gotoXY(int x, int y)
{
	COORD cursor;
	cursor.X = x;
	cursor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void Cursor::defaultXY()
{
	gotoXY(0, 47);
}