#include <iostream>

#include "screen.h"
#include "cursor.h"

using std::cout;
Cursor screenCursor;

void Screen::drawEdge()
{
	screenCursor.gotoXY(0, 0);
	cout << "¦£";
	for (int i = 1; i < width; i++)
	{
		cout << "¦¡";
	}
	cout << "¦¤";

	for (int i = 1; i < height; i++)
	{
		screenCursor.gotoXY(0, i);
		cout << "¦¢";
		screenCursor.gotoXY(width, i);
		cout << "¦¢";
	}

	screenCursor.gotoXY(0, height);
	cout << "¦¦";
	for (int i = 1; i < Screen::width; i++)
	{
		cout << "¦¡";
	}
	cout << "¦¥";
	screenCursor.defaultXY();
}

void Screen::clear()
{
	int i, j;

	for (i = 1; i < height; i++)
	{
		screenCursor.gotoXY(1, i);
		for (j = 1; j < width; j++)
		{
			cout << " ";
		}
	}

	screenCursor.gotoXY(1, height + 1);
}

void Screen::verticalLine(int x)
{
	int i;
	screenCursor.gotoXY(x, 0);
	cout << "¦¨";
	for (i = 1; i < height; i++)
	{
		screenCursor.gotoXY(x, i);
		cout << "¦¢";
	}
	screenCursor.gotoXY(x, height);
	cout << "¦ª";
	screenCursor.defaultXY();
}

void Screen::horizontalLine(int y)
{
	screenCursor.gotoXY(0, y);
	cout << "¦§";
	for (int i = 1; i < width; i++)
	{
		cout << "¦¡";
	}
	cout << "¦©";
	screenCursor.defaultXY();
}



