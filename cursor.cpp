#include <Windows.h>
#include "cursor.h"

Cursor cur;

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