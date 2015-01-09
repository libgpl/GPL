#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <vector>
#include <string>
using namespace std;

typedef sf::Vector2f Vector2f;
typedef sf::RenderWindow Window;

class Base
{
private:
	Base(bool placebo){}
public:
	Base(void);
	~Base(void);
	void setWindow(Window *window);
	Window* getWindow();
	string getVersion();
protected:
	Window *window;
	string version;
	static Base *single;
};

