#pragma once
//#include "Agent.h"
#include "MapGenerator.hpp"
#include <map>
#include <vector>
#include <string>
using namespace std;

class ranking
{
public:
	string nome;
	int pontuacao;

	ranking(string nome, int pontuacao)
	{
		this->nome = nome;
		this->pontuacao = pontuacao;
	}
};

struct order
{
	inline bool operator() (const ranking *struct1, const ranking *struct2)
	{
		return (struct1->pontuacao < struct2->pontuacao);
	}
};


namespace CC
{
	enum INFO { R_1, R_2, R_3, R_4, CAPACIDADE, ENERGIA };
}

namespace GAMES
{
	enum INFO { FOOD, GOLD, WATER, WOOD, CAPACIDADE, VIDA };
}


enum DIRECTION { UP_, DOWN_, LEFT_, RIGHT_ };

class AI;

vector<AI*> *brains = new vector<AI*>();

class AI
{
protected:
	std::string name;
public:
	AI()
	{
		//brains->push_back(this);
	}

	~AI()
	{

	}
	const std::string getName()
	{
		return name;
	}
	virtual void run() = 0;
};



class Environment
{
private:
	map<string, Base_*> bases;
	map<string, Agent*> agents_original;
	MapGenerator *mapa;
	int seed;
	// Cria a janela
	//Window *janela;
	Timer t;
	Text text;
	//enum INFO;
	//void createAgent(string name, Agent *a)
	//{
	//	agents.insert(pair<string, Agent*>(name, a));
	//	int x;
	//	int y;
	//	do
	//	{
	//		x = rand() % mapa->width;
	//		y = rand() % mapa->height;

	//	} while (mapa->map->at(x).at(y) != GROUND);
	//	// TODO
	//	a->x = x;
	//	a->y = y;
	//	a->load();
	//}

	bool validPosition(int x, int y)
	{
		if (x < 0 || x >= mapa->width || y < 0 || y >= mapa->height)
		{
			return false;
		}
		return true;
	}

	int qtdBases;
public:
	//const vector<Agent*> *getMyAgents(string name)
	//{
	//	return bases.at(name)->agents;
	//}

	Environment(int widht, int height, int time_, int qtdBases, string seed = "")
	{
		_Game::game->Application->setIcon("../../../../GPLib/resources/simia.png");
		this->qtdBases = qtdBases;
		//janela = new Window(800, 600, "IA Simulator", true, false);
		//janela->setIcon("icon.png");
		t.restart(0, 0, time_);
		text.load("calibri.ttf");
		if (seed == "")
		{
			this->seed = time(0);
		}
		else
		{
			this->seed = 0;
			for (int i = 0; i < seed.size(); i++)
			{
				this->seed += (seed.at(i) * (i + 1));
			}
		}
		srand(this->seed);

		mapa = new MapGenerator(widht, height, this->seed);
		//mapa->GenerateMap();
	}

	const int getInfo(int type, string name, int id)
	{
		if (type == 0) return bases.at(name)->agents->at(id)->getFood();
		else if (type == 1) return bases.at(name)->agents->at(id)->getGold();
		else if (type == 2) return bases.at(name)->agents->at(id)->getWater();
		else if (type == 3) return bases.at(name)->agents->at(id)->getWood();
		else if (type == 4) return bases.at(name)->agents->at(id)->getCapacity();
		else if (type == 5) return bases.at(name)->agents->at(id)->getVida();
	}
	const int getPopSize(string name)
	{
		return bases.at(name)->qtdAgentesVivos;
	}
	const int getR1Cost(string name)
	{
		return bases.at(name)->r1;
	}

	const int getR2Cost(string name)
	{
		return bases.at(name)->r2;
	}
	const int getR3Cost(string name)
	{
		return bases.at(name)->r3;
	}
	const int getR4Cost(string name)
	{
		return bases.at(name)->r4;
	}
	void registerBase(AI *myAI)
	{

		//int QTD_R1 = atoi(File::GetValue("quantidade R1", "Bases", "config.inf").c_str());
		//int QTD_R2 = atoi(File::GetValue("quantidade R2", "Bases", "config.inf").c_str());
		//int QTD_R3 = atoi(File::GetValue("quantidade R3", "Bases", "config.inf").c_str());
		//int QTD_R4 = atoi(File::GetValue("quantidade R4", "Bases", "config.inf").c_str());

		//int QTD =/* QTD_R1 + QTD_R2 + QTD_R3 + QTD_R4 +*/ qtdBases;

		int distanceY = mapa->height / sqrt(qtdBases);
		int distanceX = mapa->width / sqrt(qtdBases);
		int distance = (sqrt(pow(distanceX, 2) + pow(distanceY, 2)) * 0.8);


		bases.insert(pair<string, Base_*>(myAI->getName(), new Base_(myAI->getName(), mapa->placeNest(myAI->getName(),distance))));
		brains->push_back(myAI);
	}

	~Environment()
	{

	}

