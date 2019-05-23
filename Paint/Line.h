#pragma once
#include "EasyGraphics.h"
#include "Shape.h"
class Line : public Shape
{
public:
	Line(int x, int y, std::string fill, std::string pen);
	~Line();
	void draw(EasyGraphics* window);
	int getX2();
	int getY2();
	void setX2(int newX2);
	void setY2(int newY2);
	bool hitTest(int testX, int testY);
	void move(int x, int y);
	void drawSelection(EasyGraphics* window);
private:
	int x2 = 0;
	int y2 = 0;
};

inline int Line::getX2() { return x2; }
inline int Line::getY2() { return y2; }
inline void Line::setX2(int newX2) { x2 = newX2; }
inline void Line::setY2(int newY2) { y2 = newY2; }
inline void Line::move(int x, int y) {
	setX2(x - getX() + x2);
	setY2(y - getY() + y2);
	setY(y);
	setX(x);
}