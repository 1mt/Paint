#pragma once
#include "EasyGraphics.h"
class Shape
{
public:
	Shape();
	~Shape();
	int getX();
	int getY();
	void setX(int newX);
	void setY(int newY);
	std::string getFill();
	void setFill(std::string newFill);
	std::string getPen();
	void setPen(std::string newPen);
	virtual void draw(EasyGraphics* window) = 0;
	virtual void move(int x, int y) = 0;
	virtual bool hitTest(int testX, int testY) = 0;
	virtual void drawSelection(EasyGraphics* window) = 0;
private:
	int x;
	int y;
	std::string fill;
	std::string pen;
};

inline int Shape::getX() { return x; }
inline int Shape::getY() { return y; }
inline void Shape::setX(int newX) { x=newX; }
inline void Shape::setY(int newY) { y=newY; }
inline std::string Shape::getFill() { return fill; }
inline void Shape::setFill(std::string newFill) { fill = newFill; }
inline std::string Shape::getPen() { return pen; }
inline void Shape::setPen(std::string newPen) { pen = newPen; }