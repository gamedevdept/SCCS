class Screen
{
private:
	const int width = 161;
	const int height = 46;

public:
	void drawEdge();
	void clear();
	void verticalLine(int x);
	void horizontalLine(int y);
};