#include <vector>

#ifndef CITY_H
#define CITY_H

class City
{
private:
	int pop = 0; // �α�
	int money = 0; // ��
	int happy = 0; // �ູ��
	int rep = 0; // ��
	int date = 1;
	int mapSize = 3;
	int map[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
public:
	void drawMap();
};



#endif // !CITY_H

