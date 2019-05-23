#pragma once
#include "Shape.h"
#include "EasyGraphics.h"
class Circle : public Shape
{
public:
	Circle(int x, int y, int radius, std::string fill, std::string pen);
	~Circle();

	int getRadius();
	void setRadius(int newRadius);
	void draw(EasyGraphics* window);
	bool hitTest(int testX, int testY);
	void move(int x, int y);
	void drawSelection(EasyGraphics* window);
private:
	int radius = 50;
};

inline int Circle::getRadius() { return radius; }
inline void Circle::setRadius(int newRadius) { radius = newRadius; }
inline void Circle::move(int x, int y) { setX(x); setY(y); }