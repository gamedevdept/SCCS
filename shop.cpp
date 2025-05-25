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
	string men[6] = { "��ȭ��", "������", "��õ", "������ũ", "���̰���", "���ư���"};
	string fileName[6] = { "department.txt", "zoo.txt", "spring.txt", "waterpark.txt", "amuzement.txt", "back" };
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

}

void Shop::shopMain()
{
	textBox* title = new textBox(1, 10, "�Ǽ� ����â", 1, "");
	string men[3] = { "�ǹ� �Ǽ�", "������� �Ǽ�", "���ư���" };
	Menu* select = new Menu(1, 20, 3, men);
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