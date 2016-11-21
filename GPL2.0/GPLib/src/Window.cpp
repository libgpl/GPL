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
#include "../include/Window.hpp"
#include "../include/Panel.hpp"

Window::Window(unsigned int width, unsigned int height, std::string windowTitle, bool showMouse, bool fullscreen)
{
	this->width = width;
	this->height = height;
	this->windowTitle = windowTitle;
	this->fullscreen = fullscreen;

	//base->setWindow(new sf::RenderWindow(sf::VideoMode(width, height, 32), windowTitle, sf::Style::Close));
	//while(5 - tempo.asSeconds() > 0)
	//{
	//	tempo = relogio.getElapsedTime();
	//}
	 //TODO: fechamento da janela do splash screen
	//if(base->getWindow() != NULL)
	//{
	//	base->getWindow()->close();
	//}
	// create the window
	if (!fullscreen)	base->setWindow(new sf::RenderWindow(sf::VideoMode(width, height, 32), windowTitle, sf::Style::Close));
	else			base->setWindow(new sf::RenderWindow(sf::VideoMode(width, height, 32), windowTitle, sf::Style::Fullscreen));

	base->getWindow()->setActive();
	tempo.Zero;

	if (!showMouse) base->getWindow()->setMouseCursorVisible(false);
	// TODO: descomentar isso
	// Carrega a fonte padrão do sistema (Segoe UI)
	base->getDefaultText()->load("..\\..\\..\\..\\GPLib\\resources\\calibri.ttf");
}

Window::~Window(void)
{
}

//void Window::evolve(Game game)
//{
//	// Definição da janela de desenho
//	// TODO comentei este trecho CUIDADO
//	//game.gizmos.setWindow(window);
//	//game.input.setWindow(window);
//	//game.panel.setWindow(window);
//	//game.text.setWindow(window);
//
//	// Funcionamento do jogo
//	game.load();
//	while(!game.isFinish())
//	{
//		game.run();
//
//
//		flush();
//	}
//	game.unload();
//}

void Window::flush()
{
	// Exibindo o terminal somente em modo DEBUG
#ifdef _DEBUG
	if (panel->getMessagePollSize() > 0) panel->Draw();
#endif

	// check all the window's events that were triggered since the last iteration of the loop
	while (base->getWindow()->pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
		{
			base->getWindow()->close();
			exit(0);
		}
	}

	if (!base->getWindow()->isOpen())
	{
		exit(0);
	}

	base->getWindow()->display();
	base->getWindow()->clear(sf::Color::Black);
}

int Window::getWindowWidth() const
{
	return base->getWindow()->getSize().x;
}

int Window::getWindowHeight() const
{
	return base->getWindow()->getSize().y;
}

void Window::setIcon(std::string iconFile)
{
	// Define o icone da aplicação
	sf::Image icon;

	std::string File = "./assets/sprites/" + iconFile;

	if (!icon.loadFromFile(File))
	{
		panel->debug("ERROR", "Arquivo de icone '" + iconFile + "' não encontrado");
	}
	else
	{
		base->getWindow()->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	}
}

int Window::getFPS()
{
	static int frameCounter = 0;
	static int fps = 0;
	frameCounter++;
	tempo = relogio.getElapsedTime();
	if (tempo.asMilliseconds() > 999)
	{
		fps = frameCounter;
		frameCounter = 0;
		relogio.restart();
	}

	return fps;
}

void Window::setFPS(unsigned int fps)
{
	base->getWindow()->setVerticalSyncEnabled(true);
	base->getWindow()->setFramerateLimit(fps); // Setting max framerate to 60 (Facultative)}
}

// TODO: tirar estes dois métodos daqui
void Window::sleep(int milisec)
{
	sf::sleep(sf::milliseconds(milisec));
}

std::string Window::gplVersion() const
{
	return base->getVersion();
}

void Window::resizeWindow(int width, int height)
{
	if (this->width != width || this->height != height)
	{
		this->width = width;
		this->height = height;
		base->getWindow()->setSize(sf::Vector2u(width, height));
	}
}

void Window::setWindowFullscreen()
{
	fullscreen = !fullscreen;
	if (!fullscreen) {
		base->getWindow()->close();
		base->setWindow(new sf::RenderWindow(sf::VideoMode(width, height, 32), windowTitle, sf::Style::Close));
		base->getWindow()->setSize(sf::Vector2u(width, height));
	}
	else
	{
		base->getWindow()->close();
		base->setWindow(new sf::RenderWindow(sf::VideoMode(width, height, 32), windowTitle, sf::Style::Fullscreen));
		base->getWindow()->setSize(sf::Vector2u(width, height));
	}
}