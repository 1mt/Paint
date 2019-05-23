#pragma once
#include "Shape.h"

struct coord {
	int x;
	int y;
};

class Freehand : public Shape
{
public:
	Freehand(int x, int y, std::string fill, std::string pen);
	~Freehand();
	bool hitTest(int testX, int testY);
	void move(int x, int y);
	void drawSelection(EasyGraphics* window);
	void addPoint(int x, int y);
	void draw(EasyGraphics* window);
private:
	std::vector<coord> points;
};

