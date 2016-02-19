#pragma once

#include <string>
#include <iostream>
#include <fstream>

/*
//////////////////////////////////////////////////////////////
//							STATUS							//
//	Input			Ok - Falta testar Joystick
//	Gizmos			OK
//	Text			Ok
//	Panel			Ok
//		debug		Ok
//		Inspector	Mostra informa��es sobre um objeto - n�o implementado
//	Audio			Interface criada
//	Sound			Ok
//	Music			Ok
//	Window			Ok - Falta o splash screen			
//	Scene			Ver necessidade de implementa��o =D
//	M�todos de retorno como const, para nao serem mudados.
Sobrecarregar o operador << para escrita
//////////////////////////////////////////////////////////////
*/


////////////////////////////////////////////////////////////////////////////////////////////
// GPL2: Cabe�alho de configura��o autom�tica das bibliotecas para o Visual Studio

// N�o abrir a janela do console
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

// N�o emitir erro de compila��o por falta de atualiza��o do Windows
// desabilita o linker incremental
//#pragma comment(linker, "/incremental /incremental:no")


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


// Inclus�o da SFML 2.1
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

#include "..\..\include\Window.hpp"
#include "..\..\include\Game.hpp"
#include "..\..\include\Text.hpp"
#include "..\..\include\Input.hpp"
#include "..\..\include\Sprite.hpp"
#include "..\..\include\Gizmos.hpp"
#include "..\..\include\Music.hpp"
#include "..\..\include\Sound.hpp"

static Gizmos *gizmos = new Gizmos();

//#include "Input.hpp"
//#include "Panel.hpp"
//#include "Gizmos.hpp"
//
//
//Input input;
//Panel panel;
//Gizmos gizmos;
//

//#include "gpl.hpp"



//#pragma once
//////////////////////////////////////////////////////////////////////////////////////////////
//// GPL2: Cabe�alho de configura��o autom�tica das bibliotecas para o Visual Studio
//
//// N�o abrir a janela do console
//#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
//
//// N�o emitir erro de compila��o por falta de atualiza��o do Windows
//// desabilita o linker incremental
//#pragma comment(linker, "/incremental /incremental:no")
//
//// Inclus�o da SFML 2.1
//#ifndef _DEBUG
//	#pragma message("RELEASE SFML 2.1 - added libs: sfml-graphics.lib sfml-window.lib sfml-system.lib sfml-audio.lib (VS2010+)")
//	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-graphics.lib")
//	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-window.lib")
//	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-system.lib")
//	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-audio.lib")
//#else
//	#pragma message("DEBUG SFML 2.1 - added libs: sfml-graphics-d.lib sfml-window-d.lib sfml-system-d.lib sfml-audio-d.lib (VS2010+)")
//	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-graphics-d.lib")
//	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-window-d.lib")
//	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-system-d.lib")
//	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-audio-d.lib")
//#endif	
//
//#if _MSC_VER >= 1600
//   // this is Visual C++ 2010
//	#ifndef _DEBUG
//		#pragma message("RELEASE GPL 2.0 - added libs: gpl.lib (VS2010+)")
//		#pragma comment(lib, "..//..//GPLib//lib//NET2010//gpl.lib")
//	#else
//		#pragma message("DEBUG GPL 2.0 - added libs: gpl_d.lib (VS2010+)")
//	#endif	
//#else
//	#pragma message("ERRO: Vers�o do Visual Studio sem suporte autom�tico! ")
//#endif

///////////////////////////////////////////////////////////////////////////////////////////
//// Todos os includes da GPL
//#include "config.hpp"
//
//#include <GerenciadorEntrada.h>
//
//////////////////////////////////////////////////////////////////////////////////////////////
//
//#include "Input.hpp"
//
//namespace gpl{
//
//	namespace input
//	{
//		namespace mouse{ }
//
//		namespace keyboard{	}
//
//		namespace joystick{ }
//	}
//
//	namespace audio
//	{
//		namespace music{ }
//
//		namespace Sound{ }
//	}
//
//	namespace graphics
//	{ 
//		namespace sprite{ }
//
//		namespace text{ }
//
//		namespace gizmos{ }
//	}
//
//	namespace physics{ }
//
//	namespace network{ }
//
//	namespace debug{ }
//
//	namespace window{ }
//
//	namespace tilemap{ }
//
//}
//
//using namespace gpl;
//	using namespace gpl::input;
//		using namespace gpl::input::mouse;
//		using namespace gpl::input::keyboard;
//		using namespace gpl::input::joystick;
//	using namespace gpl::audio;
//		using namespace gpl::audio::music;
//		using namespace gpl::audio::Sound;
//	using namespace gpl::graphics;
//		using namespace gpl::graphics::sprite;
//		using namespace gpl::graphics::text;
//		using namespace gpl::graphics::gizmos;
//	using namespace gpl::physics;
//	using namespace gpl::network;
//	using namespace gpl::debug;
//	using namespace gpl::window;
//	using namespace gpl::tilemap;