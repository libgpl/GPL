#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window/Keyboard.hpp"

typedef sf::Keyboard::Key KEY;
typedef sf::Mouse::Button MOUSE;
typedef sf::Vector2f Vector2f;

//
//#include <iostream>
//#include <vector>
//
//using namespace std;


class Input
{
public:
	Input();
	~Input();
	// ---------- TECLADO ---------- 
	bool isKeyHeld(KEY _key);
	bool isKeyUp(KEY _key);
	bool isKeyDown(KEY _key);
	// ---------- MOUSE ---------- 
	bool isMouseButtonHeld(MOUSE _mouse);
	bool isMouseButtonUp(MOUSE _mouse);
	bool isMouseButtonDown(MOUSE _mouse);
	// ---------- JOYSTICK ---------- 
	bool isJoystickButtonHeld(MOUSE _mouse);
	bool isJoystickButtonUp(MOUSE _mouse);
	bool isJoystickButtonDown(MOUSE _mouse);
private:

	bool onPressed[KEY::KeyCount];
	bool onDownPressed[KEY::KeyCount];

	bool onPressedMouse[MOUSE::ButtonCount];
	bool onDownPressedMouse[MOUSE::ButtonCount];

	int timer[KEY::KeyCount];
	int mouseTimer[MOUSE::ButtonCount];

	bool isKeyDownReleased(KEY _key);
	bool isButtonDownReleased(MOUSE _mouse);
};