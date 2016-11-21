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
#pragma once

#include "Object.hpp"

typedef sf::Keyboard::Key KEY;
typedef sf::Mouse::Button MOUSE;

enum JOYSTICK { RIGHT_UP, RIGHT_RIGHT, RIGHT_DOWN, RIGHT_LEFT, L1, R1, L2, R2, SELECT, START, LEFT_STICK, RIGHT_STICK, AXIS_X, AXIX_Y, UP, DOWN, LEFT, RIGHT, JOYSTICK_COUNT };
enum PLAYER { PLAYER_1, PLAYER_2, PLAYER_COUNT };

#define input Input::getInstance()

class Input : public Object
{
public:
	~Input();
	// ---------- TECLADO ----------
	bool isPressed(KEY _key);
	bool isUp(KEY _key);
	bool isDown(KEY _key);
	// ---------- MOUSE ----------
	bool isPressed(MOUSE _mouse);
	bool isUp(MOUSE _mouse);
	bool isDown(MOUSE _mouse);
	// ---------- JOYSTICK ----------
	bool isPressed(JOYSTICK _joystick, PLAYER _player);
	bool isUp(JOYSTICK _joystick, PLAYER _player);
	bool isDown(JOYSTICK _joystick, PLAYER _player);

	int getMouseX();
	int getMouseY();
	int getMouseScroll();
	int GetMouseAngle(int x, int y);

	void mouseSnap(int x, int y);

	static Input* getInstance();
private:
	Input();
	static Input* instance;

	//Keyboard
	std::vector<bool> keyDown;
	std::map<MOUSE, bool> keyverify;
	std::vector<bool> keyUp;

	//Mouse
	unsigned int snapDistanceX;
	unsigned int snapDistanceY;
	std::vector<bool> buttonDown;
	std::vector<bool> buttonUp;

	//Joystick
	std::vector<std::vector<bool>> joyUp;
	std::vector<std::vector<bool>> joyDown;
};