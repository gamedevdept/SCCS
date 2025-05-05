#include <iostream>
#include <string>

#ifndef MENU_H
#define MENU_H

typedef struct select
{
	std::string message;
	int(*fp);
} Select;

class Menu
{


public:
	Menu();
	~Menu();
};

#endif // !MENU_H

