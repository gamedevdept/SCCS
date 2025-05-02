#include <iostream>

#ifndef TEXTBOX_H
#define TEXTBOX_H

class textBox
{
private:
	int startX = 0;
	int startY = 0;
	int endX = 0;
	int endY = 0;

public:
	textBox(int x, int y, std::string message, int center, std::string path);
	~textBox();
};


#endif