#define _CRT_SECURE_NO_WARNING

#include <iostream>
#include <string>

#include "screen.h"
#include "keyboard.h"
#include "textbox.h"
#include "asciiArt.h"

using namespace std;

int main()
{
	Screen scr;

	scr.screenEdge();
	

	textBox* title = new textBox(30, 20, "SCCS", 1);
	Ascii* asciiTitle = new Ascii("SCCS.txt", 30, 20);
	keyboardHit();
	scr.horizontalLine(30);
	delete title;
	delete asciiTitle;


	return 0;
}