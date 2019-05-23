#include "MainWindow.h"
#include <algorithm>
#include "Button.h"
#include "Shapes.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
#include "Freehand.h"
MainWindow::MainWindow(HINSTANCE hInstance)
{
	setImmediateDrawMode(false);
	
	create(hInstance, 1000, 1050, 40, true);
	waitForClose();
}
void MainWindow::onCreate()
{
	// add buttons to the screen						 
	buttons.push_back(new Button("line",L".\\img\\line.bmp", 0, 100, this));
	buttons.push_back(new Button("circle",L".\\img\\circle.bmp", 0, 200, this));
	buttons.push_back(new Button("rectangle",L".\\img\\rectangle.bmp", 0, 300, this));
	buttons.push_back(new Button("move",L".\\img\\move.bmp", 0, 400, this));
	buttons.push_back(new Button("trash",L".\\img\\trash.bmp", 0, 500, this));
	buttons.push_back(new Button("color swap",L".\\img\\color_swap.bmp", 0, 600, this));
	//buttons.push_back(new Button("open",L".\\img\\open.bmp", 0, 700, this));
	//buttons.push_back(new Button("save",L".\\img\\save.bmp", 0, 800, this));
	buttons.push_back(new Button("freehand", L".\\img\\freehand.bmp", 0, 700, this));
								 
	buttons.push_back(new Button("red pencil",L".\\img\\red_pencil.bmp", 200, 0, this));
	buttons.push_back(new Button("green pencil",L".\\img\\green_pencil.bmp", 300, 0, this));
	buttons.push_back(new Button("blue pencil",L".\\img\\blue_pencil.bmp", 400, 0, this));
	buttons.push_back(new Button("red bucket",L".\\img\\red_bucket.bmp", 600, 0, this));
	buttons.push_back(new Button("green bucket",L".\\img\\green_bucket.bmp", 700, 0, this));
	buttons.push_back(new Button("blue bucket",L".\\img\\blue_bucket.bmp", 800, 0, this));
	::SetWindowText(getHWND(), L"Paint");
	clrscr(clWhite);
	EasyGraphics::onDraw();
	EasyGraphics::onCreate();
	
}


void MainWindow::onDraw()
{
	clrscr(clWhite);
	drawShapes();
	drawMenu();
	if (selectedAction == "color swap" && workingShape != nullptr) {
		workingShape->drawSelection(this);
	}
	EasyGraphics::onDraw();
}

void MainWindow::onLButtonDown(UINT nFlags, int x, int y)
{
	bool buttonHit = false;
	std::string selectedID;
	for (Button* aButton : buttons) {
		if (aButton->hitTest(x, y)) {
			buttonHit = true;
			selectedID = aButton->getName();
			if (selectedID == "red pencil" || selectedID == "blue pencil" || selectedID == "green pencil") {
				selectedPen = selectedID;
				if (selectedAction == "color swap" && workingShape != nullptr) {
					workingShape->setPen(selectedID);
				}
				onDraw();
			}
			else if (selectedID == "red bucket" || selectedID == "blue bucket" || selectedID == "green bucket"){
				selectedFill = selectedID;
				if (selectedAction == "color swap" && workingShape != nullptr) {
					workingShape->setFill(selectedID);
				}
				onDraw();
			}
			else {
				selectedAction = selectedID;
				onDraw();
			}
			break;
		}
	}
	if (!buttonHit) {
		if (selectedAction == "line") {
			Shapes::getShapes()->addShape(new Line(x, y, selectedFill, selectedPen));
			onDraw();
			sizingInProgress = true;
		}
		else if (selectedAction == "rectangle") {
			Shapes::getShapes()->addShape(new Rect(x,y , 30, 40, selectedFill, selectedPen));
			onDraw();
			sizingInProgress = true;
			
		}
		else if (selectedAction == "circle") {
			Shapes::getShapes()->addShape(new Circle(x, y, 200, selectedFill, selectedPen));
			onDraw();
			sizingInProgress = true;
		}
		else if (selectedAction == "trash") {
			int i = 0;
			for (Shape* aShape : Shapes::getShapes()->getShapesVector()) {
				if (aShape->hitTest(x, y)) {
					Shapes::getShapes()->deleteShape(i);
					break;
				}
				i++;
			}
			onDraw();
		}
		else if (selectedAction == "move") {
			int i = 0;
			for (Shape* aShape : Shapes::getShapes()->getShapesVector()) {
				if (aShape->hitTest(x, y)) {
					workingShape = aShape;
					moveInProgress = true;
					break;
				}
				i++;
			}
			onDraw();
		}
		else if (selectedAction == "color swap") {
			for (Shape* aShape : Shapes::getShapes()->getShapesVector()) {
				if (aShape->hitTest(x, y)) {
					workingShape = aShape;
					break;
				}
			}
			onDraw();
		}
		else if (selectedAction == "freehand") {
			Shapes::getShapes()->addShape(new Freehand(x, y, selectedFill, selectedPen));
			dynamic_cast<Freehand*>(Shapes::getShapes()->getShapesVector().back())->addPoint(x, y);
			freeHandInProgress = true;
			
		}
	}
}
void MainWindow::drawMenu() {
	for (Button* aButton : buttons) {
		std::string id = aButton->getName();
		aButton->draw(this);
		if (id == selectedAction || id == selectedFill || id == selectedPen) {
			setPenColour(EasyGraphics::clRed, 2);
		}
		else {
			setPenColour(EasyGraphics::clBlack, 2);
		}
		drawRectangle(aButton->getX(), aButton->getY(), 100, 100, false);
	}
}

