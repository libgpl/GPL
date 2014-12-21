//#include "../../include/gpl_include.h"
#pragma once
////////////////////////////////////////////////////////////////////////////////////////////
// GPL2: Cabeçalho de configuração automática das bibliotecas para o Visual Studio

// Não abrir a janela do console
//#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

// Não emitir erro de compilação por falta de atualização do Windows
// desabilita o linker incremental
//#pragma comment(linker, "/incremental /incremental:no")

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

#include "../../include/gpl.h"
#include "../../include/Input.h"
#include "../../include/Gizmos.h"
/*
//////////////////////////////////////////////////////////////
//							STATUS							//
//	Input			Falta Joystick
//	Gizmos			OK
//	Text
//	Debug			
//	Sound
//	Music
//	Scene
//	GPL
//////////////////////////////////////////////////////////////
// Obs.: Passar por ponteiro a sf::RenderWindow *window para
//		 as classes que necessitam
//////////////////////////////////////////////////////////////
*/
void main()
{
	// Seção de carregamento de assets

	sf::RenderWindow *window = gplInit(800,600,"Minha Janela",true,false);	// Inicializa a biblioteca

	Input input;
	Gizmos gizmos(window);
	
	while (!input.isKeyHeld(KEY::Escape))		// Loop principal do jogo
    {
		if(input.isKeyDown(KEY::Left))
		{
			cout << "LEFT DOWN" << endl << endl;
		}
		if(input.isKeyUp(KEY::Right))
		{
			cout << "RIGHT UP" << endl << endl;
		}
		if(input.isKeyHeld(KEY::Up))
		{
			cout << "UP HELD" << endl << endl;
		}
		gizmos.line(100,100,200);
		// Lógica do Jogo
		
		gplFlush();		// Atualiza a tela - última coisa a ser chamada dentro do loop
    }
}