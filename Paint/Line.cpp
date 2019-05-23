#include "Line.h"



Line::Line(int x, int y, std::string fill, std::string pen)
{
	setX(x);
	setY(y);
	setX2(x + 1);
	setY2(y + 1);
	setPen(pen);
	setFill(fill);
}


Line::~Line()
{
	 
}

void Line::draw(EasyGraphics* window) {
	window->drawLine(getX(), getY(), x2, y2);
}

bool Line::hitTest(int testX, int testY) {
	float slope = (float)(getY2() - getY()) / (float)(getX2() - getX());
	if (testY - getY() >= slope * (testX - getX()) - 4 && (testY - getY()) <= (slope * (testX - getX()) + 4)) {
		return true;
	}
	else {
		return false;
	}
}

void Line::drawSelection(EasyGraphics* window) {
	window->setPenColour(EasyGraphics::clGrey, 8);
	window->drawLine(getX(), getY(), x2, y2);
}