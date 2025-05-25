#include <iostream>
#include <vector>

#include "coord.h"
#include "keyboard.h"
#include "cursor.h"
#include <conio.h>

using std::vector;;
using std::cout;

int* coord(vector<vector<int>> xy)
{
	int* coordinate = new int[2];
	int increaseX = -1;
	int increaseY = -1;
	int decreaseX = -1;
	int decreaseY = -1;
	int coordPoint = 0;
	int currentX = 0; // x값의 index임
	int currentY = -1; // y값임
	int input;
	int y, x;
	int i;

	cur.gotoXY(20, 29);
	cout << "X"; // [y][x]
	cur.gotoXY(25, 29);
	cout << "Y"; // [y]

	for (y = 0; y < xy.size(); y++)
	{
		if (xy[y].size() != 0)
		{
			currentY = y;
			currentX = 0;
			break;
		}

	}

	if (currentY == -1)
	{
		cur.gotoXY(20, 29);
		cout << "더는 건설할 수 없습니다!";
		_getch();
		coordinate[0] = -1;
		coordinate[1] = -1;
		return coordinate;
	}
	
	for (;;)
	{
		increaseY = -1;
		decreaseY = -1;

		for (y = currentY + 1; y < xy.size(); y++)
		{
			if (xy[y].size() != 0)
			{
				increaseY = y;
				break;
			}
		}

		for (y = currentY - 1; y >= 0; y--)
		{
			if (xy[y].size() != 0)
			{
				decreaseY = y;
				break;
			}
		}

		if (xy[currentY].size() - 1 > currentX)
		{
			increaseX = currentX + 1;
			decreaseX = currentX - 1;
		}
		else if (xy[currentY].size() - 1 == currentX && xy[currentY].size() != 1)
		{
			increaseX = -1;
			decreaseX = currentX - 1;
		}
		else
		{
			increaseX = -1;
			decreaseX = -1;
		}

		if (coordPoint == 0) // x
		{
			if (increaseX != -1)
			{
				cur.gotoXY(20, 30);
				cout << "▲";
			}
			else
			{
				cur.gotoXY(20, 30);
				cout << "  ";
			}

			if (decreaseX != -1)
			{
				cur.gotoXY(20, 32);
				cout << "▼";
			}
			else
			{
				cur.gotoXY(20, 32);
				cout << "  ";
			}

			cur.gotoXY(25, 30);
			cout << "  ";
			cur.gotoXY(25, 32);
			cout << "  ";
		}
		else // y
		{
			if (increaseY != -1)
			{
				cur.gotoXY(25, 30);
				cout << "▲";
			}
			else
			{
				cur.gotoXY(25, 30);
				cout << "  ";
			}

			if (decreaseY != -1)
			{
				cur.gotoXY(25, 32);
				cout << "▼";
			}
			else
			{
				cur.gotoXY(25, 32);
				cout << "  ";
			}
			cur.gotoXY(20, 30);
			cout << "  ";
			cur.gotoXY(20, 32);
			cout << "  ";
		}

		cur.gotoXY(25, 31);

		cout << currentY;
	

		cur.gotoXY(20, 31);

		cout << xy[currentY][currentX];
		

		cur.defaultXY();
		input = kbd.kbd();

		if (input == 13)
		{
			coordinate[0] = xy[currentY][currentX];
			coordinate[1] = currentY;
			
			return coordinate;
		}
		else if (input == 9)
		{
			coordPoint = (coordPoint + 1) % 2;
			continue;
		}

		if (coordPoint == 0)
		{
			if (input == 772 && increaseX != -1)
			{
				currentX = increaseX;
			}
			else if (input == 800 && decreaseX != -1)
			{
				currentX = decreaseX;
			}
		}
		else
		{
			if (input == 772 && increaseY != -1)
			{
				currentY = increaseY;
				currentX = 0;
			}
			else if (input == 800 && decreaseY != -1)
			{
				currentY = decreaseY;
				currentX = 0;
			}
		}

	}
}