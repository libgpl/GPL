//#pragma once
//
//#include <iostream>
//
//
////#include "gpl_include.hpp"
//#include "Input.hpp"
//#include "Sprite.hpp"
//#include "Panel.hpp"
//#include "Gizmos.hpp"
//#include "Text.hpp"
//
//
//class Game
//{
//public:
//	Input input;
//	Panel* panel;
//	Gizmos gizmos;
//	Text text;
//	Sprite imagem1;
//	Sprite imagem2;
//
//	int x;
//	int y;
//
//	Game(void);
//	~Game(void);
//	void load()
//	{
//		imagem1.load("minhaImagem.png");
//		imagem2.load("mouse.png");
//		text.load("calibri.ttf");
//
//		x = 100;
//		y = 100;
//	}
//
//	void run()
//	{
//		panel->Debug("Tesssssste", "vamosss ver");
//		imagem2.draw(x,y);
//		imagem1.draw(100,100);
//		text.draw("vamos lá", 20,20,100);
//		//panel.Debug("Teste","vamos lá");
//		if(input.isKeyDown(KEY::Left))
//		{
//			x++;
//			cout << "LEFT DOWN" << endl << endl;
//		}
//		if(input.isKeyUp(KEY::Right))
//		{
//			x--;
//			cout << "RIGHT UP" << endl << endl;
//		}
//		if(input.isKeyHeld(KEY::Up))
//		{
//			cout << "UP HELD" << endl << endl;
//		}
//		if(imagem1.collides(imagem2))
//		{
//	//		cout << "COLIDIU" << endl << endl;
//		}
//		gizmos.line(100,100,200);
//		// TODO: arrumar problema com template na classe de debug
//		//spanel.Debug("Teste","testeeeeee");
//		// Lógica do Jogo
//	}
//	void unload()
//	{
//	}
//	bool isFinish();
//private:
//	bool finish;
//};
//
