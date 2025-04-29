#include <iostream>
#include <Windows.h>
#include <string>
#include "screen.h"
#include "cursor.h"

using namespace std;

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
	gotoDefault();
}

void Screen::centerText(string message, int y)
{
	int length = message.length();
	gotoXY((Screen::width / 2) - length / 2, y);
	cout << message;
	gotoDefault();
}

int Screen::getHeight()
{
	return Screen::height;
}

int Screen::getWidth()
{
	return Screen::width;
}

void Screen::verticalLine(int x)
{

}

void Screen::horizontalLine(int y)
{
	gotoXY(0, y);
	cout << "¦§";
	for (int i = 1; i < width; i++)
	{
		cout << "¦¡";
	}
	cout << "¦©";
}