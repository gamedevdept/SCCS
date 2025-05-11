#include <iostream>
#include "cursor.h"
#include "city.h"

#define WIDTH 20
#define HEIGHT 5

using namespace std;

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
	cout << "��";
	for (int i = 0; i < width; i++)
	{
		cout << "��";
	}
	cout << "��";

	for (int i = startY + 1; i <= startY + height; i++)
	{
		cur.gotoXY(startX, i);
		cout << "��";
		cur.gotoXY(startX + width + 1, i);
		cout << "��";
	}

	cur.gotoXY(startX, startY + height + 1);
	cout << "��";
	for (int i = 0; i < width; i++)
	{
		cout << "��";
	}
	cout << "��";

	int i, j;

	for (i = HEIGHT + 1; i <= height; i += HEIGHT + 1)
	{
		cur.gotoXY(startX, startY + i);
		cout << "��";
		for (j = 1; j <= width; j++)
		{
			cout << "��";
		}
		cout << "��";
	}

	for (i = WIDTH + 1; i <= width; i += WIDTH + 1)
	{
		cur.gotoXY(startX + i, startY);
		cout << "��";
		for (j = startY + 1; j <= startY + height; j++)
		{
			cur.gotoXY(startX + i, j);
			if ((j - startY) % (HEIGHT + 1) == 0)
			{
				cout << "��";
				continue;
			}

			cout << "��";
		}
		cur.gotoXY(startX + i, startY + height + 1);
		cout << "��";
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
	cout << "��� | " << money;
	cout << "               ";
	cout << "�� | " << rep;
	cout << "               ";
	cout << "�α��� | " << pop;
	cout << "               ";
	cout << "�ູ�� | " << happy;
	cout << "               ";
	cout << "(" << date << "/52) ��";
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


City::~City()
{

}