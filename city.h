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
	int pop = 0; // 인구
	int money = 0; // 돈
	int happy = 0; // 행복도
	int rep = 0; // 명성
	int date = 1; // 날짜
	int mapSize = 3; // 지도 크기
	std::vector<std::vector<Structure>> map;
public:
	City();
	void drawMap();
	void statusBar();
	int skipDate();
	~City();
};



#endif // !CITY_H

