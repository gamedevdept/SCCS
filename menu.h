#include <iostream>
#include <string>

using namespace std;

#ifndef MENU_H
#define MENU_H

class Menu
{
private:
	int max = 0;
	int startX;
	int startY;
	int length;
	int current = 0;

public:
	Menu(int x, int y, int len, string userMenu[]);
	void refresh();
	int select();
	~Menu();
};

#endif // !MENU_H

