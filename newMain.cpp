#include "header.h"

using namespace std;

Cursor cur;
Screen scr;
Keyboard kbd;

int main()
{
	cur.gotoXY(3, 10);
	cout << "test";
	cur.defaultXY();
	scr.drawEdge();
	scr.verticalLine(3);
	kbd.keyboardHit();
	scr.horizontalLine(3);

	return 0;
}