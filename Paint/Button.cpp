#include "Button.h"


Button::Button(std::string name, std::wstring imagePath, int x, int y, EasyGraphics* window) : name(name), imagePath(imagePath), x(x), y(y)
{

}

Button::~Button()
{
}

void Button::draw(EasyGraphics* window)
{
	window->drawBitmap(imagePath.c_str(), x+3, y+3, 90, 90, EasyGraphics::clWhite);
}

bool Button::hitTest(int testX, int testY) {
	if (testX >= x && testX < (x + 100) && testY > y && testY < (y + 100)) {
		return true;
	}
	else {
		return false;
	}

}
