#include "shop.h"
#include "textbox.h"
#include "menu.h"
#include "city.h"

Shop sho;

void Shop::constructure()
{
	textBox* title = new textBox(1, 10, "�ǹ� �Ǽ�", 1, "");
	string men[6] = { "��ȭ��", "������", "��õ", "������ũ", "���̰���", "���ư���"};
	string fileName[6] = { "department", "zoo", "spring", "waterpark", "amuzement", "back" };
	Menu* select = new Menu(1, 20, 6, men);
	int sel = select->select();
	delete select;
	delete title;
	if (sel == 5)
	{
		return;
	}

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
		return;
	}
}

void Shop::construct(string name)
{
	textBox* title = new textBox(1, 10, "�Ǽ� ��ġ ����", 1, "");
	city.drawMap();
}