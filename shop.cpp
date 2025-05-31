#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

#include "shop.h"
#include "textbox.h"
#include "menu.h"
#include "city.h"
#include "coord.h"
#include "screen.h"
#include "keyboard.h"
#include "cursor.h"

Shop sho;

void Shop::constructure()
{
	int selected = 0;
	while (selected == 0)
	{
		textBox* title = new textBox(1, 10, "�ǹ� �Ǽ�", 1, "");
		string men[10] = { "department.txt", "zoo.txt", "spring.txt", "amusement.txt", "elementary.txt", "doctor.txt", "policebox.txt", "house.txt", "minifirm.txt", "���ư���" };
		Menu* select = new Menu(1, 20, 10, men, 1);
		int sel = select->select();
		delete select;
		delete title;
		if (sel == 9)
		{
			return;
		}
		else
		{
			selected = construct(men[sel]);
		}
	}
	

}

void Shop::transport()
{
	int selected = 0;
	while (selected == 0)
	{
		textBox* title = new textBox(1, 10, "������� �Ǽ�", 1, "");
		string men[6] = { "bus.txt", "terminal.txt", "subway.txt", "train.txt", "airport.txt", "���ư���" };
		Menu* select = new Menu(1, 20, 6, men, 1);
		int sel = select->select();
		delete select;
		delete title;
		if (sel == 5)
		{
			return;
		}
		else
		{
			selected = construct(men[sel]);
		}
	}
	
}
void Shop::mapUp()
{
	int cost[4] = { 0, 0, 50000, 150000};
	textBox* title = new textBox(1, 10, "�� Ȯ��", 1, "");

	//textBox* title = new textBox(1, 10, "���� ����" + cost[city.mapSize] + "*" + cost[city.mapSize] + "�������Դϴ�.", 1, "");
}

void Shop::upgrade()
{
	int selected = 0;
	while (selected == 0)
	{
		textBox* title = new textBox(1, 10, "���׷��̵�", 1, "");
		vector<UpgradeList> a = city.upgrade();
		vector<string> men;
		fstream data;
		string line;

		for (auto& i : a)
		{
			men.push_back(i.name);
		}
		men.push_back("���ư���");
		int n = men.size();
		if (n == 0)
		{
			textBox* error = new textBox(1, 20, "���׷��̵� �� �ǹ��� �����ϴ�!", 1, "");
			kbd.keyboardHit();
			return;
		}
		string* arr = new string[n]{};
		copy(men.begin(), men.end(), arr);
		Menu* select = new Menu(1, 20, men.size(), arr, 1);
		int sel = select->select();
		if (sel == men.size() - 1)
		{
			return;
		}
		else
		{
			data.open(city.map[a[sel].y][a[sel].x].upgradepath);
			getline(data, line);
			getline(data, line);
			getline(data, line);
			getline(data, line);
			if (stoi(line) > city.money)
			{
				cur.gotoXY(1, 45);
				cout << "���� �����մϴ�!";
				continue;
			}
			city.purchase(city.map[a[sel].y][a[sel].x].upgradepath, a[sel].x, a[sel].y);
			delete title;
			delete select;
			return;
		}
		
	}
}

void Shop::shopMain()
{
	city.statusBar();
	textBox* title = new textBox(1, 10, "�Ǽ� ����â", 1, "");
	string men[4] = { "�ǹ� �Ǽ�", "������� �Ǽ�", "�ǹ� ���׷��̵�", "���ư���"};
	Menu* select = new Menu(1, 20, 4, men);
	int sel = select->select();
	delete select;
	delete title;
	if (sel == 0)
	{
		constructure();
	}
	else if (sel == 1)
	{
		transport();
	}
	else if (sel == 2)
	{
		upgrade();
	}
	else
	{
		return;
	}
}

int Shop::construct(string name)
{
	fstream data(name);
	string line;
	getline(data, line);
	getline(data, line);
	getline(data, line);
	getline(data, line);
	if (stoi(line) > city.money)
	{
		cur.gotoXY(1, 45);
		cout << "���� �����մϴ�!";
		return 0;
	}
	textBox* title = new textBox(1, 3, "�Ǽ� ��ġ ����", 1, "");
	city.drawMap();
	city.vacant();
	int* coo = coord(city.vacantMap);
	if (coo[0] != -1)
	{
		city.purchase(name, coo[0], coo[1]); // x, y
	}
	delete coo;
	delete title;
	scr.clear();
	return 1;
}