#include <gpl>
// * * * * * Créditos * * * * * * //
// Prof. MSC. Luan Carlos Nesi	  //
//  Leonardo Schmitt Teixeira	  //
// * * * * * * * * * * * * * * *  //

void main()
{
	// Cria a janela
	Window janela(800, 600, "Minha Janela", true, false);

	// INICIO DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS
	
	// Declaração das variáveis das sprites
	Sprite marioAnimado;
	Sprite bola;

	//posicao x mario;
	float marioPosX = 100;

	// Load da sprite sheet do Mario e da sprite padrão bola
	marioAnimado.loadSpriteSheet("mario.png", 4, 2);
	bola.load("bola.png");

	// Setando a speed da animação do Mario
	marioAnimado.setSpeed(100);

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		// BLOCO DE COMANDOS

		//desenho da bola e do mario
		bola.draw(600, 550, 0.1,0.1);
		marioAnimado.draw(marioPosX, 500);

		//ifs que cuidam da movimentacao do mario
		if (input->isPressed(KEY::Right))
		{
			marioPosX += 0.1;
		}

		if (input->isPressed(KEY::Left))
		{
			marioPosX -= 0.1;
		}

		// Ifs que testam colisao do mario com a bola
		// Sprite.collides(outraSprite) retorna true se colidir.
		if (marioAnimado.collides(bola))
		{
			// Se colidir, setar o mário novamente para a posição 100;
			marioPosX = 100;
		}
		
		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

