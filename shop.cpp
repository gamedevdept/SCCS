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
	string men[6] = { "��ȭ�� (5000G)", "������(15000G)", "��õ(30000G)", "������ũ(50000G)", "���̰���(100000G)", "���ư���"};
	string fileName[5] = { "department.txt", "zoo.txt", "spring.txt", "waterpark.txt", "amuzement.txt" };
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