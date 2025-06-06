#include <iostream>
#include <cstdlib>
#include <ctime>

#include "minigame.h"
#include "keyboard.h"
#include "textbox.h"
#include "menu.h"
#include "city.h"
#include "cham3.h"
#include "cleaningAlba.h"

using namespace std;

Minigame minigame;


int Minigame::gameMain()
{
	textBox* title = new textBox(1, 5, "아르바이트 구인공고", 1, "");
	string select[4] = { "가위바위보", "참참참", "청소 알바", "돌아가기"};
	Menu* men = new Menu(10, 20, 4, select);
	int gamePlay = men->select();
	delete men;
	delete title;
	if (gamePlay == 0)
	{
		rockScissorPaper();
		return 0;
	}
	else if (gamePlay == 1)
	{
		gameplay();
		return 0;
	}
	else if (gamePlay == 2)
	{
		cleaningPlay();
		return 0;
	}
	else if (gamePlay == 3)
	{
		return 1;
	}

}

void Minigame::rockScissorPaper()
{
	for (;;)
	{
		string weapon[3] = { "보", "가위", "주먹" };
		textBox* title = new textBox(1, 5, "가위바위보!", 1, "");
		textBox* about = new textBox(1, 6, "1 = 보 | 2 = 가위 | 3 = 주먹", 1, "");
		srand((unsigned int)time(NULL));
		int user = kbd.kbd() - '1';
		if (user >= 3 || user < 0)
		{
			textBox* error = new textBox(1, 10, "당신은 너무 긴장한 나머지 손가락을 세 개 펴고 말았다!", 1, "");
			textBox* error2 = new textBox(1, 11, "상대 : 지금 날 놀리는 겐가? 똑바로 하란 말이야.", 1, "");
			kbd.keyboardHit();
			delete error;
			delete error2;
			continue;
		}
		int computer = rand() % 3;
		string result;
		textBox* pro = new textBox(1, 10, "당신은 " + weapon[user] + ", 상대는 " + weapon[computer] + "를 냈습니다.", 1, "");
		if (user == computer)
		{
			result = "비겼습니다. 500골드를 얻었습니다.";
			city.money += 500;
		}
		else if (user < computer && user + 2 != computer)
		{
			result = "당신이 졌습니다.";
		}
		else
		{
			result = "당신이 이겼습니다. 1000골드를 얻었습니다.";
			city.money += 1000;
		}

		textBox* fin = new textBox(1, 15, result, 1, "");

		textBox* re = new textBox(1, 30, "아무 키나 눌러 돌아가기", 1, "");
		kbd.keyboardHit();

		delete title;
		delete about;
		delete fin;
		delete re;
		delete pro;

		return;
	}
}