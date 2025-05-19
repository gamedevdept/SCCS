#include "shop.h"
#include "textbox.h"
#include "menu.h"
#include "city.h"

Shop sho;

void Shop::constructure()
{
	textBox* title = new textBox(1, 10, "건물 건설", 1, "");
	string men[6] = { "백화점", "동물원", "온천", "워터파크", "놀이공원", "돌아가기"};
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
	textBox* title = new textBox(1, 10, "건설 선택창", 1, "");
	string men[3] = { "건물 건설", "교통수단 건설", "돌아가기" };
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
	textBox* title = new textBox(1, 10, "건설 위치 선택", 1, "");
	city.drawMap();
}