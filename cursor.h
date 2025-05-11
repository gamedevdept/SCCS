#ifndef CURSOR_H
#define CURSOR_H


class Cursor
{

public:
	void gotoXY(int x, int y);
	void defaultXY();
};

extern Cursor cur;

#endif // !CURSOR_H


