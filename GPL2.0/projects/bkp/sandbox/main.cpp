#include "gpl.hpp"

void main()
{
	Sprite splashSprite;
	splashSprite.loadSpriteSheet("splash.png", 1, 15);
	splashSprite.setSpeed(206);

	SplashScreen(splashSprite, 3);

	// Cria a janela
	Window janela(800, 600, "Minha Janela", true, false);

	// INICIO DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		// BLOCO DE COMANDOS

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

