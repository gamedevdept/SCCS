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
	else //�ƽ�Ű��Ʈ, ���丮
	{
		ifstream ascii;
		ascii.open(path); // ���� ���� 

		string line; // �� �پ� �ִ� ����

		getline(ascii, line); // �� �� �ҷ�����
		if (center == 1) // ��� ���� �� ��
		{
			startX = 80 - (line.length() / 2); // ��� - length / 2�� startX�� ����
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
		} while (getline(ascii, line)); // �� �� �ҷ�����
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