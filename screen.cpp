#include <iostream>
#include <Windows.h>
#include <string>
#include "screen.h"

using namespace std;

void gotoXY(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void gotoDefault(int height)
{
	gotoXY(1, height + 1);
}

void Screen::screenClear()
{
	int i, j;

	for (i = 1; i < Screen::height; i++)
	{
		gotoXY(1, i);
		for (j = 1; j < Screen::width; j++)
		{
			cout << " ";
		}
	}

	gotoXY(1, Screen::height + 1);
	cout << endl;

}

void Screen::screenEdge()
{
	gotoXY(0, 0);
	cout << "¦£";
	for (int i = 1; i < Screen::width; i++)
	{
		cout << "¦¡";
	}
	cout << "¦¤";

	for (int i = 1; i < Screen::height; i++)
	{
		gotoXY(0, i);
		cout << "¦¢";
		gotoXY(Screen::width, i);
		cout << "¦¢";
	}

	gotoXY(0, Screen::height);
	cout << "¦¦";
	for (int i = 1; i < Screen::width; i++)
	{
		cout << "¦¡";
	}
	cout << "¦¥";
}

void Screen::screenText(string message, int x, int y)
{
	gotoXY(x, y);
	cout << message;
	gotoDefault(Screen::height);
}