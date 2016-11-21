#pragma once
#include <SimIA>
using namespace GAMES;


class MyAI : public AI
{
public:
	MyAI()
	{
		name = "Luan";
	}

	void run()
	{
		if (input->isUp(KEY::Up))	 sistema->move(name, 0, DIRECTION::UP_);
		if (input->isUp(KEY::Down))  sistema->move(name, 0, DIRECTION::DOWN_);
		if (input->isUp(KEY::Left))  sistema->move(name, 0, DIRECTION::LEFT_);
		if (input->isUp(KEY::Right)) sistema->move(name, 0, DIRECTION::RIGHT_);

		panel->debug("PopSize", sistema->getPopSize(name));
		panel->debug("FOOD", sistema->getInfo(FOOD, name, 0));
		panel->debug("GOLD", sistema->getInfo(GOLD, name, 0));
		panel->debug("WATER", sistema->getInfo(WATER, name, 0));
		panel->debug("WOOD", sistema->getInfo(WOOD, name, 0));
		panel->debug("CAPACIDADE", sistema->getInfo(CAPACIDADE, name, 0));

		if (input->isUp(KEY::Return))
		{
			system("cls");
			vector<vector<int>> m = sistema->whereAmI(name, 0);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << ((m[i][j] == 1) ? (' ') : char(219));
				}
				cout << endl;
			}
		}
	}
};
