#include <gpl.h>
//#include <Input.h>

#pragma once
// GPL2: Cabeçalho de configuração automática das bibliotecas para o Visual Studio

// Não abrir a janela do console
//#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup ")



//#pragma comment(linker, "INCREMENTAL:NO")
// Não emitir erro de compilação por falta de atualização do Windows
// desabilita o linker incremental
//#pragma comment(linker, "NO (/INCREMENTAL:NO)" )

// Inclusão da SFML 2.1
#ifndef _DEBUG
	#pragma message("RELEASE SFML 2.1 - added libs: sfml-graphics.lib sfml-window.lib sfml-system.lib sfml-audio.lib (VS2010+)")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-graphics.lib")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-window.lib")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-system.lib")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-audio.lib")
#else
	#pragma message("DEBUG SFML 2.1 - added libs: sfml-graphics-d.lib sfml-window-d.lib sfml-system-d.lib sfml-audio-d.lib (VS2010+)")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-graphics-d.lib")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-window-d.lib")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-system-d.lib")
	#pragma comment(lib, "..//..//GPLib//SFML//lib//sfml-audio-d.lib")
#endif	

#if _MSC_VER >= 1600
   // this is Visual C++ 2010
	#ifndef _DEBUG
		#pragma message("RELEASE GPL 2.0 - added libs: gpl.lib (VS2010+)")
		#pragma comment(lib, "..//..//GPLib//lib//NET2010//gpl.lib")
	#else
		#pragma message("DEBUG GPL 2.0 - added libs: gpl_d.lib (VS2010+)")
		#pragma comment(lib, "..//..//GPLib//lib//NET2010//gpl_d.lib")
	#endif	
#else
	#pragma message("ERRO: Versão do Visual Studio sem suporte automático! ")
#endif

#include <fstream>
using namespace std;
//using namespace gpl;
void main()
{
	// Seção de carregamento de assets

	gplInit(800,600,"Minha Janela",true,false);	// Inicializa a biblioteca
	while (!isKeyPressed(KEY::Escape))		// Loop principal do jogo
    {
		// Lógica do Jogo
		
		if(isKeyUp(KEY::A))
		{
			cout << "KEY UP" << endl << endl;
		}

		if(isKeyHeld(KEY::B))
		{
			cout << "KEY HELD" << endl << endl;
		}

		if(isKeyDown(KEY::C))
		{
			cout << "KEY DOWN" << endl << endl;
		}
		gplFlush();		// Atualiza a tela - última coisa a ser chamada dentro do loop
    }
}