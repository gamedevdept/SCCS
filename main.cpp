#include "header.h"

using namespace std;

Cursor cur;
Screen scr;
Keyboard kbd;
City city;

void gameScreen()
{
	city.drawMap();
	city.statusBar();
	textBox* menuOne = new textBox(30, 25, "1. 알바하기", 0, "");
	textBox* menuTwo = new textBox(30, 26, "2. 건물 구매", 0, "");
	kbd.keyboardHit();
	delete menuOne;
	delete menuTwo;
}

void endDay()
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
	delete story;
	scr.clear();
	gameScreen();


	return 0;
}