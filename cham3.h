#pragma once

#include<stdio.h>

void init_UI();
void textClear();
void imgClear();
void intro();

class Player {
public:
	int score; // 참교육 성공한 횟수에 따라 추가 돈얻을수있게
	int heart;
	int choice;
	Player() : score(0), heart(3), choice(0) {} //생성자
	void setChoice();
};

class Badman {
public:
	int heart;
	int choice;
	Badman(int heart) : heart(heart), choice(0) {} //생성자
	void setChoice();
};

class Game {
public:
	int round;
	int stage;
	Player& player;
	Badman& badman;
	Game(int round, int stage, Player& player, Badman& badman) : round(round), stage(stage), player(player), badman(badman) {}
	int fight();

};

int gameplay();

void checkResult(int randomHeart, int victoryStage, int victory);