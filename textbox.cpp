#include <iostream>
#include <string>

#include "header.h"

using namespace std;

Cursor textCursor;
Screen textScreen;

textBox::textBox(int x, int y, string message, int center, string path)
{
	Screen scr;

	startX = x;
	startY = y;

	if (message != "")
	{
		if (center == 1)
		{
			startX = 80 - (message.length() / 2);
		}
		endX = startX + message.length();
		endY = startY;
		textCursor.gotoXY(startX, startY);
		cout << message;
	}
	else
	{

	}
	textCursor.defaultXY();
}

textBox::~textBox()
{
	int i, j;

	for (i = startY; i <= endY; i++)
	{
		textCursor.gotoXY(startX, i);
		for (j = startX; j <= endX; j++)
		{
			cout << " ";
		}
	}
	textCursor.defaultXY();
}