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