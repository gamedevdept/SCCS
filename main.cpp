#define _CRT_SECURE_NO_WARNING

#include <iostream>
#include <string>
#include "screen.h"

using namespace std;

int main()
{
	Screen screen;

	screen.screenEdge();
	screen.screenClear();
	screen.screenText("Hello", 1, 1);

	return 0;
}