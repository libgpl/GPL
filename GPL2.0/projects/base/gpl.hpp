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
//		Inspector	Mostra informações sobre um objeto - não implementado
//	Audio			Interface criada
//	Sound			Ok
//	Music			Ok
//	Window			Ok - Falta o splash screen			
//	Scene			Ver necessidade de implementação =D
//	Métodos de retorno como const, para nao serem mudados.
Sobrecarregar o operador << para escrita
//////////////////////////////////////////////////////////////
*/


////////////////////////////////////////////////////////////////////////////////////////////
// GPL2: Cabeçalho de configuração automática das bibliotecas para o Visual Studio

// Não abrir a janela do console
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

// Não emitir erro de compilação por falta de atualização do Windows
// desabilita o linker incremental
//#pragma comment(linker, "/incremental /incremental:no")




// Inclusão da SFML 2.1
#ifndef _DEBUG
	#pragma message("RELEASE SFML 2.1 - added libs: sfml-graphics.lib sfml-window.lib sfml-system.lib sfml-audio.lib (VS2013)")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-graphics.lib")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-window.lib")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-system.lib")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-audio.lib")
	#pragma comment(lib, "..//..//GPLib//lib//NET2013//gpl.lib")
#else
	#pragma message("DEBUG SFML 2.1 - added libs: sfml-graphics-d.lib sfml-window-d.lib sfml-system-d.lib sfml-audio-d.lib (VS2013)")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-graphics-d.lib")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-window-d.lib")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-system-d.lib")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-audio-d.lib")
	#pragma comment(lib, "..//..//GPLib//lib//NET2013//gpl_d.lib")
#endif	

#include "..\..\GPLib\include\Window.hpp"
#include "..\..\GPLib\include\Game.hpp"
#include "..\..\GPLib\include\Text.hpp"
#include "..\..\GPLib\include\Input.hpp"
#include "..\..\GPLib\include\Sprite.hpp"
#include "..\..\GPLib\include\Gizmos.hpp"
#include "..\..\GPLib\include\Music.hpp"
#include "..\..\GPLib\include\Sound.hpp"

Gizmos *gizmos = new Gizmos();

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
//// GPL2: Cabeçalho de configuração automática das bibliotecas para o Visual Studio
//
//// Não abrir a janela do console
//#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
//
//// Não emitir erro de compilação por falta de atualização do Windows
//// desabilita o linker incremental
//#pragma comment(linker, "/incremental /incremental:no")
//
//// Inclusão da SFML 2.1
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
//	#pragma message("ERRO: Versão do Visual Studio sem suporte automático! ")
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