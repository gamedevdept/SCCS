#include "header.h"

using namespace std;

Cursor cur;
Screen scr;

int main()
{
	cur.gotoXY(3, 10);
	cout << "test";
	cur.defaultXY();
	scr.drawEdge();
	scr.verticalLine(3);
	scr.horizontalLine(3);

	return 0;
}