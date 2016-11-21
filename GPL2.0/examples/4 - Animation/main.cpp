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

	// Variável da animação
	Sprite animacao;

	// Carregamento da animação do sprite sheet
	// arquivo = "mario.png"	qtdX = 4	qtdY = 2
	animacao.loadSpriteSheet("mario.png",4,2);

	// Define uma velocidade da animação
	animacao.setSpeed(70);

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		// BLOCO DE COMANDOS

		// Desenha a animação
		// x = 400			y = 400
		// scaleX = 1.5		scaleY = 1.5
		animacao.draw(400, 400, 1.5, 1.5);

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

