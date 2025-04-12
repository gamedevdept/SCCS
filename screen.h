#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

typedef struct box
{
	int startx;
	int starty;
	int width;
	int height;
} Box;

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
	int getWidth();
	void centerText(string message, int y);
	Box* box(int startx, int starty, int width, int height, int centerAlign);
	void verticalLine(int x);
	void horizontalLine(int y);
	void boxText(Box* box, string message, int centerAlign);
	void AsciiArt (File)
};
