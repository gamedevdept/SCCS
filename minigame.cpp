#include <cstdlib>
#include <ctime>
#include "header.h"

using namespace std;

Keyboard gameKbd;

void Minigame::rockScissorPaper()
{
	textBox* title = new textBox(1, 5, "����������!", 1, "");
	textBox* about = new textBox(1, 6, "1 = �� | 2 = ���� | 3 = �ָ�", 1, "");
	srand(time(NULL));
	int user = gameKbd.kbd();
	int computer = rand() % 3;
	string result;

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

	textBox* fin = new textBox(1, 10, result, 1, "");

	textBox* re = new textBox(1, 30, "�ƹ� Ű�� ���� ���ư���", 1, "");
	gameKbd.keyboardHit();

	delete title;
	delete about;
	delete fin;
	delete re;

	return;
}