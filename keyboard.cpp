#include <conio.h>

#include "header.h"


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