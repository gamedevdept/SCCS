#include <iostream>
#include <cstdlib>
#include <ctime>

#include "minigame.h"
#include "keyboard.h"
#include "textbox.h"

using namespace std;

Keyboard gameKbd;

void Minigame::rockScissorPaper()
{
	string weapon[3] = { "��", "����", "�ָ�" };
	textBox* title = new textBox(1, 5, "����������!", 1, "");
	textBox* about = new textBox(1, 6, "1 = �� | 2 = ���� | 3 = �ָ�", 1, "");
	srand(time(NULL));
	int user = gameKbd.kbd() - '1';
	int computer = rand() % 3;
	string result;
	textBox* pro = new textBox(1, 10, "����� " + weapon[user] + ", ���� " + weapon[computer] + "�� �½��ϴ�.", 1, "");
	if (user == computer)
	{
		result = "�����ϴ�.";
	}
	else if (user < computer && user + 2 != computer)
	{
		result = "����� �����ϴ�.";
	}
	else
	{
		result = "����� �̰���ϴ�.";
	}

	textBox* fin = new textBox(1, 15, result, 1, "");

	textBox* re = new textBox(1, 30, "�ƹ� Ű�� ���� ���ư���", 1, "");
	gameKbd.keyboardHit();

	delete title;
	delete about;
	delete fin;
	delete re;
	delete pro;

	return;
}