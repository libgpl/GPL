#include "../include/Panel.h"
#include "../include/Gizmos.h"

#include "SFML/Graphics.hpp"

#include <sstream>

Panel::Panel(void)
{
}


Panel::~Panel(void)
{
}

template <typename variable>
void Panel::Debug(string key, variable value)
{
	string tempVar;
	stringstream conv;
	conv << value;
	conv >> tempVar;

	message* deb = NULL;
	message* temp = NULL;
	for(unsigned int i = 0; i < messagePoll.size(); i++)
	{
		temp = messagePoll[i];
		if(temp->key == key && temp->key != "ERROR") deb = temp;
	}
	if(deb == NULL)
	{
		deb = new message;
		deb->key = key;
		deb->value = tempVar;
		messagePoll.push_back(deb);
	}
	else
	{
		deb->value = tempVar;
	}
}

void Panel::Draw()
{
	// Desenha o retangulo
	sf::RectangleShape retangulo(sf::Vector2f(window->getSize().x,78.0f));
	retangulo.setOutlineThickness(2);
	retangulo.setOutlineColor(sf::Color(84,130,52,102));
	retangulo.setFillColor(sf::Color(0,50,0,102));
	retangulo.setPosition(0,0);
	window->draw(retangulo);

	Gizmos gizmos;
	gizmos.setWindow(window);

	gizmos.line(window->getSize().x / 3,23,50,2,84,130,52,102,90);
	gizmos.line((window->getSize().x / 3)*2,23,50,2,84,130,52,102,90);

	// TODO: resolver o problema do GPL version
	string title = "GPL "+version+" DEBUG PANEL";

	//defaultText.draw(title, window->getSize().x / 2 - title.size() * 2, 2, 10);

	int debY = 14;
	int debX = 10;
	message* temp = NULL;
	for(unsigned int i = 0; i < messagePoll.size(); i++)
	{
		if(i == 5 || i == 10)
		{
			debX += window->getSize().x / 3;	 
			debY = 14;
		}
		if(i == 14) 
		{
			//defaultText.draw("...", debX, debY-5,10,164,164,164);
			debY += 12;
			break;
		}
		temp = messagePoll[i];
		int des = debX + (window->getSize().x / 5);

		if(temp->key == "ERROR")
		{
			//defaultText.draw(temp->key +" - "+ temp->value,debX,debY,10,255,0,0);
		}
		else
		{
			//defaultText.draw(temp->key,debX,debY,10,164,164,164);
			//defaultText.draw(temp->value,des,debY,10,164,164,164);
		}
		debY += 12;
	}
}

int Panel::getMessagePollSize()
{
	return messagePoll.size();
}


//void debug(string key, bool value)
//{
//	string temp;
//	stringstream conv;
//	string booleano;
//	if(value) booleano = "TRUE";
//	else booleano = "FALSE";
//
//	conv << booleano;
//	conv >> temp;
//	debug(key,temp);
//
//}

//void debug(string key, int value)
//{
//	string temp;
//	stringstream conv;
//	conv << value;
//	conv >> temp;
//	debug(key,temp);
//}


//void debug(string key, double value)
//{
//	string temp;
//	stringstream conv;
//	conv << value;
//	conv >> temp;
//	debug(key,temp);
//}
//
//void debug(string key, float value)
//{
//	string temp;
//	stringstream conv;
//	conv << value;
//	conv >> temp;
//	debug(key,temp);
//}
//
//void debug(string key, char value)
//{
//	string temp;
//	stringstream conv;
//	conv << value;
//	conv >> temp;
//	debug(key,temp);
//}
