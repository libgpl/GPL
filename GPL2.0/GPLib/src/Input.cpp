#include "../include/Input.hpp"
#include "../include/Base.hpp"
#include "../include/Gizmos.hpp"

//#include <iostream>
using namespace std;

sf::Event event;

Input::Input(void) : snapDistanceX(1), snapDistanceY(1)
{
	keyDown.resize(sf::Keyboard::KeyCount);
	keyUp.resize(sf::Keyboard::KeyCount, true);

	buttonDown.resize(sf::Mouse::ButtonCount);
	buttonUp.resize(sf::Mouse::ButtonCount, true);

	joyUp.resize(PLAYER::PLAYER_COUNT);
	joyDown.resize(PLAYER::PLAYER_COUNT);
	for (unsigned int i = 0; i < joyUp.size(); i++)
	{
		joyUp.at(i).resize(JOYSTICK::JOYSTICK_COUNT);
		joyDown.at(i).resize(JOYSTICK::JOYSTICK_COUNT, true);
	}
}

Input::~Input(void)
{
	if (instance)
	{
		delete instance;
	}
}

Input* Input::getInstance()
{
	if (!instance)
	{
		instance = new Input();
	}
	return instance;
}

void Input::mouseSnap(int x, int y)
{
	this->snapDistanceX = x;
	this->snapDistanceY = y;
}


// ---------- KEYBOARD ---------- 
bool Input::isPressed(KEY _key)
{
	if (sf::Keyboard::isKeyPressed(_key))
	{
		return true;
	}
	return false;
}

bool Input::isUp(KEY _key)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_key)) && keyUp.at(_key))
	{
		keyUp.at(_key) = false;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_key)) && !keyUp.at(_key))
	{
		keyUp.at(_key) = true;
		return true;
	}
	return false;
}


bool Input::isDown(KEY _key)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_key)) && !keyDown.at(_key))
	{
		keyDown.at(_key) = true;
		return true;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_key)))
	{
		keyDown.at(_key) = false;
	}
	return false;
}


// ---------- MOUSE ---------- 
bool Input::isPressed(MOUSE _mouse)
{
	if (sf::Mouse::isButtonPressed(_mouse))
	{
		return true;
	}
	return false;
}

bool Input::isUp(MOUSE _mouse)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button(_mouse)) && buttonUp.at(_mouse))
	{
		buttonUp.at(_mouse) = false;
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Button(_mouse)) && !buttonUp.at(_mouse))
	{
		buttonUp.at(_mouse) = true;
		return true;
	}
	return false;
}

bool Input::isDown(MOUSE _mouse){

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button(_mouse)) && !buttonDown.at(_mouse))
	{
		buttonDown.at(_mouse) = true;
		return true;
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Button(_mouse)))
	{
		buttonDown.at(_mouse) = false;
	}
	return false;
}


// ---------- JOYSTICK ---------- 
bool Input::isPressed(JOYSTICK _joystick, PLAYER _player)
{
	////system("cls");
	////cout << "X: " << sf::Joystick::getAxisPosition(_player, sf::Joystick::X) << endl;
	////cout << "Y: " << sf::Joystick::getAxisPosition(_player, sf::Joystick::Y) << endl;

	int X = sf::Joystick::getAxisPosition(_player, sf::Joystick::PovX);
	int Y = sf::Joystick::getAxisPosition(_player, sf::Joystick::PovY);
	if (_joystick == JOYSTICK::UP)
	{
		if (Y < -1)
		{
			return true;
		}
	}
	else if (_joystick == JOYSTICK::DOWN)
	{
		if (X > 1)
		{
			return true;
		}
	}
	if (_joystick == JOYSTICK::LEFT)
	{
		if (X < -1)
		{
			return true;
		}
	}
	else if (_joystick == JOYSTICK::RIGHT)
	{
		if (X > 1)
		{
			return true;
		}
	}
	if (sf::Joystick::isButtonPressed(_player, _joystick))
	{
		return true;
	}
	return false;
}

bool Input::isUp(JOYSTICK _joystick, PLAYER _player)
{
	if (sf::Joystick::isButtonPressed(_player, _joystick) && joyUp.at(_player).at(_joystick))
	{
		joyUp.at(_player).at(_joystick) = false;
	}
	if (!sf::Joystick::isButtonPressed(_player, _joystick) && !joyUp.at(_player).at(_joystick))
	{
		joyUp.at(_player).at(_joystick) = true;
		return true;
	}
}

bool Input::isDown(JOYSTICK _joystick, PLAYER _player)
{
	if (sf::Joystick::isButtonPressed(_player, _joystick) && !joyDown.at(_player).at(_joystick))
	{
		joyDown.at(_player).at(_joystick) = true;
		return true;
	}
	if (!sf::Joystick::isButtonPressed(_player, _joystick))
	{
		joyDown.at(_player).at(_joystick) = false;
	}
	return false;
}

int Input::getMouseY()
{
	int space = (base->getWindow()->getSize().y - sf::Mouse::getPosition(*base->getWindow()).y) / snapDistanceY;
	return space * snapDistanceY;
}

int Input::getMouseX()
{
	int space = (sf::Mouse::getPosition(*base->getWindow()).x) / snapDistanceX;
	return space * snapDistanceX;
}

int Input::GetMouseAngle(int x, int y)
{
	x -= getMouseX();
	y -= getMouseY();
	return (int)(std::atan2(x, y)*(180 / 3.14));
}

int Input::getMouseScroll()
{
	if (event.type == sf::Event::MouseWheelMoved)
	{
		return event.mouseWheel.delta;
	}
	else return 0;
}

Input* Input::instance = NULL;