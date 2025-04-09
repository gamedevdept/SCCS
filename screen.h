#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

class Screen
{
private:
	int width;
	int height;

public:
	Screen()
	{
		width = 161;
		height = 46;
	}

	void screenClear();
	void screenEdge();
	void screenText(string message, int x, int y);
};
