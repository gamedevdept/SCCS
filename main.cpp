#define _CRT_SECURE_NO_WARNING

#include <iostream>
#include <string>
#include "screen.h"
#include "keyboard.h"
#include "textbox.h"

using namespace std;

int main()
{
	Screen screen;

	screen.screenEdge();
	
	textBox* title = new textBox(30, 20, "게임 제목", 1);
	keyboardHit();
	screen.horizontalLine(30);
	delete title;

	return 0;
}