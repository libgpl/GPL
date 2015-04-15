#include "../../include/gpl.hpp"


void main()
{
	// Seção de carregamento de assets
	meuContador();

	
	Window game(800,600,"Minha Janela",true,false);	// Inicializa a biblioteca

	Text text;
	text.load("calibri.ttf");

	Music musica;
	musica.load("minhaMusica.ogg");

	Sound som;
	som.load("meuSom.wav");

	//unsigned int buttonCount = sf::Joystick::getButtonCount(0);
	//bool xx = sf::Joystick::hasAxis(0,sf::Joystick::Axis::PovX);
	//bool yy = sf::Joystick::hasAxis(0,sf::Joystick::Axis::PovY);
	
	//GameObject teste222;
	//((Sprite*)teste222.addComponent("Sprite"))->load("mouseascascasc.png");
	//musica.play();
	//som.play();

	Sprite imagem;
	imagem.load("minhaImagem.png");

	Sprite imagem2;
	imagem2.load("minhaImagem.png");

	int x= 0;
	int y= 0;
	while(!input->isPressed(KEY::Escape))
	{
		imagem.draw(200,200);
		imagem2.draw(x,y);
		text.draw("Vamos lá!",100,100,10,0);
		panel->debug("X",x);
		panel->debug("Y",y);
		int vvv = base->getWindow()->getSize().y;
		panel->debug("Teste2",vvv);
		gizmos->rectangle(x,y,100,200);
		gizmos->line(x,y,300,1,255,0,0);
		gizmos->pixel(x+300,y);
		gizmos->circle(300,y,10);
		if(input->isPressed(KEY::Up))
		{
			y++;
		}
		if(input->isPressed(KEY::Down))
		{
			y--;
		}

		if(input->isPressed(KEY::Left))
		{
			x--;
		}
		if(input->isPressed(KEY::Right))
		{
			x++;
		}
		if(imagem.collides(imagem2))
		{
			text.draw("Colidou",200,100,10,0);

		}
		gizmos->circle(300,300,50);
		panel->debug("Valor",true);
			//Sprite* s = (Sprite*)teste222.getComponent("Sprite");
		//	s->draw(10,10);
		//if (sf::Joystick::isConnected(0))
		//{
		//	text.draw("J0 conectado",100,100,50);
		//}
		 //is button 1 of joystick number 0 pressed?
		//if (sf::Joystick::isButtonPressed(0, sf::Joystick::V))
		//{
		//	text.draw("V",100,100,50);
		//}
		//if (sf::Joystick::isButtonPressed(0, sf::Joystick::X))
		//{
		//	text.draw("X",100,100,50);
		//}
		//if (sf::Joystick::isButtonPressed(0, sf::Joystick::R))
		//{
		//	text.draw("R",100,100,50);
		//}
		//if (sf::Joystick::isButtonPressed(0, sf::Joystick::U))
		//{
		//	text.draw("U",100,100,50);
		//}
		//if (sf::Joystick::isButtonPressed(0, sf::Joystick::Y))
		//{
		//	text.draw("Y",100,100,50);
		//}
		//if (sf::Joystick::isButtonPressed(0, sf::Joystick::Z))
		//{
		//	text.draw("Z",100,100,50);
		//}
		//if (sf::Joystick::isButtonPressed(0, sf::Joystick::PovX))
		//{
		//	text.draw("PovX",100,100,50);
		//}
		//if (sf::Joystick::isButtonPressed(0, sf::Joystick::PovY))
		//{
		//	text.draw("PovY",100,100,50);
		//}
		//if (sf::Joystick::isButtonPressed(0, 8))
		//{
		//	text.draw("8",100,100,50);
		//}
		//if (sf::Joystick::isButtonPressed(0, 9))
		//{
		//	text.draw("9",100,100,50);
		//}
		//if (sf::Joystick::isButtonPressed(0, 10))
		//{
		//	text.draw("10",100,100,50);
		//}
		//if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY))
		//{
		//	text.draw("Y",150,150,50,255,0,0);
		//}
		//if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovX))
		//{
		//	text.draw("X",150,150,50,255,0,0);
		//}
		//for(int i = 0; i < 32; i++)
		//{
		//}
//
//		// what's the current position of the X and Y axes of joystick number 0?
//		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
//		float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
//
//		std::cout << x << " " << y << std::endl;
		panel->debug("AXIS_X",input->isPressed(JOYSTICK::AXIS_X,PLAYER_1));
		panel->debug("AXIS_Y",input->isPressed(JOYSTICK::AXIX_Y,PLAYER_1));

		panel->debug("DOWN",input->isPressed(JOYSTICK::DOWN,PLAYER_1));
		panel->debug("LEFT",input->isPressed(JOYSTICK::LEFT,PLAYER_1));
		panel->debug("UP",input->isPressed(JOYSTICK::UP,PLAYER_1));
		panel->debug("RIGHT",input->isPressed(JOYSTICK::RIGHT,PLAYER_1));

		//panel->debug("L1",input->isPressed(JOYSTICK::L1,PLAYER_1));
		//panel->debug("L2",input->isPressed(JOYSTICK::L2,PLAYER_1));
		//panel->debug("R1",input->isPressed(JOYSTICK::R1,PLAYER_1));
		//panel->debug("R2",input->isPressed(JOYSTICK::R2,PLAYER_1));

		//panel->debug("SELECT",input->isPressed(JOYSTICK::SELECT,PLAYER_1));
		//panel->debug("START",input->isPressed(JOYSTICK::START,PLAYER_1));

		//panel->debug("LEFT_STICK",input->isPressed(JOYSTICK::LEFT_STICK,PLAYER_1));
		//panel->debug("RIGHT_STICK",input->isPressed(JOYSTICK::RIGHT_STICK,PLAYER_1));

		//panel->debug("RIGHT_LEFT",input->isPressed(JOYSTICK::RIGHT_LEFT,PLAYER_1));
		//panel->debug("RIGHT_RIGHT",input->isPressed(JOYSTICK::RIGHT_RIGHT,PLAYER_1));

		//panel->debug("RIGHT_DOWN",input->isPressed(JOYSTICK::RIGHT_DOWN,PLAYER_1));
		//panel->debug("RIGHT_UP",input->isPressed(JOYSTICK::RIGHT_UP,PLAYER_1));

		game.flush();
	}
}