#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <vector>
#include <string>


typedef sf::Vector2f Vector2f;
typedef sf::RenderWindow _Window;

class Base
{
private:
	Base(bool placebo){}
public:
	Base(void);
	virtual ~Base(void);
	void setWindow(_Window* window);
	_Window* getWindow() const;
	std::string getVersion() const;
protected:
	_Window* window;
	std::string version;
	static Base* single;
};

