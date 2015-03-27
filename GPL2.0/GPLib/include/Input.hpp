#pragma once


#include "Object.hpp"

typedef sf::Keyboard::Key KEY;
typedef sf::Mouse::Button MOUSE;

enum JOYSTICK {RIGHT_UP, RIGHT_DOWN, RIGHT_LEFT, RIGHT_RIGHT, L1, R1, L2, R2, SELECT, START, LEFT_STICK, RIGHT_STICK, AXIS_X, AXIX_Y, UP, DOWN, LEFT, RIGHT};
enum PLAYER {PLAYER_1, PLAYER_2};

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
	bool onPressedJoystick[2][sf::Joystick::ButtonCount];
	bool onDownPressedJoystick[2][sf::Joystick::ButtonCount];


	int joystickTimer[2][sf::Joystick::ButtonCount];

	int timer[KEY::KeyCount];
	int mouseTimer[MOUSE::ButtonCount];

	bool isKeyDownReleased(KEY _key);
	bool isButtonDownReleased(MOUSE _mouse);
	bool isButtonDownReleasedJoysTick(JOYSTICK _joystick, PLAYER _player);
};