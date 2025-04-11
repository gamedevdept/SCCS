#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

class Screen
{
private:
	const int width = 161;
	const int height = 46;

public:

	void screenClear();
	void screenEdge();
	void screenText(string message, int x, int y);
	int getHeight();
};
