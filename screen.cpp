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
	cur.gotoDefault();
}

void Screen::screenText(string message, int x, int y)
{
	cur.gotoXY(x, y);
	cout << message;
	cur.gotoDefault();
}

void Screen::centerText(string message, int y)
{
	int length = message.length();
	cur.gotoXY((Screen::width / 2) - length / 2, y);
	cout << message;
	cur.gotoDefault();
}

int Screen::getHeight()
{
	return Screen::height;
}

int Screen::getWidth()
{
	return Screen::width;
}

Box* Screen::box(int startx, int starty, int width, int height, int centerAlign)
{
	Box* box = new Box;

	if (centerAlign == 1)
	{
		startx = (getWidth() / 2) - (width / 2);
	}

	box->startx = startx;
	box->starty = starty;
	box->width = width;
	box->height = height;

	cur.gotoXY(startx, starty);
	cout << "¦£";
	for (int i = 0; i < width - 2; i++)
	{
		cout << "¦¡";
	}
	cout << "¦¤";
	for (int i = 1; i < height - 1; i++)
	{
		cur.gotoXY(startx, starty + i);
		cout << "¦¢";
		for (int j = 0; j < width - 2; j++)
		{
			cout << " ";
		}
		cout << "¦¢";
	}
	cur.gotoXY(startx, starty + height - 1);
	cout << "¦¦";
	for (int i = 0; i < width - 2; i++)
	{
		cout << "¦¡";
	}
	cout << "¦¥";

	return box;
}

void Screen::boxText(Box* box, string message, int centerAlign)
{
	int x = box->startx + 1;
	int y = box->starty + 1;

	if (centerAlign == 1)
	{
		x += ((box->width - 2) / 2) - (message.length() / 2) - 1;
	}

	cur.gotoXY(x, y);
	cout << message;
	cur.gotoDefault();
}