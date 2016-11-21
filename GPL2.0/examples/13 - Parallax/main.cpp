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

	float x = 0;
	float y = 0;

	// Cria uma paralaxe com repetição em X e Y
	Parallax teste(true, true);
	// Adiciona 2 paineis com velocidade em X e Y de 0.5, para o painel 1
	// e velocidade em X e Y de 1.0 para o painel 2
	teste.addPanel("bg1.png", 0.5, 0.5);
	teste.addPanel("bg2.png", 1.0, 1.0);

	// FIM DA SEÇÃO DE CARREGAMENTO DE ARQUIVOS

	// Enquanto a tecla 'ESC' não for pressionada
	while (!input->isPressed(KEY::Escape))
	{
		// BLOCO DE COMANDOS
		
		// Desenha a paralaxe
		teste.draw(x, y);

		// Altera as posições dos paineis para movimentação
		if (input->isPressed(KEY::Up)) y--;
		if (input->isPressed(KEY::Down)) y++;
		if (input->isPressed(KEY::Right)) x--;
		if (input->isPressed(KEY::Left)) x++;

		// Atualiza a tela - deve ser a última coisa a ser chamada dentro do loop
		janela.flush();
	}
}

