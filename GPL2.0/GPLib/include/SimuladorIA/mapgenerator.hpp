#pragma once
#include "..\gpl"
#include <vector>
#include <list>
#include "Resource.h"
using namespace std;


class MapGenerator
{
	struct Coord
	{
		int tileX;
		int tileY;
		Coord() {}
		Coord(int x, int y)
		{
			tileX = x;
			tileY = y;
		}
	};


	Sprite chao;
	Sprite nest;
	Sprite wall;
	Sprite food;
	Sprite gold;
	Sprite wood;
	Sprite water;
public:
	int width;
	int height;
	int seed;
	vector<vector<int>> *map;

	int resX;
	int resY;
	void GenerateMap()
	{
		resX = chao.getResX();
		resY = chao.getResY();

		//placeItem(BASE, 6, 6);
		int QTD_R1 = atoi(File::GetValue("quantidade R1", "Bases", "config.inf").c_str());
		int QTD_R2 = atoi(File::GetValue("quantidade R2", "Bases", "config.inf").c_str());
		int QTD_R3 = atoi(File::GetValue("quantidade R3", "Bases", "config.inf").c_str());
		int QTD_R4 = atoi(File::GetValue("quantidade R4", "Bases", "config.inf").c_str());

		int QTD = QTD_R1 + QTD_R2 + QTD_R3 + QTD_R4;

		int distanceY = height / sqrt(QTD);
		int distanceX = width / sqrt(QTD);
		int distance = (sqrt(pow(distanceX, 2) + pow(distanceY, 2)) * 0.7);

		while (QTD > 0)
		{
			if (QTD_R1 > 0)
			{
				placeItem(RESOURCE_1, distance);
				QTD_R1--;
			}
			if (QTD_R2 > 0)
			{
				placeItem(RESOURCE_2, distance);
				QTD_R2--;
			}
			if (QTD_R3 > 0)
			{
				placeItem(RESOURCE_3, distance);
				QTD_R3--;
			}
			if (QTD_R4 > 0)
			{
				placeItem(RESOURCE_4, distance);
				QTD_R4--;
			}
			QTD = QTD_R1 + QTD_R2 + QTD_R3 + QTD_R4;
		}
	}



	vector<vector<int>> *generateMaze(int maze_size_x, int maze_size_y)
	{
		srand(seed);

		vector < vector < int > > *maze = new vector<vector<int>>(maze_size_x, vector<int>(maze_size_y));;
		list < pair < int, int> > drillers;

		maze->resize(maze_size_y);
		for (size_t y = 0; y < maze_size_y; y++)
			maze->at(y).resize(maze_size_x);

		for (size_t x = 0; x < maze_size_x; x++)
			for (size_t y = 0; y < maze_size_y; y++)
				maze->at(y)[x] = GROUND;

		drillers.push_back(make_pair(maze_size_x / 2, maze_size_y / 2));
		while (drillers.size() > 0)
		{
			list < pair < int, int> >::iterator m, _m, temp;
			m = drillers.begin();
			_m = drillers.end();
			while (m != _m)
			{
				bool remove_driller = false;
				switch (rand() % 4)
				{
				case 0:
					(*m).second -= 2;
					if ((*m).second < 0 || maze->at((*m).second)[(*m).first])
					{
						remove_driller = true;
						break;
					}
					maze->at((*m).second + 1)[(*m).first] = WALL;
					break;
				case 1:
					(*m).second += 2;
					if ((*m).second >= maze_size_y || maze->at((*m).second)[(*m).first])
					{
						remove_driller = true;
						break;
					}
					maze->at((*m).second - 1)[(*m).first] = WALL;
					break;
				case 2:
					(*m).first -= 2;
					if ((*m).first < 0 || maze->at((*m).second)[(*m).first])
					{
						remove_driller = true;
						break;
					}
					maze->at((*m).second)[(*m).first + 1] = WALL;
					break;
				case 3:
					(*m).first += 2;
					if ((*m).first >= maze_size_x || maze->at((*m).second)[(*m).first])
					{
						remove_driller = true;
						break;
					}
					maze->at((*m).second)[(*m).first - 1] = WALL;
					break;
				}
				if (remove_driller)
					m = drillers.erase(m);
				else
				{
					drillers.push_back(make_pair((*m).first, (*m).second));
					// uncomment the line below to make the maze easier 
					// if (rand()%2) 
					drillers.push_back(make_pair((*m).first, (*m).second));

					maze->at((*m).second)[(*m).first] = WALL;
					++m;
				}
			}
		}

		for (size_t x = 0; x < maze_size_x; x++)
			for (size_t y = 0; y < maze_size_y; y++)
				maze->at(y)[x] = !maze->at(y)[x];

		// criar linhas horizontais no maze
		size_t x = (rand() % 10 + 1);
		for (; x < maze_size_x; x += (rand() % 15 + 5))
			for (size_t y = 0; y < maze_size_y; y++)
				maze->at(y)[x] = GROUND;

		// criar linhas horizontais no maze
		size_t y = rand() % 10 + 1;
		for (; y < maze_size_y; y += (rand() % 15 + 5))
			for (size_t x = 0; x < maze_size_x; x++)
				maze->at(y)[x] = GROUND;


		return maze;
	}

