#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <vector>
using namespace std;

typedef sf::Keyboard::Key KEY;
typedef sf::Mouse::Button MOUSE;
typedef sf::Vector2f Vector2f;
typedef sf::RenderWindow Window;

class Base
{
public:
	Base(void);
	~Base(void);
	void setWindow(Window *window);
protected:
	Window *window;
	string version;
};

