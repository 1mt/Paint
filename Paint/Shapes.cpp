#include "Shapes.h"



Shapes::Shapes()
{

}


Shapes::~Shapes()
{
	
}

Shapes* Shapes::instance = nullptr;

Shapes* Shapes::getShapes()
{
	if (!instance) {
		instance = new Shapes();
	}
	return instance;
}

void Shapes::addShape(Shape* newShape)
{
	shapes.push_back(newShape);
}

std::vector<Shape*> Shapes::getShapesVector()
{
	return shapes;
}

void Shapes::deleteShape(int index)
{
	Shape* temp = shapes[index];
;	shapes.erase(shapes.begin() + index);
	delete temp;
}

void Shapes::destructShapes() {
	for (Shape* aShape : instance->getShapesVector()) {
		delete aShape;
	}
	delete instance;
}