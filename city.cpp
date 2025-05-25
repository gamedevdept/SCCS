#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

#include "cursor.h"
#include "city.h"
#include "structure.h"
#include "textbox.h"

#define WIDTH 20
#define HEIGHT 6

using namespace std;

City city;

City::City()
{
	int i;
	Structure a;
	vector<vector<Structure>> tempMap(mapSize, vector<Structure>(mapSize, a));
	this->map = tempMap;
}
void City::drawMap()
{

	int width = WIDTH * mapSize + mapSize - 1;
	int height = HEIGHT * mapSize + mapSize - 1;
	int startX = 80 - ((width + 2) / 2);
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
				cur.gotoXY(startX + 1 + (WIDTH + 1) * x, startY + 1 + (HEIGHT + 1) * y);
				cout << "파일 없음!";
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
	date++;
	if (date == 52)
	{
		return 1;
	}
	return 0;
}

void City::purchase(string path, int x, int y)
{
	ifstream data(path);
	string line;

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

void City::ending()
{
	string fileName[3] = { "badending.txt", "normalending.txt", "happyending.txt" };

	textBox* story = new textBox(1, 31, "", 0, fileName[happy / 40]);
}