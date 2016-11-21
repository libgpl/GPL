/*
========================================================
GPL - Game Programming Library
by Luan Carlos Nesi (2014-2016)
https://github.com/libgpl
========================================================

The MIT License (MIT)

Copyright (c) 2014-2016 Luan Nesi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "../include/SplashScreen.hpp"

SplashScreen::SplashScreen(Sprite splashSprite, unsigned int showTime)
{
	splashTime = showTime;

	// create the window
	base->setWindow(new sf::RenderWindow(sf::VideoMode(splashSprite.getResX(), splashSprite.getResY(), 32), "", sf::Style::None));

	base->getWindow()->setActive();
	tempo.Zero;

	base->getWindow()->setVerticalSyncEnabled(true);
	base->getWindow()->setFramerateLimit(60); // Setting max framerate to 60 (Facultative)}

	base->getWindow()->setMouseCursorVisible(false);

	while (splashTime - tempo.asSeconds() > 0)
	{
		tempo = relogio.getElapsedTime();

		splashSprite.draw(0, 0);
		base->getWindow()->display();
	}

	base->getWindow()->close();
}

SplashScreen::~SplashScreen()
{
}