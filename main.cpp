#include <iostream>

#include "cursor.h"
#include "screen.h"
#include "keyboard.h"
#include "city.h"
#include "minigame.h"
#include "textbox.h"
#include "menu.h"



using namespace std;

Screen scr;
City city;
Minigame minigame;

void minigameMain()
{

}

void shopMain()
{

}

void gameScreen()
{
	city.drawMap();
	city.statusBar();
	string gameList[2] = {"아르바이트 하기", "건물 구매하기"};
	Menu* menuOne = new Menu(20, 30, 2, gameList);
	int menuSelect = menuOne->select();
	delete menuOne;
	if (menuSelect == 0)
	{
		scr.clear();
		minigame.rockScissorPaper();
	}
	else
	{
		return;
	}
}

void endDay()
{
	city.skipDate();
}

void game()
{

}

void shop()
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
	for (;;)
	{
		endDay();
		gameScreen();
	}



	return 0;
}