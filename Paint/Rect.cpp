#include "Rect.h"



Rect::Rect(int x, int y, int width, int height, std::string fill, std::string pen) : width(width), height(height)
{
	setX(x);
	setY(y);
	setPen(pen);
	setFill(fill);
}


Rect::~Rect()
{
}

void Rect::draw(EasyGraphics* window) {
	window->drawRectangle(getX(), getY(), width, height, true);
}

bool Rect::hitTest(int testX, int testY) {
	if (testX >= getX() && testX < (getX() + getWidth()) && testY > getY() && testY < (getY() + getHeight())) {
		return true;
	}
	else {
		return false;
	}

}

void Rect::drawSelection(EasyGraphics* window) {
	window->setPenColour(EasyGraphics::clGrey, 4);
	window->drawRectangle(getX(), getY(), width+5, height+5, true);
}

