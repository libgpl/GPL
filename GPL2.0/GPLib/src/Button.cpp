/*
========================================================
GPL - Game Programming Library
by Luan Carlos Nesi (2014-2016)
https://github.com/libgpl
========================================================

The MIT License (MIT)

Copyright (c) 2014-2016 Luan Nesi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "../include/Button.hpp"
#include "../include/Input.hpp"

Button::Button(std::string filename)
{
	Sprite temp;
	temp.load(filename);

	int height = temp.getResY() / 3;

	normal.load(filename, 0, 0, temp.getResX(), height);
	hover.load(filename, 0, height, temp.getResX(), height);
	pressed.load(filename, 0, 2 * height, temp.getResX(), height);
}

void Button::load(std::string filename)
{
	Sprite temp;
	temp.load(filename);

	int height = temp.getResY() / 3;

	normal.load(filename, 0, 0, temp.getResX(), height);
	hover.load(filename, 0, height, temp.getResX(), height);
	pressed.load(filename, 0, 2 * height, temp.getResX(), height);
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