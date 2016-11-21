#pragma once
#include "Agent.h"

enum RESOURCES { GROUND, WALL, BASE, RESOURCE_1, RESOURCE_2, RESOURCE_3, RESOURCE_4 };

class Resource
{
	int food;
	int water;
	int wood;
	int gold;
	int capacidade;

	int x;
	int y;
	RESOURCES tipo;
	static int ID;
	int UID;
	string name;

public:
	static vector<Resource*> *fontes;
	RESOURCES getTipo();
	void collectResource(Agent *a);
	void descarregar(Agent *a, Base_ *b);
	Resource(int x, int y, RESOURCES tipo);
	const int getX();
	const int getY();
	const int getCapacidade();
	void setName(string name);
};

//int Resource::ID;
//vector<Resource*>* Resource::fontes;
