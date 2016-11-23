#pragma once
#include <SimIA>
#include <vector>
#include <string>
using namespace std;

class Mapa
{
public:
	Mapa();
	~Mapa();

	int x = 1;
	int y = 1;
	vector<vector<int>> mapa;
	Sprite images[RESOURCES::SIZE + 1];
	void addLeftColumn();
	void addRightColumn();
	void addTopRow();
	void addBottomRow();
	Mapa(string name);
	void drawMap();

};

