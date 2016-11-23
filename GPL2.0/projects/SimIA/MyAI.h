#pragma once
#include <SimIA>
using namespace GAMES;

string name = "Luan";

struct Mapa
{
	int x = 1;
	int y = 1;
	vector<vector<int>> mapa;

	void addLeftColumn(int xx)
	{
		if (xx == 0)
		{
			// Coluna Inicio
			//7 é o não visto
			mapa.emplace(mapa.begin(), vector<int>(mapa.back().size(), 7));
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
	void addTopRow(int yy)
	{
		if (yy == 0)
		{
			y++;
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

	void moveUp()
	{
		// se pode mover para cima
		if (sistema->move(name, ID, DIRECTION::UP_))
		{
			y--;
			// inserir linha acima
			Visao.addTopRow(y);
		}
	}
	void moveDown()
	{
		if (sistema->move(name, ID, DIRECTION::DOWN_))
		{
			y++;
			//Visao.y--;
			Visao.addBottomRow(y);
		}
	}
	void moveLeft()
	{
		if (sistema->move(name, ID, DIRECTION::LEFT_))
		{
			if(x > 0) x--;
			//Visao.x--;
			Visao.addLeftColumn(x);
		}
	}
	void moveRight()
	{
		if (sistema->move(name, 0, DIRECTION::RIGHT_))
		{
			x++;
			//Visao.x++;
			Visao.addRightColumn(x);
		}
	}
};



class MyAI : public AI
{
public:
	Text texto;

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

			Visao.mapa[b->x][b->y]		   = v[0][0];
			Visao.mapa[b->x][b->y + 1]	   = v[0][1];
			Visao.mapa[b->x][b->y + 2]	   = v[0][2];

			Visao.mapa[b->x + 1][b->y]	   = v[1][0];
			Visao.mapa[b->x + 1][b->y + 1] = v[1][1];
			Visao.mapa[b->x + 1][b->y + 2] = v[1][2];

			Visao.mapa[b->x + 2][b->y]	   = v[2][0];
			Visao.mapa[b->x + 2][b->y + 1] = v[2][1];
			Visao.mapa[b->x + 2][b->y + 2] = v[2][2];

		}
	}

	int ID_counter = 0;
	void setup()
	{
		Visao = Mapa(name);
		texto.load("calibri.ttf");
		Bots = new vector<Bot*>;
		Bots->push_back(new Bot(0, 0, 0));
		ID_counter++;
	}

	void run()
	{
		if (Bots->size() < sistema->getPopSize(name))
		{
			Bots->push_back(new Bot(1, 1, ID_counter));
			ID_counter++;
		}

		Visao.drawMap();

		//sensoriamento();
		//texto.draw("(" + to_string(Visao.x) + "," + to_string(Visao.y) + ")", 450, 500, 30);

		//system("cls");
		//cout << Visao.x << "," << Visao.y << endl;
		if (input->isUp(KEY::Up))
		{
			Bots->at(0)->moveUp();
		}
		if (input->isUp(KEY::Down))
		{
			Bots->at(0)->moveDown();
		}
		if (input->isUp(KEY::Left))
		{
			Bots->at(0)->moveLeft();
		}
		if (input->isUp(KEY::Right))
		{
			Bots->at(0)->moveRight();
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