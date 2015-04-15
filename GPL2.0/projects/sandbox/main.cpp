#include "gpl.hpp"

void main()
{
	// Cria a janela
	Window janela(800, 600, "Minha Janela", true, false);
	janela.setFPS(120);

	// SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	Sprite ship;
	for(int i = 0; i < 8; i++)
	{
		ship.load("shipAnimation.png", 115*i, 0, 115, 69);

	}
	ship.setSpeed(50);

	Sprite fundo1;
	fundo1.load("shipAnimation.png");
	Sprite fundo2;
	Sprite fundo3;

	// Cria uma imagem
	Sprite animacao1;

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
	Sprite imagem1;

	// Carrega a imagem
	imagem1.load("minhaImagem.png");

	// Cria uma imagem para o mouse
	Sprite imagemMouse;

	// Carrega a imagem do mouse
	imagemMouse.load("mouse.png");

	// Carrega uma fonte
	Text meuTexto;
	meuTexto.load("minhaFonte.ttf");

	// Cria um som
	Sound meuSom;

	// Carrega o som
	meuSom.load("meuSom.wav");


	// Cria uma música
	Music minhaMusica;

	// Carrega a música
	minhaMusica.load("minhaMusica.ogg");

	int x = 100;
	int y = 100;

	// Define o icone da janela
	janela.setIcon("icone.png");

	// Começa a tocar a música
	minhaMusica.play();

	// LOOP PRINCIPAL DO JOGO
	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
    {
		if (input->isPressed(KEY::A))
		{
			x-=1;
			meuSom.play(4);
		}

		if (input->isPressed(KEY::D))
		{
			x+=1;
		}

		if (input->isPressed(KEY::W))
		{
			y+=1;
		}
		if (input->isPressed(KEY::S))
		{
			y-=1;
		}

		// Desenha um retangulo
		gizmos->rectangle(300,300,40,70,2,0,0,244,255,40);

		// Desenha um círculo
		gizmos->circle(700, 400, 20, 4, 0, 233, 0, 255);

		// Desenha uma linha
		gizmos->line(500, 400, 180, 2, 222, 0, 0, 255, 23);

		// Desenha um pixel
		gizmos->pixel(10, 20, 0, 255, 0, 255);

		// Se o botão Esquerdo do mouse foi pressionado
		if (input->isPressed(MOUSE::Left))
		{
			meuTexto.draw("MOUSE LEFT", 100, 100);
		}	

		if (input->isPressed(MOUSE::Right))
		{
			meuTexto.draw("MOUSE RIGHT", 100, 100);
		}

		// Escrever texto com a fonte pré-definida anteriormente com a cor no padrão RGB (0-255)
		meuTexto.draw("Isso é um texto", 200, 200, 40);
		meuTexto.draw("Aqui é outro texto =D", 200, 240, 30, 100, 100, 100);

		panel->debug("FPS",janela.getFPS());
		panel->debug("Mouse Left", input->isPressed(MOUSE::Left));
		panel->debug("Mouse Right", input->isPressed(MOUSE::Right));
		panel->debug("Colisão", animacao1.collides(imagemMouse));
		
		// Desenha a imagem/animação
		animacao1.draw(x, y, false, 200, 45, true);		
		//ship.draw(x, y, 0);		

		// Desenha a imagem
		imagem1.draw(300,400);

		// Desenha o mouse
		imagemMouse.draw(input->getMouseX(), input->getMouseY());

		// Verifica se animacao1 colidiu com a imagem do mouse
		if(animacao1.collides(imagemMouse))
		{
			meuTexto.draw("COLIDIU", 200, 200, 40);
		}
		
		// Para o programa 1000 milisegundos = 1 segundo
		//janela.gplSleep(1000);

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
    }
}