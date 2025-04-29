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
	int getHeight();
	int getWidth();
	void centerText(string message, int y);
	void verticalLine(int x);
	void horizontalLine(int y);
};
