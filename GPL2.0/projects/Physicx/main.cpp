#include <gpl>
#include "Sprite_.hpp"

void main()
{
	// Cria a janela
	Window janela(800, 600, "Minha Janela", true, false);

	// INICIO DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS
	// Posições iniciais do objeto
	float x = 200;
	float y = 600;
	
	Sprite_ imagem;
	imagem.load("minhaImagem.png");

	imagem.setMass(5);
	imagem.setFriction(0.1);
	
	Sprite_ chao;
	chao.load("chao.png");

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	float xx = 0;
	float yy = 169;

	float xxx = 300;
	float yyy = 400;
	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		// BLOCO DE COMANDOS
		// Lógica do Jogo
		imagem.draw(x, y);
		chao.draw(xx,yy);

		// Se o botão ESQUERDO do mouse foi pressionado o projétil é lançado no ângulo 
		if (input->isDown(KEY::Up))
		{
			imagem.rigidbody.shoot(5);
		}
		if (input->isPressed(KEY::Left))
		{
			x--;
		}
		else if (input->isPressed(KEY::Right))
		{
			x++;
		}

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

