#pragma once
#include "Shape.h"
#include "EasyGraphics.h"
class Rect : public Shape
{
public:
	Rect(int x, int y, int width, int height, std::string fill, std::string pen);
	~Rect();
	int getWidth();
	int getHeight();
	void setHeight(int newHeight);
	void setWidth(int newWidth);
	void draw(EasyGraphics* window);
	bool hitTest(int testX, int testY);
	void move(int x, int y);
	void drawSelection(EasyGraphics* window);
private:
	int width;
	int height;

};

inline int Rect::getWidth() { return width; }
inline int Rect::getHeight() { return height; }
inline void Rect::setWidth(int newWidth) { width = newWidth; }
inline void Rect::setHeight(int newHeight) { height = newHeight; }
inline void Rect::move(int x, int y) { setX(x); setY(y); }
