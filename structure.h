#include <iostream>

using namespace std;

#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct mystruct
{
	string name = "";
	string path = "";
	bool upgrade = false;
	int expense = 0;
	int happyPerDay = 0;
	int repPerDay = 0;
	int popPerDay = 0;
	int moneyPerDay = 0;
	string upgradepath = "";

}Structure;

typedef struct structureUpgrade
{
	int y = 0;
	int x = 0;
	string name = "";
} UpgradeList;

#endif // !STRUCTURE_H
