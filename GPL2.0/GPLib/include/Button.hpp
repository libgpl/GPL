#pragma once
#include "Sprite.hpp"
class Button
{
private:
	Sprite normal;
	Sprite hover;
	Sprite pressed;
	int x;
	int y;
public:

	bool isPressed();
	bool isHovered();
	bool onRelease();
	bool onClick();

	Button(std::string filename);
	~Button();

	void draw(int x, int y);
};

