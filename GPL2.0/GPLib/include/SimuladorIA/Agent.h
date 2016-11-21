#pragma once
#include <ctime>
#include <iostream>
#include "..\gpl"

class Agent
{
	int capacidade;
public:
	int x;
	int y;
	int food;
	int water;
	int wood;
	int gold;
	int ultimoPontoDeColeta;
	int vida;
	bool vivo;

	const int getVida()
	{
		return vida;
	}
	const bool getVivo()
	{
		return vivo;
	}

	Agent(int x, int y, int capacidadeMinima, int vidaMinima) :food(0), water(0), wood(0), gold(0), ultimoPontoDeColeta(0), vivo(true)
	{
		this->x = x;
		this->y = y;
		capacidade = capacidadeMinima + rand() % atoi(File::GetValue("capacidade máxima", "Carga", "config.inf").c_str());

		vida = vidaMinima + rand() % atoi(File::GetValue("máxima", "Energia", "config.inf").c_str());;


	}

	const int getX()
	{
		return x;
	}

	const int getY()
	{
		return y;
	}

	const int getFood()
	{
		return food;
	}

	const int getWater()
	{
		return water;
	}

	const int getWood()
	{
		return wood;
	}

	const int getGold()
	{
		return gold;
	}

	const int getCapacity()
	{
		return capacidade;
	}

	const int getUltimoPontoDeColeta()
	{
		return ultimoPontoDeColeta;
	}

	void setUltimoPontoDeColeta(int u)
	{
		ultimoPontoDeColeta = u;
	}
};

struct pos
{
	int x;
	int y;
};


class Base_
{
	pos p;
public:
	int qtdAgentesVivos;
	int capacidadeMinima;
	int vidaMinima;
	int r1;
	int r2;
	int r3;
	int r4;
	Sprite avatar;
	vector<Agent*> *agents;
	Base_(std::string nome, pos p) : qtdAgentesVivos(0)
	{
		capacidadeMinima = atoi(File::GetValue("capacidade minima", "Carga", "config.inf").c_str());
		vidaMinima = atoi(File::GetValue("minima", "Energia", "config.inf").c_str());
		r1 = atoi(File::GetValue("custo R1", "Recursos", "config.inf").c_str());
		r2 = atoi(File::GetValue("custo R2", "Recursos", "config.inf").c_str());
		r3 = atoi(File::GetValue("custo R3", "Recursos", "config.inf").c_str());
		r4 = atoi(File::GetValue("custo R4", "Recursos", "config.inf").c_str());


		this->p = p;
		agents = new vector<Agent*>;
		avatar.load(nome + ".png");
		agents->push_back(new Agent(p.x, p.y, capacidadeMinima, vidaMinima));
		qtdAgentesVivos++;
	}
};
