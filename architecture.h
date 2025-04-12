#include <iostream>
#include <string>

using namespace std;

typedef struct apart
{
	const int moneyPerDay = 100;
	const int price[1] = { 1000 };
	string ability[1] = { "pop" };
	const int perDay = 3;
} Apartment;

typedef struct police
{
	const int moneyPerDay = 200;
	const int price[1] = { 1000 };
	string ability[1] = { "sat" };
	const int perDay = 20;
} Police;

typedef struct theatre
{
	const int moneyPerDay = 150;
	const int price = 5000;
	string ability[2] = { "sat", "rep" };
	const int perDay[2] = { 50, 10 };
} Theatre;

typedef struct business
{
	const int moneyPerDay = 500;
	const int price = 6000;
	string ability[2] = { "rep", "pop" };
	const int perDay[2] = { 20, 20 };
};