#include "menu.h"
#include "cursor.h"
#include "keyboard.h"

using namespace std;

Cursor menuCursor;

Menu::Menu(int x, int y, int len, string userMenu[])
{
	length = len;
	startX = x;
	startY = y;

	for (int i = 0; i < length; i++)
	{
		menuCursor.gotoXY(startX + 2, startY + i);
		cout << userMenu[i];
		if (max < userMenu[i].length())
		{
			max = userMenu[i].length();
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
		else
		{
			cout << " ";
		}
	}
	cur.defaultXY();
}

int Menu::select()
{
	int input;
	refresh();

	while (input = kbd.kbd())
	{
		if (input == 800 && current < length)
		{
			current++;
			refresh();
		}
		if (input == 772 && current != 0)
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
		for (int i = 0; i < max + 2; i++)
		{
			cout << " ";
		}
	}
}