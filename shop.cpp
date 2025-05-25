#include "shop.h"
#include "textbox.h"
#include "menu.h"
#include "city.h"
#include "coord.h"
#include "screen.h"

Shop sho;

void Shop::constructure()
{
	textBox* title = new textBox(1, 10, "건물 건설", 1, "");
	string men[6] = { "백화점 (5000G)", "동물원(15000G)", "온천(30000G)", "워터파크(50000G)", "놀이공원(100000G)", "돌아가기"};
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
	textBox* title = new textBox(1, 10, "교통수단 건설", 1, "");
	string men[6] = { "노선버스(5000G)", "버스터미널(15000G)", "도시철도(30000G)", "고속철도(50000G)", "공항(100000G)", "돌아가기"};
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
	textBox* title = new textBox(1, 10, "건설 선택창", 1, "");
	string men[4] = { "건물 건설", "교통수단 건설", "건물 업그레이드", "돌아가기"};
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
	textBox* title = new textBox(1, 3, "건설 위치 선택", 1, "");
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