void MainWindow::drawShapes() {
	for (Shape* aShape : Shapes::getShapes()->getShapesVector()) {
		std::string penColor = aShape->getPen();
		std::string fillColor = aShape->getFill();
		if (penColor == "red pencil") {
			setPenColour(clRed,4);
		}
		else if (penColor == "blue pencil") {
			setPenColour(clBlue , 4);
		}
		else {
			setPenColour(clGreen, 4);
		}

		if (fillColor == "red bucket") {
			selectBackColour(clRed);
		}
		else if (fillColor == "blue bucket") {
			selectBackColour(clBlue);
		}
		else {
			selectBackColour(clGreen);
		}

		aShape->draw(this);
	}

}

void MainWindow::onMouseMove(UINT nFlags, int x, int y)
{
	if (sizingInProgress) {
		if (selectedAction == "line") {
			Line* ptrToLine = dynamic_cast<Line*>(Shapes::getShapes()->getShapesVector().back());
			if (ptrToLine) {
				ptrToLine->setX2(ptrToLine->getX() + (x - ptrToLine->getX()));
				ptrToLine->setY2(ptrToLine->getY() + (y - ptrToLine->getY()));
			}
			onDraw();
			
		}
		else if (selectedAction == "rectangle") {
			Rect* ptrToLine = dynamic_cast<Rect*>(Shapes::getShapes()->getShapesVector().back());
			if (ptrToLine) {
				ptrToLine->setWidth(x - ptrToLine->getX());
				ptrToLine->setHeight(y - ptrToLine->getY());
			}
			onDraw();

		}
		else if (selectedAction == "circle") {
			Circle* ptrToLine = dynamic_cast<Circle*>(Shapes::getShapes()->getShapesVector().back());
			if (ptrToLine) {
				ptrToLine->setRadius((x - ptrToLine->getX()) + (y - ptrToLine->getY()));
			}
			onDraw();
		}
	}
	else if (moveInProgress) {
		workingShape->move(x, y);
		onDraw();
	}
	else if (freeHandInProgress) {
		Freehand* ptrToLine = dynamic_cast<Freehand*>(Shapes::getShapes()->getShapesVector().back());
		if (ptrToLine) {
			ptrToLine->addPoint(x, y);
		}
		onDraw();
	}


}
void MainWindow::onLButtonUp(UINT nFlags, int x, int y)
{
	if (sizingInProgress) {
		sizingInProgress = false;
	}
	else if (moveInProgress) {
		moveInProgress = false;
	}
	else if (freeHandInProgress) {
		freeHandInProgress = false;
	}
}


MainWindow::~MainWindow()
{
	for (auto aButton : buttons) {
		delete aButton;
	}
	delete workingShape;
	Shapes::destructShapes();
}
