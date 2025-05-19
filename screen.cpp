#include <iostream>

#include "screen.h"
#include "cursor.h"

using std::cout;

Screen scr;

void Screen::drawEdge()
{
	cur.gotoXY(0, 0);
	cout << "¦£";
	for (int i = 1; i < width; i++)
	{
		cout << "¦¡";
	}
	cout << "¦¤";

	for (int i = 1; i < height; i++)
	{
		cur.gotoXY(0, i);
		cout << "¦¢";
		cur.gotoXY(width, i);
		cout << "¦¢";
	}

	cur.gotoXY(0, height);
	cout << "¦¦";
	for (int i = 1; i < Screen::width; i++)
	{
		cout << "¦¡";
	}
	cout << "¦¥";
	cur.defaultXY();
}

void Screen::clear()
{
	int i, j;

	for (i = 1; i < height; i++)
	{
		cur.gotoXY(1, i);
		for (j = 1; j < width; j++)
		{
			cout << " ";
		}
	}

	cur.gotoXY(1, height + 1);
}

void Screen::verticalLine(int x)
{
	int i;
	cur.gotoXY(x, 0);
	cout << "¦¨";
	for (i = 1; i < height; i++)
	{
		cur.gotoXY(x, i);
		cout << "¦¢";
	}
	cur.gotoXY(x, height);
	cout << "¦ª";
	cur.defaultXY();
}

void Screen::horizontalLine(int y)
{
	cur.gotoXY(0, y);
	cout << "¦§";
	for (int i = 1; i < width; i++)
	{
		cout << "¦¡";
	}
	cout << "¦©";
	cur.defaultXY();
}