	Text t;
	MapGenerator(int width, int height, int seed)
	{
		t.load("calibri.ttf");
		map = generateMaze(height, width);
		this->seed = seed;
		srand(seed);
		this->width = width;
		this->height = height;
		chao.load("chao.png");
		wall.load("parede.png");
		food.load("comida.png");
		gold.load("gold.png");
		wood.load("madeira.png");
		water.load("agua.png");
		nest.load("ninho.png");

		GenerateMap();
	}

	void OnDrawGizmos()
	{
		//vector<Coord> ninhos;

		for (int x = 0; x < width; x++)
		{
			int xx = (x)*resX;
			for (int y = 0; y < height; y++)
			{
				int py = ((y)* resY);
				switch (map->at(x)[y])
				{
				case BASE:
					nest.draw(xx, py);
					break;
				case GROUND:
					chao.draw(xx, py);
					break;
					//				case WALL:
										//wall.draw(x*resX, py);
						//				break;
										//case _SD:
										//	SD.draw(x*resX, (-(y - height))*resY);
										//	break;
										//case _SE:
										//	SE.draw(x*resX, (-(y - height))*resY);
										//	break;
										//case _IE:
										//	IE.draw(x*resX, (-(y - height))*resY);
										//	break;
										//case _ID:
										//	ID.draw(x*resX, (-(y - height))*resY);
										//	break;
				case RESOURCE_1:
					food.draw(xx, py);
					break;
					//case BASE:
					//	nest.draw(x*resX, (-(y - height))*resY);
						//ninhos.push_back(Coord(x, y));
					break;
				case RESOURCE_2:
					water.draw(xx, py);
					break;
				case RESOURCE_3:
					wood.draw(xx, py);
					break;
				case RESOURCE_4:
					gold.draw(xx, py);
					break;
				}
				//t.draw(map->at(y)[x], x*resX + 4, py, 8, 255, 0, 0);
			}
		}
		//for each (Coord n  in ninhos)
		//{
		//	ninho.draw(n.tileX*resX - 5, (-(n.tileY - height))*resY + 5);

		//}
	}

	int countAliveNeighbours(int x, int y)
	{
		int count = 0;
		for (int i = -2; i < 3; i++)
		{
			for (int j = -2; j < 3; j++)
			{
				int neighbour_x = x + i;
				int neighbour_y = y + j;
				if (i == 1 && j == 1)
				{
					//Do nothing, we don't want to add ourselves in!
				}
				else if (neighbour_x < 0 || neighbour_y < 0 || neighbour_x >= width || neighbour_y >= height)
				{
					count = count + 1;
				}
				else if (map->at(neighbour_x)[neighbour_y] == GROUND)
				{
					count = count + 1;
				}
			}
		}
		return count;
	}

