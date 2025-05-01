#include "header.h"

using namespace std;

Cursor cur;

int main()
{
	cur.gotoXY(3, 10);
	cout << "test";
	cur.defaultXY();

	return 0;
}