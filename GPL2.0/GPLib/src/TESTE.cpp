//#include "../../include/gpl_include.hpp"
#pragma once
////////////////////////////////////////////////////////////////////////////////////////////
// GPL2: Cabeçalho de configuração automática das bibliotecas para o Visual Studio

// Não abrir a janela do console
//#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

// Não emitir erro de compilação por falta de atualização do Windows
// desabilita o linker incremental
//#pragma comment(linker, "/incremental /incremental:no")

#include <string>
#include <iostream>
#include <fstream>


void meuContador()
{
	std::string hora,dia,mes,ano; 
	std::fstream file;
	file.open("log.txt",std::ios::in | std::ios::out);
	file >> hora >> mes >> dia >> ano; 
	file.close();
	
	
	std::string data = mes + "  " + dia + " " + ano;
	std::string hora2 = __TIME__;
	std::string data2 = __DATE__;
	std::cout << hora << std::endl;
	std::cout << hora2 << std::endl;
	std::cout << data << std::endl;
	std::cout << data2 << std::endl;
	
	if(data != data2 || hora != hora2)	
	{		
	int major, minor, release;	
	std::fstream file1;
	char temp;
	file1.open("log.txt",std::ios::in | std::ios::out);
	file1 >> hora >> mes >> dia >> ano >> major >> temp >> minor >> temp >> release; 
	release++;			
	file1.close();
	
	std::fstream file2;
	file2.open("log.txt", std::ios::in | std::ios::out);
	file2 << __TIME__ << "	" << __DATE__ << "	" << major << "." << minor << "." <<  release << "		" << std::endl;
	file2.close();	
	
	std::fstream file3;
	file3.open("log.txt", std::ios::in | std::ios::app);
	file3 << __TIME__ << "	" << __DATE__ << "	" << major << "." << minor << "." << release << "		" << std::endl;
	file3.close();
	}
}


// Inclusão da SFML 2.1
#ifndef _DEBUG
	#pragma message("RELEASE SFML 2.1 - added libs: sfml-graphics.lib sfml-window.lib sfml-system.lib sfml-audio.lib (VS2010+)")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-graphics.lib")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-window.lib")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-system.lib")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-audio.lib")
#else
	#pragma message("DEBUG SFML 2.1 - added libs: sfml-graphics-d.lib sfml-window-d.lib sfml-system-d.lib sfml-audio-d.lib (VS2010+)")
	#pragma comment(lib, "..//..//SFML//lib//sfml-graphics-d.lib")
	#pragma comment(lib, "..//..//SFML//lib//sfml-window-d.lib")
	#pragma comment(lib, "..//..//SFML//lib//sfml-system-d.lib")
	#pragma comment(lib, "..//..//SFML//lib//sfml-audio-d.lib")
#endif	

#include "../../include/Window.hpp"
#include "../../include/Game.hpp"
#include "../../include/Text.hpp"
#include "../../include/Input.hpp"
#include "../../include/GameObject.hpp"

/*
//////////////////////////////////////////////////////////////
//							STATUS							//
//	Input			Ok - Falta testar Joystick
//	Gizmos			OK
//	Text			Ok
//	Panel			Ok
//		Debug		Ok
//		Inspector	Mostra informações sobre um objeto - não implementado
//	Audio			Interface criada
//	Sound			Aparentemente Ok, falta testar
//	Music			Aparentemente Ok, falta testar
//	Window			Falta o splash screen			
//	Scene			Ver necessidade de implementação =D
//	Métodos de retorno como const, para nao serem mudados.
Sobrecarregar o operador << para escrita
//////////////////////////////////////////////////////////////
*/
void main()
{
	// Seção de carregamento de assets
	meuContador();
	
	Window game(800,600,"Minha Janela",true,false);	// Inicializa a biblioteca
	Text text;
	text.load("calibri.ttf");

	unsigned int buttonCount = sf::Joystick::getButtonCount(0);
	bool xx = sf::Joystick::hasAxis(0,sf::Joystick::Axis::PovX);
	bool yy = sf::Joystick::hasAxis(0,sf::Joystick::Axis::PovY);

	GameObject teste222;
	((Sprite*)teste222.addComponent("Sprite"))->load("mouseascascasc.png");
	while(true)
	{
		Sprite* s = (Sprite*)teste222.getComponent("Sprite");
			s->draw(10,10);
		if (sf::Joystick::isConnected(0))
		{
//			text.draw("J0 conectado",100,100,50);
		}
		// is button 1 of joystick number 0 pressed?
		if (sf::Joystick::isButtonPressed(0, sf::Joystick::V))
		{
			text.draw("V",100,100,50);
		}
		if (sf::Joystick::isButtonPressed(0, sf::Joystick::X))
		{
			text.draw("X",100,100,50);
		}
		if (sf::Joystick::isButtonPressed(0, sf::Joystick::R))
		{
			text.draw("R",100,100,50);
		}
		if (sf::Joystick::isButtonPressed(0, sf::Joystick::U))
		{
			text.draw("U",100,100,50);
		}
		if (sf::Joystick::isButtonPressed(0, sf::Joystick::Y))
		{
			text.draw("Y",100,100,50);
		}
		if (sf::Joystick::isButtonPressed(0, sf::Joystick::Z))
		{
			text.draw("Z",100,100,50);
		}
		if (sf::Joystick::isButtonPressed(0, sf::Joystick::PovX))
		{
			text.draw("PovX",100,100,50);
		}
		if (sf::Joystick::isButtonPressed(0, sf::Joystick::PovY))
		{
			text.draw("PovY",100,100,50);
		}
		if (sf::Joystick::isButtonPressed(0, 8))
		{
			text.draw("8",100,100,50);
		}
		if (sf::Joystick::isButtonPressed(0, 9))
		{
			text.draw("9",100,100,50);
		}
		if (sf::Joystick::isButtonPressed(0, 10))
		{
			text.draw("10",100,100,50);
		}
		for(int i = 0; i < 32; i++)
		{
		if (sf::Joystick::isButtonPressed(0, i))
		{
			text.draw("vai",150,150,50,255,0,0);
		}
		}

		// what's the current position of the X and Y axes of joystick number 0?
		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

		std::cout << x << " " << y << std::endl;
		
		game.flush();
	}
}