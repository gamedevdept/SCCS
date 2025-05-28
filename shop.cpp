#include "shop.h"
#include "textbox.h"
#include "menu.h"
#include "city.h"
#include "coord.h"
#include "screen.h"

Shop sho;

void Shop::constructure()
{
	textBox* title = new textBox(1, 10, "�ǹ� �Ǽ�", 1, "");
	string men[6] = { "��ȭ�� (5000G)", "������(15000G)", "��õ(30000G)", "���̰���(100000G)", "�ʵ��б�(300G)", "���ư���"};
	string fileName[5] = { "department.txt", "zoo.txt", "spring.txt", "amuzement.txt", "elementary.txt"};
	Menu* select = new Menu(1, 20, 6, men);
	int sel = select->select();
	delete select;
	delete title;
	if (sel == 5)
	{
		return;
	}
	else
	{
		construct(fileName[sel]);
	}

}

void Shop::transport()
{
	textBox* title = new textBox(1, 10, "������� �Ǽ�", 1, "");
	string men[6] = { "�뼱����(5000G)", "�����͹̳�(15000G)", "����ö��(30000G)", "���ö��(50000G)", "����(100000G)", "���ư���"};
	string fileName[5] = {"bus.txt", "terminal.txt", "subway.txt", "train.txt", "airport.txt"};
	Menu* select = new Menu(1, 20, 6, men);
	int sel = select->select();
	delete select;
	delete title;
	if (sel == 5)
	{
		return;
	}
	else
	{
		construct(fileName[sel]);
	}
}

void Shop::upgrade()
{
	textBox* title = new textBox(1, 10, "���׷��̵�", 1, "");
	vector<UpgradeList> a = *city.upgrade();
	vector<string> men;
<<<<<<< HEAD

	for (auto& i : a)
	{
		men.push_back(i.name);
	}
	int n = men.size();
	string* arr = new string[n]{};
	copy(men.begin(), men.end(), arr);
	Menu* select = new Menu(1, 20, men.size(), arr);
	int sel = select->select();
	city.purchase(city.map[a[sel].y][a[sel].x].upgradepath, a[sel].x, a[sel].y);
=======
>>>>>>> d087d923a4571020792bffd52b8cc0bfc5f39ac8

	for (auto& i : a)
	{
		men.push_back(i.name);
	}
	Menu* select = new Menu(1, 20, men.len(), men);
	int sel = select->select();
	city.purchase(city.map[a[sel].y][a[sel].x].upgradepath, a[sel].x, a[sel].y);
	
}

void Shop::shopMain()
{
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

void Shop::construct(string name)
{
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
}