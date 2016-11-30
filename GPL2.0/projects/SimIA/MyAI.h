#pragma once
#include <SimIA>
#include <ctime>
using namespace GAMES;

string name = "Luan";

struct Nodo
{

	vector<Nodo*> *filhos;
	Nodo *pai;
	Nodo()
	{
		pai = NULL;
		filhos = new vector<Nodo*>();
		//filhos->push_back(this);
	}
	Nodo(Nodo* pai)
	{
		this->pai = pai;
		filhos = new vector<Nodo*>();

		//filhos->push_back(this);
		state = 7;
	}
	//Nodo *pai;
	int state;
	int direcao;
	int qtd = 0;
	void addFilhos(int estado, int dir)
	{
		qtd++;
		filhos->push_back(new Nodo(this));
		filhos->back()->state = estado;
		filhos->back()->direcao = dir;
	}
	//int direcao = -1;
	int getDirection()
	{
		//while (filhos->back()->state == WALL)
		//{
		//	filhos->pop_back();
		//}
		if (filhos == NULL)
			return 0;
		
		if (filhos->size() == 0)
		{
			return 0;
		}

		if (filhos->back()->direcao == filhos->size() - 1)
			return filhos->size() + 1;

		return filhos->size();
		//return filhos->size() - 1;
		//if (filhos->size() - 1 < 0)
		//{
		//	return qtd;
		//}
		//return filhos->size() - 1;
		//direcao++;
		//if (direcao > 3)
		//{
		//	while (filhos.size() > 1)
		//	{
		//		filhos.pop_back();
		//	}
		//	filhos[0]->state = GROUND;
		//	direcao = 0;
		//}
		//return direcao;
	}
};

struct Mapa
{
	int x = 1;
	int y = 1;
	vector<vector<int>> mapa;

	void addLeftColumn(int &xx)
	{
		if (xx == 0)
		{
			// Coluna Inicio
			//7 é o não visto
			mapa.emplace(mapa.begin(), vector<int>(mapa.back().size(), 7));
			// todos os bots devem ser deslocados
			//TODO Bots

			xx++;
			x++;
		}
	}
	void addRightColumn(int xx)
	{
		if (xx == mapa.size() - 1)
		{
			// Coluna Fim
			mapa.emplace(mapa.end(), vector<int>(mapa.back().size(), 7));
		}
	}
	void addTopRow(int &yy)
	{
		if (yy == 0)
		{
			y++;
			yy++;
			// Linha acima
			for (int i = 0; i < mapa.size(); i++)
			{
				mapa[i].emplace(mapa[i].begin(), 7);
			}
		}
	}
	void addBottomRow(int yy)
	{
		if (yy == mapa[0].size() - 1)
		{
			// Linha abaixo
			for (int i = 0; i < mapa.size(); i++)
			{
				mapa[i].emplace(mapa[i].end(), 7);
			}
		}
	}

	Sprite images[RESOURCES::SIZE + 1];

	Mapa()
	{
	}

	Mapa(string name)
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

	void drawMap()
	{
		for (int i = 0; i < mapa.size(); i++)
		{
			for (int j = 0; j < mapa[i].size(); j++)
			{
				images[mapa[i][j]].draw(400 + i * 10, j * 10);
			}
		}
	}
};
Mapa Visao;

// alterar a posicação de todos os bots quando uma linha ou coluna é adicionada

class Bot
{
public:

	int x;
	int y;
	int ID;
	Bot(int x, int y, int ID)
	{
		this->x = x;
		this->y = y;
		this->ID = ID;
	}

	bool moveUp()
	{
		// se pode mover para cima
		if (sistema->move(name, ID, DIRECTION::UP_))
		{

			// inserir linha acima
			Visao.addTopRow(y);
			y--;
			return true;
		}
		return false;
	}
	bool moveDown()
	{
		if (sistema->move(name, ID, DIRECTION::DOWN_))
		{
			//Visao.y--;
			Visao.addBottomRow(y);
			y++;
			return true;
		}
		return false;
	}
	bool moveLeft()
	{
		if (sistema->move(name, ID, DIRECTION::LEFT_))
		{
			//if(x > 0) x--;
			//Visao.x--;
			Visao.addLeftColumn(x);
			x--;
			return true;
		}
		return false;
	}
	bool moveRight()
	{
		if (sistema->move(name, 0, DIRECTION::RIGHT_))
		{
			//Visao.x++;
			Visao.addRightColumn(x);
			x++;
			return true;
		}
		return false;
	}
};



class MyAI : public AI
{
public:
	Text texto;
	Nodo *arvore;
	Nodo *nodoGuia;

	vector<Bot*> *Bots;

	MyAI()
	{
		name = "Luan";
	}

	void sensoriamento()
	{
		for each (Bot *b in *Bots)
		{
			vector<vector<int>> v = sistema->whereAmI(name, b->ID);
			if (b->x - 1 >= 0 && b->y - 1 >= 0)
				Visao.mapa[b->x - 1][b->y - 1] = v[0][0];
			if (b->x - 1 >= 0)
				Visao.mapa[b->x - 1][b->y] = v[1][0];
			if (b->x - 1 >= 0 && b->y + 1 < Visao.mapa[0].size())
				Visao.mapa[b->x - 1][b->y + 1] = v[2][0];

			if (b->y - 1 >= 0)
				Visao.mapa[b->x][b->y - 1] = v[0][1];
			Visao.mapa[b->x][b->y] = v[1][1];
			if (b->y + 1 < Visao.mapa[0].size())
				Visao.mapa[b->x][b->y + 1] = v[2][1];

			if (b->x + 1 < Visao.mapa.size() && b->y - 1 >= 0)
				Visao.mapa[b->x + 1][b->y - 1] = v[0][2];
			if (b->x + 1 < Visao.mapa.size())
				Visao.mapa[b->x + 1][b->y] = v[1][2];
			if (b->x + 1 < Visao.mapa.size() && b->y + 1 < Visao.mapa[0].size())
				Visao.mapa[b->x + 1][b->y + 1] = v[2][2];

		}
	}

