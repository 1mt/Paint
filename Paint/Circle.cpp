#include "Circle.h"

Circle::Circle(int x, int y, int radius, std::string fill, std::string pen) : radius(radius)
{
	setX(x);
	setY(y);
	setPen(pen);
	setFill(fill);
}

Circle::~Circle()
{
}

void Circle::draw(EasyGraphics* window) {
	window->drawCircle(getX(), getY(), radius, true);
}

bool Circle::hitTest(int testX, int testY) {
	int distanceBetweenPoints = abs(sqrt(pow((testX - getX()), 2) + pow((testY - getY()), 2)));
	if (distanceBetweenPoints < radius) {
		return true;
	}
	else {
		return false;
	}
}

void Circle::drawSelection (EasyGraphics* window) {
	window->setPenColour(EasyGraphics::clGrey, 4);
	window->drawCircle(getX(), getY(), radius+5, true);
}