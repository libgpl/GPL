#include "../include/gpl.h"

#include <sstream>

//text defaultText;

sf::Clock relogio;
sf::Time tempo;

sf::Event event;
int splashTime;

struct message
{
	string key;
	string value;
};

static vector<message*> messagePoll;

string gplVersion()
{
	return "v1.7.0-alpha";
}

sf::RenderWindow* gplInit(unsigned int width, unsigned int height, string windowTitle, bool showMouse, bool fullscreen)
{
	while((splashTime - tempo.asSeconds()) > 0)
	{
		tempo = relogio.getElapsedTime();
	}

	if(window != NULL) window->close();
	
	// create the window
	if(!fullscreen)	window = new sf::RenderWindow(sf::VideoMode(width, height, 32), windowTitle, sf::Style::Close);
	else			window = new sf::RenderWindow(sf::VideoMode(width, height, 32), windowTitle, sf::Style::Fullscreen);

	window->setActive();
	tempo.Zero;

	if(!showMouse) window->setMouseCursorVisible(false);


	return window;

	// Carrega a fonte padrão do sistema (Segoe UI)
	//defaultText.load("calibri.ttf");
}
//
//void gplSetIcon(string iconFile)
//{
//    // Define o icone da aplicação
//	sf::Image icon;
// 
//	string file = "./assets/sprites/" + iconFile;
//
//	if(!icon.loadFromFile(file))
//	{
//		debug("ERRO", "Arquivo de icone '"+iconFile+"' não encontrado");
//	}	
//	else
//	{
//		window->setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());
//	}	
// 
//}

//void gplSplashScreen(string filename, unsigned int showTime)
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
//
//int gplGetFPS()
//{    
//	static int frameCounter = 0;
//	static int fps = 0;
//	frameCounter++;
//	tempo = relogio.getElapsedTime();
//	if(tempo.asMilliseconds() > 999)
//	{
//		fps = frameCounter;
//		frameCounter = 0;
//		relogio.restart();
//	}
//
//	return fps;
//}
//
//void gplSetFPS(unsigned int fps)
//{
//	window->setVerticalSyncEnabled(true); 
//	window->setFramerateLimit(fps); // Setting max framerate to 60 (Facultative)}
//}

//void terminal()
//{
//	// Desenha o retangulo
//	sf::RectangleShape retangulo(sf::Vector2f((float)getScreenWidth(),(float)78));
//	retangulo.setOutlineThickness(2);
//	retangulo.setOutlineColor(sf::Color(84,130,52,102));
//	retangulo.setFillColor(sf::Color(0,50,0,102));
//	retangulo.setPosition(0,0);
//	window->draw(retangulo);
//
//	line(window->getSize().x / 3,23,50,2,84,130,52,102,90);
//	line((window->getSize().x / 3)*2,23,50,2,84,130,52,102,90);
//
//	string title = "GPL "+gplVersion()+" DEBUG PANEL";
//
//	defaultText.draw(title, window->getSize().x / 2 - title.size() * 2, 2, 10);
//
//	int debY = 14;
//	int debX = 10;
//	message* temp = NULL;
//	for(unsigned int i = 0; i < messagePoll.size(); i++)
//	{
//		if(i == 5 || i == 10)
//		{
//			debX += window->getSize().x / 3;	 
//			debY = 14;
//		}
//		if(i == 14) 
//		{
//			defaultText.draw("...", debX, debY-5,10,164,164,164);
//			debY += 12;
//			break;
//		}
//		temp = messagePoll[i];
//		int des = debX + (window->getSize().x / 5);
//
//		if(temp->key == "ERRO")
//		{
//			defaultText.draw(temp->key +" - "+ temp->value,debX,debY,10,255,0,0);
//		}
//		else
//		{
//			defaultText.draw(temp->key,debX,debY,10,164,164,164);
//			defaultText.draw(temp->value,des,debY,10,164,164,164);
//		}
//		debY += 12;
//	}
//}


void gplFlush()
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
		
	// Exibindo o terminal somente em modo DEBUG
	//#ifdef _DEBUG
	//	if(messagePoll.size() > 0) terminal();
 //   #endif

	window->display();
	window->clear(sf::Color::Black);
}

void gplSleep(int milisec)
{
	sf::sleep(sf::milliseconds(milisec));
}



