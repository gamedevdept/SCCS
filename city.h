#include <vector>

#ifndef CITY_H
#define CITY_H

class City
{
private:
	int pop = 0; // 인구
	int money = 0; // 돈
	int happy = 0; // 행복도
	int rep = 0; // 명성
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

