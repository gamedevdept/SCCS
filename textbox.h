#pragma once
#include <iostream>
#include <string>
#include "cursor.h"
#include "screen.h"

using namespace std;


class textBox
{
private:
	int x;
	int y;
	int length;
	string message;

public:
	textBox(int x, int y, string message, int center = 0)
	{
		Screen scr;

		textBox::x = x;
		textBox::y = y;
		textBox::length = message.length();
		textBox::message = message;
		if (center == 1)
		{
			textBox::x = (scr.getWidth() / 2) - (textBox::length / 2);
		}
		gotoXY(textBox::x, textBox::y);
		cout << message;
		gotoDefault();

	}

	~textBox()
	{

		gotoXY(x, y);
		for (int i = 1; i <= message.length(); i++)
		{
			cout << " ";
		}
		gotoDefault();
	}
};