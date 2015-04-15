#pragma once

#include "SFML/Graphics.hpp"
//#include "SFML/Window/Keyboard.hpp"
//#include <vector>
#include <string>
#include "Text.hpp"

typedef sf::RenderWindow _Window;
#define base Base::getInstance()

class Base
{
private:
	//Base(bool placebo){}
	Base(void);

	_Window *window;
	std::string version;
	static Base* instance;
	Text* defaultText;
public:
	Text* getDefaultText()
	{
		return defaultText;
	}

	static Base* getInstance();

	virtual ~Base(void);
	void setWindow(_Window* window);
	_Window* getWindow() const;
	std::string getVersion() const;
};