	vector<Coord*> ninhos;

	pos placeNest(string name, int distance)
	{
		RESOURCES item = BASE;
		int quantity = 1;
		pos p;
		//int distance = sqrt(pow(height / QTD, 2) + pow(width / QTD, 2));
		//int distance = sqrt(height * width);
		srand(seed);
		while (quantity > 0)
		{
			int x = rand() % width;
			int y = rand() % height;
			bool liberado = true;

			if (map->at(x)[y] == WALL && countAliveNeighbours(x, y) >= 8)
			{
				//cout << "(" << x << ", " << y << ")=	" << item << endl;
				Coord temp(x, y);
				for each (Resource *ninhoA in *Resource::fontes)
				{
					if (ninhoA->getTipo() == BASE)
					{
						int d = sqrt(pow(ninhoA->getX() - temp.tileX, 2) + pow(ninhoA->getY() - temp.tileY, 2));
						if (d < distance)
						{
							liberado = false;
							break;
						}
					}
				}
				if (liberado)
				{

					ninhos.push_back(new Coord(x, y));
					quantity--;
					map->at(x)[y] = item;

					if ((y + 1) < height) map->at(x)[y + 1] = GROUND;
					if ((y - 1) >= 0) map->at(x)[y - 1] = GROUND;
					if ((x + 1) < width) map->at(x + 1)[y] = GROUND;
					if ((x - 1) >= 0) map->at(x - 1)[y] = GROUND;

					if ((x + 1) < width && (y - 1) > 0) map->at(x + 1)[y - 1] = GROUND;
					if ((x - 1) >= 0 && (y + 1) < height) map->at(x - 1)[y + 1] = GROUND;
					if ((x + 1) < width && (y + 1) < height) map->at(x + 1)[y + 1] = GROUND;
					if ((x - 1) >= 0 && (y - 1) > 0) map->at(x - 1)[y - 1] = GROUND;

					//Resource::fontes->push_back(new Resource(x, y, item));
					new Resource(x, y, item);
					p.x = x;
					p.y = y;
					//cout << endl << "BASE (" << x << ", " << y << ")" << endl;
				}
			}
		}
		Resource::fontes->back()->setName(name);
		return p;
	}


	void placeItem(RESOURCES item, int distance)
	{
		srand(seed);
		int quantity = 1;
		//int distance = sqrt(height * width);
		while (quantity > 0)
		{
			int x = rand() % width;
			int y = rand() % height;
			bool liberado = true;

			if (map->at(x)[y] == WALL && countAliveNeighbours(x, y) >= 8)
			{
				//cout << "(" << x << ", " << y << ")=	" << item << endl;
				Coord temp(x, y);
				for each (Coord *ninhoA in ninhos)
				{
					int d = sqrt(pow(ninhoA->tileX - temp.tileX, 2) + pow(ninhoA->tileY - temp.tileY, 2));
					if (d < distance)
					{
						liberado = false;
						break;
					}
				}
				if (liberado)
				{
					ninhos.push_back(new Coord(x, y));
					quantity--;
					map->at(x)[y] = item;

					if ((y + 1) < height) map->at(x)[y + 1] = GROUND;
					if ((y - 1) >= 0) map->at(x)[y - 1] = GROUND;
					if ((x + 1) < width) map->at(x + 1)[y] = GROUND;
					if ((x - 1) >= 0) map->at(x - 1)[y] = GROUND;

					if ((x + 1) < width && (y - 1) > 0) map->at(x + 1)[y - 1] = GROUND;
					if ((x - 1) >= 0 && (y + 1) < height) map->at(x - 1)[y + 1] = GROUND;
					if ((x + 1) < width && (y + 1) < height) map->at(x + 1)[y + 1] = GROUND;
					if ((x - 1) >= 0 && (y - 1) > 0) map->at(x - 1)[y - 1] = GROUND;

					new Resource(x, y, item);
					//Resource::fontes->push_back(new Resource(x, y, item));
				}
			}
		}
	}
};
