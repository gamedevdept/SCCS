#include <vector>

#ifndef CITY_H
#define CITY_H

typedef struct structure
{
	std::string type = "empty";
	int popPerDay = 0;
	int moneyPerDay = 0;
	int repPerDay = 0;
	int happyPerDay = 0;
}Structure;

class City
{
private:
	int pop = 0; // �α�
	int money = 0; // ��
	int happy = 0; // �ູ��
	int rep = 0; // ��
	int date = 1; // ��¥
	int mapSize = 3; // ���� ũ��
	std::vector<std::vector<Structure>> map;
public:
	City();
	void drawMap();
	void statusBar();
	int skipDate();
	~City();
};



#endif // !CITY_H

