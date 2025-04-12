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
	screen.centerText("SCCS", 3);

	box* testBox = screen.box(70, 40, 30, 3, 1);
	screen.boxText(testBox, "Press any button to start", 1);

	return 0;
}