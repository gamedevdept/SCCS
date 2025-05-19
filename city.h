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
	int pop = 0; // �α�
	int money = 0; // ��
	int happy = 0; // �ູ��
	int rep = 0; // ��
	int date = 1; // ��¥
	int mapSize = 3; // ���� ũ��
	std::vector<vector<Structure>> map;
};

extern City city;

#endif // !CITY_H