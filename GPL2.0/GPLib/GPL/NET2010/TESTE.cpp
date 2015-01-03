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
#include "../../include/Game.h"
#include "../../include/GPL.h"
/*
//////////////////////////////////////////////////////////////
//							STATUS							//
//	Input			Falta Joystick
//	Gizmos			OK
//	Text
//	Panel			Colocar como static/singleton
//	Debug			
//	Inspector		mostra informações sobre um objeto
//	Sound
//	Music
//	Scene
//	GPL
//	Métodos de retorno como const, para nao serem mudaddos.
//////////////////////////////////////////////////////////////
// Obs.: Passar por ponteiro a sf::RenderWindow *window para
//		 as classes que necessitam
//////////////////////////////////////////////////////////////
*/
void main()
{
	// Seção de carregamento de assets

	GPL game(800,600,"Minha Janela",true,false);	// Inicializa a biblioteca
	game.evolve(Game());
}