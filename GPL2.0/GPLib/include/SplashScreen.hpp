#pragma once
#include "../include/Sprite.hpp"

class SplashScreen
{
private:
	int splashTime;
	sf::Time tempo;
	sf::Clock relogio;

public:
	SplashScreen(Sprite splashSprite, unsigned int showTime);
	~SplashScreen();
};

