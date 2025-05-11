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
	string weapon[3] = { "보", "가위", "주먹" };
	textBox* title = new textBox(1, 5, "가위바위보!", 1, "");
	textBox* about = new textBox(1, 6, "1 = 보 | 2 = 가위 | 3 = 주먹", 1, "");
	srand(time(NULL));
	int user = gameKbd.kbd() - '1';
	int computer = rand() % 3;
	string result;
	textBox* pro = new textBox(1, 10, "당신은 " + weapon[user] + ", 상대는 " + weapon[computer] + "를 냈습니다.", 1, "");
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

	textBox* fin = new textBox(1, 15, result, 1, "");

	textBox* re = new textBox(1, 30, "아무 키나 눌러 돌아가기", 1, "");
	gameKbd.keyboardHit();

	delete title;
	delete about;
	delete fin;
	delete re;
	delete pro;

	return;
}