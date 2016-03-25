#include <gpl>

void main()
{
	// Cria uma sprite para o splash screen
	Sprite splashSprite;

	// Carrega uma animação de um sprite sheet
	splashSprite.loadSpriteSheet("splash.png", 1, 15);

	// Define a velocidade da animação a ser usada na splash screen
	splashSprite.setSpeed(206);

	// Define a animação e o tempo de exibição da splash screen
	SplashScreen(splashSprite, 3);

	// Cria a janela
	Window janela(800, 600, "Minha Janela", true, false);

	// Define a quantidade máxima de FPS
	janela.setFPS(60);

	// Define o icone da janela
	janela.setIcon("icone.png");

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

