#include <cstdlib>
#include <ctime>
#include "header.h"

using namespace std;

Keyboard gameKbd;

void Minigame::rockScissorPaper()
{
	textBox* title = new textBox(1, 5, "가위바위보!", 1, "");
	textBox* about = new textBox(1, 6, "1 = 보 | 2 = 가위 | 3 = 주먹", 1, "");
	srand(time(NULL));
	int user = gameKbd.kbd();
	int computer = rand() % 3;
	string result;

	if (user == computer)
	{
		result = "비겼습니다.";
	}
	else if (user < computer && user + 2 != computer)
	{
		result = "당신이 졌습니다.";
	}
	else
	{
		result = "당신이 이겼습니다.";
	}

	textBox* fin = new textBox(1, 10, result, 1, "");

	textBox* re = new textBox(1, 30, "아무 키나 눌러 돌아가기", 1, "");
	gameKbd.keyboardHit();

	delete title;
	delete about;
	delete fin;
	delete re;

	return;
}