#include <gpl>

void main()
{
	// Cria a janela
	Window janela(800, 600, "Minha Janela", true, false);

	// INICIO DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	float x = 0;
	float y = 0;

	Parallax teste(true, true);
	teste.addPanel("bg1.png", 1, 1);
	teste.addPanel("bg2.png", 2, 2);

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		// BLOCO DE COMANDOS
		teste.draw(x, y);

		if (input->isPressed(KEY::Up)) y++;
		if (input->isPressed(KEY::Down)) y--;
		if (input->isPressed(KEY::Right)) x++;
		if (input->isPressed(KEY::Left)) x--;

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

