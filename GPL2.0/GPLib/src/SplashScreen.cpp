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

		splashSprite.draw(0,0);
		base->getWindow()->display();
	}

	base->getWindow()->close();

}


SplashScreen::~SplashScreen()
{
}
