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
	void statusBar();
	int skipDate();
	void purchase();
	vector<vector<int>> vacant();
	void ending();
	int pop = 0; // 인구
	int money = 0; // 돈
	int happy = 0; // 행복도
	int rep = 0; // 명성
	int date = 1; // 날짜
	int mapSize = 3; // 지도 크기
	std::vector<vector<Structure>> map;
};

extern City city;

#endif // !CITY_H