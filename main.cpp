#include "header.h"

using namespace std;

Cursor cur;
Screen scr;
Keyboard kbd;

int main()
{
	scr.drawEdge();
	textBox* title = new textBox(30, 20, "SCCS", 1, "");
	//Ascii* asciiTitle = new Ascii("SCCS.txt", 30, 20);
	kbd.keyboardHit();
	scr.horizontalLine(30);
	delete title;
	//delete asciiTitle;

	return 0;
}