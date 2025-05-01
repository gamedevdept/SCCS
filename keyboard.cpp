#include <conio.h>

#include "header.h"


int Keyboard::keyboardHit()
{
	while (true)
	{
		if (_kbhit())
		{
			return 0;
		}
	}
}