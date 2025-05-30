#include <iostream>

#include "screen.h"
#include "minigame.h"
#include "menu.h"
#include "shop.h"
#include "city.h"
#include "textbox.h"
#include "keyboard.h"



using namespace std;

void gameScreen()
{
	int end = 0;
	while (end == 0)
	{
		int complete = 1;
		while (complete == 1)
		{
			scr.clear();
			city.drawMap();
			city.statusBar();
			string gameList[3] = { "아르바이트 하기", "건물 구매하기", "턴 넘기기" };

			Menu* menuOne = new Menu(city.startX, 7 + city.height, 3, gameList);
			int menuSelect = menuOne->select();
			delete menuOne;
			if (menuSelect == 0)
			{
				scr.clear();
				complete = minigame.gameMain();
			}
			else if (menuSelect == 1)
			{
				scr.clear();
				sho.shopMain();
			}
			else if (menuSelect == 2)
			{
				complete = 0;
				scr.clear();
			}
		}
		end = city.skipDate();
	}
	
}

int main(void)
{
	scr.drawEdge();
	textBox* asciiTitle = new textBox(30, 10, "", 1, "cpp.txt");
	textBox* startKey = new textBox(70, 35, "Press any key to Start", 1, "");
	kbd.keyboardHit();
	scr.horizontalLine(30);
	delete asciiTitle;
	delete startKey;
	textBox* story = new textBox(1, 31, "", 0, "story.txt");
	kbd.keyboardHit();
	scr.drawEdge();
	delete story;
	gameScreen();
	scr.clear();

	textBox* title = new textBox(1, 5, "The End", 1, "");
	textBox* ending = new textBox(1, 15, "", 1, "endingcredit.txt");

	return 0;
}