void draw(sf::Sprite *t, bool borda)
{
	if(borda)
	{
		sf::RectangleShape retangulo(sf::Vector2f((float)(*t->getTexture()).getSize().x,(float)(*t->getTexture()).getSize().y));
		retangulo.setOutlineThickness((float)3);
		retangulo.setFillColor(sf::Color(0,0,0,0));
		retangulo.setOutlineColor(sf::Color(255, 0, 0));
		retangulo.setPosition(t->getPosition().x,t->getPosition().y);
		retangulo.setRotation(t->getRotation());
		window->draw(retangulo);
	}

	window->draw(*t);
}

void write(sf::Text *text)
{
	window->draw(*text);
}

//int mouse_x;
//int mouse_y;
//
//int getMouseY()
//{
//	return sf::Mouse::getPosition(*window).y;
//}
//
//int getMouseX()
//{
//	return sf::Mouse::getPosition(*window).x;
//}
//
//int getMouseScroll()
//{
//	if (event.type == sf::Event::MouseWheelMoved)
//	{
//		return event.mouseWheel.delta;
//	}
//	else return 0;
//}
//
//bool isKeyPressed(KEY key)
//{
//	if(sf::Keyboard::isKeyPressed(key))
//	{
//		return true;
//	}
//	return false;
//}
//
//bool isButtonPressed(MOUSE mouse)
//{
//	if (sf::Mouse::isButtonPressed(mouse))
//	{
//		return true;
//	}	
//	return false;
//}

// Return the a float rect as an int rect.
inline sf::IntRect FToIRect(const sf::FloatRect& f) {
	return sf::IntRect((int) f.left, (int) f.top, (int) f.width, (int) f.height);
}


bool testeColide(sf::Sprite& a, sf::Sprite& b, sf::Image& imgA, sf::Image& imgB) {
	sf::IntRect boundsA(FToIRect(a.getGlobalBounds()));
	sf::IntRect boundsB(FToIRect(b.getGlobalBounds()));
	sf::IntRect intersection;

	if(boundsA.intersects(boundsB, intersection)) {
		const sf::Transform& inverseA(a.getInverseTransform());
		const sf::Transform& inverseB(b.getInverseTransform());

		const sf::Vector2u& sizeA(imgA.getSize());
		const sf::Vector2u& sizeB(imgB.getSize());

		const sf::Uint8* pixA = imgA.getPixelsPtr();
		const sf::Uint8* pixB = imgB.getPixelsPtr();

		sf::Vector2f vecA, vecB;
		int xMax = intersection.left + intersection.width;
		int yMax = intersection.top + intersection.height;

		for(int x = intersection.left; x < xMax; x++)
			for(int y = intersection.top; y < yMax; y++) {
				vecA = inverseA.transformPoint((float)x, (float)y);
				vecB = inverseB.transformPoint((float)x, (float)y);

				int idxA = ((int) vecA.x + ((int) vecA.y)*sizeA.x)*4 + 3;
				int idxB = ((int) vecB.x + ((int) vecB.y)*sizeB.x)*4 + 3;

				if(vecA.x > 0 && vecA.y > 0 &&
					vecB.x > 0 && vecB.y > 0 &&
					vecA.x < sizeA.x && vecA.y < sizeA.y &&
					vecB.x < sizeB.x && vecB.y < sizeB.y &&
					pixA[idxA] > 0 &&
					pixB[idxB] > 0) {
						return true;
				}
			}
	}

	return false;
}


void debug(string key, string value)
{
	message* deb = NULL;
	message* temp = NULL;
	for(unsigned int i = 0; i < messagePoll.size(); i++)
	{
		temp = messagePoll[i];
		if(temp->key == key && temp->key != "ERRO") deb = temp;
	}
	if(deb == NULL)
	{
		deb = new message;
		deb->key = key;
		deb->value = value;
		messagePoll.push_back(deb);
	}
	else
	{
		deb->value = value;
	}
}

void debug(string key, int value)
{
	string temp;
	stringstream conv;
	conv << value;
	conv >> temp;
	debug(key,temp);
}

void debug(string key, bool value)
{
	string temp;
	stringstream conv;
	string booleano;
	if(value) booleano = "TRUE";
	else booleano = "FALSE";

	conv << booleano;
	conv >> temp;
	debug(key,temp);

}

void debug(string key, double value)
{
	string temp;
	stringstream conv;
	conv << value;
	conv >> temp;
	debug(key,temp);
}

void debug(string key, float value)
{
	string temp;
	stringstream conv;
	conv << value;
	conv >> temp;
	debug(key,temp);
}

void debug(string key, char value)
{
	string temp;
	stringstream conv;
	conv << value;
	conv >> temp;
	debug(key,temp);
}

int getScreenWidth()
{
	return window->getSize().x;
}

int getScreenHeight()
{
	return window->getSize().y;
}