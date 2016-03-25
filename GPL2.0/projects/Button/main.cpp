#include <gpl>

void main()
{
	// Cria a janela
	Window janela(800, 600, "Minha Janela", true, false);

	// INICIO DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS
	Button button("button.png");
	Text texto;
	texto.load("calibri.ttf");
	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{

		button.draw(0, 500);

		if (button.onClick())
		{
			texto.draw("Click", 100, 100, 30);
		}

		if (button.onRelease())
		{
			texto.draw("Release", 100, 130,30);
		}

		if (button.isHovered())
		{
			texto.draw("Hovered", 100, 160, 30);
		}

		if (button.isPressed())
		{
			texto.draw("Pressed", 100, 190, 30);
		}

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

