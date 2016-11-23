#pragma once
//#include <SimIA>
#include "Mapa.h"

class Bot
{
public:
	static Mapa *Visao;

	int x;
	int y;
	int ID;
	Bot();
	~Bot();
	Bot(int x, int y);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};

