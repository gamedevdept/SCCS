#include <iostream>
#include <fstream>
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
	endY = startY;

	if (message != "")
	{
		if (center == 1)
		{
			startX = 80 - (message.length() / 2);
		}
		endX = startX + message.length();
		textCursor.gotoXY(startX, startY);
		cout << message;
	}
	else
	{
		ifstream ascii;
		ascii.open(path);

		string line;

		getline(ascii, line);
		if (center == 1)
		{
			startX = 80 - (line.length() / 2);
		}
		textCursor.gotoXY(startX, startY);
		cout << line;
		endX = startX;
		while (getline(ascii, line))
		{
			if (line.length() > endX - startX)
			{
				endX = startX + line.length();
			}
			textCursor.gotoXY(startX, ++endY);
			cout << line;
		}
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