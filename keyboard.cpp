#include <conio.h>
#include "keyboard.h"


int keyboardHit()
{
	while (true)
	{
		if (_kbhit())
		{
			return 0;
		}
	}
}