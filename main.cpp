#include "header.h"

using namespace std;

Cursor cur;
Screen scr;
Keyboard kbd;
City city;

void gameScreen()
{

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

	return 0;
}