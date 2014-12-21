#include <gpl.h>

#include <iostream>
using namespace std;

void main()
{
	// Se o programador desejar uma Splash Screen esta deve ser a primeira linha, 
	// pois será exibida enquanto durar o carregamento de arquivos
	gplSplashScreen("splash.png", 4);

	// SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	sprite ship;
	for(int i = 0; i < 8; i++)
	{
		ship.load("shipAnimation.png", 115*i, 0, 115, 69);

	}
	ship.setSpeed(50);

	sprite fundo1;
	fundo1.load("shipAnimation.png");
	sprite fundo2;
	sprite fundo3;

	//// Cria um vector de sprites
	//vector<sprite> tiles;
	//for(int j = 0; j < 9; j++)
	//{
	//	sprite s;
	//	s.load("tileset.png", 66*j, 0, 66, 48);
	//	tiles.push_back(s);
	//}



	// Cria uma imagem
	sprite animacao1;

	// Carrega várias imagens para criar uma animação fazendo cortes em um sprite sheet
	for(int j = 0; j < 2; j++)
	{
		for(int i = 0; i < 4; i++)
		{
			animacao1.load("mario.png", 64*i, 98*j, 64, 98);
		}
	}
	// Define uma velocidade para a animação
	animacao1.setSpeed(70);

	// Cria uma imagem
	sprite imagem1;

	// Carrega a imagem
	imagem1.load("minhaImagem.png");

	// Cria uma imagem para o mouse
	sprite imagemMouse;

	// Carrega a imagem do mouse
	imagemMouse.load("mouse.png");

	// Carrega uma fonte
	text meuTexto;
	meuTexto.load("minhaFonte.ttf");

	// Cria um som
	sound meuSom;

	// Carrega o som
	meuSom.load("meuSom.wav");


	// Cria uma música
	music minhaMusica;

	// Carrega a música
	minhaMusica.load("minhaMusica.ogg");

	int x = 100;
	int y = 100;


	// Cria a janela
	gplInit(800, 600, "Minha Janela", true, false);
	gplSetFPS(120);

	// Define o icone da janela
	gplSetIcon("icone.png");

	// Começa a tocar a música
	minhaMusica.play();

	// LOOP PRINCIPAL DO JOGO
	// Enquanto a tecla 'ESC' não for pressionada
	while (!isKeyPressed(KEY::Escape))
    {
		if(isKeyPressed(KEY::A))
		{
			x-=1;
			meuSom.play(4);
		}

		if(isKeyPressed(KEY::D))
		{
			x+=1;
		}

		if(isKeyPressed(KEY::W))
		{
			y-=1;
		}
		if(isKeyPressed(KEY::S))
		{
			y+=1;
		}

		// Desenha o mapa
		//int tile = 0;
		//int offset = 0;
		//for(int i = 0; i < 3; i++)
		//{
		//	offset = ((i%2) == 1) ? 0 : 33;
		//	for(int j = 0; j < 3; j++)
		//	{
		//		tiles[tile].draw(j*66+offset,i*24);
		//		tile++;
		//	}
		//}

		// Desenha um retangulo
		rectangle(300,300,40,70,2,0,0,244,255,40);

		// Desenha um círculo
		circle(700,400,20,4,0,233,0,255);

		// Desenha uma linha
		line(500,400,180,2,222,0,0,255,23);

		// Desenha um pixel
		pixel(10,20,0,255,0,255);

		// Se o botão Esquerdo do mouse foi pressionado
		if (isButtonPressed(MOUSE::Left))
		{
			cout << "LEFT " << getMouseX() << " " << getMouseY() << endl; 
		}	

		if (isButtonPressed(MOUSE::Right))
		{
			cout << "RIGHT " <<  getMouseX() << " " << getMouseY() << endl; 
		}	

		// Escrever texto com a fonte pré-definida anteriormente com a cor no padrão RGB (0-255)
		meuTexto.draw("Isso é um texto", 200, 200, 40);
		meuTexto.draw("Aqui é outro texto =D", 200, 240, 30, 100, 100, 100);

		debug("FPS",gplGetFPS());
		debug("Scroll",getMouseScroll());
		debug("Mouse Left",isButtonPressed(MOUSE::Left));
		debug("Mouse Right",isButtonPressed(MOUSE::Right));
		debug("Colisão",animacao1.collides(imagemMouse));
		
		// Desenha a imagem/animação
		animacao1.draw(x, y, false, 200, 45, true);		
		//ship.draw(x, y, 0);		

		// Desenha a imagem
		imagem1.draw(300,400);

		// Desenha o mouse
		imagemMouse.draw(getMouseX(), getMouseY(), 0, false);		

		// Verifica se animacao1 colidiu com a imagem do mouse
		if(animacao1.collides(imagemMouse))
		{
			cout << "COLIDE" << endl;
		}
		else
		{
//			cout << "NAO COLIDE" << endl;
		}
		
		// Escreve no terminal o FPS
		cout << "FPS " << gplGetFPS() << endl;
		cout << getMouseScroll() << endl;
		
		// Para o programa 1000 milisegundos = 1 segundo
		//gpl_aguardar(1000);

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		gplFlush();
    }
}