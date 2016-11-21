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
#pragma once

#include <string>

//#include "gpl_include.hpp"
#include "Sprite.hpp"

//struct SplashScreen
//{
//	int splashTime;
//	sf::Time tempo;
//	sf::Clock relogio;
//
//	SplashScreen(Sprite splashSprite, unsigned int showTime)
//	{
//		splashTime = showTime;
//
//		// create the window
//		base->setWindow(new sf::RenderWindow(sf::VideoMode(splashSprite.getResX(), splashSprite.getResY(), 32), "", sf::Style::None));
//
//		base->getWindow()->setActive();
//		tempo.Zero;
//
//		base->getWindow()->setVerticalSyncEnabled(true);
//		base->getWindow()->setFramerateLimit(60); // Setting max framerate to 60 (Facultative)}
//
//		base->getWindow()->setMouseCursorVisible(false);
//
//
//		while (5 - tempo.asSeconds() > 0)
//		{
//			tempo = relogio.getElapsedTime();
//
//			splashSprite.draw(splashSprite.getResX() / 2, splashSprite.getResY()/2);
//			base->getWindow()->display();
//		}
//
//
//		base->getWindow()->close();
//		//if (!base->getWindow()->isOpen())
//		//{
//		//	exit(0);
//		//}
//	}
//};

class Window
{
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Inicializa a biblioteca. </summary>
	///
	/// <param name="width">	  	(Opcional) Resolução X/largura da janela. </param>
	/// <param name="height">	  	(Opcional) Resolução Y/altura da janela. </param>
	/// <param name="windowTitle">	(Opcional) Nome da janela. </param>
	/// <param name="showMouse">  	(Opcional) Exibir o ponteiro do mouse, padrão é exibir. </param>
	/// <param name="fullscreen"> 	(Opcional) Modo tela-cheia, padrão é sim. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Window(unsigned int width = 800, unsigned int height = 600, std::string windowTitle = "Window Name", bool showMouse = true, bool fullscreen = true);
	~Window(void);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Retorna a versão da biblioteca GPL. </summary>
	///
	/// <returns>	std::string da versão. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	std::string gplVersion() const;

	//void evolve(Game game);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Retorna a resolução da altura da janela. </summary>
	///
	/// <returns>	Altura da janela </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	int getWindowHeight() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Retorna a resolução da largura da janela. </summary>
	///
	/// <returns>	Largura da janela. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	int getWindowWidth() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Define um icone para a janela do aplicativo. </summary>
	///
	/// <param name="iconFile">	Caminho do arquivo do sprite do icone a ser carregado (bmp, png, tga,
	/// 						jpg, gif, psd, hdr, pic) </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void setIcon(std::string iconFile);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Define a taxa de FPS. </summary>
	///
	/// <param name="fps">	FPS. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void setFPS(unsigned int fps);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Retorna o FPS</summary>
	///
	/// <returns>	Quantidade de FPS</returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	int getFPS();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Faz o programa aguardar um tempo. </summary>
	///
	/// <param name="milisec">	tempo em milisegundos que o programa ficará parado. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void sleep(int milisec);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Atualiza o buffer de pintura. </summary>
	///
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void flush();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Cria uma Splash Screen. </summary>
	///
	/// <param name="Filename">	Caminho do arquivo do sprite da splash a ser carregada (bmp, png, tga,
	/// 						jpg, gif, psd, hdr, pic) </param>
	/// <param name="showTime">	(Opcional) Tempo mínimo de exibiçao, padrão 5 segundos </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	//void splashScreen(Sprite splashSprite, unsigned int showTime = 5);

	void resizeWindow(int width, int height);
	void setWindowFullscreen();
private:
	int height;
	int width;
	std::string windowTitle;
	//Base* base;
	int splashTime;
	sf::Clock relogio;
	sf::Time tempo;
	sf::Event event;
	bool fullscreen;
};