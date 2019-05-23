#include "Freehand.h"



Freehand::Freehand(int x, int y, std::string fill, std::string pen)
{
	setX(x);
	setY(y);
	setPen(pen);
	setFill(fill);
}


Freehand::~Freehand()
{
	
}

void Freehand::draw(EasyGraphics* window) {
	for (int i = 0; i < points.size() - 2; i++) {
		window->drawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
	}
}

bool Freehand::hitTest(int testX, int testY) {
	for (int i = 0; i < points.size() - 2; i++) {
		float slope = (float)(points[i+1].y - points[i].y) / (float)(points[i+1].x - points[i].x);
		if (testY - points[i].y >= slope * (testX - points[i].x) - 4 && (testY - points[i].y) <= (slope * (testX - points[i].x) + 4)) {
			return true;
		}
	}
	return false;
}

void Freehand::drawSelection(EasyGraphics* window) {
	window->setPenColour(EasyGraphics::clGrey, 8);
	for (int i = 0; i < points.size() - 2; i++) {
		window->drawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
	}
	
}

void Freehand::move(int x, int y) {
	int xDiff = x - getX();
	int yDiff = y - getY();
	for (int i = 0; i < points.size() - 1; i++) {
		points[i].x = points[i].x + xDiff;
		points[i].y = points[i].y + yDiff;
	}

	setY(y);
	setX(x);
}

void Freehand::addPoint(int x, int y) {
	coord temp;
	temp.x = x;
	temp.y = y;
	points.push_back(temp);
}
