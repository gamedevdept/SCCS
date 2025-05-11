#include "menu.h"
#include "cursor.h"
#include "keyboard.h"

using namespace std;

Cursor menuCursor;
Keyboard menuKeyboard;

Menu::Menu(int x, int y, int len, string userMenu[])
{
	length = len;
	startX = x;
	startY = y;

	for (int i = startY; i < startY + length; i++)
	{
		menuCursor.gotoXY(startX + 2, i);
		cout << userMenu[startY - i];
		if (max < userMenu[startY - i].length())
		{
			max = userMenu[startY - i].length();
		}
	}
}

void Menu::refresh()
{
	int i;
	for (i = 0; i < length; i++)
	{
		menuCursor.gotoXY(startX, startY + i);
		if (i == current)
		{
			cout << "¢º";
		}
	}
}

int Menu::select()
{
	int input;

	while (input = menuKeyboard.kbd())
	{
		if (input == 780 && current < length)
		{
			current++;
			refresh();
		}
		if (input == 72 && current != 0)
		{
			current--;
			refresh();
		}
		if (input == 13)
		{
			return current;
		}
	}
}

Menu::~Menu()
{
	int i;
	for (i = 0; i < length; i++)
	{
		menuCursor.gotoXY(startX, startY + i);
		for (int j = 0; i < max; i++)
		{
			cout << " ";
		}
	}
}