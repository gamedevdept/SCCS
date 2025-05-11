#include <conio.h>

#include "keyboard.h"

Keyboard kbd;

int Keyboard::keyboardHit()
{
	while (true)
	{
		if (_kbhit())
		{
			_getch();
			return 0;
		}
	}
}

int Keyboard::kbd()
{
	int input = _getch();
	if (input == 224)
	{
		switch (input = _getch())
		{
		case 72:
			return 772; //up
			break;
		case 75:
			return 775; //left
			break;
		case 77:
			return 777; //right
			break;
		case 80:
			return 800; //down
			break;
		}
	}
	return input;
}