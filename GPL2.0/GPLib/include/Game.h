#pragma once

#include <iostream>
using namespace std;

//#include "gpl_include.h"
#include "Input.h"
#include "Panel.h"
#include "Gizmos.h"
#include "Text.h"


class Game
{
protected:
public:
	Input input;
	Panel panel;
	Gizmos gizmos;
	Text text;

	Game(void);
	~Game(void);
	void load()
	{
	}
	void run()
	{
		//panel.Debug("Teste","vamos lá");
		if(input.isKeyDown(KEY::Left))
		{
			cout << "LEFT DOWN" << endl << endl;
		}
		if(input.isKeyUp(KEY::Right))
		{
			cout << "RIGHT UP" << endl << endl;
		}
		if(input.isKeyHeld(KEY::Up))
		{
			cout << "UP HELD" << endl << endl;
		}
		gizmos.line(100,100,200);
		// TODO: arrumar problema com template na classe de debug
		//spanel.Debug("Teste","testeeeeee");
		// Lógica do Jogo
	}
	void unload()
	{
	}
	bool isFinish();
private:
	bool finish;
};

