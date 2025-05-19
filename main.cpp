#include <iostream>

#include "screen.h"
#include "minigame.h"
#include "menu.h"
#include "shop.h"
#include "city.h"
#include "textbox.h"
#include "keyboard.h"



using namespace std;

void minigameMain()
{

}

void shopMain()
{

}

void gameScreen()
{
	int complete = 1;
	while (complete == 1)
	{
		city.drawMap();
		city.statusBar();
		string gameList[2] = { "아르바이트 하기", "건물 구매하기" };
		Menu* menuOne = new Menu(20, 30, 2, gameList);
		int menuSelect = menuOne->select();
		delete menuOne;
		if (menuSelect == 0)
		{
			scr.clear();
			complete = minigame.gameMain();
		}
		else
		{
			scr.clear();
			sho.shopMain();
		}
	}
}

void endDay()
{
	city.skipDate();
}

void game()
{

}

void ending()
{

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
	scr.clear();
	gameScreen();
	for (int i = 1;i <= 52; i++)
	{
		endDay();
		gameScreen();
	}
	scr.clear();
	scr.verticalLine(30);
	ending();



	return 0;
}