	vector<vector<int>> whereAmI(string name, int id)
	{
		Agent *a = bases.at(name)->agents->at(id);
		int x = a->getX();
		int y = a->getY();
		int w = mapa->width;
		int h = mapa->height;
		vector<vector<int>> p;

		p.resize(3);
		p[0].resize(3);
		p[1].resize(3);
		p[2].resize(3);

		p[2][0] = validPosition(x - 1, y + 1) ? mapa->map->at(x - 1)[y + 1] : WALL;
		p[1][0] = validPosition(x - 1, y) ? mapa->map->at(x - 1)[y] : WALL;
		p[0][0] = validPosition(x - 1, y - 1) ? mapa->map->at(x - 1)[y - 1] : WALL;

		p[2][1] = validPosition(x, y + 1) ? mapa->map->at(x)[y + 1] : WALL;
		p[1][1] = validPosition(x, y) ? mapa->map->at(x)[y] : WALL;
		p[0][1] = validPosition(x, y - 1) ? mapa->map->at(x)[y - 1] : WALL;

		p[2][2] = validPosition(x + 1, y + 1) ? mapa->map->at(x + 1)[y + 1] : WALL;
		p[1][2] = validPosition(x + 1, y) ? mapa->map->at(x + 1)[y] : WALL;
		p[0][2] = validPosition(x + 1, y - 1) ? mapa->map->at(x + 1)[y - 1] : WALL;

		return p;
	}

	void move(string name, int id, DIRECTION D)
	{
		Agent *a = bases.at(name)->agents->at(id);
		if (a->getVivo())
		{
			int x = a->getX();
			int y = a->getY();

			if (D == DOWN_ && (y + 1) < mapa->height)
			{
				if (mapa->map->at(x)[y + 1] != WALL)
				{
					a->y++;
					a->vida -= atoi(File::GetValue("gasto", "Energia", "config.inf").c_str());
				}
			}
			else if (D == UP_ && (y - 1) >= 0)
			{
				if (mapa->map->at(x)[y - 1] != WALL)
				{
					a->y--;
					a->vida -= atoi(File::GetValue("gasto", "Energia", "config.inf").c_str());
				}
			}
			else if (D == RIGHT_ && (x + 1) < mapa->width)
			{
				if (mapa->map->at(x + 1)[y] != WALL)
				{
					a->x++;
					a->vida -= atoi(File::GetValue("gasto", "Energia", "config.inf").c_str());
				}
			}
			else if (D == LEFT_ && (x - 1) >= 0)
			{
				if (mapa->map->at(x - 1)[y] != WALL)
				{
					a->x--;
					a->vida -= atoi(File::GetValue("gasto", "Energia", "config.inf").c_str());
				}
			}
			if (a->getVida() <= 0)
			{
				a->vivo = false;
				bases.at(name)->qtdAgentesVivos--;
			}

			// Verifica se algum agente colidiu com uma base de recurso
			for (vector<Resource*>::iterator it = Resource::fontes->begin(); it != Resource::fontes->end(); ++it)
			{
				if ((*it)->getTipo() != BASE)
				{
					if ((*it)->getX() == a->x && (*it)->getY() == a->y)
					{
						(*it)->collectResource(a);
						// Se a fonte esgotou então ela some
						if ((*it)->getCapacidade() <= 0) mapa->map->at(a->x)[a->y] = GROUND;
						//cout << "COLETA" << endl;
						//cout << "Water:	" << a->water << endl;
						//cout << "Gold:	" << a->gold << endl;
						//cout << "Wood:	" << a->wood << endl;
						//cout << "Food:	" << a->food << endl;
						//cout << "------------------------------" << endl;

					}
				}
				else if ((*it)->getTipo() == BASE)
				{
					(*it)->descarregar(a, bases.at(name));
				}
			}
		}
	}

	void draw()
	{
		// Desenha o mapa
		mapa->OnDrawGizmos();

		// Percorre todas as bases
		for (std::map<string, Base_*>::iterator it = bases.begin(); it != bases.end(); ++it)
		{
			// Desenha os agentes
			for each (Agent *a in *(*it).second->agents)
			{
				if (a->getVivo())
				{
					(*it).second->avatar.draw((a->getX()+1) * 10, (a->getY()) * 10);
				}
			}
		}
	}
	void run()
	{
		if (!t.timeEnded())
		{
			//panel->debug("FPS", janela->getFPS());

			for each (AI *var in *brains)
			{
				var->run();
			}
			draw();
			//janela->flush();
		}
		else
		{
			finish();
		}
	}
	void finish()
	{
		int i = 0;
		vector<ranking*> colocados;
		for (std::map<string, Base_*>::iterator it = bases.begin(); it != bases.end(); ++it, i++)
		{
			int pontuacao = (*it).second->agents->size() * 2 + (*it).second->qtdAgentesVivos * 8;

			colocados.push_back(new ranking((*it).first,pontuacao));

//			text.draw((*it).first + " - " + to_string(pontuacao), 10, 500 - i * 40, 30);
		}

		sort(colocados.begin(), colocados.end(),order());
		while (!input->isPressed(KEY::Escape))
		{
			text.draw("PLACAR", 300, 100,50);
			for (int i = 0; i < colocados.size(); i++)
			{
				text.draw(to_string(colocados.size()-i)+"º", 50, 350 - i * 40, 30);
				text.draw(colocados[i]->nome, 100, 350 - i * 40, 30);
				text.draw(to_string(colocados[i]->pontuacao), 400, 350 - i * 40, 30);
			}
			//{
			//	int pontuacao = (*it).second->agents->size() * 2 + (*it).second->qtdAgentesVivos * 8;
			//	text.draw((*it).first + " - " + to_string(pontuacao), 10, 500 - i * 40, 30);
			//}

			//janela->flush();
			//_Game::Hidden();
			_Game::game->Hidden();
		}
		_Game::game->Quit();
	}
};

Environment *sistema;

#define SimIA sistema = new Environment
#define registerBase(a) sistema->registerBase(new a())
#define exec();	sistema->run();
