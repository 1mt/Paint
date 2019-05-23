#pragma once
#include "EasyGraphics.h"
#include "Button.h"
#include "Shape.h"
class MainWindow : public EasyGraphics
{
public:
	MainWindow(HINSTANCE hInstance);
	~MainWindow();
	void onDraw();
	void onLButtonDown(UINT nFlags, int x, int y);
	void onLButtonUp(UINT nFlags, int x, int y);
	void onMouseMove(UINT nFlags, int x, int y);
	void onCreate();
	void drawMenu();
	void drawShapes();
private:
	//void onCreate();
	std::vector<Button*> buttons;
	std::string selectedPen = "red pencil";
	std::string selectedFill = "red bucket";
	std::string selectedAction = "line";
	// set to true when mouse is being held down
	bool sizingInProgress = false;
	// set to true when mouse is being held down a move is being performed
	bool moveInProgress = false;
	// set to freehand is being drawn
	bool freeHandInProgress = false;
	// pointer to shape currently selected
	Shape* workingShape = nullptr;
	
};
