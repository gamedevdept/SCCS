#include "header.h"

using namespace std;

Cursor cur;
Screen scr;
Keyboard kbd;

int main()
{
	scr.drawEdge();
	textBox* asciiTitle = new textBox(30, 20, "", 1, "SCCS.txt");
	kbd.keyboardHit();
	scr.horizontalLine(30);
	delete asciiTitle;

	return 0;
}