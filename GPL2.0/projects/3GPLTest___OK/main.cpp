#include <GPLGame>

struct Vector2D
{
	float x;
	float y;
};

Game
{
	Sprite teste;

	Vector2D pos;
	Vector2D posInicio;
	Vector2D destino;

	void Start()
	{
		teste.load("image.png");
		pos.x = 400;
		pos.y = 300;
		posInicio = pos;
		destino = pos;
	}

	void MinhaFunc()
	{
		panel->debug("W", pos.x);
		panel->debug("H", pos.y);
	}

	float tempo = 0;
	float duracaoMov;
	void Update()
	{
		if (input->isDown(MOUSE::Left))
		{
			// reseta pos inicial
			posInicio = pos;
			// nova posição de destino
			destino.x = input->getMouseX();
			destino.y = input->getMouseY();
			//	reseta o tempo
			tempo = 0;
			duracaoMov = 2.0f;
		}


		if (pos.x != destino.x || pos.y != destino.y)
		{
			tempo += 0.001;
			//if (tempo >= duracaoMov)
			//	tempo = duracaoMov;

			pos.x = ease->InCubic(tempo, duracaoMov, pos.x, destino.x);
			pos.y = ease->InQuintic(tempo, duracaoMov, pos.y, destino.y);
		}

		teste.draw(pos.x,pos.y);
		MinhaFunc();

		panel->debug("X", input->getMouseX());
		panel->debug("Y", input->getMouseY());
		//if(input->isPressed(KEY::Up))
		//{
		//	x += inCircle(0.1);
		//	y += outCubic(0.1);
		//	//			app->resizeWindow(1024, 768);
		//	//Application->setWindowFullscreen();
		////	base->getInstance()->window->setSize(sf::Vector2u(1024, 768));
		////	//Quit();
		//}
		//if (input->isPressed(KEY::Down))
		//{
		//	x -= inCircle(0.1);
		//	y -= outCubic(0.1);
		//}
		if (input->isDown(KEY::Right))
		{
			Application->resizeWindow(300,400);
		}
		if (input->isDown(KEY::Left))
		{
			Application->resizeWindow(800, 600);
		}

		if (input->isDown(KEY::Escape)) Quit();
	}


	void Finish()
	{
		//cout << "TESTE";
	}
};



//void main()
//{
//	// Cria a janela
//	Window janela(800, 600, "Minha Janela", true, false);
//
//	// INICIO DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS
//
//	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS
//
//	// Enquanto a tecla 'ESC' não for pressionada
//	while (!input->isPressed(KEY::Escape))
//	{
//		// BLOCO DE COMANDOS
//
//		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
//		janela.flush();
//	}
//}
//
