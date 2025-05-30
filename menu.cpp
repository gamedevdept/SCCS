#include <iostream>
#include <fstream>
#include <string>

#include "menu.h"
#include "cursor.h"
#include "keyboard.h"

using namespace std;

Menu::Menu(int x, int y, int len, string userMenu[])
{
	length = len;
	startX = x;
	startY = y;

	for (int i = 0; i < length; i++)
	{
		cur.gotoXY(startX + 2, startY + i);
		cout << userMenu[i];
		if (max < userMenu[i].length())
		{
			max = userMenu[i].length();
		}
	}
}

Menu::Menu(int x, int y, int len, string userMenu[], int structure)
{
	this->length = len;
	this->startX = x;
	this->startY = y;
	this->structure = structure;
	int indexlen = 6;
	string index[6] = { "�̸�", "����", "�ϴ� �ູ��", "�ϴ� ��", "�α� ����ġ", "�ϴ� ����" };

	fstream data;
	string line;

	int i;

	for (i = 0; i < indexlen; i++)
	{
		cur.gotoXY(startX + 2 + i * 10, startY);
		cout << index[i];
	}

	for (int i = 0; i < length; i++)
	{
		cur.gotoXY(startX + 2, startY + i + 1);
		if (userMenu[i] == "���ư���")
		{
			cout << userMenu[i];
			continue;
		}
		data.open(userMenu[i]);
		getline(data, line);
		cout << line; // �̸�
		getline(data, line);
		getline(data, line);
		getline(data, line);
		cur.gotoXY(startX + 12, startY + i + 1);
		cout << line; // ����
		getline(data, line);
		cur.gotoXY(startX + 22, startY + i + 1);
		cout << line; // �ϴ� �ູ��
		getline(data, line);
		cur.gotoXY(startX + 32, startY + i + 1);
		cout << line; // �ϴ� ��
		getline(data, line);
		cur.gotoXY(startX + 42, startY + i + 1);
		cout << line; // �α� ����ġ
		getline(data, line);
		cur.gotoXY(startX + 52, startY + i + 1);
		cout << line; // �ϴ� ����
		data.close();
	}
	max = startX + 57;
}

void Menu::refresh()
{
	if (structure == 0)
	{
		int i;
		for (i = 0; i < length; i++)
		{
			cur.gotoXY(startX, startY + i);
			if (i == current)
			{
				cout << "��";
			}
			else
			{
				cout << " ";
			}
		}
		cur.defaultXY();
	}
	else
	{
		int i;
		for (i = 0; i < length; i++)
		{
			cur.gotoXY(startX, startY + i + 1);
			if (i == current)
			{
				cout << "��";
			}
			else
			{
				cout << " ";
			}
		}
		cur.defaultXY();
	}
	
}

int Menu::select()
{

	int input;
	refresh();

	while (input = kbd.kbd())
	{
		if (input == 800 && current < length - 1)
		{
			current++;
		}
		else if (input == 800 && current == length - 1)
		{
			current = 0;
		}
		else if (input == 772 && current == 0)
		{
			current = length - 1;
		}
		else if (input == 772 && current != 0)
		{
			current--;
		}
		else if (input == 13)
		{
			return current;
		}
		refresh();
	}
}

Menu::~Menu()
{
	int i;
	for (i = 0; i < length + 1; i++)
	{
		cur.gotoXY(startX, startY + i);
		for (int i = 0; i < max + 2; i++)
		{
			cout << " ";
		}
	}
}