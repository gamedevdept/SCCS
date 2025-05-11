#include <iostream>
#include "cursor.h"
#include "city.h"

#define WIDTH 20
#define HEIGHT 5

using namespace std;

Cursor cityCursor;

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

	cityCursor.gotoXY(startX, startY);
	cout << "┌";
	for (int i = 0; i < width; i++)
	{
		cout << "─";
	}
	cout << "┐";

	for (int i = startY + 1; i <= startY + height; i++)
	{
		cityCursor.gotoXY(startX, i);
		cout << "│";
		cityCursor.gotoXY(startX + width + 1, i);
		cout << "│";
	}

	cityCursor.gotoXY(startX, startY + height + 1);
	cout << "└";
	for (int i = 0; i < width; i++)
	{
		cout << "─";
	}
	cout << "┘";

	int i, j;

	for (i = HEIGHT + 1; i <= height; i += HEIGHT + 1)
	{
		cityCursor.gotoXY(startX, startY + i);
		cout << "├";
		for (j = 1; j <= width; j++)
		{
			cout << "─";
		}
		cout << "┤";
	}

	for (i = WIDTH + 1; i <= width; i += WIDTH + 1)
	{
		cityCursor.gotoXY(startX + i, startY);
		cout << "┬";
		for (j = startY + 1; j <= startY + height; j++)
		{
			cityCursor.gotoXY(startX + i, j);
			if ((j - startY) % (HEIGHT + 1) == 0)
			{
				cout << "┼";
				continue;
			}

			cout << "│";
		}
		cityCursor.gotoXY(startX + i, startY + height + 1);
		cout << "┴";
	}
	cityCursor.defaultXY();



	for (i = 0; i < mapSize; i++)
	{
		for (j = 0; j < mapSize; j++)
		{

		}
	}
}

void City::statusBar()
{
	cityCursor.gotoXY(25, 1);
	cout << "재산 | " << money;
	cout << "               ";
	cout << "명성 | " << rep;
	cout << "               ";
	cout << "인구수 | " << pop;
	cout << "               ";
	cout << "행복도 | " << happy;
	cout << "               ";
	cout << "(" << date << "/52) 턴";
	cityCursor.defaultXY();
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


City::~City()
{

}