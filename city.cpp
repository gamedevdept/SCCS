#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

#include "cursor.h"
#include "city.h"
#include "structure.h"
#include "textbox.h"
#include "screen.h"

#define WIDTH 20
#define HEIGHT 6

using namespace std;

City city;

City::City()
{
	Structure a;
	vector<vector<Structure>> tempMap(mapSize, vector<Structure>(mapSize, a));
	this->map = tempMap;
}
void City::drawMap()
{

	int width = WIDTH * mapSize + mapSize - 1;
	height = HEIGHT * mapSize + mapSize - 1;
	startX = 80 - ((width + 2) / 2);
	int startY = 5;

	cur.gotoXY(startX, startY);
	cout << "┌";
	for (int i = 0; i < width; i++)
	{
		cout << "─";
	}
	cout << "┐";

	for (int i = startY + 1; i <= startY + height; i++)
	{
		cur.gotoXY(startX, i);
		cout << "│";
		cur.gotoXY(startX + width + 1, i);
		cout << "│";
	}

	cur.gotoXY(startX, startY + height + 1);
	cout << "└";
	for (int i = 0; i < width; i++)
	{
		cout << "─";
	}
	cout << "┘";

	int i, j;

	for (i = HEIGHT + 1; i <= height; i += HEIGHT + 1)
	{
		cur.gotoXY(startX, startY + i);
		cout << "├";
		for (j = 1; j <= width; j++)
		{
			cout << "─";
		}
		cout << "┤";
	}

	for (i = WIDTH + 1; i <= width; i += WIDTH + 1)
	{
		cur.gotoXY(startX + i, startY);
		cout << "┬";
		for (j = startY + 1; j <= startY + height; j++)
		{
			cur.gotoXY(startX + i, j);
			if ((j - startY) % (HEIGHT + 1) == 0)
			{
				cout << "┼";
				continue;
			}

			cout << "│";
		}
		cur.gotoXY(startX + i, startY + height + 1);
		cout << "┴";
	}
	cur.defaultXY();

	fstream ascii;
	string line;

	for (int y = 0; y < mapSize; y++)
	{
		for (int x = 0; x < mapSize; x++)
		{
			ascii.open(map[y][x].path);
			if (!ascii)
			{
				cur.gotoXY(startX + 1 + (WIDTH + 1) * x, startY + 1 + (HEIGHT + 1) * y + 3);
				cout << "     !건설 예정!";
				continue;
			}
			for (int k = 0; k < 5; k++)
			{
				getline(ascii, line);
				cur.gotoXY(startX + 1 + (WIDTH + 1) * x, startY + 1 + (HEIGHT + 1) * y + k);
				cout << line;
			}
			ascii.close();
		}
	}
}

void City::statusBar()
{
	cur.gotoXY(25, 1);
	cout << "재산 | " << money;
	cout << "               ";
	cout << "명성 | " << rep;
	cout << "               ";
	cout << "인구수 | " << pop;
	cout << "               ";
	cout << "행복도 | " << happy;
	cout << "               ";
	cout << "(" << date << "/52) 턴";
	cur.defaultXY();
}

int City::skipDate()
{
	int level[5] = { 0, 5000, 10000, 15000, 30000 };
	int moneyBonus[5] = { 0, 10, 20, 30, 40 };
	int happyBonus[5] = { 0, 5, 10, 20, 30 };
	int tempRep = city.rep;
	int tempHappy = city.happy;

	for (int y = 0; y < mapSize; y++)
	{
		for (int x = 0; x < mapSize; x++)
		{
			happy += map[y][x].happyPerDay;
			rep += map[y][x].repPerDay;
			money += map[y][x].moneyPerDay;
		}
	}
	if (level[this->level + 1] <= this->rep && level[this->level + 1] <= this->pop)
	{
		if (this->level <= 3)
		{
			this->level++;
			cur.gotoXY(1, 20);
			cout << "인구수와 명성이 높아져 도시의 단계가 높아졌습니다!";
			cur.gotoXY(1, 21);
			cout << "레벨 : " << this->level - 1 << " -> " << this->level;
			cur.gotoXY(1, 22);
			cout << "수익 보너스 : " << moneyBonus[this->level] << "%";
			cur.gotoXY(1, 23);
			cout << "행복도 보너스 : " << moneyBonus[this->level] << "%";
		}
	}
	textBox* title = new textBox(1, 5, "일일 정산", 1, "");
	cur.gotoXY(1, 8);
	cout << city.date << "턴";
	cur.gotoXY(1, 10);
	cout << "재산 증가량 : " << tempMoney << " -> " << city.money << " ( " << city.money - tempMoney << " )";
	cur.gotoXY(1, 12);
	cout << "재산 증가량 : " << tempPop << " -> " << city.pop << " ( " << city.pop - tempPop << " )";
	cur.gotoXY(1, 14);
	cout << "행복도 증가량 : " << tempHappy << " -> " << city.happy << " ( " << city.happy - tempHappy << " )";
	cur.gotoXY(1, 16);
	cout << "명성 증가량 : " << tempRep << " -> " << city.rep << " ( " << city.rep - tempRep << " )";

	textBox* end = new textBox(1, 30, "아무 키나 눌러 다음 턴 진행", 1, "");
	_getch();
	tempMoney = city.money;
	tempPop = city.pop;

	if (date == 52)
	{
		ending();
		return 1;
	}
	date++;
	return 0;
}

void City::purchase(string path, int x, int y)
{
	ifstream data(path);
	string line;

	getline(data, line);
	map[y][x].name = line;
	getline(data, line);
	map[y][x].path = line;
	getline(data, line);
	map[y][x].upgrade = stoi(line);
	getline(data, line);
	map[y][x].expense = stoi(line);
	getline(data, line);
	map[y][x].happyPerDay = stoi(line);
	getline(data, line);
	map[y][x].repPerDay = stoi(line);
	getline(data, line);
	map[y][x].popPerDay = stoi(line);
	getline(data, line);
	map[y][x].moneyPerDay = stoi(line);
	if (map[y][x].upgrade == 1)
	{
		getline(data, line);
		map[y][x].upgradepath = line;
	}
	data.close();

	city.money -= map[y][x].expense;
	city.pop += map[y][x].popPerDay;
}

void City::vacant()
{
	int x, y;
	vector<vector<int>> mapLine(mapSize, vector<int>(0));

	for (y = 0; y < mapSize; y++)
	{
		for (x = 0; x < mapSize; x++)
		{
			if (map[y][x].path == "")
			{
				mapLine[y].push_back(x);
			}
		}
	}

	vacantMap = mapLine;
}

vector<UpgradeList> City::upgrade()
{
	vector<UpgradeList> upgradelist;
	UpgradeList a;
	for (int y = 0; y < mapSize; y++)
	{
		for (int x = 0; x < mapSize; x++)
		{
			if (map[y][x].upgrade == 1)
			{
				a.y = y;
				a.x = x;
				a.name = map[y][x].name;
				upgradelist.push_back(a);
			}
		}
	}
	return upgradelist;
}

void City::ending()
{
	string fileName[3] = { "badending.txt", "normalending.txt", "happyending.txt" };

	scr.horizontalLine(30);
	textBox* story = new textBox(1, 31, "", 0, fileName[happy / 40]);
	_getch();
}