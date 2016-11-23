#pragma once
#include "Bot.h"
string name = "Luan";

Bot::Bot()
{
}


Bot::~Bot()
{
}
Bot::Bot(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Bot::moveUp()
{
	// se pode mover para cima
	if (sistema->move(name, ID, DIRECTION::UP_))
	{
		y--;
		// inserir linha acima
		Visao->addTopRow();
	}
}
void Bot::moveDown()
{
	if (sistema->move(name, ID, DIRECTION::DOWN_))
	{
		y++;
		//Visao.y--;
		Visao->addBottomRow();
	}
}
void Bot::moveLeft()
{
	if (sistema->move(name, ID, DIRECTION::LEFT_))
	{
		x--;
		//Visao.x--;
		Visao->addLeftColumn();
	}
}
void Bot::moveRight()
{
	if (sistema->move(name, 0, DIRECTION::RIGHT_))
	{
		x++;
		//Visao.x++;
		Visao->addRightColumn();
	}
}


Mapa* Bot::Visao = new Mapa(name);