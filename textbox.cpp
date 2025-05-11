#include <iostream>
#include <fstream>
#include <string>

#include "textbox.h"
#include "cursor.h"
#include "screen.h"

using namespace std;


Screen textScreen;

textBox::textBox(int x, int y, string message, int center, string path)
{
	Screen scr;

	startX = x;
	startY = y;
	endY = startY;

	if (message != "")
	{
		if (center == 1)
		{
			startX = 80 - (message.length() / 2);
		}
		endX = startX + message.length();
		cur.gotoXY(startX, startY);
		std::cout << message;
	}
	else //아스키아트, 스토리
	{
		ifstream ascii;
		ascii.open(path); // 파일 오픈 

		string line; // 한 줄씩 넣는 변수

		getline(ascii, line); // 한 줄 불러오기
		if (center == 1) // 가운데 정렬 할 시
		{
			startX = 80 - (line.length() / 2); // 가운데 - length / 2를 startX로 설정
		}
		endX = startX;
		
		do
		{
			if (line.length() > endX - startX)
			{
				endX = startX + line.length();
			}
			cur.gotoXY(startX, endY++);
			std::cout << line;
		} while (getline(ascii, line)); // 한 줄 불러오기
	}
	cur.defaultXY();
}

textBox::~textBox()
{
	int i, j;

	for (i = startY; i <= endY; i++)
	{
		cur.gotoXY(startX, i);
		for (j = startX; j <= endX; j++)
		{
			std::cout << " ";
		}
	}
	cur.defaultXY();
}