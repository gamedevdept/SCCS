#include <iostream>
#include "cursor.h"
#include "city.h"
#include "structure.h"
#include "textbox.h"

#define WIDTH 20
#define HEIGHT 5

using namespace std;

City city;

City::City()
{
	int i;
	vector<Structure> mapLine;
	Structure a;
	for (i = 0; i < mapSize; i++)
	{
		mapLine.push_back(a);
	}
	for (i = 0; i < mapSize; i++)
	{
		map.push_back(mapLine);
	}
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



	for (i = 0; i < mapSize; i++)
	{
		for (j = 0; j < mapSize; j++)
		{

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

void City::purchase()
{

}

vector<vector<int>> City::vacant()
{
	int i, j;
	vector<vector<int>> x = 
	{
		{},
		{},
		{},
		{},
		{},
		{}
	};

	for (i = 0; i < mapSize; i++)
	{
		for (j = 0; j < mapSize; j++)
		{
			if (map[i][j].path == "")
			{
				x[i].push_back(j);
			}
		}
	}

	return x;
}

void City::ending()
{
	string fileName[3] = { "badending.txt", "normalending.txt", "happyending.txt" };

	textBox* story = new textBox(1, 31, "", 0, fileName[happy / 40]);
}