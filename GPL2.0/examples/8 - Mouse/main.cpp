#include <gpl>
// * * * * * Créditos * * * * * * //
// Prof. MSC. Luan Carlos Nesi	  //
//  Leonardo Schmitt Teixeira	  //
// * * * * * * * * * * * * * * *  //

void main()
{
	// Cria a janela
	Window janela(800, 600, "Minha Janela", false, false);

	// INICIO DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS
	
	// Declaração das variáveis Sprite
	Sprite swordCursor;
	Sprite bola;
	
	// Declaração da variável do texto
	Text furaBola;

	// Load dos sprites usados
	swordCursor.load("SwordCursor.png");
	bola.load("bola.png");

	// Load da fonte do texto
	furaBola.load("calibri.ttf");

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{		
		// BLOCO DE COMANDOS

		// Desenhamos a sprite da espada onde:
		// X da espada é = ao X do mouse, Y da espada é = ao Y do mouse
		// Escala de 0.1, para redimencionar a imagem da espada
		swordCursor.draw(input->getMouseX(), input->getMouseY(),0.1,0.1);

		// Se a sprite da espada não colidir com a da bola, desenhe a bola
		if (!swordCursor.collides(bola))
		{
			bola.draw(380, 100, 0.1, 0.1);
		}
		// Caso contrário:
		else
		{
			furaBola.draw("Bola Furada!", 320, 380, 30);
		}
		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

