#pragma once
#include <string>
#include "EasyGraphics.h"

class Button
{
public:
	Button(std::string name, std::wstring imagePath, int x, int y, EasyGraphics* window);
	~Button();
	std::wstring getPath();
	std::string getName();
	int getX();
	int getY();
	void draw(EasyGraphics* window);
	bool hitTest(int testX, int testY);
private:
	std::wstring imagePath;
	int x;
	int y;
	std::string name;

};
inline std::wstring Button::getPath() { return imagePath; }
inline std::string Button::getName() { return name; }
inline int Button::getX() { return x; }
inline int Button::getY() { return y; }