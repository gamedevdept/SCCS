#include <iostream>
#include <cstdlib>
#include <ctime>

#include "minigame.h"
#include "keyboard.h"
#include "textbox.h"
#include "menu.h"
#include "city.h"

using namespace std;

Minigame minigame;

int Minigame::gameMain()
{
	textBox* title = new textBox(1, 5, "�Ƹ�����Ʈ ���ΰ���", 1, "");
	string select[2] = { "����������", "���ư���"};
	Menu* men = new Menu(10, 20, 2, select);
	int gamePlay = men->select();
	delete men;
	delete title;
	if (gamePlay == 0)
	{
		rockScissorPaper();
		return 0;
	}
	else
	{
		return 1;
	}

}

void Minigame::rockScissorPaper()
{
	string weapon[3] = { "��", "����", "�ָ�" };
	textBox* title = new textBox(1, 5, "����������!", 1, "");
	textBox* about = new textBox(1, 6, "1 = �� | 2 = ���� | 3 = �ָ�", 1, "");
	srand((unsigned int)time(NULL));
	int user = kbd.kbd() - '1';
	int computer = rand() % 3;
	string result;
	textBox* pro = new textBox(1, 10, "����� " + weapon[user] + ", ���� " + weapon[computer] + "�� �½��ϴ�.", 1, "");
	if (user == computer)
	{
		result = "�����ϴ�. 500��带 ������ϴ�.";
		city.money += 500;
	}
	else if (user < computer && user + 2 != computer)
	{
		result = "����� �����ϴ�.";
	}
	else
	{
		result = "����� �̰���ϴ�. 1000��带 ������ϴ�.";
		city.money += 1000;
	}

	textBox* fin = new textBox(1, 15, result, 1, "");

	textBox* re = new textBox(1, 30, "�ƹ� Ű�� ���� ���ư���", 1, "");
	kbd.keyboardHit();

	delete title;
	delete about;
	delete fin;
	delete re;
	delete pro;

	return;
}