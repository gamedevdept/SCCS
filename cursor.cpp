#include <Windows.h>
#include "cursor.h"
#include "screen.h"

using namespace std;

Screen scr;

void Cursor::gotoXY(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void Cursor::gotoDefault()
{
	gotoXY(1, scr.getHeight());
}