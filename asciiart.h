#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "screen.h"
#include "cursor.h"

using namespace std;

class Ascii
{
private:
	int width = 0;
	int height = 0;
	int startX = 0;
	int startY = 0;

public:
	Ascii(string path, int x, int y)
	{
		startX = x;
		startY = y;
		ifstream ascii;
		ascii.open(path);

		string line;

		while (getline(ascii, line))
		{
			if (line.length() > width)
			{
				width = line.length();
			}
			gotoXY(startX, startY + height++);
			cout << line;
		}
		gotoDefault();

	}
	~Ascii()
	{
		int i = 0;
		for (i; i < height; i++)
		{
			gotoXY(startX, startY + i);
			for (int j = 0; j < width; j++)
			{
				cout << " ";
			}

		}

		gotoDefault();
	}
};