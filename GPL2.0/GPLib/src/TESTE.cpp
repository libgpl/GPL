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

/*
//////////////////////////////////////////////////////////////
//							STATUS							//
//	Input			Falta Joystick
//	Gizmos			OK
//	Text			Ok
//	Panel			Aparentemente Ok, falta testar
//		Debug		Função pertencente ao panel - falta resolver problema com o textDefault
//		Inspector	Mostra informações sobre um objeto - não implementado
//	Audio			Interface criada
//	Sound			Aparentemente Ok, falta testar
//	Music			Aparentemente Ok, falta testar
//	Window			Falta o splash screen			
//	Scene			Ver necessidade de implementação =D
//	Métodos de retorno como const, para nao serem mudados.
Sobrecarregar o operador << para escrita
usar funções friends no lugar de static nos cpp's
//////////////////////////////////////////////////////////////
*/
void main()
{
	// Seção de carregamento de assets
	meuContador();

	Window game(800,600,"Minha Janela",true,false);	// Inicializa a biblioteca
	Text text;
	text.load("calibri.ttf");
	while(true)
	{
		text.draw("alouussss",100,100,50);
		game.flush();
	}
}