	int ID_counter = 0;
	Nodo *semente;
	void setup()
	{
		Visao = Mapa(name);
		texto.load("calibri.ttf");
		Bots = new vector<Bot*>;
		Bots->push_back(new Bot(1, 1, 0));
		ID_counter++;
		srand(time(0));

		// Define o nodo da arvore como ja visitado
//		nodoGuia->addFilhos();
		semente = new Nodo();
		arvore = new Nodo(semente);
		arvore->state = Visao.mapa[1][1];

		nodoGuia = arvore->pai;
	}

	void run()
	{
		//		sensoriamento();


		if (Bots->size() < sistema->getPopSize(name))
		{
			Bots->push_back(new Bot(1, 1, ID_counter));
			ID_counter++;
		}

		Visao.drawMap();

		sensoriamento();
		texto.draw("(" + to_string(Bots->at(0)->x) + "," + to_string(Bots->at(0)->y) + ")", 450, 500, 30);

		//system("cls");
		//cout << Visao.x << "," << Visao.y << endl;
		if (nodoGuia->filhos->size() > 0)
		{
			if (nodoGuia->filhos->back()->state != WALL)
				nodoGuia = nodoGuia->filhos->back();
		}
		//else
		//{
		//	//nodoGuia = nodoGuia->pai;
		//}

		int dir = nodoGuia->getDirection();

		if (dir == nodoGuia->filhos->size())
		{
			if (nodoGuia->pai != NULL)
			{
				Nodo *nodoTemp = nodoGuia->pai;
				nodoGuia = nodoTemp;
				dir = nodoGuia->getDirection();
			}
		}

		//int dir = rand() % 4;
		if (input->isUp(KEY::Up) || dir == 0)
		{
			if (nodoGuia->filhos->size() < 5)
			{
				nodoGuia->addFilhos(Visao.mapa[Bots->at(0)->x][Bots->at(0)->y], 0);
				if (Bots->at(0)->moveUp())
				{
					nodoGuia->state = Visao.mapa[Bots->at(0)->x][Bots->at(0)->y];
				}
				else
				{
					nodoGuia->filhos->back()->state = WALL;
				}
			}
			else
			{
				Nodo *nodoTemp = nodoGuia->pai;
				nodoGuia = nodoTemp;;
			}
		}
		else if (input->isUp(KEY::Down) || dir == 1)
		{
			if (nodoGuia->filhos->size() < 5)
			{
				nodoGuia->addFilhos(Visao.mapa[Bots->at(0)->x][Bots->at(0)->y], 0);
				if (Bots->at(0)->moveDown())
				{
					nodoGuia->state = Visao.mapa[Bots->at(0)->x][Bots->at(0)->y];
				}
				else
				{
					nodoGuia->filhos->back()->state = WALL;
				}
			}
			else
			{
				Nodo *nodoTemp = nodoGuia->pai;
				nodoGuia = nodoTemp;;
			}
		}
		else if (input->isUp(KEY::Left) || dir == 2)
		{
			if (nodoGuia->filhos->size() < 5)
			{
				nodoGuia->addFilhos(Visao.mapa[Bots->at(0)->x][Bots->at(0)->y], 0);
				if (Bots->at(0)->moveLeft())
				{
					nodoGuia->state = Visao.mapa[Bots->at(0)->x][Bots->at(0)->y];
				}
				else
				{
					nodoGuia->filhos->back()->state = WALL;
				}
			}
			else
			{
				Nodo *nodoTemp = nodoGuia->pai;
				nodoGuia = nodoTemp;;
			}
		}
		else if (input->isUp(KEY::Right) || dir == 3)
		{
			if (nodoGuia->filhos->size() < 5)
			{
				nodoGuia->addFilhos(Visao.mapa[Bots->at(0)->x][Bots->at(0)->y], 0);
				if (Bots->at(0)->moveRight())
				{
					nodoGuia->state = Visao.mapa[Bots->at(0)->x][Bots->at(0)->y];
				}
				else
				{
					nodoGuia->filhos->back()->state = WALL;
				}
			}
			else
			{
				Nodo *nodoTemp = nodoGuia->pai;
				nodoGuia = nodoTemp;;
			}
		}
		//panel->debug("PopSize", sistema->getPopSize(name));
		//panel->debug("FOOD", sistema->getInfo(FOOD, name, 0));
		//panel->debug("GOLD", sistema->getInfo(GOLD, name, 0));
		//panel->debug("WATER", sistema->getInfo(WATER, name, 0));
		//panel->debug("WOOD", sistema->getInfo(WOOD, name, 0));
		//panel->debug("CAPACIDADE", sistema->getInfo(CAPACIDADE, name, 0));

		//if (input->isUp(KEY::Return))
		//{
		//	system("cls");
		//	vector<vector<int>> m = sistema->whereAmI(name, 0);
		//	for (int i = 0; i < 3; i++)
		//	{
		//		for (int j = 0; j < 3; j++)
		//		{
		//			cout << ((m[i][j] == 1) ? (' ') : char(219));
		//		}
		//		cout << endl;
		//	}
		//}
	}

	void finish()
	{

	}
};