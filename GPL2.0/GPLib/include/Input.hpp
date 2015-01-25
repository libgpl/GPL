#pragma once


#include "Object.hpp"

typedef sf::Keyboard::Key KEY;
typedef sf::Mouse::Button MOUSE;

enum JOYSTICK {RIGHT_UP, RIGHT_DOWN, RIGHT_LEFT, RIGHT_RIGHT, L1, R1, L2, R2, SELECT, START, LEFT_STICK, RIGHT_STICK, AXIS_X, AXIX_Y, UP, DOWN, LEFT, RIGHT};

#define input Input::getInstance()


class Input : public Object
{
public:
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
	bool isJoystickButtonHeld(JOYSTICK _joystick);
	bool isJoystickButtonUp(JOYSTICK _joystick);
	bool isJoystickButtonDown(JOYSTICK _joystick);

	static Input* getInstance();
private:
	Input();

	static Input* instance;


	// Teclado
	bool onPressed[KEY::KeyCount];
	bool onDownPressed[KEY::KeyCount];

	// Mouse
	bool onPressedMouse[MOUSE::ButtonCount];
	bool onDownPressedMouse[MOUSE::ButtonCount];

	// Joystick
	bool onPressedJoystickP1[sf::Joystick::ButtonCount];
	bool onDownPressedJoystickP1[sf::Joystick::ButtonCount];

	bool onPressedJoystickP2[sf::Joystick::ButtonCount];
	bool onDownPressedJoystickP2[sf::Joystick::ButtonCount];

	int timer[KEY::KeyCount];
	int mouseTimer[MOUSE::ButtonCount];

	bool isKeyDownReleased(KEY _key);
	bool isButtonDownReleased(MOUSE _mouse);
	bool isButtonDownReleasedJoysTick(JOYSTICK _joystick);
};