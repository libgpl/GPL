#include "../include/GPL.h"

GPL::GPL(unsigned int width, unsigned int height, string windowTitle, bool showMouse, bool fullscreen)
{
	while((splashTime - tempo.asSeconds()) > 0)
	{
		tempo = relogio.getElapsedTime();
	}
	base = new Base();
	// TODO: fechamento da janela do splash screen
//	if(base->getWindow() != NULL) base->getWindow()->close();

	// create the window
	if(!fullscreen)	base->setWindow(new sf::RenderWindow(sf::VideoMode(width, height, 32), windowTitle, sf::Style::Close));
	else			base->setWindow(new sf::RenderWindow(sf::VideoMode(width, height, 32), windowTitle, sf::Style::Fullscreen));

	base->getWindow()->setActive();
	tempo.Zero;

	if(!showMouse) base->getWindow()->setMouseCursorVisible(false);
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
	return base->getVersion();
}

void GPL::evolve(Game game)
{
	// Definição da janela de desenho
	// TODO comentei este trecho CUIDADO
	//game.gizmos.setWindow(window);
	//game.input.setWindow(window);
	//game.panel.setWindow(window);
	//game.text.setWindow(window);

	// Funcionamento do jogo
	game.load();
	while(!game.isFinish())
	{
		game.run();

				// Exibindo o terminal somente em modo DEBUG
		#ifdef _DEBUG
				if(	game.panel->getMessagePollSize() > 0) game.panel->Draw();
		#endif


		flush();
	}
	game.unload();
}

void GPL::flush()
{
	// check all the window's events that were triggered since the last iteration of the loop
	while(base->getWindow()->pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
		{
			base->getWindow()->close();
			exit(0);
		}
	}

	if(!base->getWindow()->isOpen())
	{
		exit(0);
	}

	base->getWindow()->display();
	base->getWindow()->clear(sf::Color::Black);
}

int GPL::getScreenWidth()
{
	return base->getWindow()->getSize().x;
}

int GPL::getScreenHeight()
{
	return base->getWindow()->getSize().y;
}

void GPL::gplSetIcon(string iconFile)
{
	// Define o icone da aplicação
	sf::Image icon;

	string file = "./assets/sprites/" + iconFile;

	if(!icon.loadFromFile(file))
	{
		Panel *panel = new Panel();
		panel->Debug("ERRO", "Arquivo de icone '"+iconFile+"' não encontrado");
	}	
	else
	{
		base->getWindow()->setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
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
	base->getWindow()->setVerticalSyncEnabled(true); 
	base->getWindow()->setFramerateLimit(fps); // Setting max framerate to 60 (Facultative)}
}


void GPL::gplSleep(int milisec)
{
	sf::sleep(sf::milliseconds(milisec));
}