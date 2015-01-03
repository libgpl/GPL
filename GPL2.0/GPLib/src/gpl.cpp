#include "../include/GPL.h"

GPL::GPL(unsigned int width, unsigned int height, string windowTitle, bool showMouse, bool fullscreen)
{
	while((splashTime - tempo.asSeconds()) > 0)
	{
		tempo = relogio.getElapsedTime();
	}

	// TODO: fechamento da janela do splash screen
	//if(window != NULL) window->close();

	// create the window
	if(!fullscreen)	window = new sf::RenderWindow(sf::VideoMode(width, height, 32), windowTitle, sf::Style::Close);
	else			window = new sf::RenderWindow(sf::VideoMode(width, height, 32), windowTitle, sf::Style::Fullscreen);

	window->setActive();
	tempo.Zero;

	if(!showMouse) window->setMouseCursorVisible(false);
	// TODO: descomentar isso
	// Carrega a fonte padrão do sistema (Segoe UI)
	//defaultText.load("calibri.ttf");

	// TODO: inicializar os gizmos, inputs, panel, etc. aqui passando a window pra eles
}


GPL::~GPL(void)
{
}


string GPL::gplVersion()
{
	return version;
}

void GPL::evolve(Game game)
{
	// Definição da janela de desenho
	game.gizmos.setWindow(window);
	game.input.setWindow(window);
	game.panel.setWindow(window);
	game.text.setWindow(window);

	// Funcionamento do jogo
	game.load();
	while(!game.isFinish())
	{
		game.run();

		// Exibindo o terminal somente em modo DEBUG
#ifdef _DEBUG
		if(	game.panel.getMessagePollSize() > 0) game.panel.Draw();
#endif


		flush();
	}
	game.unload();
}

void GPL::flush()
{
	// check all the window's events that were triggered since the last iteration of the loop
	while(window->pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
		{
			window->close();
			exit(0);
		}
	}

	if(!window->isOpen())
	{
		exit(0);
	}

	window->display();
	window->clear(sf::Color::Black);
}

int GPL::getScreenWidth()
{
	return window->getSize().x;
}

int GPL::getScreenHeight()
{
	return window->getSize().y;
}

void GPL::gplSetIcon(string iconFile)
{
	// Define o icone da aplicação
	sf::Image icon;

	string file = "./assets/sprites/" + iconFile;

	if(!icon.loadFromFile(file))
	{
		// TODO: descomentar isso
		//debug("ERRO", "Arquivo de icone '"+iconFile+"' não encontrado");
	}	
	else
	{
		window->setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
	}	

}
//
//void GPL::gplSplashScreen(string filename, unsigned int showTime)
//{
//	// Cria uma sprite
//	sprite splash;
//
//	// Carrega o sprite
//	splash.load(filename);
//
//	splashTime = showTime;
//
//	// create the window
//	window = new sf::RenderWindow(sf::VideoMode(splash.getResX(), splash.getResY(), 32), "", sf::Style::None);
//
//	window->setActive();
//	tempo.Zero;
//
//	window->setVerticalSyncEnabled(true); 
//	window->setFramerateLimit(60); // Setting max framerate to 60 (Facultative)}
//
//	window->setMouseCursorVisible(false);
//
//	splash.draw(0,0);
//
//	window->display();
//}

int GPL::gplGetFPS()
{    
	static int frameCounter = 0;
	static int fps = 0;
	frameCounter++;
	tempo = relogio.getElapsedTime();
	if(tempo.asMilliseconds() > 999)
	{
		fps = frameCounter;
		frameCounter = 0;
		relogio.restart();
	}

	return fps;
}

void GPL::gplSetFPS(unsigned int fps)
{
	window->setVerticalSyncEnabled(true); 
	window->setFramerateLimit(fps); // Setting max framerate to 60 (Facultative)}
}


void GPL::gplSleep(int milisec)
{
	sf::sleep(sf::milliseconds(milisec));
}