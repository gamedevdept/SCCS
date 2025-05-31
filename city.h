#include <vector>
#include <iostream>

#include "structure.h"

using namespace std;

#ifndef CITY_H
#define CITY_H

class City
{
	
public:
	City();
	void drawMap();
	void mapUpgrade();
	void statusBar();
	int skipDate();
	void purchase(string path, int x, int y);
	void vacant();
	void ending();
	std::vector<UpgradeList> upgrade();
	int startX = 0;
	int height = 0;
	int pop = 0; // 인구
	int money = 0; // 돈
	int happy = 0; // 행복도
	int rep = 0; // 명성
	int date = 1; // 날짜
	int mapSize = 3; // 지도 크기
	int level = 0;
	int tempMoney = 0;
	int tempPop = 0;
	int tempRep = 0;
	std::vector<vector<Structure>> map;
	std::vector<vector<int>> vacantMap;
};

extern City city;

#endif // !CITY_H