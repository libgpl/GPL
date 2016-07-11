#include <gpl>

float inCircle(float t)
{
	return -1 * (sqrt(1 - t * t) - 1);
}

float outCubic(float t)
{
	return (--t) * t * t + 1;
}

void main()
{
	// Cria a janela
	Window janela(800, 600, "Minha Janela", true, false);

	// INICIO DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS
	int x = 400;
	int y = 300;

	Sprite teste;
	teste.load("image.png");

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		// BLOCO DE COMANDOS
		teste.draw(x, y);
		x = inCircle(x);
		y = outCubic(y);
		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

