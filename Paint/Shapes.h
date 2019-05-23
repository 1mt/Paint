#pragma once
#include "Shape.h"

class Shapes
{
public:
	Shapes();
	~Shapes();
	static Shapes* getShapes();
	void addShape(Shape* newShape);
	void deleteShape(int index);
	std::vector<Shape*> getShapesVector();	
	static void destructShapes();
private:
	static Shapes* instance;
	std::vector<Shape*> shapes;

};


