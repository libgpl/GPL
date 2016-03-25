#include "../include/Button.hpp"
#include "../include/Input.hpp"


Button::Button(std::string filename)
{
	Sprite temp;
	temp.load(filename);

	int height = temp.getResY() / 3;

	normal.load(filename, 0, 0, temp.getResX(), height);
	hover.load(filename, 0, height, temp.getResX(), height);
	pressed.load(filename, 0, 2*height, temp.getResX(), height);
}


Button::~Button()
{
}

void Button::draw(int x, int y)
{
	if (this->x != x) this->x = x;
	if (this->y != y) this->y = y;

	if (input->getMouseY() <= y && input->getMouseY() >= y - normal.getResY()
		&& (input->getMouseX() >= x && input->getMouseX() <= x + normal.getResX()))
	{
		if (input->isPressed(MOUSE::Left))
		{
			pressed.draw(x, y);
		}
		else
		{
			hover.draw(x, y);
		}
	}
	else
	{
		normal.draw(x, y);
	}
}

bool Button::onClick()
{
	if (input->getMouseY() <= y && input->getMouseY() >= y - normal.getResY()
		&& (input->getMouseX() >= x && input->getMouseX() <= x + normal.getResX()))
	{
		if (input->isDown(MOUSE::Left))
		{
			return true;
		}
	}
	return false;
}


bool Button::isPressed()
{
	if (input->getMouseY() <= y && input->getMouseY() >= y - normal.getResY()
		&& (input->getMouseX() >= x && input->getMouseX() <= x + normal.getResX()))
	{
		if (input->isPressed(MOUSE::Left))
		{
			return true;
		}
	}
	return false;
}

bool Button::isHovered()
{
	if (input->getMouseY() <= y && input->getMouseY() >= y - normal.getResY()
		&& (input->getMouseX() >= x && input->getMouseX() <= x + normal.getResX()))
	{
		return true;
	}
	return false;

}

bool Button::onRelease()
{
	if (input->getMouseY() <= y && input->getMouseY() >= y - normal.getResY()
		&& (input->getMouseX() >= x && input->getMouseX() <= x + normal.getResX()))
	{
		if (input->isUp(MOUSE::Left))
		{
			return true;
		}
	}
	return false;
}
