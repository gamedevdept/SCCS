#include <iostream>

#ifndef TEXTBOX_H
#define TEXTBOX_H

class textBox
{
private:
	int startX;
	int startY;
	int endX;
	int endY;

public:
	textBox(int x, int y, std::string message, int center, std::string path);
	~textBox();
};


#endif