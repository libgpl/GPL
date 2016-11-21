/*
========================================================
GPL - Game Programming Library
by Luan Carlos Nesi (2014-2016)
https://github.com/libgpl
========================================================

The MIT License (MIT)

Copyright (c) 2014-2016 Luan Nesi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "../include/Panel.hpp"
#include "../include/Gizmos.hpp"

#include "SFML/Graphics.hpp"

#include "../include/Base.hpp"

#include <sstream>

Panel::Panel(void)
{
}

Panel* Panel::getInstance()
{
	if (!instance)
	{
		instance = new Panel();
	}
	return instance;
}

Panel::~Panel(void)
{
	if (instance)
	{
		delete instance;
	}
}

void Panel::Draw()
{
	// Desenha o retangulo
	sf::RectangleShape retangulo(sf::Vector2f((float)base->getWindow()->getSize().x, 78.0f));
	retangulo.setOutlineThickness(2);
	retangulo.setOutlineColor(sf::Color(84, 130, 52, 102));
	retangulo.setFillColor(sf::Color(0, 50, 0, 102));
	retangulo.setPosition(0, 0);
	base->getWindow()->draw(retangulo);

	Gizmos *gizmos = new Gizmos();
	gizmos->line((base->getWindow()->getSize().x / 3), base->getWindow()->getSize().y - 23, 50, 2, 84, 130, 52, 102, 90);
	gizmos->line((base->getWindow()->getSize().x / 3) * 2, base->getWindow()->getSize().y - 23, 50, 2, 84, 130, 52, 102, 90);

	// TODO: resolver o problema do GPL version
	std::string title = "GPL " + base->getVersion() + " DEBUG PANEL";

	// TODO: resolver o problema do defaultText em todo o código

	base->getDefaultText()->draw(title, base->getWindow()->getSize().x / 2 - title.size() * 2, 2, 10);

	int debY = 14;
	int debX = 10;
	message* temp = NULL;
	for (unsigned int i = 0; i < messagePoll.size(); i++)
	{
		if (i == 5 || i == 10)
		{
			debX += base->getWindow()->getSize().x / 3;
			debY = 14;
		}
		if (i == 14)
		{
			base->getDefaultText()->draw("...", debX, debY - 5, 10, 164, 164, 164);
			debY += 12;
			break;
		}
		temp = messagePoll[i];
		int des = debX + (base->getWindow()->getSize().x / 5);

		if (temp->key == "ERROR")
		{
			base->getDefaultText()->draw(temp->key + " - " + temp->value, debX, debY, 10, 255, 0, 0);
		}
		else
		{
			base->getDefaultText()->draw(temp->key, debX, debY, 10, 164, 164, 164);
			base->getDefaultText()->draw(temp->value, des, debY, 10, 164, 164, 164);
		}
		debY += 12;
	}
}

int Panel::getMessagePollSize() const
{
	return messagePoll.size();
}

void Panel::debug(std::string key, std::string value)
{
	//std::string tempVar;
	//std::stringstream conv;
	//conv << value;
	//conv >> tempVar;

	message* deb = NULL;
	message* temp = NULL;
	for (unsigned int i = 0; i < messagePoll.size(); i++)
	{
		temp = messagePoll[i];
		if (temp->key == key && temp->key != "ERROR") deb = temp;
	}
	if (deb == NULL)
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

void Panel::debug(std::string key, bool value)
{
	std::string temp;
	std::stringstream conv;
	std::string booleano;
	if (value) booleano = "TRUE";
	else booleano = "FALSE";

	conv << booleano;
	conv >> temp;
	debug(key, temp);
}

void Panel::debug(std::string key, int value)
{
	std::string temp;
	std::stringstream conv;
	conv << value;
	conv >> temp;
	debug(key, temp);
}

void Panel::debug(std::string key, double value)
{
	std::string temp;
	std::stringstream conv;
	conv << value;
	conv >> temp;
	debug(key, temp);
}

void Panel::debug(std::string key, float value)
{
	std::string temp;
	std::stringstream conv;
	conv << value;
	conv >> temp;
	debug(key, temp);
}

void Panel::debug(std::string key, char value)
{
	std::string temp;
	std::stringstream conv;
	conv << value;
	conv >> temp;
	debug(key, temp);
}

Panel *Panel::instance = NULL;