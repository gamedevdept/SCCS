#include <iostream>
#include <Windows.h>
#include <string>
#include "screen.h"
#include "cursor.h"

using namespace std;

Cursor cur;

void Screen::screenClear()
{
	int i, j;

	for (i = 1; i < Screen::height; i++)
	{
		cur.gotoXY(1, i);
		for (j = 1; j < Screen::width; j++)
		{
			cout << " ";
		}
	}

	cur.gotoXY(1, Screen::height + 1);
	cout << endl;

}

void Screen::screenEdge()
{
	cur.gotoXY(0, 0);
	cout << "¦£";
	for (int i = 1; i < Screen::width; i++)
	{
		cout << "¦¡";
	}
	cout << "¦¤";

	for (int i = 1; i < Screen::height; i++)
	{
		cur.gotoXY(0, i);
		cout << "¦¢";
		cur.gotoXY(Screen::width, i);
		cout << "¦¢";
	}

	cur.gotoXY(0, Screen::height);
	cout << "¦¦";
	for (int i = 1; i < Screen::width; i++)
	{
		cout << "¦¡";
	}
	cout << "¦¥";
}

void Screen::screenText(string message, int x, int y)
{
	cur.gotoXY(x, y);
	cout << message;
	cur.gotoDefault();
}

int Screen::getHeight()
{
	return Screen::height;
}