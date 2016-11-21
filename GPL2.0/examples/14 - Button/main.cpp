#include <gpl>

void main()
{
	// Cria a janela
	Window janela(800, 600, "Minha Janela", true, false);

	// INICIO DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS
	Button botao("new_game.png");
	Text texto;
	texto.load("calibri.ttf");

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		if(botao.isHovered())
		{
			texto.draw("IS HOVERED", 20, 500, 30);
		}
		if (botao.isPressed())
		{
			texto.draw("IS PRESSED", 20, 450, 30);
		}
		if (botao.onClick())
		{
			texto.draw("ON CLICK", 20, 400, 30);
		}
		if (botao.onRelease())
		{
			texto.draw("ON RELEASE", 20, 350, 30);
		}
		// BLOCO DE COMANDOS
		botao.draw(300, 200);
		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

