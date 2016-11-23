#pragma once
#include "Mapa.h"



Mapa::Mapa()
{
}


Mapa::~Mapa()
{
}


void Mapa::addLeftColumn()
{
	if (x == 1)
	{
		// Coluna Inicio
		//7 é o não visto
		mapa.emplace(mapa.begin(), vector<int>(mapa.back().size(), 7));
		x++;
	}
}

void Mapa::addRightColumn()
{
	if (x == mapa.size() - 1)
	{
		// Coluna Fim
		mapa.emplace(mapa.end(), vector<int>(mapa.back().size(), 7));
	}
}
void Mapa::addTopRow()
{
	if (y == 1)
	{
		y++;
		// Linha acima
		for (int i = 0; i < mapa.size(); i++)
		{
			mapa[i].emplace(mapa[i].begin(), 7);
		}
	}
}
void Mapa::addBottomRow()
{
	if (y == mapa[0].size() - 1)
	{
		// Linha abaixo
		for (int i = 0; i < mapa.size(); i++)
		{
			mapa[i].emplace(mapa[i].end(), 7);
		}
	}
}


Mapa::Mapa(string name)
{
	images[RESOURCES::GROUND].load("chao.png");
	images[RESOURCES::WALL].load("parede.png");
	images[RESOURCES::BASE].load("ninho.png");
	images[RESOURCES::RESOURCE_1].load("comida.png");
	images[RESOURCES::RESOURCE_2].load("agua.png");
	images[RESOURCES::RESOURCE_3].load("madeira.png");
	images[RESOURCES::RESOURCE_4].load("gold.png");
	images[RESOURCES::SIZE].load("visto.png");

	mapa = sistema->whereAmI(name, 0);
}

void Mapa::drawMap()
{
	for (int i = 0; i < mapa.size(); i++)
	{
		for (int j = 0; j < mapa[i].size(); j++)
		{
			images[mapa[i][j]].draw(400 + i * 10, j * 10);
		}
	}
}

